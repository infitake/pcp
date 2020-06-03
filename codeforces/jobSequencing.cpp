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

struct job{
	char id;
	ll deadline;
	ll profit;
};

ll comp(job a,job b){
	return (a.profit>b.profit);
}

void jobSequecing(job js[],ll n){
	sort(js,js+n,comp);
	bool ocupied[n];
	rep(i,n) ocupied[i]=false;
	ll final_arr[n];
	for(ll i=0;i<n;i++){
		for(ll j=min(n,js[i].deadline)-1;j>=0;j--){
			if(!ocupied[j]){
				final_arr[j]=i;
				ocupied[j]=true;
				break;
			}
		}
	}
	for (int i=0; i<n; i++) 
       if (ocupied[i]) 
         cout << js[final_arr[i]].id << " "; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>n;
	job js[n];
	rep(i,n) {
		cin>>js[i].id>>js[i].deadline>>js[i].profit;
	}	
	jobSequecing(js,n);
	return 0;
}