// A divide and conquer based 
// efficient solution to find 
// median of two sorted arrays 
// of same size. 
public double findMedianSortedArrays(int[] a, int[] b, int startIndexA, int endIndexA, int startIndexB, int endIndexB)
	    {
	       
	        if ((endIndexA - startIndexA < 0) || ((endIndexB - startIndexB < 0)))
	        {
	            System.out.println("Invalid Input." );
	            return ERROR_INVALID_INPUT;
	        }
	
	        if ((endIndexA - startIndexA == 0) && ((endIndexB - startIndexB == 0)))
	        {
	            return (a[0] + b[0])/2;
	        }
	        
	        if ((endIndexA - startIndexA == 1) && ((endIndexB - startIndexB == 1)))
	        {
	            return (1.0*(max(a[startIndexA], b[startIndexB]) + min(a[endIndexA], b[endIndexB])))/2;
	        }
	         
	        double m1 = findMedian(a, startIndexA, endIndexA);
	        double m2 = findMedian(b, startIndexB, endIndexB);
	         
	        if (m2 == m1)
	        {
	            return m2;
	        }
	         
	         
	        if (m1 < m2)
	        {
	            if ((endIndexA - startIndexA) % 2 == 0)  
	            {
	                startIndexA = startIndexA + (endIndexA - startIndexA) / 2;
	                endIndexB = startIndexB + (endIndexB - startIndexB) / 2;
	            }
	            else
	            {
	                startIndexA = startIndexA + (endIndexA - startIndexA) / 2;
	                endIndexB = startIndexB + (endIndexB - startIndexB) / 2 + 1;                
	            }
	        }
	         
	         
	        else  
	        {
	            if ((endIndexB - startIndexB) % 2 == 0)  
	            {
	                startIndexB = startIndexB + (endIndexB - startIndexB) / 2;
	                endIndexA = startIndexA + (endIndexA - startIndexA) / 2;
	            }
	            else
	            {
	                startIndexB = startIndexB + (endIndexB - startIndexB) / 2;
	                endIndexA = startIndexA + (endIndexA - startIndexA) / 2 + 1;                
            }
	        }	        return findMedianSortedArrays(a, b, startIndexA, endIndexA, startIndexB, endIndexB);
	    }

// Use merge procedure of merge sort. Keep track of count while comparing elements of two arrays. 
// If count becomes n(For 2n elements), we have reached the median. 
// Take the average of the elements at indexes n-1 and n in the merged array.

// A Simple Merge based O(n) 
// solution to find median of 
// two sorted arrays 
#include <bits/stdc++.h> 
using namespace std; 

/* This function returns 
median of ar1[] and ar2[]. 
Assumptions in this function: 
Both ar1[] and ar2[] 
are sorted arrays 
Both have n elements */
int getMedian(int ar1[], 
			int ar2[], int n) 
{ 
	int i = 0; /* Current index of 
				i/p array ar1[] */
	int j = 0; /* Current index of 
				i/p array ar2[] */
	int count; 
	int m1 = -1, m2 = -1; 

	/* Since there are 2n elements, 
	median will be average of elements 
	at index n-1 and n in the array 
	obtained after merging ar1 and ar2 */
	for (count = 0; count <= n; count++) 
	{ 
		/* Below is to handle case where 
		all elements of ar1[] are 
		smaller than smallest(or first) 
		element of ar2[]*/
		if (i == n) 
		{ 
			m1 = m2; 
			m2 = ar2[0]; 
			break; 
		} 

		/*Below is to handle case where 
		all elements of ar2[] are 
		smaller than smallest(or first) 
		element of ar1[]*/
		else if (j == n) 
		{ 
			m1 = m2; 
			m2 = ar1[0]; 
			break; 
		} 
		/* equals sign because if two 
		arrays have some common elements */
		if (ar1[i] <= ar2[j]) 
		{ 
			/* Store the prev median */
			m1 = m2; 
			m2 = ar1[i]; 
			i++; 
		} 
		else
		{ 
			/* Store the prev median */
			m1 = m2; 
			m2 = ar2[j]; 
			j++; 
		} 
	} 

	return (m1 + m2)/2; 
} 

