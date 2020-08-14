#include <bits/stdc++.h>
using namespace std;

void bfs(vector<list<int>> &adj,int v,int i){
	vector<bool> visited(v,false);
	queue<int> q;
	visited[i]=true;
	q.push(i);
	while(!q.empty()){
		int u = q.front();
		cout<<u<<" ";
		q.pop();
		for(auto it = adj[u].begin();it!=adj[u].end();it++){
			if(!visited[*it]){
				// cout<<"kd "<<(*it)<<" ";
				visited[*it]=true;
				q.push(*it);
			}
		}
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
		bfs(adj,v,2);
	}
	return 0;
}