#include <bits/stdc++.h>
using namespace std;
#define N 50

// Method 1:
int gridpath(int arr[][N],int n,int m,int a,int b){
	if(a == n-1 && b == m-1) return 1;
	// if one is treated as obstacle then uncomment the below line
	// if(arr[a][b] == 1) return 0;
	if((a<0 || a>=n) || (b<0 || b>=m)) return 0;
	return gridpath(arr,n,m,a+1,b) + gridpath(arr,n,m,a,b+1);
}

// Method 2:(for printing the resultant path)
void printAllPathsUtil(int *mat, int i, int j, int m, int n, int *path, int pi) 
{ 
    // Reached the bottom of the matrix so we are left with 
    // only option to move right 
    if (i == m - 1) 
    { 
        for (int k = j; k < n; k++) 
            path[pi + k - j] = *((mat + i*n) + k); 
        for (int l = 0; l < pi + n - j; l++) 
            cout << path[l] << " "; 
        cout << endl; 
        return; 
    } 
  
    // Reached the right corner of the matrix we are left with 
    // only the downward movement. 
    if (j == n - 1) 
    { 
        for (int k = i; k < m; k++) 
            path[pi + k - i] = *((mat + k*n) + j); 
        for (int l = 0; l < pi + m - i; l++) 
            cout << path[l] << " "; 
        cout << endl; 
        return; 
    } 
  
    // Add the current cell to the path being generated 
    path[pi] = *((mat + i*n) + j); 
  
    // Print all the paths that are possible after moving down 
    printAllPathsUtil(mat, i+1, j, m, n, path, pi + 1); 
  
    // Print all the paths that are possible after moving right 
    printAllPathsUtil(mat, i, j+1, m, n, path, pi + 1); 
  
    // Print all the paths that are possible after moving diagonal 
    // printAllPathsUtil(mat, i+1, j+1, m, n, path, pi + 1); 
} 
  
// The main function that prints all paths from top left to bottom right 
// in a matrix 'mat' of size mXn 
void printAllPaths(int *mat, int m, int n) 
{ 
    int *path = new int[m+n]; 
    printAllPathsUtil(mat, 0, 0, m, n, path, 0); 
} 

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,m; cin>>t;
	while(t--){
		cin>>n>>m;
		int arr[N][N];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		cout<<gridpath(arr,n,m,0,0)<<endl;
	}
	return 0;
}