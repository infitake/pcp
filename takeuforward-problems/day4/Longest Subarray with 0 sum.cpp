#include <bits/stdc++.h>
using namespace std;
#define pb push_back

// Method 1:(basic id is if sum is again find in hash then all element upto sum is zero)
// The brute force solution is calculating the sum of each and every sub-array and checking whether the sum is zero or not. Let’s now try to improve the time complexity by taking an extra space of ‘n’ length. The new array will store the sum of all the elements up to that index. The sum-index pair will be stored in a hash-map. A Hash map allows insertion and deletion of key-value pair in constant time. Therefore, the time complexity remains unaffected. So, if the same value appears twice in the array, it will be guaranteed that the particular array will be a zero-sum sub-array.

// Mathematical Proof:
// prefix(i) = arr[0] + arr[1] +…+ arr[i]
// prefix(j) = arr[0] + arr[1] +…+ arr[j], j>i
// ifprefix(i) == prefix(j) then prefix(j) – prefix(i) = 0 that means arr[i+1] + .. + arr[j] = 0, So a sub-array has zero sum , and the length of that sub-array is j-i+1

// Algorithm:
// Create a extra space, an array of length n (prefix), a variable (sum) , length (max_len) and a hash map (hm) to store sum-index pair as a key-value pair
// Move along the input array from starting to the end
// For every index update the value of sum = sum + array[i]
// Check for every index, if the current sum is present in the hash map or not
// If present update the value of max_len to maximum of difference of two indices (current index and index in the hash-map) and max_len
// Else Put the value (sum) in the hash map, with the index as a key-value pair.
// Print the maximum length (max_len)
int lssum(vector<int> arr, int n){
	int sum=0,max_index=0;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		sum += arr[i];
		if(arr[i]==0 && max_index==0)
			max_index=1;
		if(sum ==0)
			max_index=i+1;
		if(mp.find(sum)!=mp.end()){
			max_index = max(max_index,i-mp[sum]);
		}
		else mp[sum]=i;
	}
	return max_index;
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
		for(int i=0;i<n;i++) {
			cin>> a;
			arr.pb(a);
		}
		cout<<lssum(arr,n)<<endl;
	}
	return 0;
}