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

void solve(vector<int> arr,int n,int sum){
	int start=0,last=0,sum_so_far=0;
	for(last=0;last<n;last++){
		sum_so_far += arr[last];
		if(sum_so_far > sum){
			while(sum_so_far>sum){
				sum_so_far -= arr[start++];
			}
		}
		if(sum_so_far == sum) {
			cout<<start<<" "<<last<<endl;
			return;
		}
	}
	cout<<"-1"<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,sum,a; cin>>t;
	while(t--){
		cin>>n>>sum;
		vec1 arr(n);
		rep(i,n){
			cin>>arr[i];
		}
		int finalsum = 0;
		solve(arr,n,sum);
	}
	return 0;
}