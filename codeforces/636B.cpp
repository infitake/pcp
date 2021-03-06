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
	ll t,n,x; cin>>t;
	while(t--){
		cin>>n;
		ll dif = n/2,count=0;
		vec1 arr;
		if(dif%2==0){
			ll val1 = 2,val2 = 2;
			ll mux=2;
			for(ll i=0;i<dif;i++){
				arr.pb(val1);
				val1 = mux*2;
				mux++;
			}
			mux = 2;
			for(ll i=dif;i<n-1;i++){
				count++;
				arr.pb((val2-1));
				val2 = mux*2;
				mux++;
			}
			val2 += count;
			arr.pb(val2);
			cout<<"YES"<<endl;
			for(ll i=0;i<arr.size();i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}
		if(count == 0){
			cout<<"NO"<<endl;
		}
		
	}
	return 0;
}