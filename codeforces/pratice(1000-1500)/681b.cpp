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
	ll t,n,a,b; cin>>t;
	while(t--){
		cin>>a>>b;
		string str;
		cin>>str;
		bool flag = false;
		n = str.size();
		ll last1 = n,res=0;
		char prevele = '#';
		for(ll i=0;i<n;i++){
			if(str[i]=='1'){
				if(last1 == n){
					res += a; 
				}else if(prevele == '0'){
					ll d = i-last1-1;
					res += min(d*b , a);
				}
				last1=i;
			}
			prevele = str[i];
		}
		cout<<res<<endl;
	}
	return 0;
}