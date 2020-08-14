#include <bits/stdc++.h>
using namespace std;

int cutrod(int arr[],int n){
	if(n<=0) return 0;

	int maxval=INT_MIN;

	for(int i=0;i<n;i++)
		maxval = max(maxval,arr[i]+cutrod(arr,n-1-i));

	return maxval;
}

int cutrod(int arr[],int n){
	int val[n+1];
	val[0]=0;

	int maxval;

	for(int i=1;i<=n;i++){
		maxval = INT_MIN;
		for(int j=0;j<i;j++){
			maxval = max(maxval,arr[j]+val[i-j-1]);
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
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];

		cout<<cutrod(arr,n);
		
	}
	return 0;
}