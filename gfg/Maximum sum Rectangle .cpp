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

ll kadane(ll temp[],ll n){
	ll sum=0,maxsum=INT_MIN;
	for(ll i=0;i<n;i++){
		sum += temp[i];
		if(sum<0) sum=0;
		if(sum>maxsum) maxsum = sum;
	}
	return maxsum;
}

ll maxsumrect(vector<vector<ll>> arr,ll n,ll m){
	ll sum=0,maxsum=INT_MIN;
	ll temp[n];
	for(ll i=0;i<m;i++){
		memset(temp,0,sizeof(temp));
		for(ll j=i;j<m;j++){
			for(ll k=0;k<n;k++)
				temp[k] += arr[k][j];
			sum = kadane(temp,n);
			if(sum>maxsum) maxsum = sum;
		}
	}
	return maxsum;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,m,a; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<vector<ll>> arr;
		rep(i,n){
			vector<ll> v1;
			rep(j,m){
				cin>>a;
				v1.pb(a);
			}
			arr.pb(v1);
		}
		cout<<maxsumrect(arr,n,m)<<endl;
	}
	return 0;
}