#include <bits/stdc++.h>
using namespace std;

// Method 1: backtraking
void permutation(string &str,int n,int k){
	if(k==n-1) {
		cout<<str<<endl;
		return;
	}
	if(k>=n) return;

	for(int i=k;i<n;i++){
		swap(str[i],str[k]);
		permutation(str,n,k+1);
		// This one for backtracking
		swap(str[i],str[k]);
	}
}
// Time Complexity: O(n*n!) Note that there are n! permutations and 
// it requires O(n) time to print a a permutation.

// Method 2:(using and extra string and rotate function)
void permute(string str, string out) 
{ 
    // When size of str becomes 0, out has a 
    // permutation (length of out is n) 
    if (str.size() == 0) 
    { 
        cout << out << endl; 
        return; 
    } 
  
    // One be one move all characters at 
    // the beginning of out (or result) 
    for (int i = 0; i < str.size(); i++) 
    { 
        // Remove first character from str and 
        // add it to out 
        permute(str.substr(1), out + str[0]); 
  
        // Rotate string in a way second character 
        // moves to the beginning. 
        rotate(str.begin(), str.begin() + 1, str.end()); 
    } 
} 

// Method 3: (using stl function)
void permutation(string str){
	sort(str.begin(),str.end());
	cout<<str<<endl;
	while(next_permutation(str.begin(),str.end())) cout<<str<<endl;
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
		cin>>n;
		cin>>str;
		permutation(str,n,0);
	}
	return 0;
}