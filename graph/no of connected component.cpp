#include <bits/stdc++.h>
using namespace std;

void dfsUtil(vector<list<int>> &adj,int i,vector<bool> &visited){
	visited[i]=true;

	for(auto it = adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]) dfsUtil(adj,*it,visited);
	}
}

int countConnected(vector<list<int>> &adj,int V,int E){
	vector<bool> visited(V,false);
	int count=0;
	for(int i=0;i<V;i++){
		if(!visited[i]){
			dfsUtil(adj,i,visited);
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
	int t,v,e,a,b; cin>>t;
	while(t--){
		cin>>v>>e;
		vector<list<int>> adj(v);
		for(int i=0;i<e;i++){
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		cout<<countConnected(adj,v,e)<<endl;
	}
	return 0;
}