#include <bits/stdc++.h>
using namespace std;

void dfsUtil(vector<list<int>> &adj,int v,int i,vector<bool> &visited){
	visited[i]=true;
	cout<<i<<" ";
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]) dfsUtil(adj,v,*it,visited);
	}
}

int connectedComponent(vector<list<int>> &adj,int v){
	vector<bool> visited(v,false);
	int count=0;
	for(int i=0;i<v;i++){
		if(!visited[i]){
			dfsUtil(adj,v,i,visited);
			count++;
		}
	}
	return count;
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
			adj[v2].push_back(v1);
		}
		dfs(adj,v);
		cout<<endl;
	}
	return 0;
}