// Driver Code 
int main() 
{ 
	int ar1[] = {1, 12, 15, 26, 3}; 
	int ar2[] = {2, 13, 1, 30, 45}; 

	int n1 = sizeof(ar1) / sizeof(ar1[0]); 
	int n2 = sizeof(ar2) / sizeof(ar2[0]); 
	if (n1 == n2) 
		cout << "Median is "
			<< getMedian(ar1, ar2, n1) ; 
	else
		cout << "Doesn't work for arrays"
			<< " of unequal size" ; 
	getchar(); 
	return 0; 
} 

// This code is contributed 
// by Shivi_Aggarwal 


// 1) Calculate the medians m1 and m2 of the input arrays ar1[] 
//    and ar2[] respectively.
// 2) If m1 and m2 both are equal then we are done.
//      return m1 (or m2)
// 3) If m1 is greater than m2, then median is present in one 
//    of the below two subarrays.
//     a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
//     b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
// 4) If m2 is greater than m1, then median is present in one    
//    of the below two subarrays.
//    a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
//    b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
// 5) Repeat the above process until size of both the subarrays 
//    becomes 2.
// 6) If size of the two arrays is 2 then use below formula to get 
//   the median.
//     Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
// Examples :

//    ar1[] = {1, 12, 15, 26, 3}
//    ar2[] = {2, 13, 1, 30, 45}
// For above two arrays m1 = 15 and m2 = 1

// For the above ar1[] and ar2[], m1 is smaller than m2. So median is present in one of the following two subarrays.

//    [15, 26, 3] and [2, 13, 1]
// Let us repeat the process for above two subarrays:

//     m1 = 26 m2 = 13.
// m1 is greater than m2. So the subarrays become

//   [15, 26] and [13, 1]
// Now size is 2, so median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
//                        = (max(15, 13) + min(26, 1))/2 
//                        = (15 + 1)/2
//                        = 16


// Method 2:

#include<bits/stdc++.h> 
using namespace std; 

/* to get median of a 
sorted array */
int median(int [], int); 

/* This function returns median 
of ar1[] and ar2[]. 
Assumptions in this function: 
	Both ar1[] and ar2[] are 
	sorted arrays 
	Both have n elements */
int getMedian(int ar1[], 
			int ar2[], int n) 
{ 
	/* return -1 for 
	invalid input */
	if (n <= 0) 
		return -1; 
	if (n == 1) 
		return (ar1[0] + 
				ar2[0]) / 2; 
	if (n == 2) 
		return (max(ar1[0], ar2[0]) + 
				min(ar1[1], ar2[1])) / 2; 

	/* get the median of 
	the first array */
	int m1 = median(ar1, n); 
	
	/* get the median of 
	the second array */
	int m2 = median(ar2, n); 

	/* If medians are equal then 
	return either m1 or m2 */
	if (m1 == m2) 
		return m1; 

	/* if m1 < m2 then median must 
	exist in ar1[m1....] and 
				ar2[....m2] */
	if (m1 < m2) 
	{ 
		if (n % 2 == 0) 
			return getMedian(ar1 + n / 2 - 1, 
							ar2, n - n / 2 + 1); 
		return getMedian(ar1 + n / 2, 
						ar2, n - n / 2); 
	} 

	/* if m1 > m2 then median must 
	exist in ar1[....m1] and 
				ar2[m2...] */
	if (n % 2 == 0) 
		return getMedian(ar2 + n / 2 - 1, 
						ar1, n - n / 2 + 1); 
	return getMedian(ar2 + n / 2, 
					ar1, n - n / 2); 
} 

/* Function to get median 
of a sorted array */
int median(int arr[], int n) 
{ 
	if (n % 2 == 0) 
		return (arr[n / 2] + 
				arr[n / 2 - 1]) / 2; 
	else
		return arr[n / 2]; 
} 

// Driver code 
int main() 
{ 
	int ar1[] = {1, 2, 3, 6}; 
	int ar2[] = {4, 6, , 10}; 
	int n1 = sizeof(ar1) / 
			sizeof(ar1[0]); 
	int n2 = sizeof(ar2) / 
			sizeof(ar2[0]); 
	if (n1 == n2) 
		cout << "Median is "
			<< getMedian(ar1, ar2, n1); 
	else
		cout << "Doesn't work for arrays "
			<< "of unequal size"; 
	return 0; 
} 

// Time Complexity : O(logn)


// Method 3:

