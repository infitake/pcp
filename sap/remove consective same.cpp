#include <bits/stdc++.h>
using namespace std;

void rmSame(string str,int k) {
	int n = str.size();
	stack<pair<char,int>> sp;
	for(auto s:str) {
		int count=1;
		int eq = k;
		if(sp.empty()) sp.push({s,count});
		else{
			pair<char,int> ac = sp.top();
			if(s == ac.first){
				if(ac.second+1 == eq){
					eq--;
					while(!sp.empty() && eq--){
						sp.pop();
					}
				}else{
					sp.push({s,ac.second+1});
				}
			}else{
				sp.push({s,count});
			}
		}
	}
	str="";
	while(!sp.empty()){
		pair<char,int> ac = sp.top();sp.pop();
		str += ac.first;
	}
	reverse(str.begin(),str.end());
	cout<<str<<endl;

}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,k; cin>>t;
	string str;
	while(t--){
		cin>>str>>k;
		rmSame(str,k);
	}
	return 0;
}