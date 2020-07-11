// difficult question

#include <bits/stdc++.h>
using namespace std;
// Method 1: (coomplecated)
// An Efficient Solution solves the above problem in O(n) time. Let us call the XOR of all elements in the range [i+1, j] as A, in the range [0, i] as B, and in the range [0, j] as C. If we do XOR of B with C, the overlapping elements in [0, i] from B and C zero out and we get XOR of all elements in the range [i+1, j], i.e. A. Since A = B XOR C, we have B = A XOR C. Now, if we know the value of C and we take the value of A as m, we get the count of A as the count of all B satisfying this relation. Essentially, we get the count of all subarrays having XOR-sum m for each C. As we take sum of this count over all C, we get our answer.

// 1) Initialize ans as 0.
// 2) Compute xorArr, the prefix xor-sum array.
// 3) Create a map mp in which we store count of 
//    all prefixes with XOR as a particular value. 
// 4) Traverse xorArr and for each element in xorArr
//    (A) If m^xorArr[i] XOR exists in map, then 
//        there is another previous prefix with 
//        same XOR, i.e., there is a subarray ending
//        at i with XOR equal to m. We add count of
//        all such subarrays to result. 
//    (B) If xorArr[i] is equal to m, increment ans by 1.
//    (C) Increment count of elements having XOR-sum 
//        xorArr[i] in map by 1.
// 5) Return ans.

int xorsubarray(vector<int> arr,int n,int m){
	int xorary[n],ans=0;
	unordered_map<int,int> mp;
	xorary[0]=arr[0];
	for(int i=1;i<n;i++) xorary[i] = xorary[i-1]^arr[i];
	for(int i=0;i<n;i++){
		int val = xorary[i]^m;
		ans += mp[val];
		if(xorary[i]==m) ans++;
		mp[xorary[i]]++;

	}
	return ans;
}
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,m; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		cout<<xorsubarray(arr,n,m)<<endl;
		
	}
	return 0;
}