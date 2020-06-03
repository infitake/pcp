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
	ll t,n,a,b; cin>>t;
	while(t--){
		cin>>n>>a>>b;
		ll same = a-b;
		string str;
		char first = 'a';
		for(ll i=1;i<=n;i++){
			if((i-1) != 0 && (i-1)%26 == 0) first = 'a';
			// if(str.size() == n) break;
			// cout<<"value of i"<<i<<endl;
			if(i == b){
				// cout<<"inside i == b"<<endl;
				if(same != 0){
					ll val = same;
				while(same>0){
					// cout<<"same value "<<endl;
					str += first;
					same--;
				}
				i += val-1;
				first='a';
				continue;
			}
			}
			str += first;
			first = first+1;
		}
		cout<<str<<endl;
	}
	return 0;
}