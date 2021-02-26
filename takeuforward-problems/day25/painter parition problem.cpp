#include <bits/stdc++.h>
#define vec1 vector<int> 
using namespace std;

int sum(vec1 &arr,int l,int r){
	int val=0;
	for(int i=l;i<=r;i++) val += arr[i];
	return val;
}

// Method 1: recursion 
// int painterPartition(vec1 &arr,int n,int k){
// 	if(k==1){
// 		return sum(arr,0,n-1);
// 	}

// 	if(n==1){
// 		return arr[0];
// 	}

// 	int maxval=INT_MAX;

// 	for(int i=1;i<=n;i++) 
// 		maxval = min(maxval,max(painterPartition(arr,i,k-1),sum(arr,i,n-1)));

// 	return maxval;
// }

// Method 2: dynamic programming
int painterPartition(vec1 &arr,int n,int k){
	int dp[k + 1][n + 1] = { 0 };
 
    // base cases
    // k=1
    for (int i = 1; i <= n; i++)
        dp[1][i] = sum(arr, 0, i - 1);
 
    // n=1
    for (int i = 1; i <= k; i++)
        dp[i][1] = arr[0];
 
    // 2 to k partitions
    for (int i = 2; i <= k; i++) { // 2 to n boards
        for (int j = 2; j <= n; j++) {
 
            // track minimum
            int best = INT_MAX;
 
            // i-1 th separator before position arr[p=1..j]
            for (int p = 1; p <= j; p++) 
                best = min(best, max(dp[i - 1][p],
                              sum(arr, p, j - 1)));       
 
            dp[i][j] = best;
        }
    }
 
    // required
    return dp[k][n];
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,k; cin>>t;
	while(t--){
		cin>>n>>k;
		vec1 arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<painterPartition(arr,n,k)<<endl;
	}
	return 0;
}
// don't settle on same approach
// check for base cases n=0
// write every possible case 