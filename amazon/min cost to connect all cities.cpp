#include <bits/stdc++.h>
using namespace std;
#define N 9

int minElement(int key[],bool mst[],int V){
	int min = INT_MAX,minindex;
	for(int v=0;v<V;v++){
		if(mst[v]==false && key[v]<min){
			min = key[v];
			minindex=v;
		}
	}
	return minindex;
}

void minConnecition(int graph[][N],int V){
	// we have a parent int arrya;

	int parent[V];

	bool mst[V];

	int key[V];

	for(int i=0;i<V;i++){
		mst[i]=false;key[i]=INT_MAX;
	}
	parent[0]=-1;
	key[0]=0;
	for(int count=0;count<(V-1);count++){
		// this is the min element in the graph
		int u = minElement(key,mst,V);

		mst[u]=true;
		for(int v=0;v<V;v++){
			if(graph[u][v] && mst[v]==false && graph[u][v]<key[v]){
				parent[v]=u;
				key[v]=graph[u][v];
			}
		}
	}

	int sum = 0;
	for(int i=1;i<V;i++){
		// cout<<parent[i]<<" "<<i<<" "<<graph[i][parent[i]]<<endl;
		sum += graph[i][parent[i]];
	}
	cout<<sum<<endl;
}


int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n; cin>>t;
	while(t--){
		cin>>n;
		int arr[N][N];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		minConnecition(arr,n);
		
	}
	return 0;
}