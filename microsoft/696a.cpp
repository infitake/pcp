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
		string str,ans;
		cin>>str;
		ll count=0;
		for(auto x:str){
			if(x=='1'){
				if(count==0){
					ans += "1";
					count = 2;
				}
				else if(count==2){
					ans += "0";
					count=1;
				}else if(count==1){
					ans += "1";
					count=2;
				}
			}else{
				if(count==0){
					ans += "1";
					count = 1;
				}
				else if(count==1){
					ans += "0";
					count=0;
				}else if(count==2){
					ans += "1";
					count=1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
// don't settle on same approach
// check for base cases n=0