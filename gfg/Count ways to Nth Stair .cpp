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

ll countstair(ll arr[],ll n,ll w){
	// if(w==0) return 1;
	// if(w<0) return 0;
	// if(n<=0&&w>=1) return 0;
	// return countstair(arr,n,w-arr[n-1])+countstair(arr,n-1,w);
	int table[w+1]; 
    memset(table, 0, sizeof(table)); 
    table[0] = 1; 
    for(int i=0; i<n; i++) 
        for(int j=arr[i]; j<=w; j++) 
            table[j] += table[j-arr[i]]; 
  
    return table[w];
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
		ll arr[]={1,2};
		ll w = 2;
		cout<<countstair(arr,w,n)<<endl;
	}
	return 0;
}