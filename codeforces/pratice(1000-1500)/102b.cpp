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

// bool checkpat(string text ,string pattern,ll n){
// 	for(ll i=0;i<text.size();i+=n){
// 		string check = text.substr(i,n);
// 		if(check != pattern) return false;
// 	}
// 	return true;
// }

// ll fact(ll n,string str){
// 	vec1 factorial;
// 	for(ll i=1;i<sqrt(n);i++){
// 		if(n%i==0){
// 			factorial.pb(i);
// 			if(n/i != i){
// 				factorial.pb(n/i);
// 			}
// 		}
// 	}
// 	sort(factorial.begin(),factorial.end());
// 	for(auto x:factorial){
// 		string check = str.substr(0,x);
// 		if(checkpat(str,check,x)) return x;
// 	}
// 	return -1;
// }

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,m,a,b; cin>>t;
	while(t--){
		string str1,str2,f1,f2;
		cin>>str1>>str2;
		n=str1.size();m=str2.size();
		ll a = lcm(n,m);
		ll c,d;
		c = a/m;
		// cout<<c<<" "<<m<<" "<<a<<endl;
		for(ll i=0;i<c;i++) f1 += str2;
		d = a/n;
		for(ll i=0;i<d;i++) f2 += str1;
		// cout<<"ff"<<endl;
		if(f1 == f2) cout<<f1<<endl;
		else cout<<"-1"<<endl;
		// ll count=0;
		// bool flag =false;
		// if(n>=m) {
		// 	a = fact(m,str2);
		// }
		// else {
		// 	a = fact(n,str1);
		// }
		// ll c,d;
		// c = m/a;
		// d = n/a;
		// if(m%a !=0 || n%a !=0) {
		// 	cout<<"-1"<<endl;
		// 	continue;
		// }
		// ll final = lcm(c,d);
		// string str;
		// while(final--){
		// 	str += str1.substr(0,a);
		// }
		// cout<<str<<endl;
	}
	return 0;
}
