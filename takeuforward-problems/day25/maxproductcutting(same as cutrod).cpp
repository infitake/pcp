#include <bits/stdc++.h>
using namespace std;

int cutrod(int n){
	if(n==0 || n==1) return 0;

	int maxval=0;

	for(int i=1;i<n;i++)
		maxval = max(maxval,max(i*(n-i),cutrod(n-i)*i));

	return maxval;
}

int cutrod(int n){
	int val[n+1];
	val[0]=0;

	int maxval;

	for(int i=1;i<=n;i++){
		maxval = 0;
		for(int j=1;j<i;j++){
			maxval = max(maxval,max(j*(i-j),val[i-j]*j));
		}
		val[i]=maxval;
	}
	return val[n];
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
		cout<<cutrod(n)<<endl;
		
	}
	return 0;
}