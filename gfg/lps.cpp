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

// ll lps(string str,ll l,ll r){
// 	if(l == r) return 1;
// 	if(str[l] == str[r] && l+1==r) return 2;
// 	if(str[l] == str[r]) return 2+lps(str,l+1,r-1);
// 	return max(lps(str,l+1,r),lps(str,l,r-1));
// }

ll lps(string str){
	ll n = str.size();
	ll dp[n][n];

	for(ll i=0;i<n;i++) dp[i][i]=1;

	for(ll k=2;k<=n;k++){
		for(ll i=0;i<n-k+1;i++){
			ll j=i+k-1;
			if(str[i] == str[j] && k == 2) dp[i][j] = 2;
			if(str[i] == str[j]) dp[i][j] = dp[i+1][j-1]+2;
			else dp[i][j]= max(dp[i+1][j],dp[i][j-1]);
		}
	}
	return dp[0][n-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	string str;
	while(t--){
		cin>>str;
		cout<<lps(str)<<endl;
		
	}
	return 0;
}