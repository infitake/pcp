#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 10000
#define NP 100001
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

ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}

void sieve(vector<int> &fib)
{
  	fib[0] = 0;
   	fib[1] = 1;
 
    for(int i = 2; i <= 10000000; i++)
    {
       fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> fib(10000002);
	sieve(fib);
	//ios_base& scientific (ios_base& str);
	int t,d,n; cin>>t;
	while(t--){
		cin>> n;
		if(n==0 || n==1) cout<<"YES"<<endl;
		else {
			if(find(fib.begin(),fib.end(),n) != fib.end()) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		// cout<<endl;
	}
	return 0;
}
// don't settle on same approach
// check for base cases n=0