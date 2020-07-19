#include <bits/stdc++.h>
using namespace std;

// Method 1:*using stl)
// string reversestring(string str){ 
// 	reverse(str.begin(),str.end());
// 	return str;
// }
// Method 2:*swaping the first and last
// string reversestring(string str){																																																								
// 	int n = str.size();
// 	int l = 0,r=n-1;
// 	while(l<r){
// 		swap(str[l++],str[r--]);
// 	}
// 	return str;
// }
// Method 3:
void reversestring(string &str){
	int start=0;
	for(int end=0;end<str.size();end++){
		if(str[end] == ' '){
			reverse(str.begin()+start,str.begin()+end);
			start = end+1;
		}
	}
	reverse(str.begin()+start,str.end());
	reverse(str.begin(),str.end());

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
		// cin>>str;
		// getline(cin,str);
		str="you like this program very much";
		reversestring(str);
		cout<<str<<endl;
	}
	return 0;
}