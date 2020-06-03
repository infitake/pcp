/******************************************
* AUTHOR : RAVINDER YADAV *
* NICK : INFINITY *
* INSTITUTION : NIT KURUKSHETRA *
******************************************/
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
	ll t,n,x; cin>>t;
	while(t--){
		cin>>n>>x;
		ll arr[n];
		ll is_odd = 0,is_even = 0;
		rep(i,n){
			cin>>arr[i];
			if(arr[i]%2==0) is_even++;
			else is_odd++;
		}

		if(x%2==1){
			if(is_odd%2 == 1) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		} else{
			if((is_odd%2 == 1) && (is_even%2 == 1)) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		
	}
	return 0;
}