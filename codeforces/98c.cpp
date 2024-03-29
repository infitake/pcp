#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define vec vector<ll>
#define pii pair<ll,ll>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,a; cin>>t;
	while(t--){
		string str;
		cin>>str;
		ll count=0;
		stack<char> s1,s2;
		for(auto x:str){
			if(x=='(') s1.push(x);
			else if(x=='[') s2.push(x);
			else if(x ==')'){
				if(!s1.empty()){ s1.pop();
				count++;
			}
			}else if(x == ']'){
				if(!s2.empty()) {s2.pop();
				count++;
			}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}