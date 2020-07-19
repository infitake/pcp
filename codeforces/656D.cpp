#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define pii pair<ll,ll>
#define vec1 vector<ll>
#define vec2 vector<ll,ll>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep1(i,b) for(ll i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((ll)(x).size())
#define S(x) scanf("%d",&(x))
#define S2(x,y) scanf("%d%d",&(x),&(y))
#define SL(x) scanf("%lld",&(x))
#define SL2(x) scanf("%lld%lld",&(x),&(y))
#define P(x) printf("%d\n",(x))
#define FT first
#define SN second

// This is the recursive method for the problem 
// we check for both left right and get min value
ll goodstr(string str,char c,ll n){
	if(str.size() == 1) return str[0]!=c;
	ll cntl = goodstr(str.substr(0,n/2),c+1,n/2);
	cntl += n/2 - count(str.begin()+n/2,str.end(),c);
	ll cntr = goodstr(str.substr(n/2,n-1),c+1,n/2);
	cntr += n/2 - count(str.begin(),str.begin()+n/2,c);
	return min(cntl,cntr);
}

// This is the itreative method of the problem
// here we check one and get the result

ll goodstr(){
	char c='a';
		ll count=0;
		while(n>0){
			if(n == 1 && str[0] == c){
				break;
			}else if(n == 1 && str[0] != c){
				count += 1;
				break;
			}
			string s1 = str.substr(0, (n/2)); 
			string s2 = str.substr(n/2,n-1);
			ll as1=0,as2=0,as3=0,as4=0;int mt=INT_MAX;
			for(auto s:s1){
				if(s == c) as1++;
				mt = min(mt,abs(s-c));
			}
			as3 = mt;
			mt = INT_MAX;
			for(auto s:s2){
				if(s == c) as2++;
				mt = min(mt,abs(s-c));
			}
			as4=mt;
			// cout<<as1<<" "<<as2<<" "<<endl;4
			if(as1 == as2){
				if(as3<as4){
					count += (n/2)-as1;
					str.assign(s1);
				}else{
					count += (n/2)-as2;
					str.assign(s2);
				}
			}
			else if(as1>as2){
				count += (n/2)-as1;
				str.assign(s2);
			}else{
				count += (n/2)-as2;
				str.assign(s1);
			}
			c++;
			n=n/2;
			// cout<<s1<<" "<<s2<<" "<<str<<" "<<c<<" "<<count<<endl;
			// break;
		}		
		cout<<count<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		string str;
		cin>>str;
		cout<<goodstr(str,'a',n)<<endl;
	}
	return 0;
}