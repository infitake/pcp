#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define pii pair<ll,ll>
#define vec1 vector<ll>
#define vec2 vector<ll,ll>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep1(i,b) for(ll i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((ll)(x).size())
#define S(x) scanf("%d",&(x))
#define S2(x,y) scanf("%d%d",&(x),&(y))
#define SL(x) scanf("%lld",&(x))
#define SL2(x) scanf("%lld%lld",&(x),&(y))
#define P(x) prllf("%d\n",(x))
#define FT first
#define SN second

ll main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		ll arr[n];
		rep(i,n) cin>>arr[i];
		set<ll> s;
		rep(i,n) s.insert(arr[i]);
		ll flag = 0,tap;
		ll last = 1024;
		rep(i,last) {
			ll ans=0;
			rep(j,n){
			ll val = (i+1) ^ arr[j];
			if(s.find(val)!=s.end()) ans++;
			if(ans == n) {
				flag = 1;
				tap=i+1;
				cout<<(i+1)<<endl;
				break;
			}
		}
		if(flag) break;
		}
		if(flag == 0) cout<<"-1"<<endl;

		
	}
	return 0;
}