// Approach : Start partitioning the two arrays into two groups of halves (not two parts, but both partitioned should have same number of elements). The first half contains some first elements from the first and the second arrays, and the second half contains the rest (or the last) elements form the first and the second arrays. Because the arrays can be of different sizes, it does not mean to take every half from each array. The below example clarifies the explanation. Reach a condition such that, every element in the first half is less than or equal to every element in the second half.

// How to reach this condition ?
// Example in the case of even numbers. Suppose, partition is found. Because A[] and B[] are two sorted arrays, a1 is less than or equal to a2, and b2 is less than or equal to b3. Now, to check if a1 is less than or equal to b3, and if b2 is less than or equal to a2. If that’s the case, it means that every element in the first half is less than or equal to every element in the second half, because, a1 is greater than or equal to every element before it (a0) in A[], and b2 is greater than or equal to every element before it (b1 and b0) in B[]. In case of even numbers in total the median will be the average between max of a1, b2 and the min of a2, b3, but in case of odd numbers in total the median will be the max of a2, b2. But if it is not these two cases, there are two options (in referring to the even numbers example) :
// b2 > a2 or a1 > b3
// if, b2 > a2 it means that, search on the right side of the array, and if a1 > b3 it means that, search on the left side of the array, until desired condition is found.


// Why the above condition leads to the median ?
// The median is the (n + 1) / 2 smallest element of the array, and here, the median is the (n + m + 1) / 2 smallest element among the two arrays. If, all the elements in the first half are less than (or equal) to all elements in the second half, in case of odd numbers in total, just calculate the maximum between the last two elements in the first half (a2 and b2 in our example),and this will lead us to the (n + m + 1) / 2 smallest element among the two arrays, which is the median (( + 4 + 1) / 2 = 6). But in case of even numbers in total, calculate the average between the maximum of the last two elements in the first half (a1 and b2 in our example) with its successive number among the arrays which is the minimum of first two elements in the second half (a2 and b3 in our example).

// The process of the partition :
// To make two halves, make the partition such that the index that partitioning array A[] + the index that partitioning array B[] are equal to the total number of elements plus one divided by 2, i.e. (n + m + 1) / 2 (+1 is, if the total number of elements is odd).
// First, define two variables : min_index and max_index, and initialize min_index to 0, and max_index to the length of the smaller array. In these below examples A[] is the smaller array.
// To partition A[], use the formula (min_index + max_index) / 2 and insert it to a variable i. To partition B[], use the formula (n + m + 1) / 2 – i and insert it to a variable j.
// the variable i means the number of elements to be inserted from A[] into the first half, and j means the number of elements to be inserted from B[] into the first half, the rest of the elements will be inserted into the second half.

// CPP code for median with case of returning 
// double value when even number of elements are 
// present in both array combinely 
#include<bits/stdc++.h> 
using std::cout; 

int maximum(int a, int b); 
int minimum(int a, int b); 

// Function to find median of two sorted arrays 
double findMedianSortedArrays(int *a, int n, 
							int *b, int m) 
{ 
	
	int min_index = 0, max_index = n, i, j, median; 
	
	while (min_index <= max_index) 
	{ 
		i = (min_index + max_index) / 2; 
		j = ((n + m + 1) / 2) - i; 
		
		// If j is negative then the partition is not 
		// possible having i elements from array i 
		if (j < 0) 
		{ 
			max_index = i-1; 
			continue; 
		} 

		// if i = n, it means that Elements from a[] in 
		// the second half is an empty set. and if j = 0, 
		// it means that Elements from b[] in the first 
		// half is an empty set. so it is necessary to 
		// check that, because we compare elements from 
		// these two groups. 
		// Searching on right 
		if (i < n && j > 0 && b[j - 1] > a[i])		 
			min_index = i + 1; 
				
		// if i = 0, it means that Elements from a[] in 
		// the first half is an empty set and if j = m, 
		// it means that Elements from b[] in the second 
		// half is an empty set. so it is necessary to 
		// check that, because we compare elements 
		// from these two groups. 
		// searching on left 
		else if (i > 0 && j < m && b[j] < a[i - 1])		 
			max_index = i - 1; 

		// we have found the desired halves. 
		else
		{ 
			// this condition happens when we don't have any 
			// elements in the first half from a[] so we 
			// returning the last element in b[] from 
			// the first half. 
			if (i == 0)			 
				median = b[j - 1];			 
			
			// and this condition happens when we don't 
			// have any elements in the first half from 
			// b[] so we returning the last element in 
			// a[] from the first half. 
			else if (j == 0)			 
				median = a[i - 1];			 
			else			
				median = maximum(a[i - 1], b[j - 1]);			 
			break; 
		} 
	} 
	
	// calculating the median. 
	// If number of elements is odd there is 
	// one middle element. 
	if ((n + m) % 2 == 1) 
		return (double)median; 
		
	// Elements from a[] in the second half is an empty set.	 
	if (i == n) 
		return (median+b[j]) / 2.0; 
		
	// Elements from b[] in the second half is an empty set. 
	if (j == m) 
		return (median + a[i]) / 2.0; 
	
	return (median + minimum(a[i], b[j])) / 2.0; 
} 

