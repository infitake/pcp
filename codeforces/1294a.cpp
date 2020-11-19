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
	ll t,a,b,c,n; cin>>t;
	while(t--){
		cin>>a>>b>>c>>n;
		ll sum = a+b+c+n;
		if((sum)%3 != 0){
			cout<<"NO"<<endl;
		}else{
			sum = sum/3;
			if(sum>=a && sum>=b && sum>=c ) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}

	}
	return 0;
}