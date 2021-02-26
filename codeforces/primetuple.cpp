#include <bits/stdc++.h>
#define ll long long
#define N 1000001
#define MOD 1000000007
#define dd double
#define vec1 vector<ll>
#define pii pair<ll,ll>
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

ll prm[N]={0};


void sieve()
{
    bool prime[N + 1];
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=false;
    for (ll p = 2; p * p <= N; p++)
    {
        if (prime[p] == true) 
        {
            for (ll i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    prm[0]=prm[1]=0;
    for (ll p = 2; p <= N; p++){
        if(prime[p]){
            if(p-2>=0 && prime[p-2]){
                prm[p]=prm[p-2]+1;
            }else prm[p]=prm[p-1];
        }else{
            prm[p]=prm[p-1];
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
    //ios_base& scientific (ios_base& str);
    
    sieve();
    ll t,n; cin>>t;
    while(t--){
        cin>>n;
        cout<<prm[n]<<endl;
    }
    return 0;
}
// don't settle on same approach
// check for base cases n=0