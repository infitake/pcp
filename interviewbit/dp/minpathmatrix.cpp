#include <bits/stdc++.h>
using namespace std;
#define N 10

// int minpathsum(int arr[][N],int n,int m,int x,int y){
// 	if(x<0 || x>=n || y<0 || y >=m) return INT_MAX;
// 	if(x==0 && y==0) return arr[x][y];
// 	return arr[x][y] + min(minpathsum(arr,n,m,x-1,y),minpathsum(arr,n,m,x,y-1));
// }

int minpathsum(int arr[][N],int n,int m){

	for (int i=1 ; i<n ; i++){ 
        arr[i][0] += arr[i-1][0]; 
    } 
  
    for (int j=1 ; j<m ; j++){ 
        arr[0][j] += arr[0][j-1]; 
    } 
  
    for (int i=1 ; i<n; i++) { 
        for (int j=1 ; j<m; j++) { 
            arr[i][j] += min(arr[i-1][j], arr[i][j-1]); 
        } 
    } 

    return arr[n-1][m-1];
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,m,a; cin>>t;
	while(t--){
		cin>>n>>m;
		int arr[N][N];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		
		cout<<minpathsum(arr,n,m)<<endl;
	}
	return 0;
}