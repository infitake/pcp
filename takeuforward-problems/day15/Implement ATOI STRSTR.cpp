#include <bits/stdc++.h>
using namespace std;

int stringtoint(string str){
	int val=0,sign=1;
	for(auto s:str){
	    if(s == '-') {
	        sign = -1;
	        continue;
	    }
		int k = (s-'0');
		if(k>=0 && k<=9){
			val = val*10 + (s-'0');
		}else{
			return -1;
		}
	}
	return sign*val;
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
		cout<<stringtoint(str)<<endl;
	}
	return 0;
}