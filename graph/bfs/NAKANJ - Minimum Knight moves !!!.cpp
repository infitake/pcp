/*
		https://www.spoj.com/problems/NAKANJ/
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
map<char,ll> hasher={{'a',1},{'b',2},{'c', 3},{'d', 4},{'e', 5},{'f', 6},{'g', 7},{'h', 8}};
ll x_axis[] = {2,1,-1,-2,-2,-1,1,2};
ll y_axis[] = {1,2,2,1,-1,-2,-2,-1};

struct axis{
	ll x;
	ll y;
	ll d;
};

ll bfs(ll chess[][9],ll s1,ll e1,ll s2,ll e2){
	queue<axis> q;
	axis xy = {s1,e1,0};
	q.push(xy);
	axis temp;
	ll min=INT_MIN;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp.x == s2  && temp.y == e2) {
			return temp.d;
		}
		for(ll i=0;i<8;i++){
			ll a=temp.x + x_axis[i];
			ll b=temp.y + y_axis[i];
			if((a>=1 && a<=8) && (b>=1 && b<=8)){
				// cout<<"checkk";
				if(chess[a][b]!=0) continue;
				axis newx;
				newx.x=a;
				newx.y=b;
				newx.d=temp.d+1;
				// if(min<newx.d){
					// min=newx.d;
				// }
				// if(a == s2 && b == e2) return min;
				q.push(newx);
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t; cin>>t;
	string s,d;
	while(t--){
		ll chess[9][9];
		rep(i,9){
			rep(j,9){
				chess[i][j]=0;
			}
		}
		cin>>s>>d;
		ll s1=hasher[s[0]];
		ll e1=(s[1])-'0';
		ll s2=hasher[d[0]];
		ll e2=d[1]-'0';
		cout<<bfs(chess,s1,e1,s2,e2)<<endl;
	}
	return 0;
}