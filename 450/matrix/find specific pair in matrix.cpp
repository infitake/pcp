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

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int n; cin>>n;
	vector<vector<int>> arr(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	int maxdiff=INT_MIN,maxval = INT_MIN;
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if(i==n-1 && j==n-1) {
				maxdiff = arr[i][j];
				continue;
			}
			if(i == n-1){
				maxval = max(arr[i][j],arr[i][j-1]);\
			}else if(j == n-1){
				maxval = max(arr[i][j],arr[i-1][j]);
			}else{
				maxval = max(arr[i][j],max(arr[i-1][j],arr[i][j-1]));
			}
			maxdiff = max(maxdiff,(maxval-arr[i][j]));
		}
	}
	cout<<maxdiff<<endl;
	return 0;
}