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
bool comp(ll a,ll b){
	return a>b;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		ll arr[n];
		rep(i,n) cin>>arr[i];
		sort(arr,arr+n);
		if(arr[n-1]==arr[n-2]){
			cout<<"NO"<<endl;
			continue;
		}
		map<ll,ll> mp;
		rep(i,n){
			mp[arr[i]]++;
		}
		ll count=0,flag=0;
		// vector<pair<ll,ll>> vec;
		for(auto x=mp.begin();x!=mp.end();x++){
			// vec.pb({x->first,x->second});
			if(x->second == 1) count++;
			// if(x->second == 2) count++;
			if((x->second)>2){
				cout<<"NO"<<endl;
				flag=1;
				break;
			}
		}
		if(flag) continue;
		vec1 test;
		if(count == n){
			cout<<"YES"<<endl;
			rep(i,n) cout<<arr[i]<<" ";
		}else{
			cout<<"YES"<<endl;
			cout<<arr[0]<<" ";
			for(ll i=1;i<n;i++){
				if(arr[i-1]!=arr[i]){
					cout<<arr[i]<<" ";
				}else{
					test.pb(arr[i]);
				}
			}
		}
		sort(test.begin(),test.end(),comp);
		for(auto x:test){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}