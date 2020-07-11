/*
https://www.spoj.com/problems/WATER/

solution:
https://mohamedmosamin.wordpress.com/2013/07/17/uva-212-water-among-cubes-water/
https://github.com/viraj071/SPOJ/blob/master/WATER%20-%20Water%20among%20Cubes/WATER.cpp
https://github.com/spoj-solution/solution/blob/master/src/WATER.cpp
*/

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
#define LT 101
#define pip pair<int,pair<int,int>>
ll x_axis[]={0,0,1,-1};
ll y_axis[]={1,-1,0,0};

ll cubes(ll arr[][LT],ll n,ll m){
	vector<vector<ll>> visited = vector<vector<ll>> (n,vector<ll>(m,0));
	priority_queue<pip,vector<pip>,greater<pip>> pq;
	rep(i,n){
		rep(j,m){
			if(i==0 || j==0 || i+1==n || j+1==m){
				pq.push({arr[i][j],{i,j}});
			}
		}
	}
	ll sum=0;
	while(!pq.empty()){
		pip temp1=pq.top();
		while(!pq.empty()){
			pip temp2=pq.top();
			if(temp2.first>temp1.first) break;
			pq.pop();
			if(visited[temp2.second.first][temp2.second.second]++) continue;
			sum += temp1.first-temp2.first;
			for(ll i=0;i<4;i++){
				ll a=temp2.second.first + x_axis[i];
				ll b=temp2.second.second + y_axis[i];
				if(a>=0 && a<n && b>=0 && b<m){
					pq.push({arr[a][b],{a,b}});
				}
			}
		}
	}
	
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,m; cin>>t;
	while(t--){
		cin>>n>>m;
		ll arr[LT][LT];
		rep(i,n){
			rep(j,m){
				cin>>arr[i][j];
			}
		}
		cout<<cubes(arr,n,m)<<endl;
	}
	return 0;
}