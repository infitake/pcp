// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, determine the total number of ways to decode it.

// Example 1:

// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
// Example 2:

// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

#include <bits/stdc++.h>
using namespace std;

int numDecodings(string arr) {
        long long n = arr.size();
        long long  t=0,k=0;
        vector<long long> dp(n+1,0);
        dp[n]=1;
        for(long long i=n-1;i>=0;i--){
            if(arr[i]!='0'){
                if(i<n-1){
                    t = (arr[i]-'0')*10+(arr[i+1]-'0');
                    if(t>=1 && t<=26) dp[i] += dp[i+2];
                }
                dp[i]+=dp[i+1];
            }
        } 
        return int(dp[0]);
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
		string str;
		cin>>str;
		cout<<numDecodings(str)<<endl;
	}
	return 0;
}