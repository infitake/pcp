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

void parking(vector<ll> arr,ll n,ll k){
	sort(arr.begin(),arr.end());
	ll minval = INT_MAX;
	ll j=1;
	// cout<<"kdkd";
	for(ll i=0;i<(n-k)+1;i++){
		// cout<<arr[i+k-1]<<" "<<arr[i]<<endl;
		minval = min(minval,(arr[i+k-1]-arr[i]+j));
	}
	cout<<minval<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,a,k; cin>>t;
	while(t--){
		cin>>n>>k;
		vec1 arr;
		rep(i,n) {
			cin>>a;
			arr.push_back(a);
		}
		parking(arr,n,k);
	}
	return 0;
}