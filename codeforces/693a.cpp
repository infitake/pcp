#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define vec1 vector<ll>
#define pii pair<ll,ll>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep1(i,b) for(ll i=1;i<=b;i++)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((ll)(x).size())
#define F first
#define S second
#define endll "\n"

ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,a,w,h; cin>>t;
	while(t--){
		cin>>w>>h>>n;
		if(n==1) {
			cout<<"YES"<<endl;
			continue;
		}
		if(w&1 && h&1) {
			cout<<"NO"<<endl;
			continue;
		}else{
			ll count = 1;
			while(h%2==0 || w%2==0){
				if(h%2==0 && w%2==0){
					if(h>w) h = h/2;
					else w = w/2;
				}else if(h%2==0){
					h = h/2;
				}else if(w%2==0){
					w = w/2;
				}
				count *= 2;
			}
			// cout<<"count :"<<count<<endl;
			if(count>=n) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
