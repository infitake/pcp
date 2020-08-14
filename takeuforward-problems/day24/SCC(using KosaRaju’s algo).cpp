#include <bits/stdc++.h>
using namespace std;

void dfsUtil1(vector<list<int>> &adj,int v,int i,vector<bool> &visited,stack<int> &stk){
	visited[i]=true;
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]) dfsUtil1(adj,v,*it,visited,stk);
	}
	stk.push(i);
}
void dfsUtil2(vector<list<int>> &adj,int v,int i,vector<bool> &visited){
	visited[i]=true;
	cout<<i<<" ";
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]) dfsUtil2(adj,v,*it,visited);
	}
}
void transposegraph(vector<list<int>> &transgrp,vector<list<int>> &adj,int v) {
	for(int i=0;i<v;i++){
		// cout<<"kdd";
		for(auto it = adj[i].begin();it!=adj[i].end();it++){
			transgrp[*it].push_back(i);
			// cout<<(*it)<<" "<<i<<endl;
		}
	}
}

void scc(vector<list<int>> &adj,int v){
	vector<bool> visited(v,false);
	stack<int> stk;
	for(int i=0;i<v;i++){
		if(!visited[i]) dfsUtil1(adj,v,i,visited,stk);
	}
	vector<list<int>> transgrp(v);
	transposegraph(transgrp,adj,v);
	for(int i=0;i<v;i++) visited[i]=false;
	while(!stk.empty()){
		int u = stk.top();
		// cout<<u<<endl;
		stk.pop();
		if(!visited[u])
			dfsUtil2(transgrp,v,u,visited);
		cout<<endl;
	}
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
		scc(adj,v);
		cout<<endl;
	}
	return 0;
}