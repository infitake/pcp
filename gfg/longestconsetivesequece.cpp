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

int findLongestConseqSubseq(int arr[], int n){
    map<int,int> mp;
    int min=INT_MAX,minvalue=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]<min) min = arr[i];
        mp[arr[i]]++;
    }
    int val=min-1,count=0;
    for(auto x:mp){
        // cout<<x.first<<" ";
        if((x.first)-val == 1){
            val = x.first;
            count++;
        }else{
            val=x.first;
            // cout<<"this is val"<<val<<endl;
            count=1;
        }
        if(count>minvalue) minvalue = count;
    }
    // cout<<endl;
    return minvalue;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n; cin>>t;
	while(t--){
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		cout<<findLongestConseqSubseq(arr,n)<<endl;
	}
	return 0;
}