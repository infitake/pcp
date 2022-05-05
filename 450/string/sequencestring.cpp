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

void sequence(string ans,string str,int ind,set<string> &s){
	if(str!="") s.insert(str);
	for(int i=ind;i<ans.size();i++){
		str.push_back(ans[i]);
		sequence(ans,str,i+1,s);
		str.pop_back();
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	string str; cin>>str;
	set<string> s;
	sequence(str,"",0,s);
	for(auto x:s) cout<<x<<endl;
	return 0;
}