#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define vec1 vector<ll>
#define pii pair<ll,ll>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep1(i,b) for(ll i=1;i<=b;i++)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((ll)(x).size())
#define F first
#define S second
#define endll "\n"

ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,a; cin>>t;
	while(t--){
		cin>>n;
		string str="",str1="";
		cin>>str;
		bool flag = true;
		if(str[0]=='1'){
			for(ll i=0;i<n;i++){
				if(flag) str1.pb('1');
				else str1.pb('0');
				flag = !flag;
			}
		}else{
			for(ll i=0;i<n;i++){
				if(flag) str1.pb('0');
				else str1.pb('1');
				flag = !flag;
			}
		}
		ll count=0;
		for(ll i=0;i<n;i++){
			if(str[i] != str1[i]){
				count++;
				if(i+1<n && str1[i+1] != str[i+1]) count--;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
