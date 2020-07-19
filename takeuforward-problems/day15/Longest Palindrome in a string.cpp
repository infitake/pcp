#include <bits/stdc++.h>
using namespace std;

void pallidrone(string str,int n) {
	int maxlen=1;
	int start=0;
	int l,r;
	for(int i=1;i<n;i++){
		//This is for  even length
		l=i-1;
		r=i;
		while(l>=0 && r<n && str[l]==str[r]) {
			if(r-l+1>maxlen){
				start = l;
				maxlen=(r-l+1);
			}
			l--;r++;
		}
		// This is for odd length
		l=i-1;
		r=i+1;
		while(l>=0 && r<n && str[l]==str[r]){
			if((r-l+1)>maxlen){
				start = l;
				maxlen = (r-l+1);
			}
			l--;r++;
		}
	}
	// cout<<start<<endl;
	for(int i=start;i<=start+maxlen-1;i++){
		cout<<str[i];
	}
	cout<<endl;
}

// Complexity Analysis:

// Time complexity: O(n^2), where n is the length of input string.
// Nested traversal of the string is needed. So time complexity is O(n^2).
// Auxiliary Space: O(1).
// No extra space is needed.

//Method 2:(using dp)

void pallidrone(string str,int n){
	bool dp[n][n];
	memset(dp,0,sizeof(dp));
	// this is for single char
	for(int i=0;i<n;i++) dp[i][i] = true;

	int maxlen = 1;
	int start=0;
	// this is for only 2 char
	for(int i=0;i<n;i++) {
		if(str[i]==str[i+1]) {
			start=i;
			dp[i][i+1] = true;
			maxlen = 2;
		}
	}
	// HERE L stand for the lenght of the string 
	for(int l=3;l<=n;l++) {
		for(int i=0;i<n-l+1;i++){
			int j=i+l-1;
			if(dp[i+1][j-1] && str[i]==str[j]){
				dp[i][j]=true;
				if(l>maxlen){
					start = i;
					maxlen = l;
				}
			}
		}
	}
	for(int i=start;i<=start+maxlen-1;i++){
		cout<<str[i];
	}
	cout<<endl;
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
	string str;
	while(t--){
		cin>>str;
		int n = str.size();
		pallidrone(str,n);
	}
	return 0;
}