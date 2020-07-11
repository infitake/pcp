#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}
// Method 1:
// change all the no to a max no and if max no come again
// than loop is found
bool detectloop(struct Node *root){
    int max = 10000;
    while(root!=NULL){
        if(root->data > max) return true;
        else root->data = max+1;
        root = root->next;
    }
    return false;
}
// Method 2:
// similar like finding middle
// use 2 pointer one is fast and other is slow
// if fast pointer equals slow then loop
//  Floyd’s Cycle-Finding Algorithm
// Approach: This is the fastest method and has been described below:

// Traverse linked list using two pointers.
// Move one pointer(slow_p) by one and another pointer(fast_p) by two. 
// If these pointers meet at the same node then there is a loop. 
// If pointers do not meet then linked list doesn’t have a loop.

bool detectloop(struct Node *root) {
    struct Node *fast = root,*slow = root;
    while (slow && fast && fast->next) { 
        slow = slow->next; 
        fast = fast->next->next; 
        if (slow == fast) { 
            return true; 
        } 
    } 
    return false; 
}

// Method 3:
// Approach:
// Traverse the list one by one and keep putting the node addresses in a Hash Table. 
// At any point, if NULL is reached then return false and if next of current node points
// to any of the previously stored nodes in Hash then return true.
bool detectLoop(struct Node* h) 
{ 
    unordered_set<Node*> s; 
    while (h != NULL) { 
        // If this node is already present 
        // in hashmap it means there is a cycle 
        // (Because you we encountering the 
        // node for the second time). 
        if (s.find(h) != s.end()) 
            return true; 
  
        // If we are seeing the node for 
        // the first time, insert it in hash 
        s.insert(h); 
  
        h = h->next; 
    } 
  
    return false; 
} 
void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
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
	int t,n,a,m,k; cin>>t;
	while(t--){
		struct Node *root=NULL;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
        // root->next->next->next->next = root; 
		if(detectloop(root)) cout<<"loop"<<endl;
        else cout<<"no loop"<<endl;		
	}
	return 0;
}