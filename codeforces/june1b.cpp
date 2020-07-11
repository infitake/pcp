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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t; cin>>t;
	string str;
	while(t--){
		cin>>str;
		ll len = str.size();
		ll zero=0,one=0;
		for(ll i=0;i<len;i++){
			if(str[i] == '1') one++;
			else zero++;
		}
		ll ans = min(one,zero),zero_done=0,one_done=0;
		for(ll i=0;i<len;i++){
			if(str[i] == '1'){
				one_done++;
				one--;
			}else{
				zero_done++;
				zero--;
			}
			ans = min(ans,min(zero_done+one,one_done+zero));
		}
		cout<<ans<<endl;
		
	}
	return 0;
}