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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,a; cin>>t;
	while(t--){
		cin>>n;
		vec1 arr;
		rep(i,n) {
			cin>>a;
			arr.pb(a);
		}
		if(n == 1){
			cout<<"0"<<endl;
			continue;
		}
		map<ll,ll> vec;
		// cout<<"before put"<<endl;
		rep(i,n) vec[arr[i]]++; 
		ll singles=0;
		// cout<<"before single"<<endl;
		ll mx = INT_MIN;
		for(auto it=vec.begin();it!=vec.end();it++){
			// cout<<it->first<<" "<<it->second<<endl;
			singles++;
			if(mx<it->second) mx = it->second;
		}
		ll dup = mx;
		singles = singles-1;
		// cout<<singles<<" sd "<<dup<<endl;
		// cout<<"after single"<<endl;
		ll ans = min(singles,dup);
		if(abs(singles-dup) == 1 || (dup == singles)){
			cout<<ans<<endl;
		}else {
			if(dup>singles){
				cout<<ans+1<<endl;
			}else {
				cout<<ans<<endl;
			}
		}
		// arr.erase( unique( arr.begin(), arr.end() ), arr.end() );
		// ll fs = vec.size();
		// ll sz;
		// sz = n-fs;
		// if(sz == 0){
		// 	if(n>1) sz=1;
		// 	cout<<sz<<endl;
		// 	continue;
		// }
		// if(fs>=dup){
		// 	cout<<dup<<endl;
		// } 
	}
	return 0;
}