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
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,m,a; cin>>t;
	while(t--){
		cin>>n>>m;
		ll arr[n][m];
		string str;
		rep(i,n){
			rep(j,m){
				arr[i][j]=0;
			}
		}
		vector<vector<pii>> vec; 
		rep(i,n){
			cin>>str;
			rep(j,m){
				if(str[j]=='1') arr[i][j]=1;
			}
		}
		rep(i,n){
			rep(j,m){
				vector<pii> v;
				if(arr[i][j]==1){
						
						if(i+1<n && j+1<m && arr[i][j+1]==1 && arr[i+1][j]==1 ){
							arr[i][j+1]=0 ; arr[i+1][j]=0; arr[i][j]=0;
							v.pb({i,j+1});v.pb({i+1,j});v.pb({i,j});
						}else if(i+1<n && j+1<m && arr[i][j+1]==1 && arr[i+1][j+1]==1){
							arr[i][j+1]=0 ; arr[i+1][j+1]=0; arr[i][j]=0;
							v.pb({i,j+1});v.pb({i+1,j+1});v.pb({i,j});
						}else if(i+1<n && j+1<m && arr[i+1][j]==1 && arr[i+1][j+1]==1){
							arr[i+1][j]=0 ; arr[i+1][j+1]=0; arr[i][j]=0;
							v.pb({i+1,j});v.pb({i+1,j+1});v.pb({i,j});
						}else if(i+1<n && j-1>=0 && arr[i+1][j-1]==1 && arr[i+1][j]==1){
							arr[i+1][j-1]=0 ; arr[i+1][j]=0; arr[i][j]=0;
							v.pb({i+1,j-1});v.pb({i+1,j});v.pb({i,j});
						}else if(i+1<n && j-1>=0 && arr[i][j-1]==1 && arr[i+1][j-1]==1){
							arr[i][j-1]=0 ; arr[i+1][j-1]=0; arr[i][j]=0;
							v.pb({i,j-1});v.pb({i+1,j-1});v.pb({i,j});
						}else if(i+1<n && j-1>=0 && arr[i][j-1]==1 && arr[i+1][j]==1){
							arr[i][j-1]=0 ; arr[i+1][j]=0; arr[i][j]=0;
							v.pb({i,j-1});v.pb({i+1,j});v.pb({i,j});
						}
					
					vec.pb(v);
				}
			}
		}
		ll count=0;
		rep(i,n){
			rep(j,m){
				if(arr[i][j]==1) count++;
				// cout<<arr[i][j]<<" ";
			}
			// cout<<endl;
		}
		if(count==0) {
			cout<<vec.size()<<endl;
			for(auto x:vec){
				for(auto tt:x){
					cout<<tt.first+1 <<" "<<tt.second+1 <<" ";
				}
				cout<<endl;
			}
		}else{
			cout<<"not possible"<<endl;
		}
	}
	return 0;
}