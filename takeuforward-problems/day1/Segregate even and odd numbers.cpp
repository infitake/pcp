#include <bits/stdc++.h>
using namespace std;

void evenodd(int arr[], int n){
	int l=0,r=n-1;
	while(l<r){
		if(arr[l]%2==1 && arr[r]%2==0){
			swap(arr[l],arr[r]);
			l++;r--;
		}else if(arr[l]%2==0 && arr[r]%2==1){
			l++;
		}else{
			r--;
		}
	}
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
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
		evenodd(arr,n);
		cout<<endl;
	}
	return 0;
}