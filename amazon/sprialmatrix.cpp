#include <bits/stdc++.h>
using namespace std;
#define N 9

void spiralmatrix(int arr[N][N],int i,int j,int n,int m){


	if(i>=n || j>=m) return;

	for(int p=i;p<m;p++) cout<<arr[i][p]<<" ";

	for(int p=i+1;p<n;p++) cout<<arr[p][m-1]<<" ";

	if((n-1)!=i){
		for(int p=m-2;p>=j;p--) cout<<arr[n-1][p]<<" ";
	}
	
	if((m-1)!=j){
		for(int p=n-2;p>i;p--) cout<<arr[p][j]<<" ";
	}

	spiralmatrix(arr,i+1,j+1,n-1,m-1);

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

		spiralmatrix(arr,0,0,n,m);
	}
	return 0;
}