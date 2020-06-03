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

// void swap(ll a,ll b){

// }

void heapifiy(ll arr[],ll n,ll i){
	ll l = 2*i+1;
	ll r = 2*i+2;
	ll largest = i;

	if(l<n && arr[l]>arr[largest])
		largest=l;
	if(r<n && arr[r]>arr[largest])
		largest = r;

	if(largest != i){
		swap(arr[i],arr[largest]);
		heapifiy(arr,n,largest);
	}

}


void heapSort(ll arr[],ll n){
	for(ll i=n/2-1;i>=0;i--){
		heapifiy(arr,n,i);
	}

	for(ll i=n-1;i>0;i--){
		swap(arr[0],arr[i]);
		// leave the last element and then heapify
		// because last element get his right position
		heapifiy(arr,i,0);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>n;
	ll arr[n];
	for(ll i = 0; i < n; i++) cin>>arr[i];

	heapSort(arr,n);

	for(ll i = 0; i < n; i++) cout<<arr[i]<<" ";

	cout<<endl;

	return 0;
}