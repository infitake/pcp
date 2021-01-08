#include <bits/stdc++.h>
using namespace std;

// Method 1:
int majorityElement(int arr[],int n){
	map<int,int> mp;
	for(int i=0;i<n;i++) mp[arr[i]]++;
	for(auto x:mp){
		if(x.second>=ceil(n/2.0)){
			return x.first;
		}
	}
	return -1;
}
// complexity:O(n);
// space complexity:O(n);

// METHOD 2 (Using Moore’s Voting Algorithm):

// Approach: This is a two-step process.
// The first step gives the element that maybe the majority element in the array. If there is a majority element in an array, then this step will definitely return majority element,
// otherwise, it will return candidate for majority element.
// Check if the element obtained from the above step is majority element. This step is necessary as there might be no majority element.
// Step 1: Finding a Candidate
// The algorithm for the first phase that works in O(n) is known as Moore’s Voting Algorithm. Basic idea of the algorithm is that 
// if each occurrence of an element e can be cancelled with all the other elements that are different from e then e will exist till end if it is a majority element.

// Step 2: Check if the element obtained in step 1 is majority element or not.
// Traverse through the array and check if the count of the element found is greater than half the size of the array, then print the answer else print “No majority element”.

// Algorithm:
// Loop through each element and maintains a count of majority element, and a majority index, maj_index
// If the next element is same then increment the count if the next element is not same then decrement the count.
// if the count reaches 0 then changes the maj_index to the current element and set the count again to 1.
// Now again traverse through the array and find the count of majority element found.
// If the count is greater than half the size of the array, print the element
// Else print that there is no majority element

int findcandidate(int arr[],int n){
	int max_ind=0,count=1;
	for(int i=1;i<n;i++){
		if(arr[max_ind] == arr[i]) count++;
		else count--;
		if(count == 0){
			max_ind=i;
			count=1;
		}
	}
	return arr[max_ind];
}

bool ismajority(int arr[],int n,int cnd){
	int count=0;
	for(int i=0;i<n;i++){
		if(arr[i]==cnd) count++;
	}
	// cout<<count<<endl;
	if(count>=ceil(n/2.0)) return true;
	return false;
}


int majorityElement(int arr[],int n){
	int cnd = findcandidate(arr,n);
	// cout<<cnd<<" "<<arr[cnd]<<endl;
	if(ismajority(arr,n,cnd)) return cnd;
	return -1; 
}
// complexity:O(n);
// space complexity:O(1);

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