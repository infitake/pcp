#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define vec vector<ll>
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
	ll arr[101] ={0};
	for(ll i=1;i<=100;i++){
		arr[i]=i*i;
	}
	//ios_base& scientific (ios_base& str);
	ll t,n,a,b; cin>>t;
	while(t--){
		cin>>a>>b;
		a = 2*a;
		b = 2*b;
		ll mn = (a<b)?a:b;
		ll mx = (a>b)?a:b;
		if(mn<mx/2) cout<<(mx*mx)/4<<endl;
		else{
			mn = mn*mn;
			cout<<mn<<endl;
		}
		
	}
	return 0;
}