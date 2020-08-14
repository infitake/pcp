#include <bits/stdc++.h>
using namespace std;

int scs(string str1,string str2,int x,int y) {
	if(x==0) return y;
	if(y==0) return x;
	if(str1[x-1]==str2[y-1]) return 1+scs(str1,str2,x-1,y-1);
	return 1+min(scs(str1,str2,x-1,y),scs(str1,str2,x,y-1));
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
		int n = str1.size();
		int m = str2.size();
		cout<<scs(str1,str2,n,m)<<endl;
		
	}
	return 0;
}