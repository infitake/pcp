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
	ll t,n,a;
		cin>>n;
		vec1 arr;
		ll sum=0;
		rep(i,n){
			cin>>a;
			sum += a;
			arr.pb(a);
		}
		// sort(arr.begin(),arr.end());
		ll diff = sum/(n/2);
		set<ll> s;
		map<ll,ll> mp;
		rep(i,n){
			if(mp[abs(diff-arr[i])]==0){
				mp[arr[i]]=i+1;
			}else {
				cout<<mp[abs(diff-arr[i])]<<" "<<i+1<<endl;
				mp[abs(diff-arr[i])]=0;
			
			}
		}
	
	return 0;
}
