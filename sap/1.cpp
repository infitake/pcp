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


void print(vec1 &ele,vec1 &ind,ll n){
	// map<ll,stack<ll>> mp;

	// rep(i,n) {
	// 	mp[ind[i]].push(ele[i]);
	// }

	for(ll i=0;i<n;i++){
		for(ll j=i;j>ind[i];j--){
			swap(ele[j],ele[j-1]);
		}
	}

	// rep(i,n) {
	// 	ele[i]=mp[ind[i]].top();mp[ind[i]].pop();
	// 	// if(!mp[ind[i]].empty())
	// }

	for(auto x:ele) cout<<x<<" ";
	cout<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,a; cin>>t;
	while(t--){
		cin>>n;
		vec1 ele,ind;
		rep(i,n) {
			cin>>a;
			ele.push_back(a);
		}
		rep(i,n){
			cin>>a;
			ind.pb(a);
		}
		print(ele,ind,n);
	}
	return 0;
}