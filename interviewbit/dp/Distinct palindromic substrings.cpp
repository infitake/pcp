#include <bits/stdc++.h>
using namespace std;

// Initial Values : i = 0, j = n-1;
// Given string 'str'

// CountPS(i, j)
   
//    // If length of string is 2 then we 
//    // check both character are same or not 
//    If (j == i+1)
//       return str[i] == str[j]

//    Else If str[i..j] is PALINDROME 
//       // increment count by 1 and check for 
//       // rest palindromic substring (i, j-1), (i+1, j)
//       // remove common palindrome substring (i+1, j-1)
//       return  countPS(i+1, j) + countPS(i, j-1) + 1 -
//                                    countPS(i+1, j-1);

//     Else // if NOT PALINDROME 
//        // We check for rest palindromic substrings (i, j-1)
//        // and (i+1, j)
//        // remove common palindrome substring (i+1 , j-1)
//        return  countPS(i+1, j) + countPS(i, j-1) - 
//                              countPS(i+1 , j-1);


// Method 1:
// int distinctPallidrome(string str) {
//     int n = str.size();
//     int dp[n][n];
//     memset(dp,0,sizeof(dp));
//     bool palidrome[n][n];
//     memset(palidrome,false,sizeof(palidrome));

//     // check for the singal value
//     for(int i=0;i<n;i++) palidrome[i][i]=true;

//     // check for the double value
//     for(int i=0;i<n-1;i++){
//         if(str[i]==str[i+1]){
//             dp[i][i+1]=1;
//             palidrome[i][i+1]=true;
//         }
//     }

//     // check for the other values
//     // same as the mcm problem

//     for(int gap=2;gap<n;gap++){
//         for(int i=0;i<n-gap;i++) {
//             int j = i+gap;

//             if(str[i]==str[j] && palidrome[i+1][j-1]) palidrome[i][j]=true;

//             if(palidrome[i][j]){
//                 dp[i][j] = 1+dp[i+1][j]+dp[i][j-1] - dp[i+1][j-1];
//             }else{
//                 dp[i][j] = dp[i+1][j]+dp[i][j-1] - dp[i+1][j-1];
//             }

//         }
//     }
//     return dp[0][n-1];
// }

// Method 2:
int countdistant(string str) {
    set<char> s;
    int n = str.size();
    for(int i=0;i<n;i++) s.insert(str[i]);
    return s.size();
}

int distinctPallidrome(string s) 
{ 
    unordered_map<string, int> m; 
    for (int i = 0; i < s.length(); i++) { 

        // check for odd length palindromes 
        for (int j = 0; j <= i; j++) { 

            if (!s[i + j]) 
                break; 

            if (s[i - j] == s[i + j]) { 

                // check for palindromes of length 
                // greater than 1 
                if ((i + j + 1) - (i - j) > 1) 
                    m[s.substr(i - j, 
                        (i + j + 1) - (i - j))]++; 

            } else
                break; 
        } 

        // check for even length palindromes 
        for (int j = 0; j <= i; j++) { 
            if (!s[i + j + 1]) 
                break; 
            if (s[i - j] == s[i + j + 1]) { 

                // check for palindromes of length 
                // greater than 1 
                if ((i + j + 2) - (i - j) > 1) 
                    m[s.substr(i - j, 
                        (i + j + 2) - (i - j))]++; 

            } else
                break; 
        } 
    } 
    int k = countdistant(s);
    int ft = k+m.size();
    return ft; 
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
		cout<<distinctPallidrome(str)<<endl;
	}
	return 0;
}