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

void postorderutil(ll in[],ll pre[],ll l,ll r,map<ll,ll> &mp,ll &index){
	if(l>r) return;
	ll ind = mp[pre[index++]];
	postorderutil(in,pre,l,ind-1,mp,index);
	postorderutil(in,pre,ind+1,r,mp,index);
	cout<<in[ind]<<" ";
}

void postorder(ll in[],ll pre[],ll n){
	map<ll,ll> mp;
	rep(i,n){
		mp[in[i]] = i;
	}
	ll c=0;
	postorderutil(in,pre,0,n-1,mp,c);
}

int main() {
// 	#ifndef ONLINE_JUDGE
//     	freopen("input.txt", "r", stdin);
//     	freopen("output.txt", "w", stdout);
// 	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		ll pre[n],in[n];
		rep(i,n) {
			cin>>pre[i];
			in[i]=pre[i];
		}
		sort(in,in+n);
		postorder(in,pre,n);
		cout<<endl;
	}
	return 0;
}