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
	ll t,n,q,l,r; cin>>t;
	while(t--){
		cin>>n>>q;
		string str;
		cin>>str;
		while(q--){
			cin>>l>>r;
			l--;r--;
			bool flag = false;
			for(ll i=0;i<l;i++){
				if(str[i] == str[l]) {
					flag = true;
					break;
				}
			}
			if(flag){
				cout<<"YES"<<endl;
				continue;
			}
			for(ll i=r+1;i<n;i++){
				if(str[i] == str[r]){
					flag = true;
					break;
				}
			}
			if(flag){
				cout<<"YES"<<endl;
				continue;
			}
			cout<<"NO"<<endl;
		}
	}
	return 0;
}