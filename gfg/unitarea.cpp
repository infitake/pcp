#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 105
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
vector<int> t1={-1,-1,-1,0,0,1,1,1};
vector<int> t2={-1,0,1,-1,1,-1,0,1};

void dfsutil(ll arr[][N],vector<vector<int>> &visited,ll i,ll j,ll n,ll m,ll &count){
	visited[i][j]=1;
	count = (count) + 1;
	for(ll k=0;k<8;k++){
	    ll a=i+t1[k];
	    ll b=j+t2[k];
	    if((a>=0 && a<n) && (b>=0 && b<m)){
		if(visited[a][b]==0&&arr[a][b]==1){
			dfsutil(arr,visited,a,b,n,m,count);
		}
	    }
	}
}

ll dfs(ll arr[][N],ll n,ll m){
	vector<vector<int>> vis(n,vector<int> (m,0));
	ll count=0;
	ll max = INT_MIN;
	rep(i,n){
		rep(j,m){
			if(vis[i][j]==0 && arr[i][j]==1){
				count=0;
				dfsutil(arr,vis,i,j,n,m,count);
				if(max<count){
					max = count;
				}
			}
		}
	}
	return max;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,m; cin>>t;
	while(t--){
		cin>>n>>m;
		ll arr[N][N];
		rep(i,n){
			rep(j,m){
				cin>>arr[i][j];
			}
		}
		cout<<dfs(arr,n,m)<<endl;
		
	}
	return 0;
}