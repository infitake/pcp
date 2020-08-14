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

int mindist(vec1 arr,ll n,ll x,ll y){
	queue<pii> q;// index and jump in pair of int
	q.push({x,0});
	map<ll,ll> mp;
	// we use map to check visited or not
	while(!q.empty()){
		pii ij = q.front();
		q.pop();
		int ind = ij.first;
		int jump = ij.second;

		if(ind == y) return jump;

		// this is visited
		if(mp.find(ind)!=mp.end()) continue;

		mp[ind]=jump;

		// going to left side
		int newp = ind-arr[ind];
		if(newp<0) newp = newp%n+n;
		q.push({newp,jump+1});

		q.push({(ind + arr[ind])%n,jump+1});
		
	}

	return -1;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,a,x,y; cin>>t;
	while(t--){
		cin>>n>>x>>y;
		x--;y--;
		vec1 arr;
		rep(i,n){
			cin>>a;
			arr.pb(a);
		}
		cout<<mindist(arr,n,x,y)<<endl;
	}
	return 0;
}