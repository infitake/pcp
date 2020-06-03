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
	ll t,n,k; cin>>t;
	while(t--){
		cin>>n>>k;
		ll arr[n];
		rep(i,n) cin>>arr[i];
		sort(arr,arr+n);
		ll i=0,j=n-1;
		ll count1=0,count2=0;
		
		while(i<j){
			if((arr[j]-arr[i])>k){
				while(arr[j]>arr[i]){
					arr[j]--;
					count1++;
					if((arr[j]-arr[i])<=k) break;
				}
				j--;
			}else{
				break;
			}
		}
		i=0;j=n-1;
		while(i<j){
			if((arr[j]-arr[i])>k){
				while(arr[j]>arr[i]){
					arr[j]--;
					count2++;
					if((arr[j]-arr[i])<=k) break;
				}
				i++;
			}else{
				break;
			}
		}
		cout<<"here is count1 and count2"<<count1<<" "<<count2<<endl;
		ll final = min(count1,count2);
		cout<<final<<endl;
	}
	return 0;
}