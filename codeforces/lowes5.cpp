// https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/jumpingjack-488ce744/description/
// try to solve complete question

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
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
void sieve(bool prime[]) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
  
    for (int p=2; p*p<=N; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=N; i += p) 
                prime[i] = false; 
        } 
    } 
}

bool bfs(vector<ll> &arr,int n,int m,bool prime[]){
	queue<pii> q;
	q.push({0,0});
	map<ll,ll> mp;
	while(!q.empty()){
		pii val = q.front();
		q.pop();
		ll index = val.first;
		ll jump = val.second;
		// if(jump>m) continue;
		if(jump == m && index == n-1) return true;
		if(mp.find(index)!=mp.end()) continue;
		mp[index]=jump;
		ll pre;
		if(prime[arr[index]]) pre = arr[index];
		else if(arr[index]%2==0) pre = 2;
		else{
			for(ll i=2;i<arr[index];i++){
				if(prime[i] && arr[index]%i == 0){
					pre += i;
					break;
				}
			}
		}
		if(index-pre >=0 ) q.push({(index-pre),jump+1});
		if(index+pre < n) q.push({(index+pre),jump+1});
	}
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
	bool prime[N+1]; 
    memset(prime, true, sizeof(prime)); 
	sieve(prime);
	ll t,n,a,m; cin>>t;
	while(t--){
		cin>>n;
		vec1 arr;
		rep(i,n) {
			cin>>a;
			arr.pb(a);
		}
		cin>>m;
		if(bfs(arr,n,m,prime)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}