#include <bits/stdc++.h>
using namespace std;

// Method 1:
// Let us talk about the linear time solution now. This solution uses extra space to store the last indexes of already visited characters. 
// The idea is to scan the string from left to right, keep track of the maximum length Non-Repeating Character 
// Substring seen so far in res. When we traverse the string, to know the length of current window we need to indexes.
// 1) Ending index ( j ) : We consider current index as ending index.
// 2) Starting index ( i ) : It is same as previous window if current character was not present in the previous window. 
// To check if the current character was present in the previous window or not, we store last index of every character in an array lasIndex[].
// If lastIndex[str[j]] + 1 is more than previous start, then we updated the start index i. Else we keep same i.

int lrs(string arr,int n){
    int res = 0;
    vector<int> mp(256, -1); 
    int i = 0; 
    for (int j = 0; j < n; j++) { 
        i = max(i, mp[arr[j]] + 1); 
        res = max(res, j - i + 1); 
        mp[arr[j]] = j; 
    } 
    return res; 
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
	string arr;
	while(t--){
		cin>>arr;
		int n=arr.size();
		// vector<int> arr;
		// for(int i=0;i<n;i++){
		// 	cin>>a;
		// 	arr.push_back(a);
		// }
		cout<<lrs(arr,n)<<endl;
	}
	return 0;
}