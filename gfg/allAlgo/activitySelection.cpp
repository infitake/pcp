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

struct activity {
	ll start,end;
};

bool comp(activity a1,activity a2){
	return (a1.end<a2.end);
}

void activitySelection(activity *arr,ll n){
	sort(arr,arr+n,comp);
	ll i=0;
	cout<<"("<<arr[i].start<<", "<<arr[i].end<<")"<<" ";
	for(ll j=1;j<n;j++){
		if(arr[j].start>=arr[i].end){
			cout<<"("<<arr[j].start<<", "<<arr[j].end<<")"<<" ";
			i=j;
		}
	}
	cout<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>n;
	activity arr[n];
	rep(i,n) {
		cin>>arr[i].start>>arr[i].end;
	}
	activitySelection(arr,n);
	return 0;
}