#include <bits/stdc++.h>
using namespace std;

bool dictionaryContain(string word) {
	string dictionary[] = {"mobile","samsung","sam","sung", 
                            "man","mango","icecream","and", 
                             "go","i","like","ice","cream"}; 
    int size = sizeof(dictionary)/sizeof(dictionary[0]); 

    for(int i=0;i<size;i++){
    	if(dictionary[i].compare(word) == 0)
    		return true;
    }
    return false;
}

// bool wordbreak(string str){
// 	int n = str.size();
// 	if(n==0) return true;

// 	for(int i=1;i<=n;i++){
// 		if(dictionaryContain(str.substr(0,i)) && wordbreak(str.substr(i,n-i)))
// 			return true;
// 	}
// 	return false;
// }

bool wordbreak(string str){
	int n = str.size();
	if(n==0) return true;

	bool dp[n+1];
	memset(dp,false,sizeof(dp));

	for(int i=1;i<=n;i++){

		if(dp[i]==false && dictionaryContain(str.substr(0,i)))
			dp[i]=true;

		if(dp[i] == true){
			if(i==n) return true;

			for(int j=i+1;j<=n;j++){

				if(dp[j]==false && dictionaryContain(str.substr(i,j-i)))
					dp[j]=true;

				if(dp[j]==true && j==n) return true;
			}
		}
	}
	return false;
}

bool wordBreak(string s) 
{ 
    int n = s.size(); 
    if (n == 0) 
        return true; 
  
    // Create the DP table to store results of subroblems. 
    // The value dp[i] will be true if str[0..i] can be 
    // segmented into dictionary words, otherwise false. 
    vector<bool> dp(n + 1, 0); // Initialize all values 
    // as false. 
  
    // matched_index array represents the indexes for which 
    // dp[i] is true. Initially only -1 element is present 
    // in this array. 
    vector<int> matched_index; 
    matched_index.push_back(-1); 
  
    for (int i = 0; i < n; i++) { 
        int msize = matched_index.size(); 
  
        // Flag value which tells that a substring matches 
        // with given words or not. 
        int f = 0; 
  
        // Check all the substring from the indexes matched 
        // earlier. If any of that substring matches than 
        // make flag value = 1; 
        for (int j = msize - 1; j >= 0; j--) { 
  
            // sb is substring starting from matched_index[j] 
            // + 1  and of length i - matched_index[j] 
            string sb = s.substr(matched_index[j] + 1, i - matched_index[j]); 
  
            if (dictionaryContains(sb)) { 
                f = 1; 
                break; 
            } 
        } 
  
        // If substring matches than do dp[i] = 1 and 
        // push that index in matched_index array. 
        if (f == 1) { 
            dp[i] = 1; 
            matched_index.push_back(i); 
        } 
    } 
    return dp[n - 1]; 
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
		cout<<wordbreak(str)<<endl;
		
	}
	return 0;
}