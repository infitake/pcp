#include <bits/stdc++.h>
using namespace std;

int findNo(int arr[],int n){
	int index=0,count=1;

	for(int i=1;i<n;i++){
		if(arr[index] == arr[i]) count++;
		else count --;
		if(count==0){
			index = i;
			count = 1;
		}
	}
	return arr[index];
}

int majorityElement(int arr[],int n) {
	// first we found the no
	int cand = findNo(arr,n);

	int count=0;
	for(int i=0;i<n;i++){
		if(arr[i] == cand) count++;
	}


	if(count > n/2) return cand;
	return -1;
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
		cout<<majorityElement(arr,n)<<endl;
	}
	return 0;
}