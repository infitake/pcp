/******************************************
* AUTHOR : RAVINDER YADAV *
* NICK : INFINITY *
* INSTITUTION : NIT KURUKSHETRA *
******************************************/
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

ll max(ll arr[],ll n){
	ll mx = INT_MIN;
	for(ll i=0;i<n;i++){
		if(mx < arr[i])
			mx = arr[i];
	}
	return mx;
}

void countSort(ll arr[],ll n,ll exp){

	ll countarr[10];
	ll outarr[n];

	for(ll i=0;i<10;i++){
		countarr[i]=0;
	}


	for(ll i=0;i<n;i++){
		countarr[(arr[i]/exp)%10]++;
	}
	for(ll i=1;i<10;i++){
		countarr[i] += countarr[i-1]; 
	}
	for(ll i=n-1;i>=0;i--){
		outarr[countarr[(arr[i]/exp)%10]-1] = arr[i];
		countarr[(arr[i]/exp)%10]--;
	}
	rep(i,n) arr[i]=outarr[i];
}

void radixSort(ll arr[],ll n){
	ll mx = max(arr,n);

	for(ll exp = 1;mx/exp>0;exp *= 10)
		countSort(arr,n,exp);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>n;
	ll arr[n];
	rep(i,n) cin>>arr[i];

	radixSort(arr,n);

	rep(i,n) cout<<arr[i]<<" ";

	cout<<endl;

	return 0;
}