// Function to find max 
int maximum(int a, int b) 
{ 
	return a > b ? a : b; 
} 

// Function to find minimum 
int minimum(int a, int b) 
{ 
	return a < b ? a : b; 
} 

// Driver code 
int main() 
{ 
	int a[] = {900}; 
	int b[] = { 10, 13, 14}; 
	int n = sizeof(a) / sizeof(int); 
	int m = sizeof(b) / sizeof(int); 
	
	// we need to define the smaller array as the 
	// first parameter to make sure that the 
	// time complexity will be O(log(min(n,m))) 
	if (n < m) 
		cout << "The median is : "
			<< findMedianSortedArrays(a, n, b, m); 
	else
		cout << "The median is : "
			<< findMedianSortedArrays(b, m, a, n); 

	return 0; 
} 

// Another Approach : Same program, but returns the median that exist in the merged array((n + m) / 2 – 1 position):

// CPP code for finding median of the given two 
// sorted arrays that exists in the merged array ((n+m) / 2 - 1 position) 
#include<bits/stdc++.h> 
using std::cout; 

int maximum(int a, int b); 

// Function to find median of given two sorted arrays 
int findMedianSortedArrays(int *a, int n, 
						int *b, int m) 
{ 
	
	int min_index = 0, max_index = n, i, j; 
	
	while (min_index <= max_index) 
	{ 
		i = (min_index + max_index) / 2; 
		j = ((n + m + 1) / 2) - i; 
	
		// if i = n, it means that Elements from a[] in 
		// the second half is an empty set. If j = 0, it 
		// means that Elements from b[] in the first half 
		// is an empty set. so it is necessary to check that, 
		// because we compare elements from these two groups. 
		// searching on right 
		if (i < n && j > 0 && b[j - 1] > a[i])		 
			min_index = i + 1;		 
		
		// if i = 0, it means that Elements from a[] in the 
		// first half is an empty set and if j = m, it means 
		// that Elements from b[] in the second half is an 
		// empty set. so it is necessary to check that, 
		// because we compare elements from these two groups. 
		// searching on left 
		else if (i > 0 && j < m && b[j] < a[i - 1])		 
			max_index = i - 1;		 
		
		// we have found the desired halves. 
		else
		{ 
			// this condition happens when we don't have 
			// any elements in the first half from a[] so 
			// we returning the last element in b[] from 
			// the first half. 
			if (i == 0)			 
				return b[j - 1];			 
			
			// and this condition happens when we don't have any 
			// elements in the first half from b[] so we 
			// returning the last element in a[] from the first half. 
			if (j == 0)			 
				return a[i - 1];			 
			else			
				return maximum(a[i - 1], b[j - 1]);		 
		} 
	} 
	
	cout << "ERROR!!! " << "returning\n";	 
	return 0; 
} 

// Function to find maximum 
int maximum(int a, int b) 
{ 
	return a > b ? a : b; 
} 

// Driver code 
int main() 
{ 
	int a[] = {900}; 
	int b[] = { 10,13,14}; 
	int n = sizeof(a) / sizeof(int); 
	int m = sizeof(b) / sizeof(int); 
	
	// we need to define the smaller array as the first 
	// parameter to make sure that the time complexity 
	// will be O(log(min(n,m))) 
	if (n < m) 
		cout << "The median is: "
			<< findMedianSortedArrays(a, n, b, m); 
	else
		cout << "The median is: "
			<< findMedianSortedArrays(b, m, a, n); 
	return 0; 
} 


// Time Complexity : O(log(min(n, m))), where n and m are the sizes of given sorted array