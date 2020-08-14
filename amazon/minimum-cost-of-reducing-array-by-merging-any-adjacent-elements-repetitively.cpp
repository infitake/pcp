#include <bits/stdc++.h>
using namespace std;

// we have to take value adjcent but can take many no in continous array
// this is just like the mcm problem
int minMergeAdjcent(int arr[],int n){
	if(n==0) return 0;
	vector<int> prefix(n+1,0);
	for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+arr[i-1];

	vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));

	for(int i=1;i<=n;i++) dp[i][i]=0;

	for(int L=2;L<=n;L++){
		for(int i=0;i<=n-L+1;i++){
			int j= i+L-1;

			// get the sum in a range from i to j
			int sum = prefix[j]-prefix[i-1];
			
			for(int k=i;k<j;k++){
				dp[i][j] = min(dp[i][j],sum + dp[i][k]+dp[k+1][j]);
			}

		}
	}
	return dp[1][n];
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
		int arr[n];

		for(int i=0;i<n;i++) cin>>arr[i];

		cout<<minMergeAdjcent(arr,n)<<endl;
		
	}
	return 0;
}