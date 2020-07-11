// /*
// problem:
// https://www.spoj.com/problems/MICEMAZE/
// solution:
// http://www.codebytes.in/2017/07/micemaze-spoj-solution-c-dijkstras.html
// https://github.com/viraj071/SPOJ/blob/master/1845.%20Mice%20and%20Maze/MICEMAZE.cpp
// */
// floyd warshell 
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,e,tr,m; 
	// while(t--){
		cin>>n>>e>>tr>>m;
		ll arr[n][n];
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				arr[i][j]=INT_MAX;
			}
		}
		ll a,b,c;
		while(m--){
			cin>>a>>b>>c;
			arr[a-1][b-1]=c;
		}
		for(int i=0;i<n;i++){
			arr[i][i]=0;
		}
		for(ll k=0;k<n;k++){
			for(ll i=0;i<n;i++){
				for(ll j=0;j<n;j++){
					arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
				}
			}
		}
		ll sum=0;
		for(ll i=0;i<n;i++){
			if(arr[i][e-1]<=tr) sum++;
		}
		cout<<sum<<endl;
	// }
	return 0;
}
// 4
// 2
// 1
// 8
// 1 2 1
// 1 3 1
// 2 1 1
// 2 4 1
// 3 1 1
// 3 4 1
// 4 2 1
// 4 3 1

// using dikastra 
#include <bits/stdc++.h>

#define INF 1000000

using namespace std;

struct edge {
    int v;
    int w;
};

bool operator <( edge a, edge b ) {
    return a.w < b.w;
}

void dijkstra( vector< edge > graph[], int dist[], int S, int N ) {
    int i;
    for ( i = 0; i <= N; ++i ) {
        dist[ i ] = INF;
    }
    priority_queue< edge > q;
    q.push( ( edge ) { S, 0 } );
    dist[ S ] = 0;
    while ( !q.empty() ) {
        edge p = q.top();
        q.pop();
        for ( i = 0; i < graph[ p.v ].size(); ++i ) {
            edge k = graph[ p.v ][ i ];
            if ( dist[ p.v ] + k.w < dist[ k.v ] ) {
                dist[ k.v ] = dist[ p.v ] + k.w;
                q.push( k );
            }
        }
    }
}

int main() {
    int N, S, T, M, u, v, w;
    scanf( "%d%d%d%d", &N, &S, &T, &M );
    vector< edge > graph[ N + 1 ];
    int dist[ N + 1 ], count = 0, i;
    for ( i = 0; i < M; ++i ) {
        scanf( "%d%d%d", &u, &v, &w );
        graph[ v ].push_back( ( edge ) { u, w } );
    }
    dijkstra( graph, dist,S, N );

    for ( i = 1; i <= N; ++i ) {
    	// cout<<dist[i]<<" ";
        if ( dist[ i ] <= T ) {

            count++;
        }
    }
    printf( "%d\n", count );
    return 0;
}