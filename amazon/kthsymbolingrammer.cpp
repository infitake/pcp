#include <bits/stdc++.h>
using namespace std;

void kthsmallest(int n,int k){
	if(n==1 || k==1) return 0;

	return (k&1)? kthsmallest(n-1,(k+1)/2): 1-kthsmallest(n-1,k/2);
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,k; cin>>t;
	while(t--){
		cin>>n>>k;
		cout<<kthsmallest(n,k)<<endl;
	}
	return 0;
}