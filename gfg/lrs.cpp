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

// ll lrs(string str1,string str2,ll n,ll m){
// 	if(n==0 || m==0) return 0;
// 	if(str1[n-1] == str2[m-1]) return 1+lrs(str1,str2,n-1,m-1);
// 	else return max(lrs(str1,str2,n-1,m),lrs(str1,str2,n,m-1));
// }
ll lrs(string str1,ll n){
	ll dp[n+1][n+1];
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=n;j++){
			if(i==0 || j==0) dp[i][j]=0;
			else if(str1[i-1]==str1[j-1] && i!=j) dp[i][j] =1+dp[i-1][j-1];
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n][n];
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
		string str1,str2;
		cin>>str1;
		str2=str1;
		reverse(str2.begin(),str2.end());
		// cout<<str1<<" "<<str2;
		ll val = lrs(str1,n);
		cout<<val<<endl;
	}
	return 0;
}