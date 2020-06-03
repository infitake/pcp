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

vector<bool> simpleSieve(int n){
	std::vector<bool> is_prime(n+1,true);
	is_prime[0]=false;
	is_prime[1]=false;
	for(int  i=2;i<=sqrt(n);i++){
		if(is_prime[i]){
			for(int j=i*i;j<n;j+=i){
				is_prime[j]=false;
			}
		}
	}
	// for(int i=0;i<n;i++){
	// 	cout<<i<<" "<<is_prime[i]<<" "<<endl;
	// }
	return is_prime;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; 
	cin>>n;
	std::vector<bool> v;
	v = simpleSieve(n);
	
	for(int i=0;i<n;i++){
		cout<<i<<" "<<v[i]<<" "<<endl;
	}
	cout<<endl;
	return 0;
}