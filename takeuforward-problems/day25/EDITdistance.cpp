#include <bits/stdc++.h>
using namespace std;


int editdistance(string str1,string str2,int n,int m){
	if(n==0) return m;
	if(m==0) return n;
	if(str1[n-1]==str2[m-1]) return editdistance(str1,str2,n-1,m-1);
	return 1+min(min(editdistance(str1,str2,n-1,m),editdistance(str1,str2,n,m-1)),editdistance(str1,str2,n-1,m-1));
}
int editdistance(string str1,string str2,int n,int m){
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0) dp[i][j]=j;
			else if(j==0) dp[i][j]=i;
			else if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
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
		cout<<editdistance(str1,str2,n,m)<<endl;
	}
	return 0;
}

// In the above-given method we require O(m x n) space. 
// This will not be suitable if the length of strings is greater than 2000 as it can only create 2D array of 2000 x 2000. 
// o fill a row in DP array we require only one row the upper row. 
// For example, if we are filling the i = 10 rows in DP array we require only values of 9th row. 
// So we simply create a DP array of 2 x str1 length. This approach reduces the space complexity. 
// Here is the C++ implementation of the above-mentioned problem.

// A Space efficient Dynamic Programming 
// based C++ program to find minimum 
// number operations to convert str1 to str2 
#include <bits/stdc++.h> 
using namespace std; 

void EditDistDP(string str1, string str2) 
{ 
	int len1 = str1.length(); 
	int len2 = str2.length(); 

	// Create a DP array to memoize result 
	// of previous computations 
	int DP[2][len1 + 1]; 

	// To fill the DP array with 0 
	memset(DP, 0, sizeof DP); 

	// Base condition when second string 
	// is empty then we remove all characters 
	for (int i = 0; i <= len1; i++) 
		DP[0][i] = i; 

	// Start filling the DP 
	// This loop run for every 
	// character in second string 
	for (int i = 1; i <= len2; i++) { 
		// This loop compares the char from 
		// second string with first string 
		// characters 
		for (int j = 0; j <= len1; j++) { 
			// if first string is empty then 
			// we have to perform add character 
			// operation to get second string 
			if (j == 0) 
				DP[i % 2][j] = i; 

			// if character from both string 
			// is same then we do not perform any 
			// operation . here i % 2 is for bound 
			// the row number. 
			else if (str1[j - 1] == str2[i - 1]) { 
				DP[i % 2][j] = DP[(i - 1) % 2][j - 1]; 
			} 

			// if character from both string is 
			// not same then we take the minimum 
			// from three specified operation 
			else { 
				DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j], 
									min(DP[i % 2][j - 1], 
										DP[(i - 1) % 2][j - 1])); 
			} 
		} 
	} 

	// after complete fill the DP array 
	// if the len2 is even then we end 
	// up in the 0th row else we end up 
	// in the 1th row so we take len2 % 2 
	// to get row 
	cout << DP[len2 % 2][len1] << endl; 
} 

// Driver program 
int main() 
{ 
	string str1 = "food"; 
	string str2 = "money"; 
	EditDistDP(str1, str2); 
	return 0; 
} 
