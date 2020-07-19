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

bool isprime(ll n){
	for(ll i=3;i<=sqrt(n);i+=2) if (n%i==0) return false;
	return true;
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
		if(n&1){
			if(isprime(n)) cout<<"1"<<" "<<n-1<<endl;
			else{
				for(ll i=3;i<=sqrt(n);i+=2){
					if(n%i==0) {
						ll k=n/i;
						cout<<k<<" "<<n-k<<endl;
						break;
					}
				}
		}
		}else{
			cout<<n/2<<" "<<n/2<<endl;
		}
		
	}
	return 0;
}