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
#define P(x) printf("%d\n",(x))
#define FT first
#define SN second
#define mod %

bool finalmod(vec1 arr){
	ll n = arr.size();
	for(ll i=0;i<n;i++){ if(arr[i]!=0) return true; }
	return false;
}

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
		vec1 arr;
		rep(i,n){cin>>a; arr.pb((a));}
		map<ll,ll> m;
		ll max=INT_MIN;
		for(auto x:arr){
			if(x%k == 0)continue;
			m[k-(x mod k)]++;
			if(max<m[k-(x mod k)]) max = m[k-(x mod k)] ;
		}
		ll ans=0;
		for(auto x:m){
			if(x.second == max){
				ans = k*(x.second -1)+x.first+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}