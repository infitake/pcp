#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Method 1:

// The elements in the array is from 0 to n-1 and all of them are positive. 
// So to find out the duplicate elements, a HashMap is required,
// but the question is to solve the problem in constant space. 
// There is a catch, the array is of length n and the elements are from 0 to n-1 (n elements).
// The array can be used as a HashMap.

// This approach is good but print duplicate element multiple times
// eg: 1 6 3 1 3 6 6 print 1 3 6 6 
void printRepeating(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
	{ 
	    if (arr[abs(arr[i])] >= 0) 
	    arr[abs(arr[i])] = -arr[abs(arr[i])]; 
	    else
	    cout << abs(arr[i]) << " "; 
	} 
} 

// Method 2:

// The basic idea is to use a HashMap to solve the problem.
// But there is a catch, the numbers in the array are from 0 to n-1, and the input array has length n.
// So, the input array can be used as a HashMap. While Traversing the array, 
// if an element ‘a’ is encountered then increase the value of a%n‘th element by n.
// The frequency can be retrieved by dividing the a % n’th element by n.

// This approach is good but order of element is not maintain
// eg: 3 6 3 1 4 1 6 print 1 3 6 ans is :3 1 6
void printRepeating( int arr[], int n) 
{ 
    // First check all the values that are 
    // present in an array then go to that 
    // values as indexes and increment by 
    // the size of array 
    for (int i = 0; i < n; i++) 
    { 
        int index = arr[i] % n; 
        arr[index] += n; 
    } 
  
    // Now check which value exists more 
    // than once by dividing with the size 
    // of array 
    for (int i = 0; i < n; i++) 
    { 
        if ((arr[i]/n) > 1) 
            cout << i << " "; 
    } 
}

// Method 3:
void printRepeating(int arr[], int n) 
{ 
    int i; 
  
    // Flag variable used to 
    // represent whether repeating 
    // element is found or not. 
    int fl = 0; 
  
    for (i = 0; i < n; i++) { 
  
        // Check if current element is 
        // repeating or not. If it is 
        // repeating then value will 
        // be greater than or equal to n. 
        if (arr[arr[i] % n] >= n) { 
  
            // Check if it is first 
            // repetition or not. If it is 
            // first repetition then value 
            // at index arr[i] is less than 
            // 2*n. Print arr[i] if it is 
            // first repetition. 
            if (arr[arr[i] % n] < 2 * n) { 
                cout << arr[i] % n << " "; 
                fl = 1; 
            } 
        } 
  
        // Add n to index arr[i] to mark 
        // presence of arr[i] or to 
        // mark repetition of arr[i]. 
        arr[arr[i] % n] += n; 
    } 
  
    // If flag variable is not set 
    // then no repeating element is 
    // found. So print -1. 
    if (!fl) 
        cout << "-1"; 
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
		printRepeating(arr,n);
		cout<<endl;
	}
	return 0;
}