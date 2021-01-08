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
	ll t,n,a; cin>>t;
	while(t--){
		cin>>a;
		n = a;
		ll i=2;
		vec1 ans;
		bool flag = false;
		while(i*i <= n){
			n=a;
			vec1 v;
			while(n%i==0){
				// flag = true;
				n = n/i;
				if(n%i==0){
					v.pb(i);
				}else{
					n = n*i;
					v.pb(n);
					break;
				}
			}
			i++;
			if(v.size()>ans.size()){
				ans = v;
			}
		}
		if(ans.size()==0){
			ans.pb(n);
		}
		cout<<ans.size()<<endl;
		for(auto x:ans){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}