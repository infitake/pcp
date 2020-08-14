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

void dfs(vector<list<ll>> &adj,vector<bool> &visited,map<ll,ll> &rootchild,map<ll,ll> &subtree,ll i){
	visited[i]=true;
	// cout<<i<<endl;
	subtree[i]=1;
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		// cout<<"iterator "<<*it<<endl;
		if(!visited[*it]){
			rootchild[*it]=i;
			dfs(adj,visited,rootchild,subtree,*it);
			subtree[i] += subtree[*it];
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
	ll t,n,e,k,a,b;
	// while(t--){
		cin>>n;
		vector<list<ll>> adj(n+1);
		vector<pii> edges;
		vector<bool> visited(n,false);
		map<ll,ll> rootchild;
		map<ll,ll> subtree;
		cin>>e>>k;
		for(ll i=0;i<e;i++){
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
			edges.pb({a,b});
			// cout<<a<<" "<<b<<endl;
		}
		dfs(adj,visited,rootchild,subtree,1);
		for(ll i=0;i<e;i++){
			int fst=edges[i].first;
			int sec=edges[i].second;

			if(rootchild[fst]!=sec) swap(fst,sec);

			cout<<(n-subtree[fst])*subtree[fst]<<endl;
		}
		
	// }
	return 0;
}