#include <bits/stdc++.h>
using namespace std;

// Method 1;
// int rotatedarrayx(vector<int> &arr,int n,int k){
// 	int ind;
// 	for(int i=0;i<n-1;i++){
// 		if(arr[i]>arr[i+1]){
// 			ind=i+1;
// 			break;
// 		}
// 	}
// 	int l,r;
// 	if(k>=arr[0] && k<=arr[ind-1]) {
// 		l=0,r=ind-1;
// 	}else if(k>=arr[ind] && k<=arr[n-1]){
// 		l=ind;r=n-1;
// 	}
	// while(l<=r){
	// 	int mid = l+(r-l)/2;
	// 	if(arr[mid]==k) return mid;
	// 	if(arr[mid]<k) l=mid+1;
	// 	else r= mid;
	// }
	// return -1;
// }

// Method 2:
// All solutions provided here assume that all elements in array are distinct.

// The idea is to find the pivot point, divide the array in two sub-arrays and call binary search.
// The main idea for finding pivot is – for a sorted (in increasing order) and pivoted array, pivot element is the only element for which next element to it is smaller than it.
// Using above criteria and binary search methodology we can get pivot element in O(logn) time

// Input arr[] = {3, 4, 5, 1, 2}
// Element to Search = 1
//   1) Find out pivot point and divide the array in two
//       sub-arrays. (pivot = 2) /*Index of 5*/
//   2) Now call binary search for one of the two sub-arrays.
//       (a) If element is greater than 0th element then
//              search in left array
//       (b) Else Search in right array
//           (1 will go in else as 1 < 0th element(3))
//   3) If element is found in selected sub-array then return index
//      Else return -1.
     

int binaryserach(vector<int> &arr,int l,int r,int k){
	while(l<=r){
		int mid = l+(r-l)/2;
		if(arr[mid]==k) return mid;
		if(arr[mid]<k) l=mid+1;
		else r= mid;
	}
	return -1;
}


int findpivot(vector<int> &arr,int low,int high){
	while(low<high){
		int mid = low+(high-low)/2;
		if(mid<high && arr[mid]>arr[mid+1]) return mid;
		if(low>=0 && arr[mid]<arr[mid-1])  return mid-1;

		if(arr[mid]<arr[mid+1]) low=mid+1;
		else high = mid;
	}
	return -1;
}

int rotatedarrayx(vector<int> &arr,int n,int k){
	int pivot = findpivot(arr,0,n-1);
	if(pivot == -1) return binaryserach(arr,0,n-1,k);
	if(arr[pivot] == k) return pivot;

	if(arr[0]<=k) return binaryserach(arr,0,pivot-1,k);
	else return binaryserach(arr,pivot,n-1,k); 
}



int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,k; cin>>t;
	while(t--){
		cin>>n>>k;
		vector<int> arr;
		for(int i=0;i<n;i++) {
			cin>>a;
			arr.push_back(a);
		}
		cout<<rotatedarrayx(arr,n,k)<<endl;
	}
	return 0;
}