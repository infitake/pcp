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
	ll t,n,m,k; cin>>t;
	while(t--){
		cin>>n>>m>>k;
		ll v= n/k;
		if(m == 0) {
			cout<<"0"<<endl;
			continue;
		}
		if(v>m){
			cout<<m<<endl;
		} else{
			ll diff = m-v,max = v;
			ll arr[k],i=1;
			for(ll j=1;j<=k-1;j++){
			arr[j]=0;
		}
			while(diff>0){
				if(i>=(k-1)) i = (i%(k-1));
				arr[i]++;
				// cout<<"i value"<<i<<"arr "<<arr[i]<<endl;
				i++;
				diff--;
			}
			// cout<<"after loop";
			// for(ll p=1;p<=k-1;p++) cout<<arr[p]<<endl;
			// sort(arr,arr+(k-1));
			ll min = INT_MIN;
			for(ll p = 1;p<=k-1;p++) {
				if(min<arr[p])
					min = arr[p];
			}
			// ll min = arr[k-1];
			// cout<<"min"<<min<<"max"<<max<<endl;
			cout<<(max-min)<<endl;
			// if((dif-1)>0){
			// 	cout<<"1"<<endl;
			// }else{
			// 	cout<<"0"<<endl;
			// }
		}
		// cout<<"after above"<<endl;
	}
	return 0;
}