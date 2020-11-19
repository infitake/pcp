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
	ll t,n,k,a; cin>>t;
	while(t--){
		cin>>n>>k;
		string str;
		cin>>str;
		set<ll> posof1;
		ll ans =0;
		rep(i,n){
			if(str[i]=='1') posof1.insert(i);
		}
		rep(i,n){
			if(str[i]=='0'){
				auto it = posof1.lower_bound(i-k);
				if(it == posof1.end() || *it > i+k){
					str[i]='1';
					ans++;
					posof1.insert(i);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}