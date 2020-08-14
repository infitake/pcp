#include <bits/stdc++.h>
using namespace std;

// this is the dfs approach for finding cycle
// bool iscyclicUtil(vector<list<int>> &adj,int v,int i,vector<bool> &visited,int parent){
// 	visited[i]=true;
// 	// cout<<i<<" ";
// 	for(auto it=adj[i].begin();it!=adj[i].end();it++){
// 		if(!visited[*it]) {
// 			if(iscyclicUtil(adj,v,*it,visited,i)) return true;
// 		}
// 		else if(*it != parent){
// 			return true;
// 		}
// 	}
// 	return false;
// }

// bool iscyclic(vector<list<int>> &adj,int v){
// 	vector<bool> visited(v,false);
// 	for(int i=0;i<v;i++){
// 		if(!visited[i]) {
// 			if(iscyclicUtil(adj,v,i,visited,-1)) return true;
// 		}
// 	}
// 	return false;
// }

// This is the bfs approach for finding cycle
// bool iscyclicUtil(vector<list<int>> &adj,int v,int i,vector<bool> &visited){
// 	vector<int> parent(v,-1);
// 	queue<int> q;
// 	q.push(i);
// 	while(!q.empty()){
// 		int u = q.front();
// 		q.pop();
// 		for(auto it = adj[u].begin();it!=adj[u].end();it++){
// 			if(!visited[*it]){
// 				visited[*it]=true;
// 				parent[*it]=u;
// 				q.push(*it);
// 			}
// 			else if(*it != parent[u]){
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }

// bool iscyclic(vector<list<int>> &adj,int v){
// 	vector<bool> visited(v,false);
// 	for(int i=0;i<v;i++){
// 		if(!visited[i]) {
// 			if(iscyclicUtil(adj,v,i,visited)) return true;
// 		}
// 	}
// 	return false;
// }

// detact cycle in directed graph (taking a recursionstk in place of a parent )
bool iscyclicUtil(vector<list<int>> &adj,int v,int i,vector<bool> &visited,vector<bool> &recursionstk){
	if(!visited[i]){
		visited[i]=true;
		recursionstk[i]=true;
		for(auto it=adj[i].begin();it!=adj[i].end();it++){
			if(!visited[*it]) {
				if(iscyclicUtil(adj,v,*it,visited,recursionstk)) return true;
			}
			else if(recursionstk[*it]){
				return true;
			}
		}
	}
	recursionstk[i]=false;
	return false;
}

bool iscyclic(vector<list<int>> &adj,int v){
	vector<bool> visited(v,false),recursionstk(v,false);
	for(int i=0;i<v;i++){
		if(!visited[i]) {
			if(iscyclicUtil(adj,v,i,visited,recursionstk)) return true;
		}
	}
	return false;
}

// union and find method for cycle detection
int find(int parent[], int i)  
{  
    if (parent[i] == -1)  
        return i;  
    return find(parent, parent[i]);  
}  
  
// A utility function to do union of two subsets  
void Union(int parent[], int x, int y)  
{  
    int xset = find(parent, x);  
    int yset = find(parent, y);  
    if(xset != yset) 
    {  
        parent[xset] = yset;  
    }  
}  
  
// The main function to check whether a given graph contains  
// cycle or not  
int isCycle( Graph* graph )  
{  
    // Allocate memory for creating V subsets  
    int *parent = new int[graph->V * sizeof(int)];  
  
    // Initialize all subsets as single element sets  
    memset(parent, -1, sizeof(int) * graph->V);  
  
    // Iterate through all edges of graph, find subset of both  
    // vertices of every edge, if both subsets are same, then  
    // there is cycle in graph.  
    for(int i = 0; i < graph->E; ++i)  
    {  
        int x = find(parent, graph->edge[i].src);  
        int y = find(parent, graph->edge[i].dest);  
  
        if (x == y)  
            return 1;  
  
        Union(parent, x, y);  
    }  
    return 0;  
} 

// this is using the color scheme
bool Graph::DFSUtil(int u, int color[]) 
{ 
    // GRAY :  This vertex is being processed (DFS 
    //         for this vertex has started, but not 
    //         ended (or this vertex is in function 
    //         call stack) 
    color[u] = GRAY; 
  
    // Iterate through all adjacent vertices 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // An adjacent of u 
  
        // If there is 
        if (color[v] == GRAY) 
          return true; 
  
        // If v is not processed and there is a back 
        // edge in subtree rooted with v 
        if (color[v] == WHITE && DFSUtil(v, color)) 
          return true; 
    } 
  
    // Mark this vertex as processed 
    color[u] = BLACK; 
  
    return false; 
} 
  
// Returns true if there is a cycle in graph 
bool Graph::isCyclic() 
{ 
    // Initialize color of all vertices as WHITE 
    int *color = new int[V]; 
    for (int i = 0; i < V; i++) 
        color[i] = WHITE; 
  
    // Do a DFS traversal beginning with all 
    // vertices 
    for (int i = 0; i < V; i++) 
        if (color[i] == WHITE) 
           if (DFSUtil(i, color) == true) 
              return true; 
  
    return false; 
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
		cout<<iscyclic(adj,v)<<endl;
	}
	return 0;
}