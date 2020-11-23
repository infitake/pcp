#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define vec1 vector<ll>
#define pii pair<ll,ll>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,a,w; cin>>t;
	while(t--){
		cin>>n>>w;
		vec1 arr,ans;
		ll count=0,sum=0;
		rep(i,n){
			cin>>a;
			arr.pb(a);
		}
		vector<pii> vec;
		rep(i,n){
			vec.pb({arr[i],i+1});
		}
		sort(vec.begin(),vec.end());
		for(ll i=n-1;i>=0;i--){
			sum+=vec[i].first;
			if(vec[i].first<=w && sum<=w) {
				count++;
				ans.pb(vec[i].second);
			}else if(sum>w){
				sum -= vec[i].first;
				// break;
			}
		}
		if(count==0 || sum<ceil(w/2.0)) cout<<"-1"<<endl;
		else {
			cout<<count<<endl;
			for(ll i=0;i<ans.size();i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}