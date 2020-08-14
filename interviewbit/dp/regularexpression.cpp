#include <bits/stdc++.h>
using namespace std;

// this is for all the character will be same

// int Solution::isMatch(const string str1, const string str2) {
// int n=str1.size();
//     int m=str2.size();
//     bool dp[n+1][m+1];
//     dp[0][0]=true;
//     for(int i=1;i<=n;i++) dp[0][i] = false; 
//     for(int i=1;i<=m;i++) dp[i][0] = false; 


//     for (int j = 1; j <= m; j++) 
//         if (str2[j - 1] == '*') 
//             dp[0][j] = dp[0][j - 1]; 

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++) {
//             if(str1[i-1]==str2[j-1] || str2[j-1] == '?'){
//                 dp[i][j]=dp[i-1][j-1];
//             }else if(str2[j-1] == '*'){
//                 dp[i][j] = dp[i][j-1] || dp[i-1][j];
//             }else{
//                 dp[i][j]=false;
//             }
//         }
//     }
//     return dp[n][m];
// }


// if subgrp is present in the string
bool regularexp(string str1,string str2) {
	int n=str1.size();
        int m=str2.size();
        bool dp[n+1][m+1];
        dp[0][0]=true;
        for(int i=1;i<=m;i++) dp[0][i] = false; 
        for(int i=1;i<=n;i++) dp[i][0] = false; 


        for (int j = 1; j <= m; j++) 
            if (str2[j - 1] == '*') 
                dp[0][j] = dp[0][j - 2]; 

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) {
                if(str1[i-1]==str2[j-1] || str2[j-1] == '.'){
                    dp[i][j]=dp[i-1][j-1];
                }else if(str2[j-1] == '*'){
                    // dp[i][j] = dp[i][j-1] || dp[i-1][j];
                    if (str1[i-1] == str2[j-2] || str2[j-2] == '.')
                        dp[i][j] = dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                    else
                        dp[i][j] = dp[i][j-2];
                }else{
                    dp[i][j]=false;
                }
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
	int t,n; cin>>t;
	while(t--){
		string str1,str2;
		cin>>str1>>str2;
		cout<<regularexp(str1,str2)<<endl;
	}
	return 0;
}