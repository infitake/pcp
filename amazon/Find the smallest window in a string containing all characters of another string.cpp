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

int hashfun(string str){
    int n = str.size();
    int num=0;
    for(int i=0;i<n;i++){
        num = (num*10) + (str[i]-'a');
    }
    return num;
}

void stringReductionUtil(int k,string s,string &finalstr,int &i,int n,string &stp){
	// cout<<finalstr<<endl;
    if(i>=n) return ;
    if(i<n){
        // s = s.erase(i,k);
        string st = "";
        st += s.substr(0,i);
        st += s.substr(i+k,n-k);
        // cout<<st<<endl;
        finalstr =st;
        stringReductionUtil(k,s,st,++i,n,stp);
    }
    if(hashfun(stp)<hashfun(finalstr)){
        stp = finalstr;
    } 
}


string stringReduction(int k, string s) {
    string finalstr = "",stp="";
    int n = s.size();
    int i=0;
    stringReductionUtil(k,s,finalstr,i,n,stp);
    return stp;
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
		int k;
		cin>>k;
		string str1,str2;
		cin>>str1;

		cout<<stringReduction(k,str1)<<endl;
	}
	return 0;
}