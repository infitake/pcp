#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define vec vector<ll>
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
	ll t,n,x,y,a; cin>>t;
	while(t--){
		cin>>n;
		ll j=0,a=0,b=0;
		vector<pair<ll,ll>> v;
		while(j<n){
			cin>>x>>y;
			v.pb({x,y});
			j++;
		}
		sort(v.begin(),v.end());
		string str="";
		bool flag = true;
		for(ll i=0;i<n;i++){
			if(v[i].first<a || v[i].second<b){
				flag = false;
				break;
			}
			ll xx=v[i].first-a;
			ll yy=v[i].second-b;
			while(xx--) str += 'R';
			while(yy--) str += 'U';
			a = v[i].first;
			b = v[i].second;
		}
		if(!flag) cout<<"NO"<<endl;
		else cout<<"YES"<<"\n"<<str<<endl;
	}
	return 0;
}