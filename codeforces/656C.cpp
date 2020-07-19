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

// ll goodstring(vector<ll> arr,ll n){
// 	ll l=0,r=n-1,min=INT_MIN,index=0,last=0;
// 	while(l<r){
// 		if(arr[l]>=arr[r]){
// 			if(arr[r]>=min){
// 				min = arr[r];
// 				r--; 
// 			}else{
// 				min = arr[r];
// 				last = r-0;
// 				r--;
// 			}
// 		}else{
// 			if(arr[l]>=min){
// 				min = arr[l];
// 				l++;
// 			}else{
// 				min = arr[l];
// 				last = l-0;
// 				l++;
// 			}
// 		}
// 	}
// 	return last;
// }
ll goodstring(vector<ll> arr,ll n){
	ll l=0,r=n-1,min=INT_MIN,index=0,last=0;
	while(r>0){
		if(arr[r]<=arr[r-1]) r--;
		else break;
	}
	while(r>0){
		if(arr[r]>=arr[r-1]) r--;
		else break;
	}
	return r;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,a; cin>>t;
	while(t--){
		cin>>n;
		vec1 arr;
		for(ll i=0;i<n;i++){
			cin>>a;
			arr.pb(a);
		}
		cout<<goodstring(arr,n)<<endl;	
	}
	return 0;
}