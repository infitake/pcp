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

// ll coinChange(ll arr[],ll n,ll sum){
// 	if(sum == 0) return 1;
// 	if(sum<0) return 0;
// 	if(n<=0&&sum>=1) return 0;

// 	return coinChange(arr,n,sum-arr[n-1])+coinChange(arr,n-1,sum);
// }
ll coinChange(ll arr[],ll n,ll sum){
	ll dp[sum+1][n];
	for(ll i=0;i<n;i++){
		dp[0][i]=1;
	}
	ll x,y;
	for(ll i=1;i<sum+1;i++){
		for(ll j=0;j<n;j++) {
			if(i-arr[j]>=0) x = dp[i-arr[j]][j];
			else x = 0;
			if(j>=1) y=dp[i][j-1];
			else y=0;
			dp[i][j]=x+y;
		}
	}
	return dp[sum][n-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,m; cin>>t;
	while(t--){
		cin>>n;
		ll arr[n];
		rep(i,n) cin>>arr[i];
		cin>>m;
		cout<<coinChange(arr,n,m)<<endl;
		
	}
	return 0;
}