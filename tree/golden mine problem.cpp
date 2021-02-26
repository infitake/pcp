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
int dx[3]={0,-1,1},dy[3]={1,1,1};
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}

void goldenMine(vector<vector<int>> &arr,int n,int m,int i,int j,int sum,int &maxsum){
	if(i<0 || i>=n) return;
	if(j==m){
		maxsum = max(maxsum,sum);
		return;
	}

	for(int k=0;k<3;k++){
		int x = dx[k]+i;
		int y = dy[k]+j;
		goldenMine(arr,n,m,x,y,sum+arr[i][j],maxsum);
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
	int t,n,m,a; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<vector<int>>  arr(n,vector<int>(m));
		rep(i,n){
			rep(j,m){
				cin>>arr[i][j];
			}
		}

		int sum,maxsum=0;
		for(int i=0;i<n;i++){
			sum=0;
			goldenMine(arr,n,m,i,0,sum,maxsum);
		}
		cout<<maxsum<<endl;
		// int sum,maxsum=0;
  //       for(int j=1;j<m;j++){
  //           for(int i =0;i<n;i++){
  //               int right = ((j-1)>=0)?arr[i][j-1]:0;
  //               int right_up = (i-1>=0 && j-1>=0)?arr[i-1][j-1]:0;
  //               int right_down= (i+1<n && j-1>=0)?arr[i+1][j-1]:0;
  //               arr[i][j] += max(right,max(right_up,right_down));
  //           }
  //       }
  //       for(int i=0;i<n;i++){
  //           maxsum = max(maxsum,arr[i][m-1]);
  //       }
  //       return maxsum;
	}
	return 0;
}
// don't settle on same approach
// check for base cases n=0
// write every possible case 