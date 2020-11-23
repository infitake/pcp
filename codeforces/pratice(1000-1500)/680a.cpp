#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 10000001
#define MOD 1000000007
#define dd double
#define vec1 vector<ll>
#define pii pair<ll,ll>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b); 
}
void sieve(vector<ll> &arr) 
{ 
	vector<char> is_prime(N, true);
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i * i <= N; i++) {
	    if (is_prime[i]) {
	    	arr.pb(i);
	        for (ll j = i * i; j <= N; j += i)
	            is_prime[j] = false;
	    }
	}
} 
int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	vec1 prime;
	sieve(prime);
	ll t,n,p,q; cin>>t;
	while(t--){
		cin>>p>>q;
		if(p<q) cout<<p<<endl;
		if(p>q){
			if(gcd(p,q)==1) cout<<p<<endl;
			else if(p%q!=0) cout<<p<<endl;
			else if(p%q==0){
				ll maxval = INT_MAX;
				for(auto x:prime){
					if(x<=q && q%x==0){
						maxval = min(maxval,p/x);
					}
				}
				cout<<maxval<<endl;
			}
		}
	}
	return 0;
}