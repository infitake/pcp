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
// 6
// 1 4 45 6 0 19
// 51
// 5
// 1 10 5 2 7
// 9
// 10
// 1 11 100 1 0 200 3 2 1 250
// 280
// 3
// 1 2 4

ll smallestSubarray(vec1 &arr,ll n,ll w) {
	ll len=0,minval = INT_MAX,start=0,end,sum=0;
	for(end=0;end<n;end++){
		sum += arr[end];
		len++;
		if(sum>=w){
			minval = min(minval,len);
			while(sum>w){
				sum -= arr[start++];
				len--;
				if(sum>w) minval = min(minval,len);
			}
		}
	}
	if(minval == INT_MAX) return -1;
	return minval;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,a,sum; cin>>t;
	while(t--){
		cin>>n;
		vec1 arr;
		rep(i,n){
			cin>>a;
			arr.pb(a);
		}
		cin>>sum;
		cout<<smallestSubarray(arr,n,sum)<<endl;
	}
	return 0;
}