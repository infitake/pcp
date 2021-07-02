#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define vec1 vector<int>
#define pii pair<int,int>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define initdp(a,b) for(int i=0;i<=a;i++)for(int j=0;j<=b;j++)dp[i][j]=-1;
#define fi first
#define se second
#define mid(l,r) l+(r-l)/2
#define removeduplicates(vec) vec.erase( unique( vec.begin(), vec.end() ), vec.end() )
#define memset1(v) memset(v,-1,sizeof(v))
#define memset0(v) memset(v,0,sizeof(v))
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}

bool check(string str){
	int n = str.size();
	int l = 0,r=n-1;
	while(l<r && str[l]==str[r]) { l++;r--; }
	return (l>=r);
}
// cabdacb

bool pallindromeSwapper(string &str,int l,int r){
	if(check(str)) return true;
	while(l<r && str[l]==str[r] ) { l++;r--; }
	if(l>=r) return true;
	string str1 = str;
	swap(str1[l],str1[l+1]);
	if(str1[l]==str1[r] && pallindromeSwapper(str1,l+1,r-1)) {str=str1; return true;}
	string str2 = str;
	swap(str2[r],str2[r-1]);
	if(str2[l]==str2[r] && pallindromeSwapper(str2,l+1,r-1)) {str=str2; return true;}
	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a; cin>>t;
	while(t--){
		string str;
		cin>>str;
		n = str.size();
		bool flag = pallindromeSwapper(str,0,n-1);
		if(flag) cout<<str<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
// don't settle on same approach
// check for base cases n=0
// write every possible case 

bool couldBeP(string s) {
    map<char, int> res;
    for (auto v:s) {
        res[v]++;
    }
    auto it=res.begin();
    int signle=0;
    while(it!=res.end()) {
        if (it->second%2!=0) {
            signle++;
        }
        it++;
    }
    return signle<=1;
}

int minswap(string s) {
    if (!couldBeP(s)) return -1;
    int len = s.size();
    int l =0;
    int r =len-1;
    int sc = 0;
    int k=r;
    while (l<r) {
        k=r;
        while (k>=l && s[l]!=s[k]) {
            k--;
        }
        if (l!=k && s[l]==s[k]) {
            while (k<r) {
                swap(s[k], s[k+1]);
                k++;
                sc++;
            }
            r--;
            l++;
        } else {
            swap(s[l],s[l+1] );
            sc++;
        }
    }
    //std::cout<<"ms----: "<<s<<endl;
    return sc;
}


int main() {
    string s1 = "abaabab"; 
    std::cout << minswap(s1)<<std::endl;
    string s2 = "mamad"; 
    std::cout<< minswap(s2)<<std::endl;
    string s3 = "ntiin";
    std::cout<<minswap(s3)<<std::endl;  
}