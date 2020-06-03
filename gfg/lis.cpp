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

ll lis(ll arr[],ll n){
	ll dp[n];
	rep(i,n) dp[i]=0;
	dp[0]=1;
	ll res = 0;
	for(ll i=1;i<n;i++){
		dp[i]=1;
		for(ll j = 0 ;j<i;j++){
			if(arr[j]<arr[i] && dp[j]+1>dp[i]){
				dp[i]=dp[j]+1;
			}
		}
	}
	// rep(i,n) cout<<dp[i]<<" ";
	sort(dp,dp+n);
	return dp[n-1];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>n;
	ll arr[n];
	rep(i,n) cin>>arr[i];
	cout<<lis(arr,n)<<endl;
	return 0;
}