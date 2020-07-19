#include <bits/stdc++.h>
using namespace std;

// An anagram of a string is another string that contains same characters, 
// only the order of characters can be different. 
// For example, “abcd” and “dabc” are anagram of each other.

// Method 1:(using sorting)
// bool checkanagram(string str1,string str2){
// 	if(str1.size() != str2.size()) return false;
// 	sort(str1.begin(),str1.end());
// 	sort(str2.begin(),str2.end());
// 	for(int i=0;i<str1.size();i++){
// 		if(str1[i]!=str2[i]) return false;
// 	}
// 	return true;
// }

// Method 2:(using map)
// This contain extra space
bool checkanagram(string str1,string str2){
	if(str1.size() != str2.size()) return false;
	map<char,int> mp;
	for(auto s:str1) mp[s]++;
	for(auto s:str2) mp[s]--;
	for(auto x:mp){
		if(x.second) return false; 
	}
	return true;
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
		cout<<checkanagram(str1,str2)<<endl;
	}
	return 0;
}