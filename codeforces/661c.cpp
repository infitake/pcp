#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define vec1 vector<ll>
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
		cin>>n;
		vec1 arr;
		rep(i,n){
			cin>>a;
			arr.pb(a);
		}
		sort(arr.begin(),arr.end());
		map<ll,ll> mp;
		map<ll,set<ll>> s;
		for(ll i=0;i<n;i++){
			for(ll j=i+1;j<n;j++){
				if(mp[arr[i]+arr[j]]==0){
					mp[arr[i]+arr[j]]++;
					s[arr[i]+arr[j]].insert(i);
					s[arr[i]+arr[j]].insert(j);
				}else{
					if(s[arr[i]+arr[j]].find(i)==s[arr[i]+arr[j]].end() && s[arr[i]+arr[j]].find(j) == s[arr[i]+arr[j]].end()){
						mp[arr[i]+arr[j]]++;
						s[arr[i]+arr[j]].insert(i);
						s[arr[i]+arr[j]].insert(j);
					}else
						continue;
				}
			}
		}
		ll maxval = 0;
		for(auto x:mp){
			maxval = max(maxval,x.second);
		}
		cout<<maxval<<endl;
	}
	return 0;
}