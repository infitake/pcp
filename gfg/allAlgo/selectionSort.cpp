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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll n,temp,val,min;
	cin>>n;
	ll arr[n];
	for(ll i = 0; i < n; i++) cin>>arr[i];
	for(ll i=0;i<n-1;i++){
		min = arr[i];
		val = i;
		for(ll j=i;j<n;j++){
			if(min>arr[j]){
				min = arr[j];
				val = j;
			}
		}
		temp = arr[i];
		arr[i]=min;
		arr[val]=temp;
	}
	for(ll i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}