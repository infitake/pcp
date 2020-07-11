#include <bits/stdc++.h> 
using namespace std; 
#define N 10


// Method 1:
bool issafe(int arr[N][N],int n ,int color[]){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			// here arr[i][j]==1 means the 2 edges are connected
			// so they are adjacent to each other
			// if they have same color then we have to return false;
			if(arr[i][j] && color[i]==color[j]) return false; 
		}
	}
	return true;
}

void printcolor(int color[],int n){
	for(int i=0;i<n;i++) cout<<color[i]<<" ";
	cout<<endl;
}

bool mcolor(int arr[N][N],int n,int color[],int m,int color_index){
	if(color_index == n) {
		if(issafe(arr,n,color)){
			printcolor(color,n);
			return true;
		}
		return false;
	}

	for(int j=1;j<=m;j++){
		color[color_index]=j;
		// goes for next index of color
		if(mcolor(arr,n,color,m,color_index+1)) return true;
		color[color_index]=0;
	}
	return false;
}

// Method 2:(backtracking)
/* A utility function to check if  
   the current color assignment 
   is safe for vertex v i.e. checks  
   whether the edge exists or not 
   (i.e, graph[v][i]==1). If exist  
   then checks whether the color to  
   be filled in the new vertex(c is 
   sent in the parameter) is already 
   used by its adjacent  
   vertices(i-->adj vertices) or  
   not (i.e, color[i]==c) */
bool isSafe( 
    int v, bool graph[V][V], 
    int color[], int c) 
{ 
    for (int i = 0; i < V; i++) 
        if ( 
            graph[v][i] && c == color[i]) 
            return false; 
    return true; 
} 
  
/* A recursive utility function  
to solve m coloring problem */
bool graphColoringUtil( 
    bool graph[V][V], int m, 
    int color[], int v) 
{ 
    /* base case: If all vertices are  
       assigned a color then return true */
    if (v == V) 
        return true; 
  
    /* Consider this vertex v and  
       try different colors */
    for (int c = 1; c <= m; c++) { 
        /* Check if assignment of color  
           c to v is fine*/
        if (isSafe( 
                v, graph, color, c)) { 
            color[v] = c; 
  
            /* recur to assign colors to  
               rest of the vertices */
            if ( 
                graphColoringUtil( 
                    graph, m, color, v + 1) 
                == true) 
                return true; 
  
            /* If assigning color c doesn't 
               lead to a solution then remove it */
            color[v] = 0; 
        } 
    } 
  
    /* If no color can be assigned to  
       this vertex then return false */
    return false; 
} 
  
/* This function solves the m Coloring  
   problem using Backtracking. It mainly  
   uses graphColoringUtil() to solve the  
   problem. It returns false if the m  
   colors cannot be assigned, otherwise  
   return true and prints assignments of  
   colors to all vertices. Please note  
   that there may be more than one solutions, 
   this function prints one of the 
   feasible solutions.*/
bool graphColoring( 
    bool graph[V][V], int m) 
{ 
    // Initialize all color values as 0. 
    // This initialization is needed 
    // correct functioning of isSafe() 
    int color[V]; 
    for (int i = 0; i < V; i++) 
        color[i] = 0; 
  
    // Call graphColoringUtil() for vertex 0 
    if ( 
        graphColoringUtil( 
            graph, m, color, 0) 
        == false) { 
        printf("Solution does not exist"); 
        return false; 
    } 
  
    // Print the solution 
    printSolution(color); 
    return true; 
}


int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a; cin>>t;
	while(t--){
		cin>>n;
		int arr[N][N];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		int m;
		cin>>m;
		int color[n];
		memset(color,0,sizeof(color));
		// here 0 is represent the first index color
		if(mcolor(arr,n,color,m,0)!=true)
			cout<<"no solution";
	}
	return 0;
}

// This is code is contributed by rathbhupendra 
