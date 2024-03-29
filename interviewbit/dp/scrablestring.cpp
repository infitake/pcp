#include <bits/stdc++.h>
using namespace std;

bool scrablestring(string str1,string str2){
	// case 1:if size is different;
	if(str1.size() != str2.size()) return false;

	int n = str1.size();

	// case 2:if(size is 0)

	if(n == 0) return true;

	// case 3:if string are equal

	if(str1 == str2) return true;

	// case 4:(check for anagram) if differnt charter in both array return false;

	string c1=str1,c2=str2;
	sort(c1.begin(),c1.end());
	sort(c2.begin(),c2.end());

	if(c1!=c2) return false;

	for(int i=1;i<n;i++){
		// cout<<"kl";
	// 	If S2 is a scrambled form of S1, then there must exist an index i such that at least one of the following conditions is true:
	// S2[0...i] is a scrambled string of S1[0...i] and S2[i+1...n] is a scrambled string of S1[i+1...n].
	// S2[0...i] is a scrambled string of S1[n-i...n] and S2[i+1...n] is a scrambled string of S1[0...n-i-1].

		if(scrablestring(str1.substr(0,i),str2.substr(0,i)) 
			&& scrablestring(str1.substr(i,n-i),str2.substr(i,n-i)))
			return true;

		if(scrablestring(str1.substr(0,i),str2.substr(n-i,i)) 
			&& scrablestring(str1.substr(i,n-i),str2.substr(0,n-i)))
			return true;		

	}

	return false;
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
		cout<<scrablestring(str1,str2)<<endl;
	}
	return 0;
}