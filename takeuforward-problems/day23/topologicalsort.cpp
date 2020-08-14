#include <bits/stdc++.h>
using namespace std;

void toposortUtil(vector<list<int>> &adj,int v,int i,vector<bool> &visited,stack<int> &top){
	visited[i]=true;
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]) toposortUtil(adj,v,*it,visited,top);
	}
	top.push(i);
}

void toposort(vector<list<int>> &adj,int v){
	vector<bool> visited(v,false);
	stack<int> top;
	for(int i=0;i<v;i++){
		if(!visited[i]) toposortUtil(adj,v,i,visited,top);
	}
	while(!top.empty()){
		cout<<top.top()<<" ";
		top.pop();
	}
}

//Kahn’s algorithm for Topological Sorting

void khantoposort(vector<list<int>> &adj,int v){
	vector<int> inorder(v,0);
	for(int i=0;i<v;i++){
		for(auto it=adj[i].begin();it!=adj[i].end();it++){
			inorder[*it]++;
		}
	}
	vector<int> topsort;
	int count=0;
	queue<int> q;
	for(int i=0;i<v;i++){
		if(inorder[i] == 0) q.push(i);
	} 

	while(!q.empty()){
		int u = q.front();
		q.pop();
		topsort.push_back(u);
		for(auto it=adj[u].begin();it!=adj[u].end();it++){
			if(--inorder[*it] == 0)
				q.push(*it);
		}
		count++;
	}
	if(count != v) {
		cout<<"not possible "<<endl;
		return;
	}
	for(auto x:topsort) cout<<x<<" ";
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,v,e,v1,v2; cin>>t;
	while(t--){
		cin>>v>>e;
		vector<list<int>> adj(v); 
		for(int i=0;i<e;i++){
			cin>>v1>>v2;
			adj[v1].push_back(v2);
			// adj[v2].push_back(v1);
		}
		khantoposort(adj,v);
		cout<<endl;
	}
	return 0;
}