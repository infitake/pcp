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

ll specialexchange(vec1 &arr,ll n){
	ll a=min(arr,n);
	ll b=secondmin(arr,n,a);
	ll c=max(arr,n);
	ll ap = b-a;

	ll l=0,r=n-1,s1,s2;
	if(arr[0]!=a) s1=0;
	else for(ll i=1;i<n;i++) if((arr[i]-arr[i-1])!=ap) s1=i;
	if(arr[n-1]!=c) s2=n-1;
	else for(ll i=n-2;i>=0;i--) if((arr[i]-arr[i+1])!=ap) s2=i;
	
}

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
		cout<<specialexchange(arr,n)<<endl;
	}
	return 0;
}