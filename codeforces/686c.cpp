#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define vec1 vector<ll>
#define pii pair<ll,ll>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep1(i,b) for(ll i=1;i<=b;i++)
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
		vec1 vec;
		map<long long, vector<long long> > myMap;
		for(ll i=0;i<n;i++){
			myMap[arr[i]].push_back(i);
		}
		ll minval = INT_MAX,count=0,a=0,b=n-1;
		for(auto v : myMap){
			vec = v.second;
			count=0;
			ll k = vec.size();
			count += ((vec[0] - a)==0)?0:1;
			for(ll i=1;i<k;i++){
				if((vec[i]-vec[i-1]) > 1) count++;
			}
			count += (b-(vec[k-1])==0)?0:1;
			minval = min(minval,count);
		}
		cout<<minval<<endl;
	}
	return 0;
}