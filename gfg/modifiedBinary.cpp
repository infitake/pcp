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

ll bs(ll arr[],ll l,ll r,ll key){
	while(l<r){
		ll mid = l+(r-l)/2;
		if(arr[mid] == key) return mid;
		if(arr[mid-1] == key) return mid-1;
		if(arr[mid+1] == key) return mid+1;

		if(arr[mid-1]<key&&arr[mid]<key&&arr[mid+1]<key) l = mid+1;
		else r = mid -1;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,x; cin>>n>>x;
	ll arr[n];
	rep(i,n) cin>>arr[i];
	cout<<bs(arr,0,n-1,x);

	return 0;
}