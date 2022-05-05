#include <bits/stdc++.h>
using namespace std;

// Method 1:
//			    _           _
//			   | |_       _| |
//			   | | |_   _| | |
//			   | | | |_| | | |
//			   | | | | | | | |

// you have to find the 2 max building around a index
// so you can precompute the left and right max building for every index

// int trappingwater(vector<int> arr){
// 	int n = arr.size(),l=0,r=0,res=0;
// 	for(int i=0;i<n-1;i++){
// 		for(int j=0;j<i;j++){
// 			l = max(l,arr[j]);
// 		}
// 		for(int j=i+1;j<n;j++){
// 			r = max(r,arr[j]);
// 		}
// 		res += min(l,r)-arr[i];
// 	}
// 	return res;
// }

// Complexity Analysis:
// Time Complexity: O(n2).
// There are two nested loops traversing the array, So time Complexity is O(n2).
// Space Complexity: O(1).
// No extra space required.

// Method 2:(with space complexity)
int trappingwater(vector<int> arr){
	int n = arr.size(),l[n],r[n],res=0;
	l[0]=arr[0];
	r[n-1]=arr[n-1];
	for(int j=1;j<n;j++){
		l[j] = max(l[j-1],arr[j]);
	}
	for(int j=n-2;j>=0;j--){
		r[j] = max(r[j+1],arr[j]);
	}
	for(int i=0;i<n;i++){
	res += min(l[i],r[i])-arr[i];
	}
	return res;
}
// Complexity Analysis:
// Time Complexity: O(n).
// Only one traversal of the array is needed, So time Complexity is O(n).
// Space Complexity: O(n).
// Two extra array is needed each of size n.

// Method 3: Space Optimization for above Solution: 
// Instead of maintaing two arrays of size n for storing left and right max of each element, 
// maintain two variables to store the maximum till that point. Since water trapped at any element = min(max_left, max_right) – arr[i]. 
// Calculate water trapped on smaller element out of A[lo] and A[hi] first and move the pointers till lo doesn’t cross hi.

int trappingwater(vector<int> arr){
	int n = arr.size(),l=0,r=n-1,lmax=0,rmax=0,res=0;
	while(l<=r){
		if(arr[l]<arr[r]){
			if(arr[l]>lmax) lmax=arr[l];
			else res += lmax-arr[l];
			l++;
		}else{
			if(arr[r]>rmax) rmax=arr[r];
			else res += rmax-arr[r];
			r--;
		}
	}
	return res;
}
// Method 4:Here another efficient solution has been shown.

// Approach : The concept here is that if there is a larger wall to the right then the water can be retained with height equal to the smaller wall on the left. 
// If there are no larger walls to the right then start from the left. There must be a larger wall to the left now. Let’s take an example if the heights are {….,3, 2, 1, 4,….}, 
// So here 3 and 4 are boundaries the heights 2 and 1 are submerged and cannot act as boundaries. So at any point or index knowing the previous boundary is sufficient 
// if there is a higher or equal length boundary in the remaining part of the array. If not then traverse the array backwards and now must be a larger wall to the left.
// Algorithm :
// Loop from index 0 to the end of the given array.
// If a wall greater than or equal to the previous wall is encountered then make note of the index of that wall in a var called prev_index.
// Keep adding previous wall’s height minus the current (ith) wall to the variable water.
// Have a temporary variable that stores the same value as water.
// If no wall greater than or equal to the previous wall is found then quit.
// If prev_index < size of the input array then subtract the temp variable from water, and loop from end of the input array to prev_index and find a wall greater than 
// or equal to the previous wall (in this case, the last wall from backwards).

int maxWater(int arr[], int n) 
    { 
        int size = n - 1; 
  
        // Let the first element be stored as 
        // previous, we shall loop from index 1 
        int prev = arr[0]; 
  
        // To store previous wall's index 
        int prev_index = 0; 
        int water = 0; 
  
        // To store the water until a larger wall 
        // is found, if there are no larger walls 
        // then delete temp value from water 
        int temp = 0; 
        for (int i = 1; i <= size; i++) { 
  
            // If the current wall is taller than 
            // the previous wall then make current 
            // wall as the previous wall and its 
            // index as previous wall's index 
            // for the subsequent loops 
            if (arr[i] >= prev) { 
                prev = arr[i]; 
                prev_index = i; 
  
                // Because larger or same height wall is found 
                temp = 0; 
            } 
            else { 
  
                // Since current wall is shorter than 
                // the previous, we subtract previous 
                // wall's height from the current wall's 
                // height and add it to the water 
                water += prev - arr[i]; 
  
                // Store the same value in temp as well 
                // If we dont find any larger wall then 
                // we will subtract temp from water 
                temp += prev - arr[i]; 
            } 
        } 
  
        // If the last wall was larger than or equal 
        // to the previous wall then prev_index would 
        // be equal to size of the array (last element) 
        // If we didn't find a wall greater than or equal 
        // to the previous wall from the left then 
        // prev_index must be less than the index 
        // of the last element 
        if (prev_index < size) { 
  
            // Temp would've stored the water collected 
            // from previous largest wall till the end 
            // of array if no larger wall was found then 
            // it has excess water and remove that 
            // from 'water' var 
            water -= temp; 
  
            // We start from the end of the array, so previous 
            // should be assigned to the last element 
            prev = arr[size]; 
  
            // Loop from the end of array up to the 'previous index' 
            // which would contain the "largest wall from the left" 
            for (int i = size; i >= prev_index; i--) { 
  
                // Right end wall will be definitely smaller 
                // than the 'previous index' wall 
                if (arr[i] >= prev) { 
                    prev = arr[i]; 
                } 
                else { 
                    water += prev - arr[i]; 
                } 
            } 
        } 
  
        // Return the maximum water 
        return water; 
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
		cout<<trappingwater(arr);
	}
	return 0;
}