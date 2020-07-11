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
#define P(x) prllf("%d\n",(x))
#define FT first
#define SN second

ll solve(ll b,ll a){
	ll ans=0;
	while(a > b) {
    if(8*b <= a) {
       b = b*8; ans++; 
    }
    else if(4*b <= a) {
        b = b*4; ans++;
    }
    else if(2*b <= a) {
        b = b*2; ans++;
    }
    else break;
    }
    if(a ==b) return ans;
	return -1;
}
// 8863319836238788 283626234759641216
ll findOperation(ll a,ll b){
	if(a == b) return 0;
	if(a<b) return solve(a,b);
	else return solve(b,a);
}

ll main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,a,b; cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<findOperation(a,b)<<endl;
	}
	return 0;
}