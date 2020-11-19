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
	ll t,n,a; cin>>t;
	while(t--){
		cin>>n;
		ll vec[51][51];
		ll k=n;
		string str;
		ll row=0,col=0,p=0;

		while(p<n){
			cin>>str;
			col=0;
			for(auto x:str){
				vec[row][col++]=x-'0';
			}
			str="";
			row++;
			p++;
		}
		// for(ll i=0;i<n;i++){
		// 	for(ll j=0;j<n;j++){
		// 		cout<<vec[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;
		ll flag = true,lc=true;
		for(ll i=0;i<n;i++){
			for(ll j=n-1;j>=0;j--){
				// cout<<vec[i][j]<<endl;
				if(vec[i][j]==1){
					if(lc==false){
						// cout<<"::: ddd ::: "<<i<<" "<<j<<" "<<vec[i+1][j]<<endl;
						if(i+1!=n && vec[i+1][j]==1){
							lc=true;
							// cout<<"kd";
							continue;
						}else if(i+1 ==n){
							continue;
						}
						else{
							flag=false;
							break;
						}
					}
				}else{
					lc=false;
				}
			}
			if(!flag) break;
			lc=true;
		}
		if(flag==true) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}