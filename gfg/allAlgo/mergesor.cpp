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

void merge(ll arr[],ll l,ll r,ll mid){
	ll n = mid-l+1;
	ll m = r-mid;
	ll arr1[n],arr2[m];
	for(ll i=0;i<n;i++) arr1[i]=arr[l+i];
	for(ll j=0;j<m;j++) arr2[j]=arr[mid+j+1];
	ll i=0,j=0,k=l;
	while(n>i && m>j){
		if(arr1[i]>arr2[j]){
			arr[k]=arr2[j];
			j++;
		} else{
			arr[k]=arr1[i];
			i++;
		}
		k++;
	}
	while(n>i){
		arr[k]=arr1[i];
		i++;k++;
	}
	while(m>j){
		arr[k]=arr2[j];
		j++;k++;
	}
}

void mergeSort(ll arr[],ll s,ll e){
	if(s<e){
		ll mid = s + (e-s)/2;
		mergeSort(arr,s,mid);
		mergeSort(arr,mid+1,e);
		merge(arr,s,e,mid);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>n;
	ll arr[n];
	rep(i,n) cin>>arr[i];

	mergeSort(arr,0,n-1);
	for(ll i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}