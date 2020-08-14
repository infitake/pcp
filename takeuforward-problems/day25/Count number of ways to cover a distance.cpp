#include <bits/stdc++.h>
using namespace std;

int fib(int n){
	if (n<0)      return 0; 
    if (n==0)  return 1; 
	return fib(n-1)+fib(n-2)+fib(n-3);
}

int fib(int n){
	int dp[n+1];
	dp[0]=1;dp[1]=1;dp[2]=2;
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	return dp[n];
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
		cout<<fib(n)<<endl;
	}
	return 0;
}