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
ll max(ll a, ll b)  
{  
    return (a > b)? a : b;  
} 

ll lcs(char *s1,char *s2,ll x,ll y){
	ll dp[x+1][y+1];

	for(ll i=0;i<=x;i++){
		for(ll j=0;j<=y;j++){
			if(i == 0 || j==0) dp[i][j]=0;
			if(s1[i-1] == s2[j-1])
				dp[i][j] = 1+dp[i-1][j-1];
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	for(ll i=0;i<=x;i++){
		for(ll j=0;j<=y;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[x-1][y-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,m; cin>>t;
	while(t--){
		cin>>n>>m;
		char s1[n],s2[m];
		rep(i,n) cin>>s1[i];
		rep(i,m) cin>>s2[i];
		cin>>s1;
		cin>>s2;
		ll l1 = strlen(s1);
		ll l2 = strlen(s2);
		cout<<lcs(s1,s2,l1,l2)<<endl;
	}
	return 0;
}