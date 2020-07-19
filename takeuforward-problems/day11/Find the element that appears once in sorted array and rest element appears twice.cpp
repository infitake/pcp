#include <bits/stdc++.h>
using namespace std;

// Method 1:(using the bitwise operator)
int elementapper(vector<int> &arr,int n){
	int val = arr[0];

	for(int i=1;i<n;i++) val = val ^ arr[i];

	return val;
}
// complexity O(n)

// Method 2:(using binary search)
// An Efficient Solution can find the required element in O(Log n) time. The idea is to use Binary Search. Below is an observation in the input array.
// All elements before the required have the first occurrence at even index (0, 2, ..) and next occurrence at odd index (1, 3, …).
// And all elements after the required elements have the first occurrence at odd index and next occurrence at even index.

// 1) Find the middle index, say ‘mid’.

// 2) If ‘mid’ is even, then compare arr[mid] and arr[mid + 1]. If both are the same, then the required element after ‘mid’ else before mid.

// 3) If ‘mid’ is odd, then compare arr[mid] and arr[mid – 1]. If both are the same, then the required element after ‘mid’ else before mid.

int elementapper(vector<int> &arr,int n){
	int l=0,r=n-1;
	while(l<=r){
		if(l == r) return arr[l];
		int mid = l+(r-l)/2;
		if(mid%2==0){
			if(arr[mid] == arr[mid+1]) l = mid+2;
			else r = mid;
		}else{
			if(arr[mid] == arr[mid-1]) l = mid+1;
			else r = mid-1;
		}
	}
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
	int t,n,a; cin>>t;
	while(t--){
		cin>>n;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		cout<<elementapper(arr,n)<<endl;
		
	}
	return 0;
}