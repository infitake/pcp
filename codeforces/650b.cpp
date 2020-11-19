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
		ll odd=0,even=0;
		bool flag=true;
		for(ll i=0;i<n;i++){
			if(flag){
				if(arr[i]&1) odd++;  
			} else{
				if(arr[i]%2==0) even++;
			}
			flag = !flag;
		}
		if(odd!=even) cout<<"-1"<<endl;
		else cout<<even<<endl;
		// if(count&1) cout<<"-1"<<endl;
		// else cout<<count/2<<endl;
	}
	return 0;
}