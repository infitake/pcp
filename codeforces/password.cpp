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
		string str;
		cin>>str;
		// case 5;
		if(str.size()<10){
			cout<<"NO"<<endl;
			continue;
		}
		n=str.size();
		char special[] = {'@','#','%','&','?'};
		set<char> s;
		for(int i=0;i<6;i++) s.insert(special[i]);
		ll l_case=0,u_case=0,number=0,special_char=0;

		for(auto x:str){
			if(x>=97 && x<=122){
				l_case++;
			}else if(x>=65 && x<=90){
				u_case++;
			}else if(s.find(x)!=s.end()){
				special_char++;
			}else if(x>=48 && x<=57){
				number++;
			}
		}
		if(l_case==0 || u_case==0 || special_char==0 || number==0){
			cout<<"NO"<<endl;continue;
		}
		if(u_case==1){
			if((str[0]>=65 && str[0]<=90) || (str[n-1]>=65 && str[n-1]<=90)) {
				cout<<"NO"<<endl;continue;
			}
		}
		if(special_char==1){
			if(s.find(str[0])!=s.end() || s.find(str[n-1])!=s.end()){
				cout<<"NO"<<endl;continue;
			}
		}
		if(number==1){
			if((str[0]>=48 && str[0]<=57)||(str[n-1]>=48 && str[n-1]<=57)){
				cout<<"NO"<<endl;continue;
			}
		}
		cout<<"YES"<<endl;
	}
	return 0;
}
// don't settle on same approach
// check for base cases n=0