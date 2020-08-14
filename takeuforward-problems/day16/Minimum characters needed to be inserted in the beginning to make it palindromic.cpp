#include <bits/stdc++.h>
using namespace std;


// Method 1:(kmp method )
// But this method is not right 
// we have only check for the reference
void generatelps(string arr,int lps[],int n){
	int len =0;
	lps[0]=0;
	int i=1;
	while(i<n){
		if(arr[i] == arr[len]){
			len++;
			lps[i]=len;
			i++;
		}else{
			if(len !=0) len = lps[len-1];
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}


// int mininsertion(string str){
// 	string rstr = str;
// 	reverse(rstr.begin(),rstr.end());
// 	// cout<<rstr<<endl;
// 	string totalarr = str + "$" + rstr;
// 	int lps[totalarr.size()];
// 	generatelps(totalarr,lps,totalarr.size());

// 	return (str.size()-lps[totalarr.size()-1]);
// }

// Method 2 (using the recurrsion)
// int mininsertion(string str,int l,int r) {
// 	if(l>r) return INT_MAX;
// 	if(l == r) return 0;
// 	if(l == r-1) return (str[l]==str[r])? 0:1;

// 	if(str[l] == str[r]){
// 		return mininsertion(str,l+1,r-1);
// 	}
// 	return min(mininsertion(str,l,r-1),mininsertion(str,l+1,r))+1;
// }

// Method 3:(using dp)
// Dynamic Programming based Solution
// If we observe the above approach carefully, we can find that it exhibits overlapping subproblems.
// Suppose we want to find the minimum number of insertions in string “abcde”:

//                   abcde
//             /       |      \
//            /        |        \
//            bcde         abcd       bcd  <- case 3 is discarded as str[l] != str[h]
//        /   |   \       /   |   \
//       /    |    \     /    |    \
//      cde   bcd  cd   bcd abc bc
//    / | \  / | \ /|\ / | \
// de cd d cd bc c………………….
// The substrings in bold show that the recursion to be terminated and the recursion tree cannot originate from there. Substring in the same color indicates overlapping subproblems.

// How to re-use solutions of subproblems? Memoization technique is used to avoid similar subproblem recalls. We can create a table to store results of subproblems so that they can be used directly if same subproblem is encountered again.

// The below table represents the stored values for the string abcde.

// a b c d e
// ----------
// 0 1 2 3 4
// 0 0 1 2 3 
// 0 0 0 1 2 
// 0 0 0 0 1 
// 0 0 0 0 0
// How to fill the table?
// The table should be filled in diagonal fashion. For the string abcde, 0….4, the following should be order in which the table is filled:

// Gap = 1: (0, 1) (1, 2) (2, 3) (3, 4)

// Gap = 2: (0, 2) (1, 3) (2, 4)

// Gap = 3: (0, 3) (1, 4)

// Gap = 4: (0, 4)

int mininsertion(string str,int n){
	int dp[n][n];
	memset(dp,0,sizeof(dp));
	for(int gap=1;gap<n;gap++){
		for(int i=0,j=gap;j<n;i++,j++){
			if(str[i]==str[j]){
				dp[i][j]=dp[i+1][j-1];
			}else{
				dp[i][j] = min(dp[i][j-1],dp[i+1][j])+1;
			}
		}
	}
	return dp[0][n-1];
}
// Method 4 (using lcs)
int lcs( string X, string Y, int m, int n )  
{  
    int L[n+1][n+1];  
    int i, j;  
      
    /* Following steps build L[m+1][n+1] in bottom  
        up fashion. Note that L[i][j] contains length  
        of LCS of X[0..i-1] and Y[0..j-1] */
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
      
    /* L[m][n] contains length of LCS for X[0..n-1]  
        and Y[0..m-1] */
    return L[m][n];  
}  
  
void reverseStr(string& str)  
{  
    int n = str.length();  
  
    // Swap character starting from two  
    // corners  n
    for (int i = 0; i < n / 2; i++)  
        swap(str[i], str[n - i - 1]);  
}  
  
// LCS based function to find minimum number of  
// insertions  
int findMinInsertionsLCS(string str, int n)  
{  
    // Creata another string to store reverse of 'str'  
    string rev = "";  
    rev = str;  
    reverseStr(rev);  
      
    // The output is length of string minus length of lcs of  
    // str and it reverse  
    return (n - lcs(str, rev, n, n));  
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
		int n = str.size();
		// cout<<mininsertion(str)<<endl;
		// cout<<mininsertion(str,0,n-1)<<endl;
		cout<<mininsertion(str,n)<<endl;
	}
	return 0;
}