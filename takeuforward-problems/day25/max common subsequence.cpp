#include <bits/stdc++.h>
using namespace std;
// this is same as kadane'algo but different in when 2 -ve value are come the product is +ve

// int maxcommonsequence(string str1,string str2,int n,int m){
// 	if(n<=0 || m<=0) return 0;

// 	if(str1[n-1] == str2[m-1]) return 1+maxcommonsequence(str1,str2,n-1,m-1);
// 	return max(maxcommonsequence(str1,str2,n-1,m),maxcommonsequence(str1,str2,n,m-1));
// }

// using dp
int maxcommonsequence(string str1,string str2,int n,int m){
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0) dp[i][j]=0;
			else if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];
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
		string str1,str2;
		cin>>str1>>str2;
		int n = str1.size();
		int m = str2.size();
		cout<<maxcommonsequence(str1,str2,n,m)<<endl;
	}
	return 0;
}