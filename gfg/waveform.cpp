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

void wave(ll arr[],ll n){
	sort(arr,arr+n);
	ll arr1[n];
	for(ll i=0;i<n;i++) arr1[i]=0;
	ll count = n-1;
	for(ll i=0;i<n;i += 2){
		arr1[i]=arr[count--];
	}
	for(ll i = 1;i<n;i += 2){
		arr1[i]=arr[count--];
	}
	rep(i,n) cout<<arr1[i]<<" ";
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>n;
	ll arr[n];
	rep(i,n) cin>>arr[i];

	wave(arr,n);

	return 0;
}