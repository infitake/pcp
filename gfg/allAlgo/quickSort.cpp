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
// void swap(ll *a,ll *b){
// 	ll t = *a;
// 	*a = *b;
// 	*b = t;
// }

ll partiion(ll arr[],ll l,ll r){
	ll pivot = arr[r];
	ll i = l-1;

	for(ll j=l;j<r;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return i+1;
}

void quickSort(ll arr[],ll l,ll r){
	if(l<r){
		ll pivot = partiion(arr,l,r);

		quickSort(arr,l,pivot-1);
		quickSort(arr,pivot+1,r);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>n;
	ll arr[n];

	for(ll i = 0; i < n; i++) cin>>arr[i];

	quickSort(arr,0,n-1);

	for(ll i = 0; i < n; i++) cout<<arr[i]<<" ";

	cout<<endl;

	return 0;
}