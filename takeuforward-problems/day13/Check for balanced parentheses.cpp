#include <bits/stdc++.h>
using namespace std;

bool validparenthese(string str){
	stack<char> stk;
	for(auto s:str){
		if(s == '(') stk.push(s);
		else{
			if(stk.empty()) return false;
			stk.pop();
		}
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
		string str;
		cin>>str;
		cout<<validparenthese(str)<<endl;
	}
	return 0;
}