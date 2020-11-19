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
		cin>>n;
		vec1 arr;
		rep(i,n){
			cin>>a;
			arr.pb(a);
		}
		sort(arr.begin(),arr.end());
		for(ll i=1;i<n;i++){
			if(arr[i]-arr[i-1] <= 1){
				arr[i-1]=0;
			}
		}
		ll count=0;
		rep(i,n){
			if(arr[i]!=0) count++;
		}
		if(count == 1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}