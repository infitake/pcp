#include <bits/stdc++.h>
using namespace std;
#define N 10


int maxpathcell(int arr[][N],int dp[][N],int n,int i,int j){
	if(i<0 || i>=n || j<0 || j>=n) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int x=INT_MIN,y=INT_MIN,w=INT_MIN,z=INT_MIN;
	if(j<n-1 && arr[i][j]+1 == arr[i][j+1])
		x = 1+maxpathcell(arr,dp,n,i,j+1);
	if(i>0 && arr[i][j]+1 == arr[i-1][j])
		y = 1+maxpathcell(arr,dp,n,i-1,j);
	if(j>0 && arr[i][j]+1 == arr[i][j-1])
		w = 1+maxpathcell(arr,dp,n,i,j-1);
	if(i<n-1 && arr[i][j]+1 == arr[i+1][j])
		z = 1+maxpathcell(arr,dp,n,i+1,j);

	return dp[i][j]=max(x,max(y,max(w,max(z,1))));
}

int maxpath(int arr[][N],int n){
	int result = 1;
	int dp[N][N];
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j =0;j<n;j++){
			if(dp[i][j]==-1)
				maxpathcell(arr,dp,n,i,j);
			result = max(result,dp[i][j]);
		}
	}
	return result;
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
		cout<<maxpath(arr,n)<<endl;
	}
	return 0;
}