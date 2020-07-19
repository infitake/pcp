#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<char,ll> roman={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	string s;
	while(t--){
		cin>>s;
		n=s.length();
		ll sum=0;
		ll i;
		for(i=0;i<n-1;i++){
			if(roman[s[i]]<roman[s[i+1]]){
				sum += roman[s[i+1]]-roman[s[i]];
				i++;
			}else{
				sum += roman[s[i]];
			}
		}
		if(i==n-1) sum += roman[s[i]];
		cout<<sum<<endl;
	}
	return 0;
}