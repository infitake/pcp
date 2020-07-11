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

// ll mcm(ll arr[],ll i,ll j){
// 	if( i== j) return 0;
// 	ll min=INT_MAX;
// 	ll count=0;
// 	for(ll k=i;k<j;k++){
// 		count = mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
// 		if(min>count) min = count;
// 	}
// 	return min;
// }

ll mcm(ll arr[],ll n){
	ll  dp[n][n];
	for(ll i=0;i<n;i++) dp[i][i]=0;
	ll minval;
	for(ll l=2;l<n;l++){
		for(ll i=1;i<n-l+1;i++){
			ll j= i+l-1;
			dp[i][j] = INT_MAX;
			for(ll k= i;k<=j-1;k++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
			}
		}
	}
	return dp[1][n-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		ll arr[n];
		rep(i,n) cin>>arr[i];
		cout<<mcm(arr,n)<<endl;
	}
	return 0;
}