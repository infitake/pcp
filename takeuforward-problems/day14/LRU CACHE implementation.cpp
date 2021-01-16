#include <bits/stdc++.h>
using namespace std;



// We use two data structures to implement an LRU Cache.

// Queue which is implemented using a doubly linked list. The maximum size of the queue will be equal to the total number of frames available (cache size). 
// The most recently used pages will be near front end and least recently pages will be near the rear end.
// A Hash with page number as key and address of the corresponding queue node as value.
// When a page is referenced, the required page may be in the memory. If it is in the memory, we need to detach the node of the list and bring it to the front of the queue.
// If the required page is not in memory, we bring that in memory. In simple words, we add a new node to the front of the queue and update the corresponding node address in the hash. 
// If the queue is full, i.e. all the frames are full, 
// we remove a node from the rear of the queue, and add the new node to the front of the queue.


class LRU {
	list<int> dq;
	unordered_map<int,list<int>::iterator> mp;
	int cachesize;
public:
	LRU(int);
	void refer(int);
	void display();
};

LRU::LRU(int x){
	cachesize=x;
}
void LRU::refer(int x){
	if(mp.find(x)==mp.end()){
		// we have to check the cache it is full or not
		if(dq.size() == cachesize){
			int last = dq.back();
			dq.pop_back();
			mp.erase(last);
		}
	}
	else
		dq.erase(mp[x]);

	
	dq.push_front(x);
	mp[x]=dq.begin();

}

void LRU::display(){
	for(auto x:dq) cout<<x<<" ";
	cout<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
 	LRU ca(4); 
  
    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(1); 
    ca.refer(4); 
    ca.refer(5); 
    ca.display(); 
  
    return 0; 
}

class LRUCache {
public:
    list<int>q;
    map<int,pair<int,list<int>::iterator> >mp;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    void move(int key)
    {
        q.erase(mp[key].second);
        q.push_front(key);
        mp[key].second=q.begin();
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        int ans=mp[key].first;
       // mp.erase(key);
        move(key);
        return ans;
        
    }
    
    void put(int key, int val) {
        if(mp.find(key)!=mp.end())
        {
            mp[key].first=val;
            move(key);
        }
        else
        {
            q.push_front(key);
            mp[key]={val,q.begin()};
            n--;
        }
       
        if(n<0)
        {
            n++;
            mp.erase(q.back());
            q.pop_back();
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */