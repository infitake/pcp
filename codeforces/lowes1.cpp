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

int isBitPalindrome(int x) {
    int reversed = 0, aux = x;
    while (aux > 0) {
        reversed = (reversed  << 1) | (aux & 1);
        aux = aux >> 1;
    }
    return (reversed  == x) ? 1 : 0;
}
int nopallidrome(int num){
    int rev_num = 0; 
    while (num > 0) { 
        rev_num = rev_num * 10 + num % 10; 
        num = num / 10; 
    } 
    return rev_num; 
}

void sieve(ll lowes[]){
	// for(ll j=1;j<1000001;)
	lowes[0]=0;
	for(ll i=1;i<=1000000;i++){
			if(i%2==0) lowes[i] = lowes[i-1];
			else{
				ll bin = isBitPalindrome(i);
				ll rev = nopallidrome(i);
				if(rev == i && bin==1) lowes[i] = lowes[i-1]+1;
				else lowes[i]=lowes[i-1];
			}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll lowes[1000001];
	sieve(lowes);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		cout<<lowes[n]<<endl;
	}
	return 0;
}
