#include <bits/stdc++.h>
using namespace std;
int nextgap(int gap){
	if(gap<=1) return 0;
	return gap/2 + gap%2;
}

// this find the solution in O(1) space
int k2sort(vector<int> &arr1,vector<int> &arr2,int n,int m,int k){
	int i,j,gap=n+m;
	for(gap = nextgap(gap);gap>0;gap=nextgap(gap)){
		// for first array
		for(i=0;i+gap<n;i++){
			if(arr1[i]>arr1[i+gap]) swap(arr1[i],arr1[i+gap]);
		}

		// gap b/w both array;

		for(j=(gap>n)?gap-n:0;i<n&&j<m;i++,j++){
			if(arr1[i]>arr2[j]) swap(arr1[i],arr2[j]);
		}

		// in last array
		if(j<m){
			for(j=0;j+gap<m;j++){
				if(arr2[j]>arr2[j+gap]) swap(arr2[j],arr2[j+gap]);
			}
		}
	}
	for(i=0;i<n;i++){
		if(k==1) return arr1[i];
		k--;
	}
	for(i=0;i<m;i++){
		if(k==1) return arr2[i];
		k--;
	}
	return -1;
}

// Method 2:
int find(int A[], int B[], int m,  
         int n, int k_req)  
{ 
    int k = 0, i = 0, j = 0; 
  
    // Keep taking smaller of the current 
    // elements of two sorted arrays and 
    // keep incrementing k 
    while(i < m && j < n) 
    { 
        if(A[i] < B[j])  
        { 
            k++; 
            if(k == k_req) 
                return A[i]; 
            i++; 
        }  
        else
        { 
            k++; 
            if(k == k_req) 
                return B[j]; 
            j++; 
        } 
    } 
  
    // If array B[] is completely traversed 
    while(i < m)  
    { 
        k++; 
        if(k == k_req) 
            return A[i]; 
        i++; 
    } 
  
    // If array A[] is completely traversed 
    while(j < n)  
    { 
        k++; 
        if(k == k_req) 
            return B[j]; 
        j++; 
    } 
}  
// Method 3:
// While the above implementation is very efficient, we can still get away with making it more efficient. 
// Instead of dividing the array into segments of n / 2 and m / 2 then recursing, we can divide them both by k / 2 and recurse.

// Explanation:
// Instead of comparing the middle element of the arrays,
// we compare the k / 2nd element.
// Let arr1 and arr2 be the arrays.
// Now, if arr1[k / 2]  arr1[1]

// New subproblem:
// Array 1 - 6 7 9
// Array 2 - 1 4 8 10
// k = 5 - 2 = 3

// floor(k / 2) = 1
// arr1[1] = 6
// arr2[1] = 1
// arr1[1] > arr2[1]

// New subproblem:
// Array 1 - 6 7 9
// Array 2 - 4 8 10
// k = 3 - 1 = 2

// floor(k / 2) = 1
// arr1[1] = 6
// arr2[1] = 4
// arr1[1] > arr2[1]

// New subproblem:
// Array 1 - 6 7 9
// Array 2 - 8 10
// k = 2 - 1 = 1

// Now, we directly compare first elements,
// since k = 1. 
// arr1[1] < arr2[1]
// Hence, arr1[1] = 6 is the answer.

int kth(int arr1[], int arr2[], int m, int n, int k, 
                           int st1 = 0, int st2 = 0) 
{ 
    // In case we have reached end of array 1 
    if (st1 == m) 
        return arr2[st2 + k - 1]; 
  
    // In case we have reached end of array 2 
    if (st2 == n) 
        return arr1[st1 + k - 1]; 
  
    // k should never reach 0 or exceed sizes 
    // of arrays 
    if (k == 0 || k > (m - st1) + (n - st2)) 
        return -1; 
  
    // Compare first elements of arrays and return 
    if (k == 1) 
        return (arr1[st1] < arr2[st2]) ? 
            arr1[st1] : arr2[st2]; 
    int curr = k / 2; 
  
    // Size of array 1 is less than k / 2 
    if (curr - 1 >= m - st1) 
    { 
        // Last element of array 1 is not kth 
        // We can directly return the (k - m)th 
        // element in array 2 
        if (arr1[m - 1] < arr2[st2 + curr - 1]) 
            return arr2[st2 + (k - (m - st1) - 1)]; 
        else
            return kth(arr1, arr2, m, n, k - curr, 
                st1, st2 + curr); 
    } 
  
    // Size of array 2 is less than k / 2 
    if (curr-1 >= n-st2) 
    { 
        if (arr2[n - 1] < arr1[st1 + curr - 1]) 
            return arr1[st1 + (k - (n - st2) - 1)]; 
        else
            return kth(arr1, arr2, m, n, k - curr, 
                st1 + curr, st2); 
    } 
    else
    { 
        // Normal comparison, move starting index 
        // of one array k / 2 to the right 
        if (arr1[curr + st1 - 1] < arr2[curr + st2 - 1]) 
            return kth(arr1, arr2, m, n, k - curr, 
                st1 + curr, st2); 
        else
            return kth(arr1, arr2, m, n, k - curr, 
                st1, st2 + curr); 
    } 
}

//Method 4:
// Now, k can take a maximum value of m + n. This means that log k can be in the worst case, log(m + n). Logm + logn = log(mn) by properties of logarithms, 
// and when m, n > 2, log(m + n) < log(mn). 
// Thus this algorithm slightly outperforms the previous algorithm.
int kth(int arr1[], int m, int arr2[], int n, int k) 
{ 
      
  if (k > (m+n) || k < 1) return -1; 
    
  // let m <= n 
  if (m > n) return kth(arr2, n, arr1, m, k); 
    
  // if arr1 is empty returning k-th element of arr2 
  if (m == 0) return arr2[k - 1]; 
    
  // if k = 1 return minimum of first two elements of both arrays  
  if (k == 1) return min(arr1[0], arr2[0]); 
    
  // now the divide and conquer part 
  int i = min(m, k / 2), j = min(n, k / 2); 
    
  if (arr1[i - 1] > arr2[j - 1] )  
    // Now we need to find only k-j th element since we have found out the lowest j 
    return kth(arr1, m, arr2 + j, n - j, k - j); 
  else 
    // Now we need to find only k-i th element since we have found out the lowest i 
    return kth(arr1 + i, m - i, arr2, n, k - i); 
} 


int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,k,m; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<int> arr1,arr2;
		for(int i=0;i<n;i++){
			cin>>a;
			arr1.push_back(a);
		}
		for(int i=0;i<m;i++){
			cin>>a;
			arr2.push_back(a);
		}
		cin>>k;
		cout<<k2sort(arr1,arr2,n,m,k)<<endl;
	}
	return 0;
}