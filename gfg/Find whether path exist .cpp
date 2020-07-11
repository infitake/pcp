#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100
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
ll x_axis[]={0,0,1,-1};
ll y_axis[]={1,-1,0,0};
void bfsutil(ll arr[N][N],bool visit[N][N],ll i,ll j,ll n){
	visit[i][j]=true;
	for(ll u=0;u<4;u++){
		ll a=i+x_axis[u];
		ll b=j+y_axis[u];
		if(a>=0&&a<n&&b>=0&&b<n && !visit[a][b] && arr[a][b]!=0)
			bfsutil(arr,visit,a,b,n);
	}
}

bool bfs(ll arr[N][N],ll n){
	bool visit[N][N];
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			visit[i][j]=false;
		}
	}
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(arr[i][j]==1 && !visit[i][j]){
			 bfsutil(arr,visit,i,j,n);
			}
		}
	}
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(arr[i][j]==2 ){
				// cout<<"hello"<<endl;
			 	if(visit[i][j]) return true;
			 	else return false;
			}
		}
	}
	return false;
} 

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		ll arr[N][N];
		rep(i,n){
			rep(j,n){
				cin>>arr[i][j];
			}
		}
		cout<<bfs(arr,n)<<endl;
	}
	return 0;
}