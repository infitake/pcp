#include <bits/stdc++.h>
using namespace std;

// Method 1:(simple iterative way)
string lcp(vector<string> str,int n){
	if(str.size() == 0) return "";
	string sstr;
	int l=INT_MAX;
	for(auto s:str){
		if(s.size()<l){
			l = s.size();
			sstr = s;
		}
	}

	string finalstr="";
	int i=0,flag=0;
	for(auto s:sstr){
		for(auto word:str) {
			if(s != word[i] && i<word.size()){
				flag = 1;
				break;
			}
		}
		if(flag) break;
		finalstr += s;
		i++;
	}

	return finalstr;
}

// Method 2:(using recursion)
string commonPrefixUtil(string str1, string str2) 
{ 
    string result; 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Compare str1 and str2 
    for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++) 
    { 
        if (str1[i] != str2[j]) 
            break; 
        result.push_back(str1[i]); 
    } 
  
    return (result); 
} 
  
// A Function that returns the longest common prefix 
// from the array of strings 
string commonPrefix (string arr[], int n) 
{ 
    string prefix =  arr[0]; 
  
    for (int i=1; i<=n-1; i++) 
        prefix = commonPrefixUtil(prefix, arr[i]); 
  
    return (prefix); 
} 

// Method 3:(using binary search)
int findMinLength(string arr[], int n) 
{ 
    int min = INT_MAX; 
  
    for (int i=0; i<=n-1; i++) 
        if (arr[i].length() < min) 
            min = arr[i].length(); 
    return(min); 
} 
  
bool allContainsPrefix(string arr[], int n, string str, 
                       int start, int end) 
{ 
    for (int i=0; i<=n-1; i++) 
        for (int j=start; j<=end; j++) 
            if (arr[i][j] != str[j]) 
                return (false); 
    return (true); 
} 
  
// A Function that returns the longest common prefix 
// from the array of strings 
string commonPrefix(string arr[], int n) 
{ 
    int index = findMinLength(arr, n); 
    string prefix; // Our resultant string 
  
    // We will do an in-place binary search on the 
    // first string of the array in the range 0 to 
    // index 
    int low = 0, high = index; 
  
    while (low <= high) 
    { 
        // Same as (low + high)/2, but avoids overflow 
        // for large low and high 
        int mid = low + (high - low) / 2; 
  
        if (allContainsPrefix (arr, n, arr[0], low, mid)) 
        { 
            // If all the strings in the input array contains 
            // this prefix then append this substring to 
            // our answer 
            prefix = prefix + arr[0].substr(low, mid-low+1); 
  
            // And then go for the right part 
            low = mid + 1; 
        } 
  
        else // Go for the left part 
            high = mid - 1; 
    } 
  
    return (prefix); 
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
		vector<string> str;
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			str.push_back(s);
		}
		cout<<lcp(str,n)<<endl;
	}
	return 0;
}