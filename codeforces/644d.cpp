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
	ll t,n,a,k; cin>>t;
	while(t--){
		cin>>n>>k;
		// if(n&1){
		// 	if(k>=n){
		// 		cout<<1<<endl;
		// 	}else{
		// 		ll div = n/k;
		// 		ll rem = n%k;
		// 		cout<<div<<endl;
		// 	}
		// }else{
		// 	if(k>=n){
		// 		cout<<1<<endl;
		// 	}else{
		// 		ll div = n/k;
		// 		ll rem = n%k;69405561 22020729
		// 		if(rem==0) cout<<div<<endl;
		// 		else cout<<div<<endl;

		// 	}
		// }
		if(k==1) {
			cout<<n<<endl;
			continue;
		}
		if(k>=n){
			cout<<1<<endl;
			continue;
		}
		ll flag = false;
		// cout<<"sqrt "<<sqrt(k)<<endl;
		ll ans = n;
		for(ll i=2;i<=sqrt(n) && i<=k;i++){
			if (n % i == 0)
    {
		      if (i <= k)
		        ans = min(ans, n / i);
		      if (i != n / i && n / i <= k)
		        ans = min(ans, i);
		    }
		}
		cout<<ans<<endl;
	}
	return 0;
}