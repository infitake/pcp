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
	ll t,n,a; cin>>t;
	while(t--){
		cin>>n;
		vec1 arr(n);
		rep(i,n){
			cin>>arr[i];
		}
		int start=0,mid=0,end=n;
		while(mid<end && start<end){
			if(arr[mid]<0){
				swap(arr[start],arr[mid]);
				start++;mid++;
			}else{
				mid++;
			}
		} 
		for(auto x:arr) cout<<x<<" ";
		cout<<endl;

	}
	return 0;
}