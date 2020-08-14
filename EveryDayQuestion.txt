								Take you forward every solution 
Day1

1.find duplicate in a array
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

2 . Sort an array of 0’s 1’s 2’s without using extra space or sorting algo
#include <bits/stdc++.h>
using namespace std;

// Method 1:
void sort012(int arr[],int n){
	int c0=0,c1=0,c2=0;
	for(int i=0;i<n;i++){
		if(arr[i]==0) c0++;
		else if(arr[i]==1) c1++;
		else if(arr[i]==2) c2++; 
	}
	for(int i=0;i<n;i++){
		if(c0>0){
			arr[i]=0;
			c0--;
		}else if(c1>0){
			arr[i]=1;
			c1--;
		}else if(c2>0){
			arr[i]=2;
			c2--;
		}
	}
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

// Method 2:
// Dutch National Flag Algorithm OR 3-way Partitioning:
// At first, the full array is unknown. There are three indices – low, mid and high. Initially, the value of low = mid = 1 and high = N.
// If the ith element is 0 then swap the element to the low range, thus shrinking the unknown range.
// Similarly, if the element is 1 then keep it as it is but shrink the unknown range.
// If the element is 2 then swap it with an element in high range.
void sort012(int a[], int arr_size) 
{ 
    int lo = 0; 
    int hi = arr_size - 1; 
    int mid = 0; 
  
    // Iterate till all the elements 
    // are sorted 
    while (mid <= hi) { 
        switch (a[mid]) { 
  
        // If the element is 0 
        case 0: 
            swap(a[lo++], a[mid++]); 
            break; 
  
        // If the element is 1 . 
        case 1: 
            mid++; 
            break; 
  
        // If the element is 2 
        case 2: 
            swap(a[mid], a[hi--]); 
            break; 
        } 
    } 
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
		sort012(arr,n);
		cout<<endl;
	}
	return 0;
}


3. Finding Missing and repeating no
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Method 1:
// using duplicate number approach
void missingandrepeat(ll arr[], ll n){
   ll repat=INT_MAX;
   for(ll i=0;i<n;i++){
       if(arr[abs(arr[i])-1]>0){
           arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
       }
       else{
           if(repat>abs(arr[i])) repat = abs(arr[i]);
       }
   }
   cout<<repat<<" ";
   for(ll i=0;i<n;i++){
       if(arr[i]>0) {cout<<i+1<< " "; break;}
   }
}

// Method 2: (using equations)
// Approach: From the sum of first N natural numbers,

// SumN = 1 + 2 + 3 + … + N = (N * (N + 1)) / 2
// And, let the sum of all the array elements be Sum. Now,
// SumN = Sum – A + B
// A – B = Sum – SumN …(equation 1)

// And from the sum of the squares of first N natural numbers,

// SumSqN = 12 + 22 + 32 + … + N2 = (N * (N + 1) * (2 * n + 1)) / 6
// And, let the sum of the squares of all the array elements be SumSq. Now,
// SumSq = SumSqN + A2 – B2
// SumSq – SumSqN = (A + B) * (A – B) …(equation 2)

// Put value of (A – B) from equation 1 in equation 2,

// SumSq – SumSqN = (A + B) * (Sum – SumN)
// A + B = (SumSq – SumSqN) / (Sum – SumN) …(equation 3)

// Solving equation 1 and equation 3 will give,

// B = (((SumSq – SumSqN) / (Sum – SumN)) + SumN – Sum) / 2
// And, A = Sum – SumN + B

void missingandrepeat(int arr[], int n) 
    { 
  
        // Sum of first n natural numbers 
        int sumN = (n * (n + 1)) / 2; 
  
        // Sum of squares of first n natural numbers 
        int sumSqN = (n * (n + 1) * (2 * n + 1)) / 6; 
  
        // To store the sum and sum of squares 
        // of the array elements 
        int sum = 0, sumSq = 0, i; 
  
        for (i = 0; i < n; i++) { 
            sum += arr[i]; 
            sumSq = sumSq + (pow(arr[i], 2)); 
        } 
  
        int B = (((sumSq - sumSqN) / (sum - sumN)) + sumN - sum) / 2; 
        int A = sum - sumN + B; 
         cout << "A = " ; 
         cout << A << endl; 
         cout << "B = " ; 
         cout << B << endl; 
} 

// Method 3 (Make two equations)
// Approach:
// Let x be the missing and y be the repeating element.
// Get the sum of all numbers using formula S = n(n+1)/2 – x + y
// Get product of all numbers using formula P = 1*2*3*…*n * y / x
// The above two steps give us two equations, we can solve the equations and get the values of x and y.

// Note: This method can cause arithmetic overflow as we calculate product and sum of all array elements.

// Method 4 (Use XOR)
// Approach:

// Let x and y be the desired output elements.
// Calculate XOR of all the array elements.
// xor1 = arr[0]^arr[1]^arr[2]…..arr[n-1]

// XOR the result with all numbers from 1 to n
// xor1 = xor1^1^2^…..^n

// In the result xor1, all elements would nullify each other except x and y. 
// All the bits that are set in xor1 will be set in either x or y. So if we take any set bit (We have chosen the rightmost set bit in code) of 
// xor1 and divide the elements of the array in two sets – one set of elements with same bit set and other set with same bit not set. By doing so,
//  we will get x in one set and y in another set. 
// Now if we do XOR of all the elements in first set, 
// we will get x, and by doing same in other set we will get y..

void missingandrepeat(ll arr[], ll n) 
{ 
    /* Will hold xor of all elements  
    and numbers from 1 to n */
    ll xor1; 
  
    /* Will have only single set bit of xor1 */
    ll set_bit_no; 
    ll x,y;
    ll i; 
    x = 0; 
    y = 0; 
  
    xor1 = arr[0]; 
  
    /* Get the xor of all array elements */
    for (i = 1; i < n; i++) 
        xor1 = xor1 ^ arr[i]; 
  
    /* XOR the previous result with numbers  
    from 1 to n*/
    for (i = 1; i <= n; i++) 
        xor1 = xor1 ^ i; 
  
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1); 
  
    /* Now divide elements into two  
    sets by comparing a rightmost set 
    bit of xor1 with the bit at the same  
    position in each element. Also,  
    get XORs of two sets. The two 
    XORs are the output elements.  
    The following two for loops  
    serve the purpose */
    for (i = 0; i < n; i++) { 
        if (arr[i] & set_bit_no) 
            /* arr[i] belongs to first set */
            x = x ^ arr[i]; 
  
        else
            /* arr[i] belongs to second set*/
            y = y ^ arr[i]; 
    } 
    for (i = 1; i <= n; i++) { 
        if (i & set_bit_no) 
            /* i belongs to first set */
            x = x ^ i; 
  
        else
            /* i belongs to second set*/
            y = y ^ i; 
    } 
  
    /* *x and *y hold the desired 
        output elements */
    cout<<y<<" "<<x;
}
int main()
{
  #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    ll t,n; cin>>t;
    while(t--) {
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        missingandrepeat(arr,n);
        cout<<endl;
    }
}

4.kadanes Algo
#include <bits/stdc++.h>
using namespace std;

// Method 1:(simple traversing and get max sum) 
void kadanes(int arr[],int n){
	int sum=0,max = INT_MIN;
	for(int i=0;i<n;i++){
		sum += arr[i];
		if(sum<0) sum = 0;
		else if(sum > max) max = sum;
	}
	cout<<max<<endl;
}

// Method 2:(print max sum with start and last index)
void kadanes(int arr[],int n){
	int sum=0,max = INT_MIN,start=0,last=0,s=0;
	for(int i=0;i<n;i++){
		sum += arr[i];
		if(sum<0){
			sum=0;
			s=i+1;
			// start = i+1;	
			// last = i+1;
		}
		else if(sum > max){
			max = sum;
			last=i;
			start=s;
		} 
	}
	cout<<max<<" "<<start<<" "<<last<<endl;
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
		kadanes(arr,n);
	}
	return 0;
}

5. find repeating element in array in O(n) & O(1) time
#include <bits/stdc++.h>
using namespace std;

// Method 1 (Make two equations)
// Let the numbers which are being repeated are X and Y. We make two equations for X and Y and the simple task left is to solve the two equations.
// We know the sum of integers from 1 to n is n(n+1)/2 and product is n!. We calculate the sum of input array, when this sum is subtracted from n(n+1)/2, we get X + Y because X and Y are the two numbers missing from set [1..n]. Similarly calculate product of input array, when this product is divided from n!, we get X*Y. Given sum and product of X and Y, we can find easily out X and Y.

// Let summation of all numbers in array be S and product be P

// X + Y = S – n(n+1)/2
// XY = P/n!

// Using above two equations, we can find out X and Y. For array = 4 2 4 5 2 3 1, we get S = 21 and P as 960.

// X + Y = 21 – 15 = 6

// XY = 960/5! = 8

// X – Y = sqrt((X+Y)^2 – 4*XY) = sqrt(4) = 2

// Using below two equations, we easily get X = (6 + 2)/2 and Y = (6-2)/2
// X + Y = 6
// X – Y = 2

int fact(int n)  
{  
    return (n == 0)? 1 : n*fact(n-1);  
} 

void printRepeating(int arr[], int size)  
{  
    int S = 0; /* S is for sum of elements in arr[] */
    int P = 1; /* P is for product of elements in arr[] */
    int x, y; /* x and y are two repeating elements */
    int D; /* D is for difference of x and y, i.e., x-y*/
    int n = size - 2, i;  
      
    /* Calculate Sum and Product of all elements in arr[] */
    for(i = 0; i < size; i++)  
    {  
        S = S + arr[i];  
        P = P*arr[i];  
    }      
          
    S = S - n*(n+1)/2; /* S is x + y now */
    P = P/fact(n);     /* P is x*y now */
          
    D = sqrt(S*S - 4*P); /* D is x - y now */
          
    x = (D + S)/2;  
    y = (S - D)/2;  
          
    cout<<x<<" "<<y;  
}  

// Method 2 (Use XOR)
// Let the repeating numbers be X and Y, 
// if we xor all the elements in the array and all integers from 1 to n, 
// then the result is X xor Y.
// The 1’s in binary representation of X xor Y is corresponding to the different bits between X and Y. 
// Suppose that the kth bit of X xor Y is 1, we can xor all the elements in the array and all integers from 1 to n,
//  whose kth bits are 1. The result will be one of X and Y.

void printRepeating(int arr[], int size)  
{  
    int Xor = arr[0]; /* Will hold Xor of all elements */
    int set_bit_no; /* Will have only single set bit of Xor */
    int i;  
    int n = size - 2;  
    int x = 0, y = 0;  
          
    /* Get the Xor of all elements in arr[] and {1, 2 .. n} */
    for(i = 1; i < size; i++)  
        Xor ^= arr[i];  
    for(i = 1; i <= n; i++)  
        Xor ^= i;  
      
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = Xor & ~(Xor-1);  
      
    /* Now divide elements in two sets by comparing rightmost set  
    bit of Xor with bit at same position in each element. */
    for(i = 0; i < size; i++)  
    {  
        if(arr[i] & set_bit_no)  
        x = x ^ arr[i]; /*Xor of first set in arr[] */
        else
        y = y ^ arr[i]; /*Xor of second set in arr[] */
    }  
    for(i = 1; i <= n; i++)  
    {  
        if(i & set_bit_no)  
        x = x ^ i; /*Xor of first set in arr[] and {1, 2, ...n }*/
        else
        y = y ^ i; /*Xor of second set in arr[] and {1, 2, ...n } */
    }  
          
    cout<<y<<" "<<x;  
}  

// Method 3:


void printRepeating(int arr[], int size)  
{  
    int i;    
          
    for(i = 0; i < size; i++)  
    {  
        if(arr[abs(arr[i])] > 0)  
            arr[abs(arr[i])] = -arr[abs(arr[i])];  
        else
            cout<<" " << abs(arr[i]) <<" ";  
    }      
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
	}
	return 0;
}

6. Median of Array
// A divide and conquer based 
// efficient solution to find 
// median of two sorted arrays 
// of same size. 


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
	int ar1[] = {1, 12, 15, 26, 38}; 
	int ar2[] = {2, 13, 17, 30, 45}; 

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

//    ar1[] = {1, 12, 15, 26, 38}
//    ar2[] = {2, 13, 17, 30, 45}
// For above two arrays m1 = 15 and m2 = 17

// For the above ar1[] and ar2[], m1 is smaller than m2. So median is present in one of the following two subarrays.

//    [15, 26, 38] and [2, 13, 17]
// Let us repeat the process for above two subarrays:

//     m1 = 26 m2 = 13.
// m1 is greater than m2. So the subarrays become

//   [15, 26] and [13, 17]
// Now size is 2, so median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
//                        = (max(15, 13) + min(26, 17))/2 
//                        = (15 + 17)/2
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
	int ar2[] = {4, 6, 8, 10}; 
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
// The median is the (n + 1) / 2 smallest element of the array, and here, the median is the (n + m + 1) / 2 smallest element among the two arrays. If, all the elements in the first half are less than (or equal) to all elements in the second half, in case of odd numbers in total, just calculate the maximum between the last two elements in the first half (a2 and b2 in our example),and this will lead us to the (n + m + 1) / 2 smallest element among the two arrays, which is the median ((7 + 4 + 1) / 2 = 6). But in case of even numbers in total, calculate the average between the maximum of the last two elements in the first half (a1 and b2 in our example) with its successive number among the arrays which is the minimum of first two elements in the second half (a2 and b3 in our example).

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

7. kth element of 2 sorted array
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

8. overlaping subinterval

#include<bits/stdc++.h>
using namespace std;
#define ll long long


// Method 1:(using job seducheling concept)
ll comp(pair<ll,ll> a,pair<ll,ll> b){
    return a.first<b.first; 
}

void overlap(vector<pair<ll,ll>> arr,ll n){
	vector<ll> vec;
	sort(arr.begin(),arr.end(),comp);
    ll fst=arr[0].first,sec=arr[0].second;
    for(ll i=1;i<n;i++){
        if(sec>=arr[i].first && sec<=arr[i].second) sec=arr[i].second;
        else if(sec < arr[i].first){
            vec.push_back(fst);
            vec.push_back(sec);
            fst = arr[i].first;
            sec = arr[i].second;
            if(i+1 == n){
              	vec.push_back(fst);
          		vec.push_back(sec);
            }
        }
    }
   	if(find(vec.begin(),vec.end(),fst)==vec.end()) vec.push_back(fst); 
   	if(find(vec.begin(),vec.end(),sec)==vec.end()) vec.push_back(sec);
   	if(fst == sec) vec.push_back(fst);

    for(auto x:vec) cout<<x<<" ";
}

// Method 2: extended version of 1 method using stack
void overlap(vector<pair<ll,ll>> arr, int n) 
{ 
    // Test if the given set has at least one interval 
    if (n <= 0) 
        return; 
  
    // Create an empty stack of intervals 
    stack<pair<ll,ll>> s; 
  
    // sort the intervals in increasing order of start time 
    sort(arr.begin(),arr.end(),comp); 
  
    // push the first interval to stack 
    s.push(arr[0]); 
  
    // Start from the next interval and merge if necessary 
    for (int i = 1 ; i < n; i++) 
    { 
        // get interval from stack top 
        pair<ll,ll> top = s.top(); 
  
        // if current interval is not overlapping with stack top, 
        // push it to the stack 
        if (top.second < arr[i].first) 
            s.push(arr[i]); 
  
        // Otherwise update the ending time of top if ending of current 
        // interval is more 
        else if (top.second < arr[i].second) 
        { 
            top.second = arr[i].second; 
            s.pop(); 
            s.push(top); 
        } 
    } 
    while (!s.empty()) 
    { 
        pair<ll,ll> t = s.top(); 
        cout <<t.first <<" "<< t.second<<" "; 
        s.pop(); 
    } 
} 

// Method 3:
// A O(n Log n) and O(1) Extra Space Solution
// The above solution requires O(n) extra space for stack. We can avoid use of extra space by doing merge operations in-place. Below are detailed steps.

// 1) Sort all intervals in decreasing order of start time.
// 2) Traverse sorted intervals starting from first interval, 
//    do following for every interval.
//       a) If current interval is not first interval and it 
//          overlaps with previous interval, then merge it with
//          previous interval. Keep doing it while the interval
//          overlaps with the previous one.         
//       b) Else add current interval to output list of intervals.
// Note that if intervals are sorted by decreasing order of start times,
// we can quickly check if intervals overlap or not by comparing start time of previous interval with end time of current interval.
void overlap(vector<pair<ll,ll>> arr, ll n) 
{  
    // Sort Intervals in increasing order of 
    // start time 
    sort(arr.begin(),arr.end(),comp); 
  
    ll index = 0; // Stores index of last element  
    // in output array (modified arr[])  
  
    // Traverse all input Intervals  
    for (ll i=1; i<n; i++)  
    {  
        // If this is not first Interval and overlaps  
        // with the previous one  
        if (arr[index].second >=  arr[i].first)  
        {  
               // Merge previous and current Intervals  
            arr[index].second = max(arr[index].second, arr[i].second);  
            arr[index].first = min(arr[index].first, arr[i].first);  
        }  
        else { 
            arr[index] = arr[i];  
            index++; 
        }     
    }  
  
    // Now arr[0..index-1] stores the merged Intervals   
    for (ll i = 0; i <= index; i++)  
        cout  << arr[i].first << " " << arr[i].second <<" ";  
}  

int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t,n,a,b; cin>>t;
    while(t--) {
        cin>>n;
        vector<pair<ll,ll>> arr;
        for(ll i=0;i<n;i++){
            cin>>a>>b;
            arr.push_back({a,b});
        }
        overlap(arr,n);
        cout<<endl;
    }
}

9. merge 2 sorted array
#include <bits/stdc++.h>
using namespace std;
#define ll int

// Method 1:(using insertion sort like technique from last element of both array)
// The idea is to begin from last element of ar2[] and search it in ar1[]. If there is a greater element in ar1[], then we move last element of ar1[] to ar2[]. To keep ar1[] and ar2[] sorted, we need to place last element of ar2[] at correct place in ar1[]. We can use Insertion Sort type of insertion for this. Below is algorithm:

// 1) Iterate through every element of ar2[] starting from last 
//    element. Do following for every element ar2[i]
//     a) Store last element of ar1[i]: last = ar1[i]
//     b) Loop from last element of ar1[] while element ar1[j] is 
//        smaller than ar2[i].
//           ar1[j+1] = ar1[j] // Move element one position ahead
//           j--
//     c) If any element of ar1[] was moved or (j != m-1)
//           ar1[j+1] = ar2[i] 
//           ar2[i] = last  
// In above loop, elements in ar1[] and ar2[] are always kept sorted.
// void merge(ll arr1[],ll arr2[],ll n,ll m){
// 	for(ll i=m-1;i>=0;i--){
// 		ll j,last=arr1[n-1];
// 		for(j=n-2;j>=0 && arr1[j]>arr2[i];j--)
// 			arr1[j+1]=arr1[j];
// 		if(j!=n-2 || last>arr2[i]){
// 			arr1[j+1]=arr2[i];
// 			arr2[i]=last;
// 		}
// 	}
// 	for(ll i=0;i<n;i++) cout<<arr1[i]<<" ";
// 	for(ll i=0;i<m;i++) cout<<arr2[i]<<" ";
// }
// Method 2:(swap in a particular gap)
// The idea: we start comparing elements that are far from each other rather than adjacent.
// For every pass, we calculate the gap and compare the elements towards the right of the gap. Every pass, the gap reduces to the ceiling value of dividing by 2.

// Examples:

// First example: a1[] = {3 27 38 43}, a2[] = {9 10 82}
// Start with gap =  ceiling of n/2 = 4 [This gap is for 
//                                   whole merged array]
//         3 27 38 43   9 10 82 
//         3 27 38 43   9 10 82
//         3 10 38 43   9 27 82
//         gap = 2:
//         3 10 38 43   9 27 82
//         3 10 38 43   9 27 82
//         3 10 38 43   9 27 82 
//         3 27 9 10   38 43 82
//         3 27 9 10   38 43 82
//         gap = 1:
//         3 27 9 10   38 43 82
//         3 27 9 10   38 43 82
//         3 9 27 10   38 43 82
//         3 9 10 27   38 43 82
//         3 9 10 27   38 43 82
//         3 9 10 27   38 43 82
// Output : 3 9 10 27 38 43 82

// Second Example: a1[] = {10 27 38 43 82}, a2[] = {3 9}
// Start with gap = ceiling of n/2 (4):
// 10 27 38 43 82   3 9 
// 10 27 38 43 82   3 9
// 10 3 38 43 82   27 9
// 10 3 9 43 82   27 38
// gap = 2:
// 10 3 9 43 82   27 38
// 9 3 10 43 82   27 38
// 9 3 10 43 82   27 38
// 9 3 10 43 82   27 38
// 9 3 10 27 82   43 38
// 9 3 10 27 38   43 82
// gap = 1
// 9 3 10 27 38   43 82
// 3 9 10 27 38   43 82
// 3 9 10 27 38   43 82
// 3 9 10 27 38   43 82
// 3 9 10 27 38   43 82
// 3 9 10 27 38   43 82
// Output : 3 9 10 27 38   43 82
int nextGap(int gap) 
{ 
    if (gap <= 1) 
        return 0; 
    return (gap / 2) + (gap % 2); 
} 

void merge(int arr1[], int arr2[], int n, int m) 
{ 
    int i, j, gap = n + m; 
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
    { 
        // comparing elements in the first array. 
        for (i = 0; i + gap < n; i++) 
            if (arr1[i] > arr1[i + gap]) 
                swap(arr1[i], arr1[i + gap]); 
  
        //comparing elements in both arrays. 
        for (j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++) 
            if (arr1[i] > arr2[j]) 
                swap(arr1[i], arr2[j]); 
  
        if (j < m) 
        { 
            //comparing elements in the second array. 
            for (j = 0; j + gap < m; j++) 
                if (arr2[j] > arr2[j + gap]) 
                    swap(arr2[j], arr2[j + gap]); 
        } 
    } 
    for(ll i=0;i<n;i++) cout<<arr1[i]<<" ";
	for(ll i=0;i<m;i++) cout<<arr2[i]<<" ";
} 

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,m; cin>>t;
	while(t--){
		cin>>n>>m;
		ll arr1[n],arr2[m];
		for(ll i=0;i<n;i++) cin>>arr1[i];
		for(ll i=0;i<m;i++) cin>>arr2[i];
		merge(arr1,arr2,n,m);
		cout<<endl;
	}
	return 0;
}

10. segregate even and odd no
#include <bits/stdc++.h>
using namespace std;

void evenodd(int arr[], int n){
	int l=0,r=n-1;
	while(l<r){
		if(arr[l]%2==1 && arr[r]%2==0){
			swap(arr[l],arr[r]);
			l++;r--;
		}else if(arr[l]%2==0 && arr[r]%2==1){
			l++;
		}else{
			r--;
		}
	}
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
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
		evenodd(arr,n);
		cout<<endl;
	}
	return 0;
}

Day 2

1. rotate matrix
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N 101

// Method 1:
// Algorithm:

// To solve the given problem there are two tasks. 1st is finding the transpose and second is reversing the columns without using extra space
// A transpose of a matrix is when the matrix is flipped over its diagonal, i.e the row index of an element becomes the column index and vice versa.
// So to find the transpose interchange the elements at position (i, j) with (j, i).
// Run two loops, the outer loop from 0 to row count and inner loop from 0 to index of the outer loop.
// To reverse the column of the transposed matrix, run two nested loops, the outer loop from 0 to column count and inner loop from 0 to row count/2, 
// interchange elements at (i, j) with (i, row[count-1-j]), where i and j are indices of inner and outer loop respectively.
void transpose(int arr[N][N],ll n){
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			swap(arr[i][j],arr[j][i]);
		}
	}
}
void reverse(int arr[N][N],int n) {
	for(int i=0;i<n;i++){
		int l=0,r=n-1;
		while(l<r){
			swap(arr[l][i],arr[r][i]);
			l++;r--;
		}
	}
}
void printmat(int arr[N][N],ll n){
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

void rotatematrix(int arr[N][N],ll n){
	transpose(arr,n);
	reverse(arr,n);
	printmat(arr,n);
}

// Method 2:
// Approach: To solve the question without any extra space, rotate the array in form of squares, dividing the matrix into squares or cycles. For example,
// A 4 X 4 matrix will have 2 cycles. The first cycle is formed by its 1st row, last column, last row and 1st column. The second cycle is formed by 2nd row, 
// second-last column, second-last row and 2nd column. The idea is for each square cycle, swap the elements involved with the corresponding cell in the matrix in anti-clockwise direction i.e. 
// from top to left, left to bottom, bottom to right and from right to top one at a time using nothing but a temporary variable to achieve this.

// Demonstration:

// First Cycle (Involves Red Elements)
//  1  2  3 4 
//  5  6  7 8 
//  9 10 11 12 
//  13 14 15 16 

// Moving first group of four elements (First
// elements of 1st row, last row, 1st column 
// and last column) of first cycle in counter
// clockwise. 
//  4  2  3 16
//  5  6  7 8 
//  9 10 11 12 
//  1 14  15 13 
 
// Moving next group of four elements of 
// first cycle in counter clockwise 
//  4  8  3 16 
//  5  6  7  15  
//  2  10 11 12 
//  1  14  9 13 

// Moving final group of four elements of 
// first cycle in counter clockwise 
//  4  8 12 16 
//  3  6  7 15 
//  2 10 11 14 
//  1  5  9 13 


// Second Cycle (Involves Blue Elements)
//  4  8 12 16 
//  3  6 7  15 
//  2  10 11 14 
//  1  5  9 13 

// Fixing second cycle
//  4  8 12 16 
//  3  7 11 15 
//  2  6 10 14 
//  1  5  9 13
// Algorithm:

// There is N/2 squares or cycles in a matrix of side N. Process a square one at a time. Run a loop to traverse the matrix a cycle at a time, 
// i.e loop from 0 to N/2 – 1, loop counter is i
// Consider elements in group of 4 in current square, rotate the 4 elements at a time. So the number of such groups in a cycle is N – 2*i.
// So run a loop in each cycle from x to N – x – 1, loop counter is y
// The elements in the current group is (x, y), (y, N-1-x), (N-1-x, N-1-y), (N-1-y, x), now rotate the these 4 elements, 
// i.e (x, y) <- (y, N-1-x), (y, N-1-x)<- (N-1-x, N-1-y), (N-1-x, N-1-y)<- (N-1-y, x), (N-1-y, x)<- (x, y)
// Print the matrix.
// filter_none
void rotateMatrix(int mat[][N]) 
{ 
    // Consider all squares one by one 
    for (int x = 0; x < N / 2; x++) { 
        // Consider elements in group 
        // of 4 in current square 
        for (int y = x; y < N - x - 1; y++) { 
            // Store current cell in 
            // temp variable 
            int temp = mat[x][y]; 
  
            // Move values from right to top 
            mat[x][y] = mat[y][N - 1 - x]; 
  
            // Move values from bottom to right 
            mat[y][N - 1 - x] 
                = mat[N - 1 - x][N - 1 - y]; 
  
            // Move values from left to bottom 
            mat[N - 1 - x][N - 1 - y] 
                = mat[N - 1 - y][x]; 
  
            // Assign temp to left 
            mat[N - 1 - y][x] = temp; 
        } 
    } 
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
		int arr[N][N];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		} 
		rotatematrix(arr,n);

		cout<<endl;
	}
	return 0;
}

2. inversion of array
#include <bits/stdc++.h>
using namespace std;

// METHOD 1 (Simple)

// Approach :Traverse through the array and for every index find the number of smaller elements on its right side of the array. 
// This can be done using a nested loop. Sum up the counts for all index in the array and print the sum.
// Algorithm :
// Traverse through the array from start to end
// For every element find the count of elements smaller than the current number upto that index using another loop.
// Sum up the count of inversion for every index.
// Print the count of inversions.
int getInvCount(int arr[], int n) 
{ 
    int inv_count = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] > arr[j]) 
                inv_count++; 
  
    return inv_count; 
} 

// Complexity Analysis:
// Time Complexity: O(n^2), Two nested loops are needed to traverse the array from start to end so the Time complexity is O(n^2)
// Space Compelxity:O(1), No extra space is required.


// METHOD 2(Enhance Merge Sort)

// Approach:
// Suppose the number of inversions in the left half and right half of the array (let be inv1 and inv2), what kinds of inversions are not accounted for in Inv1 + Inv2?
//  The answer is – the inversions that need to be counted during the merge step.
//  Therefore, to get a number of inversions, that needs to be added a number of inversions in the left subarray, right subarray and merge().
// inv_count1
// How to get number of inversions in merge()?
// In merge process, let i is used for indexing left sub-array and j for right sub-array. At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions. 
// because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]

// Algorithm:
// The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step until the base case is reached.
// Create a function merge that counts the number of inversions when two halves of the array are merged, create two indices i and j, i is the index for first half and j is an index of the second half. 
// if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
// Create a recursive function to divide the array into halves and find the answer by summing the number of inversions is the first half, number of inversion in the second half and the number of inversions by merging the two.
// The base case of recursion is when there is only one element in the given half.
// Print the answer

int merge(int arr[],int l,int mid,int r){
	int i=l,j=mid;
	int temp[r],k=l,inv=0;
	while(i<=mid-1 && j<=r){
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else{
			temp[k++]=arr[j++];
			inv += (mid-i);
		}
	}
	while(i<=(mid-1)){
		temp[k++]=arr[i++];
	}
	while(j<=r){
		temp[k++]=arr[j++];
	}
	for (i = l; i <= r; i++) 
        arr[i] = temp[i]; 
	return inv;

}

int mergesort(int arr[],int l,int r){
	int inv=0;
	if(l<r){
		int mid = l+(r-l)/2;
		inv +=mergesort(arr,l,mid);
		inv +=mergesort(arr,mid+1,r);
		inv +=merge(arr,l,mid+1,r);
	}
	return inv;
}

// Method 3:(using set in stl)
// Create an empty Set in C++ STL (Note that a Set in C++ STL is 
//    implemented using Self-Balancing Binary Search Tree). And insert
//    first element of array into the set.

// 2) Initialize inversion count as 0.

// 3) Iterate from 1 to n-1 and do following for every element in arr[i]
//      a) Insert arr[i] into the set.
//      b) Find the first element greater than arr[i] in set
//         using upper_bound() defined Set STL.
//      c) Find distance of above found element from last element in set
//         and add this distance to inversion count.

// 4) Return inversion count.
int getInvCount(int arr[],int n) 
{ 
    // Create an empty set and insert first element in it 
    multiset<int> set1; 
    set1.insert(arr[0]); 
  
    int invcount = 0; // Initialize result 
  
    multiset<int>::iterator itset1; // Iterator for the set 
  
    // Traverse all elements starting from second 
    for (int i=1; i<n; i++) 
    { 
        // Insert arr[i] in set (Note that set maintains 
        // sorted order) 
        set1.insert(arr[i]); 
  
        // Set the iterator to first greater element than arr[i] 
        // in set (Note that set stores arr[0],.., arr[i-1] 
        itset1 = set1.upper_bound(arr[i]); 
  
        // Get distance of first greater element from end 
        // and this distance is count of greater elements 
        // on left side of arr[i] 
        invcount += distance(itset1, set1.end()); 
    } 
  
    return invcount; 
} 

//  Method 4:(using AVL Trees)
// An AVL tree node 
// Approach: The idea is to use Self-Balancing Binary Search Tree like Red-Black Tree, AVL Tree, etc and augment it so that every node also keeps track of number of nodes in right subtree. 
// So every node will contain the count of nodes in its right subtree i.e. the number of nodes greater than that number. So it can be seen that the count increases when there is a pair (a,b), where a appears before b in the array and a > b, So as the array is traversed from start to the end, 
// add the elements to the AVL tree and the count of the nodes in its right subtree of the newly inserted node will be the count increased or the number of pairs (a,b) where b is the present element.

// Algorithm:

// Create an AVL tree, with a property that every node will contain the size of its subtree.
// Traverse the array from start to the end.
// For every element insert the element in the AVL tree
// The count of the nodes which are greater than the current element can be found out by checking the size of the subtree of its right children, So it can be guaranteed that elements in the right subtree of current node have index less than the current element and their values are greater than the current element.
// So those element satisfy the criteria.
// So increase the count by size of subtree of right child of the current inserted node.
// Display the count.
struct Node 
{ 
    int key, height; 
    struct Node *left, *right; 
  
// size of the tree rooted with this Node 
    int size;  
}; 
  
// A utility function to get the height of 
// the tree rooted with N 
int height(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 
  
// A utility function to size of the 
// tree of rooted with N 
int size(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->size; 
} 
  
/* Helper function that allocates a new Node with 
the given key and NULL left and right pointers. */
struct Node* newNode(int key) 
{ 
    struct Node* node = new Node; 
    node->key   = key; 
    node->left   = node->right  = NULL; 
    node->height = node->size = 1; 
    return(node); 
} 
  
// A utility function to right rotate  
// subtree rooted with y 
struct Node *rightRotate(struct Node *y) 
{ 
    struct Node *x = y->left; 
    struct Node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), 
 height(y->right))+1; 
    x->height = max(height(x->left), 
 height(x->right))+1; 
  
    // Update sizes 
    y->size = size(y->left) + size(y->right) + 1; 
    x->size = size(x->left) + size(x->right) + 1; 
  
    // Return new root 
    return x; 
} 
  
// A utility function to left rotate  
// subtree rooted with x 
struct Node *leftRotate(struct Node *x) 
{ 
    struct Node *y = x->right; 
    struct Node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Update sizes 
    x->size = size(x->left) + size(x->right) + 1; 
    y->size = size(y->left) + size(y->right) + 1; 
  
    // Return new root 
    return y; 
} 
  
// Get Balance factor of Node N 
int getBalance(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 
  
// Inserts a new key to the tree rotted with Node. Also, updates 
// *result (inversion count) 
struct Node* insert(struct Node* node, int key, int *result) 
{ 
    /* 1.  Perform the normal BST rotation */
    if (node == NULL) 
        return(newNode(key)); 
  
    if (key < node->key) 
    { 
        node->left  = insert(node->left, key, result); 
  
        // UPDATE COUNT OF GREATE ELEMENTS FOR KEY 
        *result = *result + size(node->right) + 1; 
    } 
    else
        node->right = insert(node->right, key, result); 
  
    /* 2. Update height and size of this ancestor node */
    node->height = max(height(node->left), 
                       height(node->right)) + 1; 
    node->size = size(node->left) + size(node->right) + 1; 
  
    /* 3. Get the balance factor of this ancestor node to 
          check whether this node became unbalanced */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then there are 
    // 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
// The following function returns inversion count in arr[] 
int getInvCount(int arr[], int n) 
{ 
  struct Node *root = NULL;  // Create empty AVL Tree 
  
  int result = 0;   // Initialize result 
  
  // Starting from first element, insert all elements one by 
  // one in an AVL tree. 
  for (int i=0; i<n; i++) 
  
     // Note that address of result is passed as insert 
     // operation updates result by adding count of elements 
     // greater than arr[i] on left of arr[i] 
     root = insert(root, arr[i], &result); 
  
  return result; 
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
		cout<<mergesort(arr,0,n-1)<<endl;
	}
	return 0;
}

3.next permutation
#include <bits/stdc++.h>
using namespace std;

// Method 1:(using stl function)
void permutation(string str){
	bool val = next_permutation(str.begin(),str.end());
		if(val == false) cout<<"not exists"<<endl;
		else cout<<str<<endl;
}

// Method 2:
// . The idea is based on the following facts:
// 1) An sequence sorted in descending order does not have next permutation. For example edcba” does not have next permutation.
// 2) For a sequence which is not sorted in descending order for example “abedc”, we can follow below steps.
// ……….a) Traverse from right and find the first item that is not following the descending order. For example in “abedc”, the character ‘b’ does not follow the descending order.
// ……….b) Swap the found character with closest greater (or smallest greater) element on right side of it. In case of “abedc”, we have ‘c’ as the closest greater element. After swapping ‘b’ and ‘c’, string becomes “acedb”.
// ……….c) After swapping, sort the string after the position of character found in step a. After sorting the substring “edb” of “acedb”, we get “acbde” which is the required next permutation.

// Optimizations in step b) and c)
// a) Since the sequence is sorted in decreasing order, we can use binary search to find the closest greater element.
// c) Since the sequence is already sorted in decreasing order (even after swapping as we swapped with the closest greater), we can get the sequence sorted (in increasing order) after reversing it.
void swap(char* a, char* b) 
{ 
    if (*a == *b) 
        return; 
    *a ^= *b; 
    *b ^= *a; 
    *a ^= *b; 
} 
void rev(string& s, int l, int r) 
{ 
    while (l < r) 
        swap(&s[l++], &s[r--]); 
} 
  
int bsearch(string str,int l,int r,int key){
	int index=-1;
	while(l<=r){
		int mid = l+(r-l)/2;
		if(str[mid]<=key){
			r=mid-1;
		}else{
			l=mid+1;
			if(index == -1 || str[index]>=str[mid])
				index = mid;
		}
	}
	return index;
}

void permutation(string str){
	int l = str.size(),i=l-2;
	while(i>=0 && str[i]>str[i+1])
		i--;
	if(i<0) cout<<"nahi mile";
	else{
		int index = bsearch(str,i+1,l-1,str[i]);
		swap(&str[i],&str[index]);
		rev(str,i+1,l-1);
	}
	cout<<str;
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
	string str;
	// permutation(str);
	while(t--){
		cin>>str;
		permutation(str);
		cout<<endl;
	}
	return 0;
}
4.rotate matrix
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000001
void transpose(ll arr[][N],ll n){
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			swap(arr[i][j],arr[j][i]);
		}
	}
}
void printmat(ll arr[][N],ll n){
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
void rotatematrix(ll arr[][N],ll n){
	transpose(arr,n);
	// reverse(arr,n);
	printmat(arr,n);
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		ll arr[N][N];
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				cin>>arr[i][j];
			}
		} 
		rotatematrix(arr,n);
	}
	return 0;
}
5. pascal triangle
#include <bits/stdc++.h>
using namespace std;

// Method 1:( O(n^3) time complexity )
// Number of entries in every line is equal to line number. For example, the first line has “1”, the second line has “1 1”,
// the third line has “1 2 1”,.. and so on. Every entry in a line is value of a Binomial Coefficient. The value of ith entry in line number line is C(line, i). 
// The value can be calculated using following formula.

// C(line, i)   = line! / ( (line-i)! * i! ) 
// A simple method is to run two loops and calculate the value of Binomial Coefficient in inner loop
int binomialCoeff(int n, int k) 
{ 
    int res = 1; 
    if (k > n - k) 
    k = n - k; 
    for (int i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
      
    return res; 
}
void printPascal(int n) 
{ 
    // Iterate through every line and 
    // print entries in it 
    for (int line = 0; line < n; line++) 
    { 
        // Every line has number of  
        // integers equal to line  
        // number 
        for (int i = 0; i <= line; i++) 
            printf("%d ", 
                    binomialCoeff(line, i)); 
        printf("\n"); 
    } 
} 
// Method 2( O(n^2) time and O(n^2) extra space )
// If we take a closer at the triangle, we observe that every entry is sum of the two values above it. 
// So we can create a 2D array that stores previously generated values. To generate a value in a line, 
// we can use the previously stored values from array.
void printPascal(int n) 
{ 
      
    // An auxiliary array to store  
    // generated pscal triangle values 
    int arr[n][n];  
  
    // Iterate through every line and  
    // print integer(s) in it 
    for (int line = 0; line < n; line++) 
    { 
        // Every line has number of integers  
        // equal to line number 
        for (int i = 0; i <= line; i++) 
        { 
        // First and last values in every row are 1 
        if (line == i || i == 0) 
            arr[line][i] = 1; 
        // Other values are sum of values just  
        // above and left of above 
        else
            arr[line][i] = arr[line - 1][i - 1] +  
                            arr[line - 1][i]; 
        cout << arr[line][i] << " "; 
        } 
        cout << "\n"; 
    } 
} 
// Method 3 ( O(n^2) time and O(1) extra space )
// This method is based on method 1. We know that ith entry in a line number line is Binomial Coefficient C(line, i) and all lines start with value 1. 
// The idea is to calculate C(line, i) using C(line, i-1). It can be calculated in O(1) time using the following.

// C(line, i)   = line! / ( (line-i)! * i! )
// C(line, i-1) = line! / ( (line - i + 1)! * (i-1)! )
// We can derive following expression from above two expressions.
// C(line, i) = C(line, i-1) * (line - i + 1) / i

// So C(line, i) can be calculated from C(line, i-1) in O(1) time
void printPascal(int n) 
{ 
      
for (int line = 1; line <= n; line++) 
{ 
    int C = 1; // used to represent C(line, i) 
    for (int i = 1; i <= line; i++)  
    { 
          
        // The first value in a line is always 1 
        cout<< C<<" ";  
        C = C * (line - i) / i;  
    } 
    cout<<"\n"; 
} 
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
		printPascal(n);
	}
	return 0;
}

6.set matrix zero
#include <bits/stdc++.h>
using namespace std;

// Method 1: (make string of all the i and j index in which element are 0.)
void setZeroes(vector<vector<int>>& arr) {
        int n=arr.size();
        int m = arr[0].size();
        string str="";
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]==0) {
					if(i>=10 && i<=99){
						str += "ti"+to_string(i);
					}else if(i>=100 && i<=999){
						str += "di"+to_string(i);
					}else{
						str += to_string(i);
					}
					if(j>=10 && j<=99) {
						str += "tj"+to_string(j);
					}else if(j>=100 && j<=999) {
						str += "dj"+to_string(j);
					}else{
						str += to_string(j);
					}
				}
			}
		}
		int len = str.size(),k=0;
		// cout<<str<<endl;
		// for(int i=0;i<len;i++) cout<<str[i]<<" ";
		while(k<len){
			int l,r;
			if(str[k]=='t' && str[k+1]=='i'){
				k=k+2;
				l=(str[k]-'0')*10+(str[++k]-'0');

			}else if(str[k]=='d' && str[k+1]=='i'){
				k=k+2;
				l= (str[k]-'0')*100+(str[++k]-'0')*10+(str[++k]-'0');
			}else{
				l=str[k]-'0';	
			}
			++k;
			if(str[k]=='t' && str[k+1]=='j'){
				k=k+2;
				r=(str[k]-'0')*10+(str[++k]-'0');

			}else if(str[k]=='d' && str[k+1]=='j'){
				k=k+2;
				r= (str[k]-'0')*100+(str[++k]-'0')*10+(str[++k]-'0');
			}else{
				r=str[k]-'0';	
			}
			++k;
			// cout<<l<<" "<<r<<endl;
			for(int i=0;i<m;i++){
				arr[l][i]=0;
			}
			for(int i=0;i<n;i++){
				arr[i][r]=0;
			}
		}
    }
// complexity = O(n*m+k(n+m))

// Method 2: Brute O(1) space.
// Intuition

// In the above approach we use additional memory to keep a track of rows and columns which need to be set to zero. This additional use of space can be avoided by manipulating the original array instead.

// Algorithm
class Solution {
  public void setZeroes(int[][] matrix) {
    int MODIFIED = -1000000;
    int R = matrix.length;
    int C = matrix[0].length;

    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        if (matrix[r][c] == 0) {
          // We modify the corresponding rows and column elements in place.
          // Note, we only change the non zeroes to MODIFIED
          for (int k = 0; k < C; k++) {
            if (matrix[r][k] != 0) {
              matrix[r][k] = MODIFIED;
            }
          }
          for (int k = 0; k < R; k++) {
            if (matrix[k][c] != 0) {
              matrix[k][c] = MODIFIED;
            }
          }
        }
      }
    }

    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        // Make a second pass and change all MODIFIED elements to 0 """
        if (matrix[r][c] == MODIFIED) {
          matrix[r][c] = 0;
        }
      }
    }
  }
}

// Iterate over the original array and if we find an entry, say cell[i][j] to be 0, then we iterate over row i and column j separately and set all the non zero elements to some high negative dummy value (say -1000000). 
    // Note, choosing the right dummy value for your solution is dependent on the constraints of the problem. 
    // Any value outside the range of permissible values in the matrix will work as a dummy value.
// Finally, we iterate over the original matrix and if we find an entry to be equal to the high negative value (constant defined initially in the code as MODIFIED), then we set the value in the cell to 0.

// Complexity Analysis

// Time Complexity : O((M \times N) \times (M + N))O((M×N)×(M+N)) where M and N are the number of rows and columns respectively. Even though this solution avoids using space, but is very inefficient since in worst case 
    // for every cell we might have to zero out its corresponding row and column. Thus for all (M \times N)(M×N) cells zeroing out (M + N)(M+N) cells.
// Space Complexity : O(1)O(1)

// Method 3:O(1) Space, Efficient Solution
// Intuition

// The inefficiency in the second approach is that we might be repeatedly setting a row or column even if it was set to zero already. We can avoid this by postponing the step of setting a row or a column to zeroes.

// We can rather use the first cell of every row and column as a flag. This flag would determine whether a row or column has been set to zero. This means for every cell instead of going to M+NM+N cells and setting it to zero we just set the flag in two cells.

// if cell[i][j] == 0 {
//     cell[i][0] = 0
//     cell[0][j] = 0
// }
// These flags are used later to update the matrix. If the first cell of a row is set to zero this means the row should be marked zero. If the first cell of a column is set to zero this means the column should be marked zero.

// Algorithm
class Solution {
  public void setZeroes(int[][] matrix) {
    Boolean isCol = false;
    int R = matrix.length;
    int C = matrix[0].length;

    for (int i = 0; i < R; i++) {

      // Since first cell for both first row and first column is the same i.e. matrix[0][0]
      // We can use an additional variable for either the first row/column.
      // For this solution we are using an additional variable for the first column
      // and using matrix[0][0] for the first row.
      if (matrix[i][0] == 0) {
        isCol = true;
      }

      for (int j = 1; j < C; j++) {
        // If an element is zero, we set the first element of the corresponding row and column to 0
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    // Iterate over the array once again and using the first row and first column, update the elements.
    for (int i = 1; i < R; i++) {
      for (int j = 1; j < C; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    // See if the first row needs to be set to zero as well
    if (matrix[0][0] == 0) {
      for (int j = 0; j < C; j++) {
        matrix[0][j] = 0;
      }
    }

    // See if the first column needs to be set to zero as well
    if (isCol) {
      for (int i = 0; i < R; i++) {
        matrix[i][0] = 0;
      }
    }
  }
}

// We iterate over the matrix and we mark the first cell of a row i and first cell of a column j, if the condition in the pseudo code above is satisfied. i.e. if cell[i][j] == 0.

// The first cell of row and column for the first row and first column is the same i.e. cell[0][0]. Hence, we use an additional variable to tell us if the first column had been marked or not and the cell[0][0] would be used to tell the same for the first row.

// Now, we iterate over the original matrix starting from second row and second column i.e. matrix[1][1] onwards. For every cell we check if the row r or column c had been marked earlier by checking the respective first row cell or first column cell. 
// If any of them was marked, we set the value in the cell to 0. Note the first row and first column serve as the row_set and column_set that we used in the first approach.

// We then check if cell[0][0] == 0, if this is the case, we mark the first row as zero.

// And finally, we check if the first column was marked, we make all entries in it as zeros.

// Current
// 1 / 18
// In the above animation we iterate all the cells and mark the corresponding first row/column cell incase of a cell with zero value.


// We iterate the matrix we got from the above steps and mark respective cells zeroes.




// Complexity Analysis

// Time Complexity : O(M \times N)O(M×N)
// Space Complexity : O(1)
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
		vector<vector<int>> arr;
		for(int i=0;i<n;i++){
			vector<int> v;
			for(int j=0;j<m;j++){
				cin>>a;
				v.push_back(a);
			}
			arr.push_back(v);
		}
		setZeroes(arr);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		
	}
	return 0;
}

7.stockbuyandsale
#include <bits/stdc++.h>
using namespace std;

// Method 1:
int maxPrice(int arr[],int start,int end){
	if(end<=start) return 0;
	int maxprofit=0;
	for(int i=start;i<end;i++){
		for(int j=i+1;j<=end;j++){
			if(arr[j]>arr[i]){
				int max_curr = (arr[j]-arr[i])
								+maxPrice(arr,start,i-1)
								+maxPrice(arr,j+1,end);
				maxprofit = max(max_curr,maxprofit);
			}
		}
	}
	return maxprofit;
}

// Method 2:
// Find the local minima and store it as starting index. If not exists, return.
// Find the local maxima. and store it as ending index. If we reach the end, set the end as ending index.
// Update the solution (Increment count of buy sell pairs)
// Repeat the above steps if end is not reached

void stockBuySell(int price[], int n) 
{ 
    // Prices must be given for at least two days 
    if (n == 1) 
        return; 
  
    // Traverse through given price array 
    int i = 0; 
    while (i < n - 1) { 
  
        // Find Local Minima 
        // Note that the limit is (n-2) as we are 
        // comparing present element to the next element 
        while ((i < n - 1) && (price[i + 1] <= price[i])) 
            i++; 
  
        // If we reached the end, break 
        // as no further solution possible 
        if (i == n - 1) 
            break; 
  
        // Store the index of minima 
        int buy = i++; 
  
        // Find Local Maxima 
        // Note that the limit is (n-1) as we are 
        // comparing to previous element 
        while ((i < n) && (price[i] >= price[i - 1])) 
            i++; 
  
        // Store the index of maxima 
        int sell = i - 1; 
  
        cout << "Buy on day: " << buy 
             << "\t Sell on day: " << sell << endl; 
    } 
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
		cout<<maxPrice(arr,0,n-1)<<endl;
		
	}
	return 0;
}


Day 3:

1. count trailing zero in factorial of a number
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Method 1: (count no of 5 because they are responsible for 0)
ll trailzero(ll n){
	ll count=0;
	for(ll i=5;n/i>=1;i = i*5){
		count += n/i;
	}
	return count;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		cout<<trailzero(n)<<endl;
		
	}
	return 0;
}

2.excel column number
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Method 1:
// If remainder with 26 comes out to be 0 (meaning 26, 52 and so on)
 // then we put ‘Z’ in the output string and new n becomes n/26 -1 because here we are considering 26 to be ‘Z’ while in actual it’s 25th with respect to ‘A’.

// Similarly if the remainder comes out to be non zero. (like 1, 2, 3 and so on) then we need to just insert the char accordingly in the string and do n = n/26.

// Finally we reverse the string and print.
string colnumber(ll n){
	ll k= n;
	string str;
	while(k>0){
		ll rem = k%26;
		if(rem ==0) {
			k = k/26-1;
			str += 'Z';
		}
		else {
			k = k/26;
			str += 'A'+(rem-1);
		}
	}
	reverse(str.begin(),str.end());
	return str;
}

// Method 2:
// The problem is similar to converting a decimal number to its binary representation but instead of binary base system where we have two digits only 0 and 1, here we have 26 characters from A-Z .

// So, we are dealing with base 26 instead of base binary.

// That’s not where the fun ends, we don’t have zero in this number system, as A represents 1, B represents 2 and so on Z represents 26.

// To make the problem easily understandable, we approach the problem in two steps:

// Convert the number to base 26 representation, considering we have 0 also in the system.
// Change the representation to the one without having 0 in its system.
// HOW? Here is an example

// Step 1:
// Consider we have number 676, How to get its representation in base 26 system ? Same way we do for binary system, Instead of division and remainder by 2, we do division and remainder by 26.

// Base 26 representation of 676 is : 100 
// Step2

// But Hey, we can’t have zero in our representation. right? Because its not part of our number system. How do we get rid of zero? Well its simple, but before doing that lets remind one simple math trick:


// Subtraction: 
// 5000 - 9, How do you subtract 9 from 0 ? You borrow
// from next significant bit, right.  

// In decimal number system to deal with zero we borrow 10, and subtract 1 from next significant.
// In Base 26 Number System to deal with zero we borrow 26 and subtract 1 from next significant bit.
// So Convert 10026 to number system which does not have ‘0’, we get (25 26)26
// Symbolic representation of the same is : YZ
void printString(int n) 
{ 
    int arr[10000]; 
    int i = 0; 
  
    // Step 1: Converting to number assuming 
    // 0 in number system 
    while (n) { 
        arr[i] = n % 26; 
        n = n / 26; 
        i++; 
    } 
  
    // Step 2: Getting rid of 0, as 0 is 
    // not part of number system 
    for (int j = 0; j < i - 1; j++) { 
        if (arr[j] <= 0) { 
            arr[j] += 26; 
            arr[j + 1] = arr[j + 1] - 1; 
        } 
    } 
  
    for (int j = i; j >= 0; j--) { 
        if (arr[j] > 0) 
            cout << char('A' + arr[j] - 1); 
    } 
  
    cout << endl; 
} 
  

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		cout<<colnumber(n)<<endl;
		
	}
	return 0;
}

3. find gcd in logn
#include <bits/stdc++.h>
using namespace std;

// Method 1:
// The algorithm is based on below facts.

// If we subtract smaller number from larger (we reduce larger number), GCD doesn’t change. 
// So if we keep subtracting repeatedly the larger of two, we end up with GCD.
// Now instead of subtraction, if we divide smaller number, the algorithm stops when we find remainder 0.
// Below is a recursive function to evaluate gcd using Euclid’s algorithm.
int gcd(int a ,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}
// Time Complexity: O(Log min(a, b))

// Method 2:
// ax+by = gcd(a,b);
// Extended Euclidean Algorithm:
// Extended Euclidean algorithm also finds integer coefficients x and y such that:

//   ax + by = gcd(a, b) 
// Examples:

// Input: a = 30, b = 20
// Output: gcd = 10
//         x = 1, y = -1
// (Note that 30*1 + 20*(-1) = 10)

// Input: a = 35, b = 15
// Output: gcd = 5
//         x = 1, y = -2
// (Note that 35*1 + 15*(-2) = 5)
// The extended Euclidean algorithm updates results of gcd(a, b) using the results calculated by recursive call gcd(b%a, a).
// Let values of x and y calculated by the recursive call be x1 and y1. x and y are updated using the below expressions.


// x = y1 - ⌊b/a⌋ * x1
// y = x1

int gcd(int a,int b,int *x,int *y){
	if(a==0) {
		*x=0;
		*y=1;
		return b;
	}
	int x1,y1;
	int ans = gcd(b%a,a,&x1,&y1);
	*x=y1-(b/a)*x1;
	*y=x1;
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
	int t,a,b; cin>>t;
	while(t--){
		cin>>a>>b;
		int x,y;
		cout<<gcd(a,b,&x,&y)<<endl;
		// cout<<x<<" "<<y<<endl;
	}
	return 0;
}

4.excel sheet part 2
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sheet(string str,ll n){
    ll p=26;
    ll p_pow=1;
    ll k = n;
    ll ans=0;
    while(k>0){
        ll rem = str[k-1]-'A'+1;
        ans += rem*p_pow;
        p_pow = p_pow*p;
        k--;
    }
    return ans;
}
// 27
// 26
// 51
// 52
// 80
// 676
// 702
// 705
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t,n; cin>>t;
    string str;
    while(t--) {
        cin>>str;
        n = str.size();
        cout<<sheet(str,n)<<endl;
    }
}

5.grid unique path 1
#include <bits/stdc++.h>
using namespace std;
#define N 50

// Method 1:
int gridpath(int arr[][N],int n,int m,int a,int b){
	if(a == n-1 && b == m-1) return 1;
	// if one is treated as obstacle then uncomment the below line
	// if(arr[a][b] == 1) return 0;
	if((a<0 || a>=n) || (b<0 || b>=m)) return 0;
	return gridpath(arr,n,m,a+1,b) + gridpath(arr,n,m,a,b+1);
}

// Method 2:(for printing the resultant path)
void printAllPathsUtil(int *mat, int i, int j, int m, int n, int *path, int pi) 
{ 
    // Reached the bottom of the matrix so we are left with 
    // only option to move right 
    if (i == m - 1) 
    { 
        for (int k = j; k < n; k++) 
            path[pi + k - j] = *((mat + i*n) + k); 
        for (int l = 0; l < pi + n - j; l++) 
            cout << path[l] << " "; 
        cout << endl; 
        return; 
    } 
  
    // Reached the right corner of the matrix we are left with 
    // only the downward movement. 
    if (j == n - 1) 
    { 
        for (int k = i; k < m; k++) 
            path[pi + k - i] = *((mat + k*n) + j); 
        for (int l = 0; l < pi + m - i; l++) 
            cout << path[l] << " "; 
        cout << endl; 
        return; 
    } 
  
    // Add the current cell to the path being generated 
    path[pi] = *((mat + i*n) + j); 
  
    // Print all the paths that are possible after moving down 
    printAllPathsUtil(mat, i+1, j, m, n, path, pi + 1); 
  
    // Print all the paths that are possible after moving right 
    printAllPathsUtil(mat, i, j+1, m, n, path, pi + 1); 
  
    // Print all the paths that are possible after moving diagonal 
    // printAllPathsUtil(mat, i+1, j+1, m, n, path, pi + 1); 
} 
  
// The main function that prints all paths from top left to bottom right 
// in a matrix 'mat' of size mXn 
void printAllPaths(int *mat, int m, int n) 
{ 
    int *path = new int[m+n]; 
    printAllPathsUtil(mat, 0, 0, m, n, path, 0); 
} 

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,m; cin>>t;
	while(t--){
		cin>>n>>m;
		int arr[N][N];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		cout<<gridpath(arr,n,m,0,0)<<endl;
	}
	return 0;
}

6.find npowx in logn
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 1000000007

// Method 1:
// using fast exponent with module
ll fastexpo(ll a,ll b){
	if(b==0) return 1;
	ll d = fastexpo(a,b/2);
	if(b&1) {
		if(b>0) return ((d*d)%N*a)%N;
		else return (((d%N)*(d%N))%N)/a;
	}
	else return ((d%N)*(d%N))%N;
}
// Method 2:
// here p is modular value
int power(int x, unsigned int y, int p)  
{  
    int res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
} 

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,a,b; cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<fastexpo(a,b)<<endl;	
	}
	return 0;
}

7.majority element
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
	return max_ind;
}

bool ismajority(int arr[],int n,int cnd){
	int count=0;
	for(int i=0;i<n;i++){
		if(arr[i]==cnd) count++;
	}
	if(count>=ceil(n/2.0)) return true;
	return false;
}


int majorityElement(int arr[],int n){
	int cnd = findcandidate(arr,n);
	if(ismajority(arr,n,cnd)) return arr[cnd];
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

Day4:
1. 2 sum problem
#include <bits/stdc++.h>
using namespace std;
// Method 1:
vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> vec;
        int n = nums.size();
        for(int i=0;i<n;i++) mp[nums[i]]=i+1;
        for(int i=0;i<n;i++){
            int j = mp[(target-nums[i])];
            if(j>0 && i!=j-1){
                vec.push_back(i);
                vec.push_back(j-1);
                break;
            }
        }
        return vec;
 }

// Method 2:
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int val = target-nums[i];
            if(mp.find(val)!=mp.end()){
                ans.push_back(mp[val]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    } 

// Method 3:
vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>res;
        int n = numbers.size();
        if(n == 0)  return res;
        int i = 0, j = n - 1;
        while(i < j){
            int x = numbers[i] + numbers[j];
            if(x == target){
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            else if(x > target)
                j--;
            else 
                i++;
        }
        return res;
    }

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,target; cin>>t;
	while(t--){
		cin>>n>>target;
		vector<int> arr;
		vector<int> ans;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		ans = twoSum(arr,target);
		for(auto x:ans) cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}

2.3 sum problem
#include <bits/stdc++.h>
using namespace std;
// Method 1:(2 pointer)
vector<vector<int>> threeSum( vector<int>& nums,int target ) {
    vector<vector<int>> result;
    int size = nums.size();
    if( size <= 2 ) return result;

    sort( nums.begin(), nums.end() );
    int sum;
    for( int i=0; i < size - 2; i++ ) {
        // if( nums[i] > 0 ) break;
        if( i > 0 && nums[i-1] == nums[i] ) continue;

        int start = i + 1, end = nums.size() - 1;
        while( start < end ) {
            sum = nums[i] + nums[start] + nums[end];
            if( sum == 0 ) {
                result.push_back( { nums[i], nums[start], nums[end] } );
                start++;
                end--;
                while( start < end && nums[start] == nums[start - 1] ) start++;
                while( start < end && nums[end] == nums[end + 1] ) end--;
            }
            else if( sum > 0 )
                end--;
            else
                start++;
        }
    }
    return result;
}


int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,target; cin>>t;
	while(t--){
		cin>>n>>target;
		vector<int> arr;
		vector<vector<int>> ans;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		ans = threeSum(arr,target);
		// for(auto x:ans) cout<<x<<" ";
        int k=ans.size();
        int l = ans[0].size();
        for(int i=0;i<k;i++){
            for(int j=0;j<l;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
		cout<<endl;
	}
	return 0;
}


3. 4 sum problem
#include <bits/stdc++.h>
using namespace std;

// Method 1:(2 pointer)
vector<vector<int>> fourSum( vector<int>& nums,int target ) {
    vector<vector<int>> result;
    int size = nums.size();
    if( size <= 3 ) return result;

    sort( nums.begin(), nums.end() );
    int sum;
    for(int j=0;j<size-3;j++){
        if( j>0 && nums[j-1] == nums[j] ) continue;
    for( int i=j+1; i < size - 2; i++ ) {
        // if( nums[i] > 0 ) break;
        if( i > j+1 && nums[i-1] == nums[i] ) continue;

        int start = i + 1, end = nums.size() - 1;
        while( start < end ) {
            sum = target-(nums[i] + nums[j]);
            if( sum == nums[start]+nums[end] ) {
                result.push_back( {nums[j], nums[i], nums[start], nums[end] } );
                start++;
                end--;
                while( start < end && nums[start] == nums[start - 1] ) start++;
                while( start < end && nums[end] == nums[end + 1] ) end--;
            }
            else if( nums[start]+nums[end] > sum)
                end--;
            else
                start++;
        }
    }
}
    return result;
}


int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,target; cin>>t;
	while(t--){
		cin>>n>>target;
		vector<int> arr;
		vector<vector<int>> ans;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		ans = fourSum(arr,target);
        
        int k=ans.size();
        int l = ans[0].size();
        for(int i=0;i<k;i++){
            for(int j=0;j<l;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
		cout<<endl;
	}
	return 0;
}

4. count no of subarray with xor
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

5.longest subarray with 0 sum
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

6. longest consective serquence
#include <bits/stdc++.h>
using namespace std;
// Method 1:(using sort)
int lcs(vector<int> arr,int n){
	sort(arr.begin(),arr.end());
    int val = arr[0];
    int sum=1,maxsum=INT_MIN;
    for(int i=1;i<n;i++){
        if(arr[i] == val) continue;
        if(arr[i]==val+1){
            val += 1;
            sum++;
        }else {
            if(maxsum<sum){
                maxsum=sum;
            }
            val = arr[i];
            //cout<<"else"<<val<<endl;
            sum=1;
        }
    }
    if(maxsum<sum){
        maxsum=sum;
    }
    return maxsum;
}
// complexity O(nlogn)
// space O(1)

// Method 2: (using Hash)
int lcs(vector<int> arr,int n){
	map<int,int> mp;
	sort(arr.begin(),arr.end());
	// for(auto x:arr) cout<<x<<" ";
	for(int i=0;i<n;i++) mp[arr[i]]=i;
	int sam,i=0,count=1,maxval=1;
	for(auto x:mp){
		if(i==0) { sam = x.first; i++; continue;}
		i++;
		if(x.first == sam +1){
			count++;
			sam=x.first;
		}else{
			maxval = max(maxval,count);
			count=1;
			sam=x.first;
		}
	}
	maxval=max(maxval,count);
	return maxval;
}
// complexity O(n)
// space O(n)


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
		cout<<lcs(arr,n)<<endl;
	}
	return 0;
}

7. longest substring with repeat
#include <bits/stdc++.h>
using namespace std;

// Method 1:
// Let us talk about the linear time solution now. This solution uses extra space to store the last indexes of already visited characters. 
// The idea is to scan the string from left to right, keep track of the maximum length Non-Repeating Character 
// Substring seen so far in res. When we traverse the string, to know the length of current window we need to indexes.
// 1) Ending index ( j ) : We consider current index as ending index.
// 2) Starting index ( i ) : It is same as previous window if current character was not present in the previous window. 
// To check if the current character was present in the previous window or not, we store last index of every character in an array lasIndex[].
// If lastIndex[str[j]] + 1 is more than previous start, then we updated the start index i. Else we keep same i.

int lrs(string arr,int n){
    int res = 0;
    vector<int> mp(256, -1); 
    int i = 0; 
    for (int j = 0; j < n; j++) { 
        i = max(i, mp[arr[j]] + 1); 
        res = max(res, j - i + 1); 
        mp[arr[j]] = j; 
    } 
    return res; 
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
	string arr;
	while(t--){
		cin>>arr;
		int n=arr.size();
		// vector<int> arr;
		// for(int i=0;i<n;i++){
		// 	cin>>a;
		// 	arr.push_back(a);
		// }
		cout<<lrs(arr,n)<<endl;
	}
	return 0;
}

Day 5:
1. Add 2 number as linkedlist
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}
int len(struct Node *root){
	int a=0;
	while(root!=NULL) {
		root=root->next;
		a++;
	}
	return a;
}

struct Node* revs(struct Node *root){
	struct Node *pre=NULL,*curr=root;
	struct Node *h=NULL;
	while(curr != NULL){
		h = curr->next;
		curr->next = pre;
		pre = curr;
		curr = h;
	}
	root = pre;
	return root;
}

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}

struct Node* sumlinklist(struct Node *node1,struct Node *node2){
	struct Node *temp1=node1,*temp2=node2;
	temp1 = revs(temp1);
	temp2 = revs(temp2);
	struct Node *root1=temp1,*root2=temp2;
	int carry=0;
	while(root2!=NULL){
		int count = root1->data+root2->data+carry;
		carry = (count>=10)? 1:0;
		root1->data=count%10;
		if(root1->next == NULL && carry==1) {
			root1->next = new Node(carry);
			root1=root1->next;
		}
		root1=root1->next;
		root2=root2->next;
	}
	while(root1!=NULL){
		int count = root1->data+carry;
		carry = (count>=10)? 1:0;
		root1->data=count%10;
		if(root1->next == NULL && carry==1) {
			root1->next = new Node(carry);
			root1=root1->next;
		}
		root1=root1->next;
	}
	temp1 = revs(temp1);
	return temp1;
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
		struct Node *root1=NULL,*root2=NULL;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a;
			root1=insert(root1,a);
		}
		for(int i=0;i<m;i++){
			cin>>a;
			root2=insert(root2,a);
		}
		int len1=len(root1);
		int len2=len(root2);
		if(len1>len2){
			root1 = sumlinklist(root1,root2);
			print(root1);
		}
		else {
			root2 = sumlinklist(root2,root1);
			print(root2);
		}
        
	}
	return 0;
}

2. delete a given node
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}
// Method 1:
void deleteNode(struct Node **node){
    if((*node) == NULL) return;
    struct Node *temp = (*node)->next->next;
    swap((*node)->data,(*node)->next->data);
    (*node)->next = temp;
}
// This solution doesn’t work if the node to be deleted is the last node of the list. 
// To make this solution work we can mark the end node as a dummy node. 
// But the programs/functions that are using this function should also be modified.

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
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
		struct Node *root=NULL;
		cin>>n>>m;
        m--;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
		Node *node = root;
        while(m--){
            node=node->next;
        }
        // cout<<node->data<<endl;
        deleteNode(&node);
        print(root);
	}
	return 0;
}

3.merge 2 sorted linked list
// C++ program to merge two sorted linked lists 
// in-place. 
#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
// Function to create newNode in a linkedlist 
struct Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 
  
// A utility function to print linked list 
void printList(struct Node* node) 
{ 
    while (node != NULL) { 
        printf("%d  ", node->data); 
        node = node->next; 
    } 
} 
  
// Merges two lists with headers as h1 and h2. 
// It assumes that h1's data is smaller than 
// or equal to h2's data. 
struct Node* mergeUtil(struct Node* h1, 
                       struct Node* h2) 
{ 
    // if only one node in first list 
    // simply point its head to second list 
    if (!h1->next) { 
        h1->next = h2; 
        return h1; 
    } 
  
    // Initialize current and next pointers of 
    // both lists 
    struct Node *curr1 = h1, *next1 = h1->next; 
    struct Node *curr2 = h2, *next2 = h2->next; 
  
    while (next1 && curr2) { 
        // if curr2 lies in between curr1 and next1 
        // then do curr1->curr2->next1 
        if ((curr2->data) >= (curr1->data) && (curr2->data) <= (next1->data)) { 
            next2 = curr2->next; 
            curr1->next = curr2; 
            curr2->next = next1; 
  
            // now let curr1 and curr2 to point 
            // to their immediate next pointers 
            curr1 = curr2; 
            curr2 = next2; 
        } 
        else { 
            // if more nodes in first list 
            if (next1->next) { 
                next1 = next1->next; 
                curr1 = curr1->next; 
            } 
  
            // else point the last node of first list 
            // to the remaining nodes of second list 
            else { 
                next1->next = curr2; 
                return h1; 
            } 
        } 
    } 
    return h1; 
} 
  
// Merges two given lists in-place. This function 
// mainly compares head nodes and calls mergeUtil() 
struct Node* merge(struct Node* h1, 
                   struct Node* h2) 
{ 
    if (!h1) 
        return h2; 
    if (!h2) 
        return h1; 
  
    // start with the linked list 
    // whose head data is the least 
    if (h1->data < h2->data) 
        return mergeUtil(h1, h2); 
    else
        return mergeUtil(h2, h1); 
} 
  
// Driver program 
int main() 
{ 
    struct Node* head1 = newNode(1); 
    head1->next = newNode(3); 
    head1->next->next = newNode(5); 
  
    // 1->3->5 LinkedList created 
  
    struct Node* head2 = newNode(0); 
    head2->next = newNode(2); 
    head2->next->next = newNode(4); 
  
    // 0->2->4 LinkedList created 
  
    struct Node* mergedhead = merge(head1, head2); 
  
    printList(mergedhead); 
    return 0; 
} 

4.find middle of linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}
// Method 1:
void middle(struct Node *root){
	struct Node *fast = root,*slow=root;
	while(fast->next!=NULL){
		fast = fast->next;
		if(fast->next!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
	}
	cout<<slow->data<<" "<<endl;
}

// Method 2:
void middle(struct Node *head) 
{ 
    int count = 0; 
    struct Node *mid = head; 
  
    while (head != NULL) 
    { 
        /* update mid, when 'count' is odd number */
        if (count & 1) 
            mid = mid->next; 
  
        ++count; 
        head = head->next; 
    } 
  
    /* if empty list is provided */
    if (mid != NULL) 
        printf("The middle element is [%d]\n\n", mid->data); 
} 

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
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
		struct Node *root=NULL;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
		middle(root);
		// print(root);
	}
	return 0;
}

5. remove nth node from back of linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}
// Method 1:
// Deleting Bth node from last is basically same as deleting (length-B+1) from start. 
// In our approach first we evaluate the length of linked-list, then check

// If length < B, then we can’t remove the node
// If length = B, then return head->next
// If length > B, then it means we have to delete the intermediate node, 
// we will delete this node and make its prev node point to next node of deleted node.
Node* removeNthFromEnd(Node* head, int B) 
{ 
    // To store length of the linked list 
    int len = 0; 
    Node* tmp = head; 
    while (tmp != NULL) { 
        len++; 
        tmp = tmp->next;  
    } 
      
    // B > length, then we can't remove node 
    if (B > len)  
    { 
        cout << "Length of the linked list is " << len; 
        cout  << " we can't remove "<< B << "th node from the"; 
        cout << " linked list\n"; 
        return head;  
    } 
      
    // We need to remove head node 
    else if (B == len) { 
          
        // Return head->next 
        return head->next;  
          
    } 
    else 
    { 
        // Remove len - B th node from starting 
        int diff = len - B;           
        Node* prev= NULL;        
        Node* curr = head;          
        for(int i = 0;i < diff;i++){ 
            prev = curr;             
            curr = curr->next;       
        } 
        prev->next = curr->next; 
        return head; 
    } 
      
} 

// Method 2:
// Take two pointers, first will point to the head of the linked list and second will point to the Nth node from the beginning.
// Now keep increment both the pointers by one at the same time until second is pointing to the last node of the linked list.
// After the operations from the previous step, first pointer should be pointing to the Nth node from the end by now.
// So, delete the node first pointer is pointing to.
Node* deleteNode(int key) 
    { 
  
        // First pointer will point to 
        // the head of the linked list 
        Node *first = head; 
  
        // Second pointer will poin to the 
        // Nth node from the beginning 
        Node *second = head; 
        for (int i = 0; i < key; i++) 
        { 
  
            // If count of nodes in the given 
            // linked list is <= N 
            if (second->next == NULL)  
            { 
  
                // If count = N i.e. 
                // delete the head node 
                if (i == key - 1) 
                    head = head->next; 
                return head; 
            } 
            second = second->next; 
        } 
  
        // Increment both the pointers by one until 
        // second pointer reaches the end 
        while (second->next != NULL) 
        { 
            first = first->next; 
            second = second->next; 
        } 
  
        // First must be pointing to the 
        // Nth node from the end by now 
        // So, delete the node first is pointing to 
        first->next = first->next->next; 
        return head; 
} 

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
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
		struct Node *root=NULL;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
		lastn(root,m);
		// print(root);
	}
	return 0;
}
6. reverse a linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}

// Method 1:(simple iterative)
struct Node* reverse(struct Node *root) {
	struct Node *pre=NULL,*curr=root;
	struct Node *h=NULL;
	while(curr != NULL){
		h = curr->next;
		curr->next = pre;
		pre = curr;
		curr = h;
	}
	root = pre;
	return root;
}
// Method 2: (recursive method)
 // 1) Divide the list in two parts - first node and 
 //      rest of the linked list.
 //   2) Call reverse for the rest of the linked list.
 //   3) Link rest to first.
 //   4) Fix head pointer
Node* reverse(Node* head) 
    { 
        if (head == NULL || head->next == NULL) 
            return head; 
  
        /* reverse the rest list and put  
          the first element at the end */
        Node* rest = reverse(head->next); 
        head->next->next = head; 
  
        /* tricky step -- see the diagram */
        head->next = NULL; 
  
        /* fix the head pointer */
        return rest; 
 }

 // Method 3:
  
// A simple and tail recursive function to reverse 
// a linked list.  prev is passed as NULL initially. 
void reverseUtil(Node* curr, Node* prev, Node** head) 
{ 
    /* If last node mark it head*/
    if (!curr->next) { 
        *head = curr; 
  
        /* Update next to prev node */
        curr->next = prev; 
        return; 
    } 
  
    /* Save curr->next node for recursive call */
    Node* next = curr->next; 
  
    /* and update next ..*/
    curr->next = prev; 
  
    reverseUtil(next, curr, head); 
}  

 void reverse(Node** head) 
{ 
    if (!head) 
        return; 
    reverseUtil(*head, NULL, head); 
} 

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
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
		struct Node *root=NULL;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
		root=reverse(root);
		print(root);
	}
	return 0;
}


Day 6:
1.clone a linkedlist with random pointer
// C++ program to clone a linked list with next 
// and arbit pointers in O(n) time 
#include <bits/stdc++.h> 
using namespace std; 
  
// Structure of linked list Node 
struct Node 
{ 
    int data; 
    Node *next,*random; 
    Node(int x) 
    { 
        data = x; 
        next = random = NULL; 
    } 
}; 
  
// Utility function to print the list. 
void print(Node *start) 
{ 
    Node *ptr = start; 
    while (ptr) 
    { 
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl; 
        ptr = ptr->next; 
    } 
} 
  
// This function clones a given linked list 
// in O(1) space 
Node* clone(Node *start) 
{ 
    Node* curr = start, *temp; 
  
    // insert additional node after 
    // every node of original list 
    while (curr) 
    { 
        temp = curr->next; 
  
        // Inserting node 
        curr->next = new Node(curr->data); 
        curr->next->next = temp; 
        curr = temp; 
    } 
  
    curr = start; 
  
    // adjust the random pointers of the 
    // newly added nodes 
    while (curr) 
    { 
        if(curr->next) 
            curr->next->random = curr->random ?  
                                 curr->random->next : curr->random; 
  
        // move to the next newly added node by 
        // skipping an original node 
        curr = curr->next?curr->next->next:curr->next; 
    } 
  
    Node* original = start, *copy = start->next; 
  
    // save the start of copied linked list 
    temp = copy; 
  
    // now separate the original list and copied list 
    while (original && copy) 
    { 
        original->next = 
         original->next? original->next->next : original->next; 
  
        copy->next = copy->next?copy->next->next:copy->next; 
        original = original->next; 
        copy = copy->next; 
    } 
  
    return temp; 
} 
  
// Driver code 
int main() 
{ 
    Node* start = new Node(1); 
    start->next = new Node(2); 
    start->next->next = new Node(3); 
    start->next->next->next = new Node(4); 
    start->next->next->next->next = new Node(5); 
  
    // 1's random points to 3 
    start->random = start->next->next; 
  
    // 2's random points to 1 
    start->next->random = start; 
  
    // 3's and 4's random points to 5 
    start->next->next->random = 
                    start->next->next->next->next; 
    start->next->next->next->random = 
                    start->next->next->next->next; 
  
    // 5's random points to 2 
    start->next->next->next->next->random = 
                                      start->next; 
  
    cout << "Original list : \n"; 
    print(start); 
  
    cout << "\nCloned list : \n"; 
    Node *cloned_list = clone(start); 
    print(cloned_list); 
  
    return 0; 
} 

2. detect Cycle
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}
// Method 1:
// change all the no to a max no and if max no come again
// than loop is found
bool detectloop(struct Node *root){
    int max = 10000;
    while(root!=NULL){
        if(root->data > max) return true;
        else root->data = max+1;
        root = root->next;
    }
    return false;
}
// Method 2:
// similar like finding middle
// use 2 pointer one is fast and other is slow
// if fast pointer equals slow then loop
//  Floyd’s Cycle-Finding Algorithm
// Approach: This is the fastest method and has been described below:

// Traverse linked list using two pointers.
// Move one pointer(slow_p) by one and another pointer(fast_p) by two. 
// If these pointers meet at the same node then there is a loop. 
// If pointers do not meet then linked list doesn’t have a loop.

bool detectloop(struct Node *root) {
    struct Node *fast = root,*slow = root;
    while (slow && fast && fast->next) { 
        slow = slow->next; 
        fast = fast->next->next; 
        if (slow == fast) { 
            return true; 
        } 
    } 
    return false; 
}

// Method 3:
// Approach:
// Traverse the list one by one and keep putting the node addresses in a Hash Table. 
// At any point, if NULL is reached then return false and if next of current node points
// to any of the previously stored nodes in Hash then return true.
bool detectLoop(struct Node* h) 
{ 
    unordered_set<Node*> s; 
    while (h != NULL) { 
        // If this node is already present 
        // in hashmap it means there is a cycle 
        // (Because you we encountering the 
        // node for the second time). 
        if (s.find(h) != s.end()) 
            return true; 
  
        // If we are seeing the node for 
        // the first time, insert it in hash 
        s.insert(h); 
  
        h = h->next; 
    } 
  
    return false; 
} 
void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,m,k; cin>>t;
	while(t--){
		struct Node *root=NULL;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
        // root->next->next->next->next = root; 
		if(detectloop(root)) cout<<"loop"<<endl;
        else cout<<"no loop"<<endl;		
	}
	return 0;
}

3. find intersection poin tof y linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}

int len(struct Node *root){
	int a=0;
	while(root!=NULL) {
		root=root->next;
		a++;
	}
	return a;
}

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}
// Method 1:
int intersection(struct Node *root1,struct Node *root2,int d){
	struct Node *node1=root1,*node2=root2;
	while(d--){
		node1=node1->next;
	}
	while(node1!=NULL && node2!=NULL){
		// cout<<node1->data <<" "<<node2->data<<endl;
		if(node1->data == node2->data) return node1->data;
		node1 =node1->next;
		node2=node2->next;
	}
	return -1;
}
// complexity:O(m+n)
// space:O(1)

// Method 2:
// 1) Let X be the length of the first linked list until intersection point.
//    Let Y be the length of the second linked list until the intersection point.
//    Let Z be the length of the linked list from the intersection point to End of
//    the linked list including the intersection node.
//    We Have
//            X + Z = C1;
//            Y + Z = C2;
// 2) Reverse first linked list.
// 3) Traverse Second linked list. Let C3 be the length of second list - 1. 
//      Now we have
//         X + Y = C3
//      We have 3 linear equations. By solving them, we get
//        X = (C1 + C3 – C2)/2;
//        Y = (C2 + C3 – C1)/2;
//        Z = (C1 + C2 – C3)/2;
//       WE GOT THE INTERSECTION POINT.
// 4)  Reverse first linked list.
// Advantage: No Comparison of pointers.
// Disadvantage : Modifying linked list(Reversing list).

// Time complexity: O(m+n)
// Auxiliary Space: O(1)


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
		struct Node *root1=NULL,*root2=NULL;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a;
			root1=insert(root1,a);
		}
		for(int i=0;i<m;i++){
			cin>>a;
			root2=insert(root2,a);
		}
		int point;
		int len1=len(root1);
		int len2=len(root2);
		int d= abs(len1-len2);
		if(len1>len2){
			point = intersection(root1,root2,d);
			// print(root1);
		}
		else {
			point = intersection(root2,root1,d);
			// print(root2);
		}
		cout<<point<<endl;
        
	}
	return 0;
}

4. linkedlistpallidrone
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}
int len(struct Node *root){
	int a=0;
	while(root!=NULL) {
		root=root->next;
		a++;
	}
	return a;
}

struct Node* revs(struct Node *root){
	struct Node *pre=NULL,*curr=root;
	struct Node *h=NULL;
	while(curr != NULL){
		h = curr->next;
		curr->next = pre;
		pre = curr;
		curr = h;
	}
	root = pre;
	return root;
}

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}

// Method 1:using stack
bool isPalindrome(Node *head){
	stack<int> stk;
	struct Node* root = head,*node=head;
	while(root!=NULL){
		stk.push(root->data);
		root=root->next;
	}
	while(node!=NULL){
		int d = stk.top();
		stk.pop();
		if(d != node->data) return false;
		node = node->next; 
	}
	return true;
}

// METHOD 2 (By reversing the list)
// This method takes O(n) time and O(1) extra space.
// 1) Get the middle of the linked list.
// 2) Reverse the second half of the linked list.
// 3) Check if the first half and second half are identical.
// 4) Construct the original linked list by reversing the second half again and attaching it back to the first half

// To divide the list in two halves, method 2 of this post is used.
// When number of nodes are even, the first and second half contain exactly half nodes. 
// The challenging thing in this method is to handle the case when number of nodes are odd. 
// We don’t want the middle node as part of any of the lists as we are going to compare them for equality. 
// For odd case, we use a separate variable ‘midnode’.
  
/* Function to check if given linked list is 
  palindrome or not */
bool isPalindrome(struct Node* head) 
{ 
    struct Node *slow_ptr = head, *fast_ptr = head; 
    struct Node *second_half, *prev_of_slow_ptr = head; 
    struct Node* midnode = NULL; // To handle odd size list 
    bool res = true; // initialize result 
  
    if (head != NULL && head->next != NULL) { 
        /* Get the middle of the list. Move slow_ptr by 1 
          and fast_ptrr by 2, slow_ptr will have the middle 
          node */
        while (fast_ptr != NULL && fast_ptr->next != NULL) { 
            fast_ptr = fast_ptr->next->next; 
  
            /*We need previous of the slow_ptr for 
             linked lists  with odd elements */
            prev_of_slow_ptr = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
  
        /* fast_ptr would become NULL when there are even elements in list.  
           And not NULL for odd elements. We need to skip the middle node  
           for odd case and store it somewhere so that we can restore the 
           original list*/
        if (fast_ptr != NULL) { 
            midnode = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
  
        // Now reverse the second half and compare it with first half 
        second_half = slow_ptr; 
        prev_of_slow_ptr->next = NULL; // NULL terminate first half 
        reverse(&second_half); // Reverse the second half 
        res = compareLists(head, second_half); // compare 
  
        /* Construct the original list back */
        reverse(&second_half); // Reverse the second half again 
  
        // If there was a mid node (odd size case) which 
        // was not part of either first half or second half. 
        if (midnode != NULL) { 
            prev_of_slow_ptr->next = midnode; 
            midnode->next = second_half; 
        } 
        else
            prev_of_slow_ptr->next = second_half; 
    } 
    return res; 
} 
  
/* Function to reverse the linked list  Note that this 
    function may change the head */
void reverse(struct Node** head_ref) 
{ 
    struct Node* prev = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
  
/* Function to check if two input lists have same data*/
bool compareLists(struct Node* head1, struct Node* head2) 
{ 
    struct Node* temp1 = head1; 
    struct Node* temp2 = head2; 
  
    while (temp1 && temp2) { 
        if (temp1->data == temp2->data) { 
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        } 
        else
            return 0; 
    } 
  
    /* Both are empty reurn 1*/
    if (temp1 == NULL && temp2 == NULL) 
        return 1; 
  
    /* Will reach here when one is NULL 
      and other is not */
    return 0; 
} 

// METHOD 3 (Using Recursion)
// Use two pointers left and right. Move right and left using recursion and check for following in each recursive call.
// 1) Sub-list is palindrome.
// 2) Value at current left and right are matching.

// If both above conditions are true then return true.

// The idea is to use function call stack as container. Recursively traverse till the end of list. When we return from last NULL,
// we will be at last node. The last node to be compared with first node of list.

// In order to access first node of list, we need list head to be available in the last call of recursion.
// Hence we pass head also to the recursive function. If they both match we need to compare (2, n-2) nodes.
// Again when recursion falls back to (n-2)nd node, we need reference to 2nd node from head. We advance the head pointer in previous call, 
// to refer to next node in the list.

// However, the trick in identifying double pointer. 
// Passing single pointer is as good as pass-by-value, 
// and we will pass the same pointer again and again. 
// We need to pass the address of head pointer for reflecting the changes in parent recursive calls.

bool isPalindromeUtil(struct node** left, struct node* right) 
{ 
    /* stop recursion when right becomes NULL */
    if (right == NULL) 
        return true; 
  
    /* If sub-list is not palindrome then no need to 
    check for current left and right, return false */
    bool isp = isPalindromeUtil(left, right->next); 
    if (isp == false) 
        return false; 
  
    /* Check values at current left and right */
    bool isp1 = (right->data == (*left)->data); 
  
    /* Move left to next node */
    *left = (*left)->next; 
  
    return isp1; 
} 
  
// A wrapper over isPalindromeUtil() 
bool isPalindrome(struct node* head) 
{ 
    isPalindromeUtil(&head, head); 
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
		struct Node *root=NULL;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
		cout<<isPalindrome(root)<<endl;
		
        
	}
	return 0;
}

5. remove cycle
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}

// Method 1:
// similar like finding middle
// use 2 pointer one is fast and other is slow
// if fast pointer equals slow then loop
//  Floyd’s Cycle-Finding Algorithm
// Approach: This is the fastest method and has been described below:

// Traverse linked list using two pointers.
// Move one pointer(slow_p) by one and another pointer(fast_p) by two. 
// If these pointers meet at the same node then there is a loop. 
// If pointers do not meet then linked list doesn’t have a loop.
void rmcycle(struct Node *loop,struct Node *root){
	struct Node *ptr1,*ptr2;
	ptr1=root;
	while(1){
		ptr2 = loop;
		while(ptr2->next!=loop && ptr2->next != ptr1){
			ptr2=ptr2->next;
		}
		if(ptr2->next == ptr1) break;
		ptr1 = ptr1->next;
	}
	ptr2->next = NULL;
}

// Method 2 (Better Solution)

// This method is also dependent on Floyd’s Cycle detection algorithm.
// Detect Loop using Floyd’s Cycle detection algorithm and get the pointer to a loop node.
// Count the number of nodes in loop. Let the count be k.
// Fix one pointer to the head and another to a kth node from the head.
// Move both pointers at the same pace, they will meet at loop starting node.
// Get a pointer to the last node of the loop and make next of it as NULL.

void rmLoop(struct Node* loop_node, struct Node* head) 
{ 
    struct Node* ptr1 = loop_node; 
    struct Node* ptr2 = loop_node; 
  
    // Count the number of nodes in loop 
    unsigned int k = 1, i; 
    while (ptr1->next != ptr2) { 
        ptr1 = ptr1->next; 
        k++; 
    } 
  
    // Fix one pointer to head 
    ptr1 = head; 
  
    // And the other pointer to k nodes after head 
    ptr2 = head; 
    for (i = 0; i < k; i++) 
        ptr2 = ptr2->next; 
  
    /*  Move both pointers at the same pace, 
      they will meet at loop starting node */
    while (ptr2 != ptr1) { 
        ptr1 = ptr1->next; 
        ptr2 = ptr2->next; 
    } 
  
    // Get pointer to the last node 
    while (ptr2->next != ptr1) 
        ptr2 = ptr2->next; 
  
    /* Set the next node of the loop ending node 
      to fix the loop */
    ptr2->next = NULL; 
} 

bool detectloop(struct Node *root) {
    struct Node *fast = root,*slow = root;
    while (slow && fast && fast->next) { 
        slow = slow->next; 
        fast = fast->next->next; 
        if (slow == fast) { 
        	rmcycle(slow,root);
            return true; 
        } 
    } 
    return false; 
}

// Method 3 (Optimized Method 2: Without Counting Nodes in Loop)
// We do not need to count number of nodes in Loop. After detecting the loop, if we start slow pointer from head and move both slow and fast pointers at same speed until fast don’t meet, they would meet at the beginning of the loop.

// How does this work?
// Let slow and fast meet at some point after Floyd’s Cycle finding algorithm. Below diagram shows the situation when cycle is found.




// LinkedListCycle

// We can conclude below from above diagram


// Distance traveled by fast pointer = 2 * (Distance traveled 
//                                          by slow pointer)

// (m + n*x + k) = 2*(m + n*y + k)

// Note that before meeting the point shown above, fast
// was moving at twice speed.

// x -->  Number of complete cyclic rounds made by 
//        fast pointer before they meet first time

// y -->  Number of complete cyclic rounds made by 
//        slow pointer before they meet first time

// From above equation, we can conclude below

//     m + k = (x-2y)*n

// Which means m+k is a multiple of n. 
// So if we start moving both pointers again at same speed such that one pointer (say slow) begins from head node of linked list and other pointer (say fast) begins from meeting point. When slow pointer reaches beginning of loop (has made m steps), fast pointer would have made also moved m steps as they are now moving same pace. Since m+k is a multiple of n and fast starts from k, they would meet at the beginning. Can they meet before also? No because slow pointer enters the cycle first time after m steps.


void detectAndRemoveLoop(Node* head) 
{ 
    // If list is empty or has only one node 
    // without loop 
    if (head == NULL || head->next == NULL) 
        return; 
  
    Node *slow = head, *fast = head; 
  
    // Move slow and fast 1 and 2 steps 
    // ahead respectively. 
    slow = slow->next; 
    fast = fast->next->next; 
  
    // Search for loop using slow and 
    // fast pointers 
    while (fast && fast->next) { 
        if (slow == fast) 
            break; 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
  
    /* If loop exists */
    if (slow == fast) { 
        slow = head; 
        while (slow->next != fast->next) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
  
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    } 
} 

// Method 4 Hashing: Hash the address of the linked list nodes
// We can hash the addresses of the linked list nodes in an unordered map and just check if the element already exists in the map. 
// If it exists, we have reached a node which already exists by a cycle,
// hence we need to make the last node’s next pointer NULL.
void hashAndRemove(Node* head) 
{ 
    // hash map to hash addresses of the linked list nodes 
    unordered_map<Node*, int> node_map; 
    // pointer to last node 
    Node* last = NULL; 
    while (head != NULL) { 
        // if node not present in the map, insert it in the map 
        if (node_map.find(head) == node_map.end()) { 
            node_map[head]++; 
            last = head; 
            head = head->next; 
        } 
        // if present, it is a cycle, make the last node's next pointer NULL 
        else { 
            last->next = NULL; 
            break; 
        } 
    } 
}
 
void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,m,k; cin>>t;
	while(t--){
		struct Node *root=NULL;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
        root->next->next->next->next = root; 
		if(detectloop(root)) cout<<"loop"<<endl;
        else cout<<"no loop"<<endl;		
        if(detectloop(root)) cout<<"loop"<<endl;
        else cout<<"no loop"<<endl;		
	}
	return 0;
}

6. flattenlinkedlist
// C++ program for Flattening 
// a linked list using Heaps 
#include <bits/stdc++.h> 
using namespace std; 

// Structure of given Linked list 
struct Node { 
	int data; 
	struct Node* right; 
	struct Node* left; 

	Node(int x) 
	{ 
		data = x; 
		right = NULL; 
		left = NULL; 
	} 
}; 

// Function to print the 
// linked list 
void printList(Node* Node) 
{ 
	while (Node != NULL) { 
		printf("%d ", Node->data); 
		Node = Node->left; 
	} 
} 

// Function that compares the value 
// pointed by node and returns true 
// if first data is greater 
struct compare { 
	bool operator()(Node* a, Node* b) 
	{ 
		return a->data > b->data; 
	} 
}; 

// Function which returns the root 
// of the flattened linked list 
Node* flatten(Node* root) 
{ 
	Node* ptr = root; 
	Node* head = NULL; 

	// Min Heap which will return 
	// smallest element currently 
	// present in heap 
	priority_queue<Node*, 
				vector<Node*>, 
				compare> 
		pq; 

	// Push the head nodes of each 
	// leftward linked list 
	while (ptr != NULL) { 
		pq.push(ptr); 
		ptr = ptr->right; 
	} 

	// This loop will execute 
	// till the map becomes empty 
	while (!pq.empty()) { 

		// Pop out the node that 
		// contains element 
		// currently in heap 
		Node* temp = pq.top(); 
		pq.pop(); 

		// Push the next node pointed by 
		// the current node into heap 
		// if it is not null 
		if (temp->left != NULL) { 
			pq.push(temp->left); 
		} 

		// Create new linked list 
		// that is to be returned 
		if (head == NULL) { 
			head = temp; 
			ptr = temp; 
		} 
		else { 
			ptr->left = temp; 
			ptr = temp; 
		} 
	} 

	// Pointer to head node 
	// in the linked list 
	return head; 
} 

// Create and push new nodes 
void push(Node** head_ref, 
		int new_data) 
{ 
	Node* new_node = (Node*)malloc(sizeof(Node)); 
	new_node->right = NULL; 
	new_node->data = new_data; 
	new_node->left = (*head_ref); 

	(*head_ref) = new_node; 
} 

// Driver Code 
int main() 
{ 
	Node* root = NULL; 

	// Given Linked List 
	push(&root, 30); 
	push(&root, 8); 
	push(&root, 7); 
	push(&root, 5); 

	push(&(root->right), 20); 
	push(&(root->right), 10); 

	push(&(root->right->right), 50); 
	push(&(root->right->right), 22); 
	push(&(root->right->right), 19); 

	push(&(root->right->right->right), 45); 
	push(&(root->right->right->right), 40); 
	push(&(root->right->right->right), 35); 
	push(&(root->right->right->right), 20); 

	// Flatten the list 
	root = flatten(root); 

	// Print the flatened linked list 
	printList(root); 

	return 0; 
} 


7.reverse a linked list in group
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}
int len(struct Node *root){
	int a=0;
	while(root!=NULL) {
		root=root->next;
		a++;
	}
	return a;
}

struct Node* revs(struct Node *root){
	struct Node *pre=NULL,*curr=root;
	struct Node *h=NULL;
	while(curr != NULL){
		h = curr->next;
		curr->next = pre;
		pre = curr;
		curr = h;
	}
	root = pre;
	return root;
}

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}
// Good Question 
// Method 1:
// 1
// 8 3
// 1 2 3 4 5 6 7 8
// you have 3 set of result 123 456 and 78 
// so first reverse first set and change the root pointer for another set
// Reverse the first sub-list of size k. While reversing keep track of the next node and previous node. Let the pointer to the next node be next and pointer to the previous node be prev. See this post for reversing a linked list.
// head->next = reverse(next, k) ( Recursively call for rest of the list and link the two sub-lists )
// Return prev ( prev becomes the new head of the list (see the diagrams of iterative method of this post) )

struct Node *grpreverse(struct Node *root,int k){
    struct Node *temp = root,*prev=NULL,*curr=root,*h=NULL,*last;
    int i=0;
    while(curr!=NULL && i<k){
        h=curr->next;
        curr->next=prev;
        prev=curr;
        curr=h;
        i++;
    }

    if(h!=NULL){
        root->next = grpreverse(h,k);
    }
    return prev;
}

// Method 2:
//  we have used a stack which will store the nodes of the given linked list.
//   Firstly, push the k elements of the linked list in the stack.
//    Now pop elements one by one and keep track of the previously popped node.
//     Point the next pointer of prev node to top element of stack. 
//     Repeat this process, until NULL is reached.

// This algorithm uses O(k) extra space.
struct Node* Reverse(struct Node* head, int k) 
{ 
    // Create a stack of Node* 
    stack<Node*> mystack; 
    struct Node* current = head; 
    struct Node* prev = NULL; 
  
    while (current != NULL) { 
  
        // Terminate the loop whichever comes first 
        // either current == NULL or count >= k 
        int count = 0; 
        while (current != NULL && count < k) { 
            mystack.push(current); 
            current = current->next; 
            count++; 
        } 
  
        // Now pop the elements of stack one by one 
        while (mystack.size() > 0) { 
  
            // If final list has not been started yet. 
            if (prev == NULL) { 
                prev = mystack.top(); 
                head = prev; 
                mystack.pop(); 
            } else { 
                prev->next = mystack.top(); 
                prev = prev->next; 
                mystack.pop(); 
            } 
        } 
    } 
  
    // Next of last element will point to NULL. 
    prev->next = NULL; 
  
    return head; 
}

// Method 3:
// Approach: Two different approaches to solve this problem have been discussed in Set 1 and Set 2 of this article. In this article, an approach based on deque will be discussed.
// Create a deque.
// Store the address of the first k nodes in the deque.
// Pop first and the last value from the deque and swap the data values at those addresses.
// Repeat step 3 till the deque is not empty.
// Repeat step 2 for the next k nodes and till the end of the linked list is not reached.
/* Function to reverse the linked list in groups of  
size k and return the pointer to the new head node. */
struct node* reverse(struct node* head, int k) 
{ 
  
    if (head == NULL) 
        return head; 
  
    // Create deque to store the address 
    // of the nodes of the linked list 
    deque<node*> q; 
  
    // Store head pointer in current to 
    // traverse the linked list 
    node* current = head; 
    int i; 
  
    // Iterate through the entire linked 
    // list by moving the current 
    while (current != NULL) { 
        i = 1; 
  
        // Store addresses of the k 
        // nodes in the deque 
        while (i <= k) { 
            if (current == NULL) 
                break; 
            q.push_back(current); 
            current = current->next; 
            i++; 
        } 
  
        /* pop first and the last value from  
        the deque and swap the data values at  
        those addresses 
        Do this till there exist an address in  
        the deque or deque is not empty*/
        while (!q.empty()) { 
            node* front = q.front(); 
            node* last = q.back(); 
            swap(front->data, last->data); 
  
            // pop from the front if 
            // the deque is not empty 
            if (!q.empty()) 
                q.pop_front(); 
  
            // pop from the back if 
            // the deque is not empty 
            if (!q.empty()) 
                q.pop_back(); 
        } 
    } 
    return head; 
} 
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,m,k; cin>>t;
	while(t--){
		struct Node *root=NULL;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
		root=grpreverse(root,k);
        print(root);		
	}
	return 0;
}

8. rotate a linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}
struct Node* rotate(struct Node *root,int k){
    if(k == 0) return root;
    struct Node *curr = root,*temp=root;
    while(curr!=NULL && k>1){
        curr = curr->next;
        k--;
    }
    if(curr == NULL || curr->next == NULL) return temp;
    struct Node *h = curr->next;
    curr->next=NULL;
    struct Node *fl = h;
    while(fl->next != NULL) fl = fl->next;
    fl->next = temp;
    return h;
}
 
void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,m,k; cin>>t;
	while(t--){
		struct Node *root=NULL;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
        root = rotate(root,k);
        print(root);	
	}
	return 0;
}

Day7

1.find starting point of loop
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}

// Method 1:
int startpoint(struct Node *loop,struct Node *root){
    struct Node *ptr1,*ptr2;
    ptr1=loop;ptr2=loop;
    int k=1;
    while(ptr1->next != ptr2){
        ptr1 = ptr1->next;
        k++;
    }
    ptr1 = root;
    ptr2 = root;
    while(k--){
        ptr1=ptr1->next;
    }
    while(ptr1 != ptr2){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return ptr1->data;
}

int detectloop(struct Node* root){
    struct Node *fast=root,*slow=root;
    while(slow!=NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return startpoint(slow,root);
        }
    }
    return -1;
}

// Method 2:
// Function to detect and remove loop 
// in a linked list that may contain loop 
Node* detectAndRemoveLoop(Node* head) 
{ 
    // If list is empty or has only one node 
    // without loop 
    if (head == NULL || head->next == NULL) 
        return NULL; 
  
    Node *slow = head, *fast = head; 
  
    // Move slow and fast 1 and 2 steps 
    // ahead respectively. 
    slow = slow->next; 
    fast = fast->next->next; 
  
    // Search for loop using slow and 
    // fast pointers 
    while (fast && fast->next) { 
        if (slow == fast) 
            break; 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
  
    // If loop does not exist 
    if (slow != fast) 
        return NULL; 
  
    // If loop exists. Start slow from 
    // head and fast from meeting point. 
    slow = head; 
    while (slow != fast) { 
        slow = slow->next; 
        fast = fast->next; 
    } 
  
}

// Method 3:
ListNode* detectCycle(ListNode* A) 
{ 
  
    // declaring map to store node address 
    unordered_set<ListNode*> uset; 
  
    ListNode *ptr = A; 
  
    // Default consider that no cycle is present 
    while (ptr != NULL) { 
  
        // checking if address is already present in map  
        if (uset.find(ptr) != uset.end())  
          return ptr; 
  
        // if address not present then insert into the set 
        else 
            uset.insert(ptr);  
          
        ptr = ptr->next; 
    } 
    return NULL; 
}

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,m,k; cin>>t;
	while(t--){
		struct Node *root=NULL;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
        root->next->next->next->next->next = root->next->next; 
		cout<<detectloop(root)<<endl;
    }
	return 0;
}

2. max continus no of 1 in array
#include <bits/stdc++.h>
using namespace std;

int count1(vector<int> arr){
	int n= arr.size();
	int l=0,r=0,count=0,maxval=0;
	for (int i = 0; i < n; i++) {  
        if (arr[i] == 0) count = 0;  
        else{ 
            count++;
            maxval = max(maxval, count); 
        } 
    } 
	return maxval;
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
		cout<<count1(arr)<<endl;
	}
	return 0;
}

3. 3sum
#include <bits/stdc++.h>
using namespace std;
// Method 1:(2 pointer)
vector<vector<int>> threeSum( vector<int>& nums,int target ) {
    vector<vector<int>> result;
    int size = nums.size();
    if(size<=2) return result;
    sort(nums.begin(),nums.end());
    for(int i=0;i<size-2;i++){
        if(i>0 && nums[i-1]==nums[i]) continue;
        int start = i+1;
        int end = size-1;
        while(start<end){
            int val = nums[i]+nums[start]+nums[end];
            if(val == target){
                result.push_back({nums[i],nums[start],nums[end]});
                start++;
                end--;
                while(start<end && nums[start]==nums[start-1]) start++;
                while(start<end && nums[end] == nums[end+1]) end--;
            }else if(val<target) start++;
            else end--;
        }
    }
    return result;
}


int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,target; cin>>t;
	while(t--){
		cin>>n>>target;
		vector<int> arr;
		vector<vector<int>> ans;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		ans = threeSum(arr,target);
		// for(auto x:ans) cout<<x<<" ";
        int k=ans.size();
        int l = ans[0].size();
        for(int i=0;i<k;i++){
            for(int j=0;j<l;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
		cout<<endl;
	}
	return 0;
}

4.remvoe duplicate from sorted array
#include <bits/stdc++.h>
using namespace std;

// using vector erase function
// void rmduplicate(vector<int> &arr){
// 	arr.erase(unique(arr.begin(),arr.end()),arr.end());
// 	for(auto x:arr) cout<<x<<" ";
// 	cout<<endl;
// 	cout<<arr.size()<<endl;
// }

// Method 2: using a set
// void rmduplicate(vector<int> arr){
// 	unordered_set<int> st;
// 	for(auto x:arr) st.insert(x);
// 	for(auto x:st) cout<<x<<" ";
// 	cout<<endl;
// 	cout<<st.size()<<endl;

// }
// Method 3: constant space
// void rmduplicate(vector<int> &arr){
// 	int n = arr.size();
  
//     // To store index of next unique element 
//     int j = 0; 
  
//     // Doing same as done in Method 1 
//     // Just maintaining another updated index i.. j 
//     for (int i=0; i < n-1; i++) 
//         if (arr[i] != arr[i+1]) 
//             arr[j++] = arr[i]; 
  
//     arr[j++] = arr[n-1]; 
//     for(int i=0;i<j;i++) cout<<arr[i]<<" ";
// 	cout<<endl;
// 	cout<<j<<endl;
  
// } 

// This is take 2 duplicate and rm remaining
// this is second part of rm duplicte|| on leetcode
void rmduplicate(vector<int> &arr){
	if ( arr.empty() ) return 0;
        int n = arr.size();
	    int j=0,count=1,prev;
        arr[j++]=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i-1] == arr[i]){
                if(count==2) continue;
                arr[j++]=arr[i];
                count++;
                // prev=arr[i];
            }else{
                arr[j++]=arr[i];
                count=1;
            }
        }
        // if(arr[n-1]!=arr[n-2]) arr[j++]=arr[n-1];
        // if(arr[n-1]==arr[n-2] && count<2) arr[j++]=arr[n-1];
    for(int i=0;i<j;i++) cout<<arr[i]<<" ";
	cout<<endl;
	cout<<j<<endl;
  
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
		rmduplicate(arr);
	}
	return 0;
}

5.n meeting in a room
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct job {
    int index;
  int first;
  int second;
};

bool comp(struct job j1,struct job j2){
    return j1.second<j2.second;
}

int main()
{
    ll t,n; cin>>t;
    while(t--) {
        cin>>n;
        ll str[n],fin[n];
        for(ll i=0;i<n;i++){
            cin>>str[i];
        }
        for(ll i=0;i<n;i++){
            cin>>fin[i];
        }
        struct job jobs[n];
        for(ll i=0;i<n;i++){
            jobs[i].index = i+1;
            jobs[i].first = str[i];
            jobs[i].second = fin[i];
        }
        sort(jobs,jobs+n,comp); 
        cout<<jobs[0].index<<" ";
        ll lasjob = jobs[0].second;
        for(ll i=1;i<n;i++){
            if(jobs[i].first>lasjob){
                cout<<jobs[i].index<<" ";
                lasjob = jobs[i].second;
            }
        }
        cout<<endl;
    }
}

6.tapping rainwater
#include <bits/stdc++.h>
using namespace std;

// Method 1:
			//  _           _
			// | |_       _| |
			// | | |_   _| | |
			// | | | |_| | | |
			// | | | | | | | |

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

nt maxWater(int arr[], int n) 
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
    mo
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

Day 8:
1. coin piles
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,k; cin>>t;
    while(t--) {
        cin>>n>>k;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll val = arr[0],count=0;
        for(ll i=1;i<n;i++){
            if(abs(val-arr[i])>k){
                while(abs(val-arr[i])>k){
                    if(val>arr[i]) --val;
                    else --arr[i];
                    count++;
                }
            }
            val=arr[i];
        }
        cout<<count<<endl;
    }
}
// method 2:

int minimumCoins(int a[], int n, int k) 
{ 
    // To store the coins needed to be removed 
    int cnt = 0; 
  
    // Minimum value from the array 
    int minVal = *min_element(a, a + n); 
  
    // Itereate over the array and remove extra coins 
    for (int i = 0; i < n; i++) { 
        int diff = a[i] - minVal; 
  
        // If the difference between the current pile and 
        // the minimum coin pile is greater than k 
        if (diff > k) { 
  
            // Count the extra coins to be removed 
            cnt += (diff - k); 
        } 
    } 
  
    // Return the required count 
    return cnt; 
}

2.job sequecncing
#include <bits/stdc++.h>
using namespace std;

struct job {
	char id;
	int deadline;
	int profit;
};

// Method 1:
// put the job according to their profit
// and put all job in their last slot of deadline first
// if this slot is fill than go to next slot

bool comp(struct job a,struct job b){
	return a.profit>b.profit;
}

void jobsequencing(struct job j1[],int n){
	sort(j1,j1+n,comp);
	int slot[n];
	int result[n];
	memset(slot,false,sizeof(slot));
	for(int i=0;i<n;i++){
		for(int j=min(n,j1[i].deadline)-1;j>=0;j--){
			if(slot[j]==false){
				result[j]=i;
				slot[j]=true;
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(slot[i]) cout<<j1[i].id<<" ";
	}
	cout<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,b,c; cin>>t;
	char a;
	while(t--){
		cin>>n;
		struct job j1[n];
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			j1[i].id=a;
			j1[i].deadline=b;
			j1[i].profit=c;
		}
		jobsequencing(j1,n);
		
	}
	return 0;
}

// Method 2:(using the disjoint set)
// C++ Program to find the maximum profit job sequence 
// from a given array of jobs with deadlines and profits 
#include<bits/stdc++.h> 
using namespace std; 

// A structure to represent various attributes of a Job 
struct Job 
{ 
	// Each job has id, deadline and profit 
	char id; 
	int deadLine, profit; 
}; 

// A Simple Disjoint Set Data Structure 
struct DisjointSet 
{ 
	int *parent; 

	// Constructor 
	DisjointSet(int n) 
	{ 
		parent = new int[n+1]; 

		// Every node is a parent of itself 
		for (int i = 0; i <= n; i++) 
			parent[i] = i; 
	} 

	// Path Compression 
	int find(int s) 
	{ 
		/* Make the parent of the nodes in the path 
		from u--> parent[u] point to parent[u] */
		if (s == parent[s]) 
			return s; 
		return parent[s] = find(parent[s]); 
	} 

	// Makes u as parent of v. 
	void merge(int u, int v) 
	{ 
		//update the greatest available 
		//free slot to u 
		parent[v] = u; 
	} 
}; 

// Used to sort in descending order on the basis 
// of profit for each job 
bool cmp(Job a, Job b) 
{ 
	return (a.profit > b.profit); 
} 

// Functions returns the maximum deadline from the set 
// of jobs 
int findMaxDeadline(struct Job arr[], int n) 
{ 
	int ans = INT_MIN; 
	for (int i = 0; i < n; i++) 
		ans = max(ans, arr[i].deadLine); 
	return ans; 
} 

int printJobScheduling(Job arr[], int n) 
{ 
	// Sort Jobs in descending order on the basis 
	// of their profit 
	sort(arr, arr + n, cmp); 

	// Find the maximum deadline among all jobs and 
	// create a disjoint set data structure with 
	// maxDeadline disjoint sets initially. 
	int maxDeadline = findMaxDeadline(arr, n); 
	DisjointSet ds(maxDeadline); 

	// Traverse through all the jobs 
	for (int i = 0; i < n; i++) 
	{ 
		// Find the maximum available free slot for 
		// this job (corresponding to its deadline) 
		int availableSlot = ds.find(arr[i].deadLine); 

		// If maximum available free slot is greater 
		// than 0, then free slot available 
		if (availableSlot > 0) 
		{ 
			// This slot is taken by this job 'i' 
			// so we need to update the greatest 
			// free slot. Note that, in merge, we 
			// make first parameter as parent of 
			// second parameter. So future queries 
			// for availableSlot will return maximum 
			// available slot in set of 
			// "availableSlot - 1" 
			ds.merge(ds.find(availableSlot - 1), 
							availableSlot); 

			cout << arr[i].id << " "; 
		} 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	Job arr[] = { { 'a', 2, 100 }, { 'b', 1, 19 }, 
				{ 'c', 2, 27 }, { 'd', 1, 25 }, 
				{ 'e', 3, 15 } }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Following jobs need to be "
		<< "executed for maximum profit\n"; 
	printJobScheduling(arr, n); 
	return 0; 
} 

3.min no of coins (greddy algo)
// C++ program to find minimum 
// number of denominations 
#include <bits/stdc++.h> 
using namespace std; 

// All denominations of Indian Currency 
int deno[] = { 1, 2, 5, 10, 20, 
			50, 100, 500, 1000 }; 
int n = sizeof(deno) / sizeof(deno[0]); 

void findMin(int V) 
{ 
	sort(deno, deno + n); 

	// Initialize result 
	vector<int> ans; 

	// Traverse through all denomination 
	for (int i = n - 1; i >= 0; i--) { 

		// Find denominations 
		while (V >= deno[i]) { 
			V -= deno[i]; 
			ans.push_back(deno[i]); 
		} 
	} 

	// Print result 
	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i] << " "; 
} 

// Driver program 
int main() 
{ 
	int n = 93; 
	cout << "Following is minimal"
		<< " number of change for " << n 
		<< ": "; 
	findMin(n); 
	return 0; 
} 

4.fractional knapsack
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
	double r1=(double)a.first/a.second;
	double r2 = (double)b.first/b.second;
	return r1>r2;
}

int fractionalknapsack(vector<pair<int,int>> arr,int n,int w){
	sort(arr.begin(),arr.end(),comp);
	int curWeight = 0; 
    double finalvalue = 0.0; 
    for (int i = 0; i < n; i++) { 
        if (curWeight + arr[i].second <= w) { 
            curWeight += arr[i].second; 
            finalvalue += arr[i].first; 
        } else { 
            int remain = w - curWeight; 
            finalvalue += arr[i].first * ((double) remain / arr[i].second); 
            break; 
        } 
    } 
	return finalvalue;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,w,a,b; cin>>t;
	while(t--){
		cin>>n>>w;
		vector<pair<int,int>> arr;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			arr.push_back({a,b});
		}
		cout<<fractionalknapsack(arr,n,w)<<endl;
		
	}
	return 0;
}

5. min no of platform required
#include <bits/stdc++.h>
using namespace std;

// Method 1:

int minplatform(vector<float> arr,vector<float> dep){
	int n=arr.size();
	int m=dep.size();
	int i=0,j=0;
	int count=0,maxval=INT_MIN;
	while(i<n&&j<m){
		if(arr[i]<dep[j]){
			count++;
			i++;
		}else{
			count--;
			j++;
		}
		maxval = max(maxval,count);
	}
	while(i<n){
		count++;
		i++;
		maxval = max(maxval,count);
	}
	while(j<m){
		count--;
		j++;
		maxval = max(maxval,count);
	}
	return maxval;
}

// Method 2:
// Approach: The idea is to take every interval one by one and find the number of intervals that overlap with it. 
// Keep track of the maximum number of intervals that overlap with an interval. Finally, return the maximum value.
// Algorithm:
// Run two nested loops the outer loop from start to end and inner loop from i+1 to end.
// For every iteration of outer loop find the count of intervals that intersect with the current interval.
// Update the answer with maximum count of overlap in each iteration of outer loop.

int findPlatform(int arr[], int dep[], int n) 
{ 
  
    // plat_needed indicates number of platforms 
    // needed at a time 
    int plat_needed = 1, result = 1; 
    int i = 1, j = 0; 
  
    // run a nested  loop to find overlap 
    for (int i = 0; i < n; i++) { 
        // minimum platform 
        plat_needed = 1; 
  
        for (int j = i + 1; j < n; j++) { 
            // check for overlap 
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i])) 
                plat_needed++; 
        } 
  
        // update result 
        result = max(result, plat_needed); 
    } 
  
    return result; 
} 


// Complexity Analysis:
// Time Complexity: O(n^2).
// Two nested loops traverse the array, so the time complexity is O(n^2).
// Space Complexity: O(1).
// As no extra space is required.



// Method 3:
// Efficient Solution:

// Approach: The idea is to consider all events in sorted order. 
// Once the events are in sorted order, trace the number of trains at any time keeping track of trains that have arrived, 
// but not departed.
// For example consider the above example.

// arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
// dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

// All events are sorted by time.
// Total platforms at any time can be obtained by
// subtracting total departures from total arrivals
// by that time.

//  Time      Event Type     Total Platforms Needed 
//                                at this Time                               
//  9:00       Arrival                  1
//  9:10       Departure                0
//  9:40       Arrival                  1
//  9:50       Arrival                  2
//  11:00      Arrival                  3 
//  11:20      Departure                2
//  11:30      Departure                1
//  12:00      Departure                0
//  15:00      Arrival                  1
//  18:00      Arrival                  2 
//  19:00      Departure                1
//  20:00      Departure                0

// Minimum Platforms needed on railway station 
// = Maximum platforms needed at any time 
// = 3  
// Note: This approach assumes that trains are arriving and departing on the same date.

// Algorithm:
// Sort the arrival and departure time of trains.
// Create two pointers i=0, and j=0 and a variable to store ans and current count plat
// Run a loop while i<n and j<n and compare the ith element of arrival array and jth element of departure array.
// if the arrival time is less than or equal to departure then one more platform is needed so increase the count, i.e. plat++ and increment i
// Else if the arrival time greater than departure then one less platform is needed so decrease the count, i.e. plat++ and increment j
// Update the ans, i.e ans = max(ans, plat).
// Implementation: This doesn’t create a single sorted list of all events, 
// rather it individually sorts arr[] and dep[] arrays, and then uses merge process of merge sort to process them together as a single sorted array.
int findPlatform(int arr[], int dep[], int n) 
{ 
    // Sort arrival and departure arrays 
    sort(arr, arr + n); 
    sort(dep, dep + n); 
  
    // plat_needed indicates number of platforms 
    // needed at a time 
    int plat_needed = 1, result = 1; 
    int i = 1, j = 0; 
  
    // Similar to merge in merge sort to process 
    // all events in sorted order 
    while (i < n && j < n) { 
  
        // If next event in sorted order is arrival, 
        // increment count of platforms needed 
        if (arr[i] <= dep[j]) { 
            plat_needed++; 
            i++; 
        } 
  
        // Else decrement count of platforms needed 
        else if (arr[i] > dep[j]) { 
            plat_needed--; 
            j++; 
        } 
  
        // Update result if needed 
        if (plat_needed > result) 
            result = plat_needed; 
    } 
  
    return result; 
} 
// Complexity Analysis:
// Time Complexity: O(n Log n).
// One traversal of both the array is needed, so the time Complexity is O(n).
// Space Complexity: O(1).
// As no extra space is required.

// Method 4:
// we are inserting all the arrival and departure times in a multimap. 
// The first value of element in multimap tells the arrival/departure time and second value tells whether it’s arrival or departure represented by ‘a’ or ‘d’ respectively.
// If its arrival then do increment by 1 otherwise decrease value by 1. 
// If we are taking the input from STDIN then we can directly insert the times in the multimap and no need to store the times in the array.

int findPlatform(int arr[], int dep[], int n) 
{ 
    // Insert all the times (arr. and dep.) 
    // in the multimap. 
    multimap<int, char> order; 
    for (int i = 0; i < n; i++) { 
  
        // If its arrival then second value 
        // of pair is 'a' else 'd' 
        order.insert(make_pair(arr[i], 'a')); 
        order.insert(make_pair(dep[i], 'd')); 
    } 
  
    int result = 0; 
    int plat_needed = 0; 
  
    multimap<int, char>::iterator it = order.begin(); 
  
    // Start iterating the multimap. 
    for (; it != order.end(); it++) { 
  
        // If its 'a' then add 1 to plat_needed 
        // else minus 1 from plat_needed. 
        if ((*it).second == 'a') 
            plat_needed++; 
        else
            plat_needed--; 
  
        if (plat_needed > result) 
            result = plat_needed; 
    } 
    return result; 
} 

// Method 5:
// If all the arrival and departure occur on the same day then we can use and auxiliary array to compute the required number of the platform in O(n).

// Whenever an arrival occurs we increase the count of the required platform when a departure occurs we decrease the required platform at that point of time, 
// after that, we take the cumulative sum, which would provide the required number of platform for all point of time, out of these values maximum value is our answer.
int minPlatform(int arrival[], int departure[], int n) 
{ 
  
    // as time range from 0 to 2359 in 24 hour clock, 
    // we declare an array for values from 0 to 2360 
    int platform[2361] = {}; 
    int requiredPlatform = 1; 
    for (int i = 0; i < n; i++) { 
  
        // increment the platforms for arrival 
        ++platform[arrival[i]];  
  
         // once train departs we decrease the platform count 
        --platform[departure[i] + 1]; 
    } 
  
    // We are running loop till 2361 because maximum time value 
    // in a day can be 23:60 
    for (int i = 1; i < 2361; i++) { 
  
        // taking cumulative sum of platform give us required 
        // number of platform fro every minute 
        platform[i] = platform[i] + platform[i - 1];  
        requiredPlatform = max(requiredPlatform, platform[i]); 
    } 
    return requiredPlatform; 
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
		vector<float> arr;
		vector<float> dep;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		for(int i=0;i<m;i++){
			cin>>a;
			dep.push_back(a);
		}  
		cout<<minplatform(arr,dep)<<endl;
	}
	return 0;
}

6. unboundknapsack
// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Approach: The idea here is to just find the item which has largest value to weight ratio. 
// Then fill the whole knapsack with this item only in order to maximize the final value of the knapsack.

// Function to return the maximum required value 
float knapSack(int W, float wt[], float val[], int n) 
{ 

	// maxratio will store the maximum value to weight 
	// ratio we can have for any item and maxindex 
	// will store the index of that element 
	float maxratio = INT_MIN; 
	int maxindex = 0; 

	// Find the maximum ratio 
	for (int i = 0; i < n; i++) { 
		if ((val[i] / wt[i]) > maxratio) { 
			maxratio = (val[i] / wt[i]); 
			maxindex = i; 
		} 
	} 

	// The item with the maximum value to 
	// weight ratio will be put into 
	// the knapsack repeatedly until full 
	return (W * maxratio); 
} 

// Driver code 
int main() 
{ 
	float val[] = { 14, 27, 44, 19 }; 
	float wt[] = { 6, 7, 9, 8 }; 
	int n = sizeof(val) / sizeof(val[0]); 
	int W = 50; 

	cout << knapSack(W, wt, val, n); 

	return 0; 
} 

7.n meeting in a room
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct job {
    int index;
  int first;
  int second;
};


bool comp(struct job j1,struct job j2){
    return j1.second<j2.second;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n; cin>>t;
    while(t--) {
        cin>>n;
        ll str[n],fin[n];
        for(ll i=0;i<n;i++){
            cin>>str[i];
        }
        for(ll i=0;i<n;i++){
            cin>>fin[i];
        }
        struct job jobs[n];
        for(ll i=0;i<n;i++){
            jobs[i].index = i+1;
            jobs[i].first = str[i];
            jobs[i].second = fin[i];
        }
        sort(jobs,jobs+n,comp); 
        cout<<jobs[0].index<<" ";
        ll lasjob = jobs[0].second;
        for(ll i=1;i<n;i++){
            if(jobs[i].first>lasjob){
                cout<<jobs[i].index<<" ";
                lasjob = jobs[i].second;
            }
        }
        cout<<endl;
    }
}

Day 9: (backtracking)

1. mcoloring
#include <bits/stdc++.h> 
using namespace std; 
#define N 10


// Method 1:
bool issafe(int arr[N][N],int n ,int color[]){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			// here arr[i][j]==1 means the 2 edges are connected
			// so they are adjacent to each other
			// if they have same color then we have to return false;
			if(arr[i][j] && color[i]==color[j]) return false; 
		}
	}
	return true;
}

void printcolor(int color[],int n){
	for(int i=0;i<n;i++) cout<<color[i]<<" ";
	cout<<endl;
}

bool mcolor(int arr[N][N],int n,int color[],int m,int color_index){
	if(color_index == n) {
		if(issafe(arr,n,color)){
			printcolor(color,n);
			return true;
		}
		return false;
	}

	for(int j=1;j<=m;j++){
		color[color_index]=j;
		// goes for next index of color
		if(mcolor(arr,n,color,m,color_index+1)) return true;
		color[color_index]=0;
	}
	return false;
}

// Method 2:(backtracking)
/* A utility function to check if  
   the current color assignment 
   is safe for vertex v i.e. checks  
   whether the edge exists or not 
   (i.e, graph[v][i]==1). If exist  
   then checks whether the color to  
   be filled in the new vertex(c is 
   sent in the parameter) is already 
   used by its adjacent  
   vertices(i-->adj vertices) or  
   not (i.e, color[i]==c) */
bool isSafe( 
    int v, bool graph[V][V], 
    int color[], int c) 
{ 
    for (int i = 0; i < V; i++) 
        if ( 
            graph[v][i] && c == color[i]) 
            return false; 
    return true; 
} 
  
/* A recursive utility function  
to solve m coloring problem */
bool graphColoringUtil( 
    bool graph[V][V], int m, 
    int color[], int v) 
{ 
    /* base case: If all vertices are  
       assigned a color then return true */
    if (v == V) 
        return true; 
  
    /* Consider this vertex v and  
       try different colors */
    for (int c = 1; c <= m; c++) { 
        /* Check if assignment of color  
           c to v is fine*/
        if (isSafe( 
                v, graph, color, c)) { 
            color[v] = c; 
  
            /* recur to assign colors to  
               rest of the vertices */
            if ( 
                graphColoringUtil( 
                    graph, m, color, v + 1) 
                == true) 
                return true; 
  
            /* If assigning color c doesn't 
               lead to a solution then remove it */
            color[v] = 0; 
        } 
    } 
  
    /* If no color can be assigned to  
       this vertex then return false */
    return false; 
} 
  
/* This function solves the m Coloring  
   problem using Backtracking. It mainly  
   uses graphColoringUtil() to solve the  
   problem. It returns false if the m  
   colors cannot be assigned, otherwise  
   return true and prints assignments of  
   colors to all vertices. Please note  
   that there may be more than one solutions, 
   this function prints one of the 
   feasible solutions.*/
bool graphColoring( 
    bool graph[V][V], int m) 
{ 
    // Initialize all color values as 0. 
    // This initialization is needed 
    // correct functioning of isSafe() 
    int color[V]; 
    for (int i = 0; i < V; i++) 
        color[i] = 0; 
  
    // Call graphColoringUtil() for vertex 0 
    if ( 
        graphColoringUtil( 
            graph, m, color, 0) 
        == false) { 
        printf("Solution does not exist"); 
        return false; 
    } 
  
    // Print the solution 
    printSolution(color); 
    return true; 
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
		int arr[N][N];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		int m;
		cin>>m;
		int color[n];
		memset(color,0,sizeof(color));
		// here 0 is represent the first index color
		if(mcolor(arr,n,color,m,0)!=true)
			cout<<"no solution";
	}
	return 0;
}

// This is code is contributed by rathbhupendra 


2. knight tour
#include <bits/stdc++.h>
using namespace std;


int x_axis[] = {2,1,-1,-2,-2,-1,1,2};
int y_axis[] = {1,2,2,1,-1,-2,-2,-1};

// Method 1:(This is the backtracking Method)

void printarr(vector<vector<int>> &arr,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool issafe(vector<vector<int>> &arr,int n,int x,int y){
	if(x>=0 && x<n && y>=0&&y<n && arr[x][y]==-1) return true;
	return false;
}

bool solvekt(vector<vector<int>> &arr,int n,int x,int y,int num){
	// cout<<num<<endl;
	if(num == (n*n)){
		printarr(arr,n);
		return true;
	}
	for(int i=0;i<8;i++){
		int a=x + x_axis[i];
		int b=y + y_axis[i];
		if(issafe(arr,n,a,b)){
			arr[a][b]=num;
			if(solvekt(arr,n,a,b,num+1)==true) return true;
			arr[a][b]=-1;
		}
	}
	return false;
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
		n=8;
		vector<vector<int>> arr(n,vector<int>(n,-1));
		arr[0][0]=0;
		if(!solvekt(arr,n,0,0,1)) cout<<"solution not exit"<<endl;
	}
	return 0;
}

3. n queen problem
#include <bits/stdc++.h>
using namespace std;

// Method 1:
bool issafe(vector<vector<int>> &arr,int n,int row,int col){
	int i,j;
	for(i=0;i<n;i++) if(arr[row][i]) return false;
	for(i=0;i<n;i++) if(arr[i][col]) return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (arr[i][j]) 
            return false; 
    for (i = row, j = col; j >= 0 && i < n; i++, j--) 
        if (arr[i][j]) 
            return false; 
    for (i = row, j = col; i<n && j<n; i++, j++) 
        if (arr[i][j]) 
            return false; 
    for (i = row, j = col; i >= 0 && j < n; i--, j++) 
        if (arr[i][j]) 
            return false; 
    return true;
}

bool nqueenproblem(vector<vector<int>> &arr,int n,int row){
	if(row>=n) return true;
	for(int col=0;col<n;col++){
		if(issafe(arr,n,row,col)){
			arr[row][col]=1;
			if(nqueenproblem(arr,n,row+1)) return true;
			arr[row][col]=0;
		}
	}
	return false;
}

// Method2:Backtracking with efficiency
// bool solveNQUtil(int board[N][N], int col) 
// { 
//     /* base case: If all queens are placed 
//       then return true */
//     if (col >= N) 
//         return true; 
  
//     /* Consider this column and try placing 
//        this queen in all rows one by one */
//     for (int i = 0; i < N; i++) { 
//         /* Check if the queen can be placed on 
//           board[i][col] */
//         /* A check if a queen can be placed on  
//            board[row][col].We just need to check 
//            ld[row-col+n-1] and rd[row+coln] where 
//            ld and rd are for left and right  
//            diagonal respectively*/
//         if ((ld[i - col + N - 1] != 1 && 
//                   rd[i + col] != 1) && cl[i] != 1) { 
//              Place this queen in board[i][col] 
//             board[i][col] = 1; 
//             ld[i - col + N - 1] = 
//                           rd[i + col] = cl[i] = 1; 
  
//             /* recur to place rest of the queens */
//             if (solveNQUtil(board, col + 1)) 
//                 return true; 
  
//             /* If placing queen in board[i][col] 
//                doesn't lead to a solution, then 
//                remove queen from board[i][col] */
//             board[i][col] = 0; // BACKTRACK 
//             ld[i - col + N - 1] = 
//                          rd[i + col] = cl[i] = 0; 
//         } 
//     } 
  
//     /* If the queen cannot be placed in any row in 
//         this colum col  then return false */
//     return false; 
// } 

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
		vector<vector<int>> arr;
		for(int i=0;i<n;i++){
			vector<int> v;
			for(int j=0;j<n;j++){
				a=0;
				v.push_back(a);
			}
			arr.push_back(v);
		}
		cout<<nqueenproblem(arr,n,0)<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

4. nqueen preinstall solution
#include <bits/stdc++.h>
using namespace std;

// Method 1:
bool issafe(vector<vector<int>> &arr,int n,int row,int col){
	int i,j;
	for(i=0;i<n;i++) if(arr[row][i]) return false;
	for(i=0;i<n;i++) if(arr[i][col]) return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (arr[i][j]) 
            return false; 
    for (i = row, j = col; j >= 0 && i < n; i++, j--) 
        if (arr[i][j]) 
            return false; 
    for (i = row, j = col; i<n && j<n; i++, j++) 
        if (arr[i][j]) 
            return false; 
    for (i = row, j = col; i >= 0 && j < n; i--, j++) 
        if (arr[i][j]) 
            return false; 
    return true;
}

bool nqueenproblem(vector<vector<int>> &arr,int n,int row){
	if(row>=n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	} 
	bool res=false;
	for(int col=0;col<n;col++){
		if(issafe(arr,n,row,col)){
			arr[row][col]=1;
			res = nqueenproblem(arr,n,row+1) || res;
			arr[row][col]=0;
		}
	}
	return res;
}

// Method2:Backtracking with efficiency
// bool solveNQUtil(int board[N][N], int col) 
// { 
//     /* base case: If all queens are placed 
//       then return true */
//     if (col >= N) 
//         return true; 
  
//     /* Consider this column and try placing 
//        this queen in all rows one by one */
//     for (int i = 0; i < N; i++) { 
//         /* Check if the queen can be placed on 
//           board[i][col] */
//         /* A check if a queen can be placed on  
//            board[row][col].We just need to check 
//            ld[row-col+n-1] and rd[row+coln] where 
//            ld and rd are for left and right  
//            diagonal respectively*/
//         if ((ld[i - col + N - 1] != 1 && 
//                   rd[i + col] != 1) && cl[i] != 1) { 
//              Place this queen in board[i][col] 
//             board[i][col] = 1; 
//             ld[i - col + N - 1] = 
//                           rd[i + col] = cl[i] = 1; 
  
//             /* recur to place rest of the queens */
//             if (solveNQUtil(board, col + 1)) 
//                 return true; 
  
//             /* If placing queen in board[i][col] 
//                doesn't lead to a solution, then 
//                remove queen from board[i][col] */
//             board[i][col] = 0; // BACKTRACK 
//             ld[i - col + N - 1] = 
//                          rd[i + col] = cl[i] = 0; 
//         } 
//     } 
  
//     /* If the queen cannot be placed in any row in 
//         this colum col  then return false */
//     return false; 
// } 

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
		vector<vector<int>> arr;
		for(int i=0;i<n;i++){
			vector<int> v;
			for(int j=0;j<n;j++){
				a=0;
				v.push_back(a);
			}
			arr.push_back(v);
		}
		cout<<nqueenproblem(arr,n,0)<<endl;
	}
	return 0;
}

5.rat in maze2
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &sol,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool issafe(vector<vector<int>> &arr,int n,int x,int y,vector<vector<bool>> &visited){
	if(x==-1 || x==n || y==-1 || y==n || arr[x][y]==0 || visited[x][y]) return false;
	return true;
}

// 1 0 0 0 0
// 1 1 1 1 1
// 1 1 1 0 1 
// 0 0 0 0 1
// 0 0 0 0 1
void ratinmaze2(vector<vector<int>> &arr,int n,int x,int y,string &path,vector<string> &finalpath,vector<vector<bool>> &visited){
	if(x==-1 || x==n || y==-1 || y==n || arr[x][y]==0 || visited[x][y]) return;

	if(x==n-1&&y==n-1){
		cout<<path<<" ";
		finalpath.push_back(path);
		return;
	} 
	visited[x][y]=true;
	if(issafe(arr,x+1,y,n,visited)){
		path.push_back('D');
		ratinmaze2(arr,n,x+1,y,path,finalpath,visited);
		path.pop_back();
	}
	if(issafe(arr,x,y-1,n,visited)){
		path.push_back('L');
		ratinmaze2(arr,n,x,y-1,path,finalpath,visited);
		path.pop_back();
	}
	if(issafe(arr,x,y+1,n,visited)){
		path.push_back('R');
		ratinmaze2(arr,n,x,y+1,path,finalpath,visited);
		path.pop_back();
	}
	if(issafe(arr,x-1,y,n,visited)){
		path.push_back('U');
		ratinmaze2(arr,n,x-1,y,path,finalpath,visited);
		path.pop_back();
	}
	
	visited[x][y]=false;
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
		vector<vector<int>> arr;
		for(int i=0;i<n;i++){
			vector<int> v;
			for(int j=0;j<n;j++){
				cin>>a;
				v.push_back(a);
			}
			arr.push_back(v);
		}
		vector<vector<bool>> visited(n,vector<bool>(n,false));
		string path;
		vector<string> finalpath;

		ratinmaze2(arr,n,0,0,path,finalpath,visited);
		for(auto x:finalpath) cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}

6. permutation of string
#include <bits/stdc++.h>
using namespace std;

// Method 1: backtraking
void permutation(string &str,int n,int k){
	if(k==n-1) {
		cout<<str<<endl;
		return;
	}
	if(k>=n) return;

	for(int i=k;i<n;i++){
		swap(str[i],str[k]);
		permutation(str,n,k+1);
		// This one for backtracking
		swap(str[i],str[k]);
	}
}
// Time Complexity: O(n*n!) Note that there are n! permutations and 
// it requires O(n) time to print a a permutation.

// Method 2:(using and extra string and rotate function)
void permute(string str, string out) 
{ 
    // When size of str becomes 0, out has a 
    // permutation (length of out is n) 
    if (str.size() == 0) 
    { 
        cout << out << endl; 
        return; 
    } 
  
    // One be one move all characters at 
    // the beginning of out (or result) 
    for (int i = 0; i < str.size(); i++) 
    { 
        // Remove first character from str and 
        // add it to out 
        permute(str.substr(1), out + str[0]); 
  
        // Rotate string in a way second character 
        // moves to the beginning. 
        rotate(str.begin(), str.begin() + 1, str.end()); 
    } 
} 

// Method 3: (using stl function)
void permutation(string str){
	sort(str.begin(),str.end());
	cout<<str<<endl;
	while(next_permutation(str.begin(),str.end())) cout<<str<<endl;
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
	string str;
	while(t--){
		cin>>n;
		cin>>str;
		permutation(str,n,0);
	}
	return 0;
}

7. rat in maze
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &sol,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool issafe(vector<vector<int>> &arr,int n,int x,int y){
	return (x>=0 && x<n && y>=0 && y<n && arr[x][y]==1);
}

bool ratinmaze(vector<vector<int>> &arr,vector<vector<int>> &sol,int n,int x,int y){
	if(x==n-1&&y==n-1 && arr[x][y]==1){
		sol[x][y]=1;
		print(sol,n);
		return true;
	}

	if(issafe(arr,n,x,y)){
		sol[x][y]=1;
		if(ratinmaze(arr,sol,n,x+1,y)) return true;
		if(ratinmaze(arr,sol,n,x,y+1)) return true;
		sol[x][y]=0;
		return false;
	}
	return false;
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
		vector<vector<int>> arr;
		for(int i=0;i<n;i++){
			vector<int> v;
			for(int j=0;j<n;j++){
				cin>>a;
				v.push_back(a);
			}
			arr.push_back(v);
		}
		vector<vector<int>> sol(n,vector<int>(n,0));
		if(!ratinmaze(arr,sol,n,0,0)) cout<<"no solution"<<endl;
	}
	return 0;
}

8. subset problem
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &taken,int n){
	for(int i=0;i<n;i++) cout<<taken[i]<<" ";
	cout<<endl;
}

void subsetsumutil(vector<int> &arr,vector<int> &taken,int arr_size,int t_size,int sum,int index,int actualsum){
	if(sum == actualsum){
		print(taken,t_size);
		if(index+1<arr_size && sum-arr[index]+arr[index+1]<=actualsum){
			subsetsumutil(arr,taken,arr_size,t_size-1,sum-arr[index],index+1,actualsum);
		}
	}else{
		if(index<arr_size && sum+arr[index]<=actualsum){
			for(int i=index;i<arr_size;i++){
				taken[t_size]=arr[i];
				if(sum+arr[i]<=actualsum)
					subsetsumutil(arr,taken,arr_size,t_size+1,sum+arr[i],i+1,actualsum);
			}
		}
	}
}

void subsetsum(vector<int> &arr,int n,int sum){
	vector<int>  taken(n,0);
	sort(arr.begin(),arr.end());
	int total=0;
	for(int i=0;i<n;i++) total += arr[i];
	if(arr[0]<=sum && total>=sum)
		subsetsumutil(arr,taken,n,0,0,0,sum);
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,s; cin>>t;
	while(t--){
		cin>>n>>s;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		subsetsum(arr,n,s);
	}
	return 0;
}

9. word break
// A recursive program to print all possible 
// partitions of a given string into dictionary 
// words 
#include <iostream> 
using namespace std; 

/* A utility function to check whether a word 
is present in dictionary or not. An array of 
strings is used for dictionary. Using array 
of strings for dictionary is definitely not 
a good idea. We have used for simplicity of 
the program*/
int dictionaryContains(string &word) 
{ 
	string dictionary[] = {"mobile","samsung","sam","sung", 
							"man","mango", "icecream","and", 
							"go","i","love","ice","cream"}; 
	int n = sizeof(dictionary)/sizeof(dictionary[0]); 
	for (int i = 0; i < n; i++) 
		if (dictionary[i].compare(word) == 0) 
			return true; 
	return false; 
} 

//prototype of wordBreakUtil 
void wordBreakUtil(string str, int size, string result); 

// Prints all possible word breaks of given string 
void wordBreak(string str) 
{ 
	// last argument is prefix 
	wordBreakUtil(str, str.size(), ""); 
} 

// result store the current prefix with spaces 
// between words 
void wordBreakUtil(string str, int n, string result) 
{ 
	//Process all prefixes one by one 
	for (int i=1; i<=n; i++) 
	{ 
		//extract substring from 0 to i in prefix 
		string prefix = str.substr(0, i); 

		// if dictionary conatins this prefix, then 
		// we check for remaining string. Otherwise 
		// we ignore this prefix (there is no else for 
		// this if) and try next 
		if (dictionaryContains(prefix)) 
		{ 
			// if no more elements are there, print it 
			if (i == n) 
			{ 
				// add this element to previous prefix 
				result += prefix; 
				cout << result << endl; //print result 
				return; 
			} 
			wordBreakUtil(str.substr(i, n-i), n-i, 
								result + prefix + " "); 
		} 
	}	 //end for 
}//end function 

int main() 
{ 
	cout << "First Test:\n"; 
	wordBreak("iloveicecreamandmango"); 

	cout << "\nSecond Test:\n"; 
	wordBreak("ilovesamsungmobile"); 
	return 0; 
} 

// Method 2:(using dp and simple recursion)
// A recursive program to test whether a given 
// string can be segmented into space separated 
// words in dictionary 
#include <iostream> 
using namespace std; 

/* A utility function to check whether a word is 
present in dictionary or not. An array of strings 
is used for dictionary. Using array of strings for 
dictionary is definitely not a good idea. We have 
used for simplicity of the program*/
int dictionaryContains(string word) 
{ 
	string dictionary[] = {"mobile","samsung","sam","sung", 
							"man","mango","icecream","and", 
							"go","i","like","ice","cream"}; 
	int size = sizeof(dictionary)/sizeof(dictionary[0]); 
	for (int i = 0; i < size; i++) 
		if (dictionary[i].compare(word) == 0) 
		return true; 
	return false; 
} 

// returns true if string can be segmented into space 
// separated words, otherwise returns false 
bool wordBreak(string str) 
{ 
	int size = str.size(); 

	// Base case 
	if (size == 0) return true; 

	// Try all prefixes of lengths from 1 to size 
	for (int i=1; i<=size; i++) 
	{ 
		// The parameter for dictionaryContains is 
		// str.substr(0, i) which is prefix (of input 
		// string) of length 'i'. We first check whether 
		// current prefix is in dictionary. Then we 
		// recursively check for remaining string 
		// str.substr(i, size-i) which is suffix of 
		// length size-i 
		if (dictionaryContains( str.substr(0, i) ) && 
			wordBreak( str.substr(i, size-i) )) 
			return true; 
	} 

	// If we have tried all prefixes and 
	// none of them worked 
	return false; 
} 

// Driver program to test above functions 
int main() 
{ 
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n"; 
	return 0; 
} 

// Method 3
// A Dynamic Programming based program to test whether a given string can 
// be segmented into space separated words in dictionary 
#include <iostream> 
#include <string.h> 
using namespace std; 

/* A utility function to check whether a word is present in dictionary or not. 
An array of strings is used for dictionary. Using array of strings for 
dictionary is definitely not a good idea. We have used for simplicity of 
the program*/
int dictionaryContains(string word) 
{ 
	string dictionary[] = {"mobile","samsung","sam","sung","man","mango", 
						"icecream","and","go","i","like","ice","cream"}; 
	int size = sizeof(dictionary)/sizeof(dictionary[0]); 
	for (int i = 0; i < size; i++) 
		if (dictionary[i].compare(word) == 0) 
		return true; 
	return false; 
} 

// Returns true if string can be segmented into space separated 
// words, otherwise returns false 
bool wordBreak(string str) 
{ 
	int size = str.size(); 
	if (size == 0) return true; 

	// Create the DP table to store results of subroblems. The value wb[i] 
	// will be true if str[0..i-1] can be segmented into dictionary words, 
	// otherwise false. 
	bool wb[size+1]; 
	memset(wb, 0, sizeof(wb)); // Initialize all values as false. 

	for (int i=1; i<=size; i++) 
	{ 
		// if wb[i] is false, then check if current prefix can make it true. 
		// Current prefix is "str.substr(0, i)" 
		if (wb[i] == false && dictionaryContains( str.substr(0, i) )) 
			wb[i] = true; 

		// wb[i] is true, then check for all substrings starting from 
		// (i+1)th character and store their results. 
		if (wb[i] == true) 
		{ 
			// If we reached the last prefix 
			if (i == size) 
				return true; 

			for (int j = i+1; j <= size; j++) 
			{ 
				// Update wb[j] if it is false and can be updated 
				// Note the parameter passed to dictionaryContains() is 
				// substring starting from index 'i' and length 'j-i' 
				if (wb[j] == false && dictionaryContains( str.substr(i, j-i) )) 
					wb[j] = true; 

				// If we reached the last character 
				if (j == size && wb[j] == true) 
					return true; 
			} 
		} 
	} 

	/* Uncomment these lines to print DP table "wb[]" 
	for (int i = 1; i <= size; i++) 
		cout << " " << wb[i]; */

	// If we have tried all prefixes and none of them worked 
	return false; 
} 

// Driver program to test above functions 
int main() 
{ 
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n"; 
	return 0; 
} 

// Method 4(optimised dp)
// A Dynamic Programming based program to test 
// whether a given string can be segmented into 
// space separated words in dictionary 
#include <bits/stdc++.h> 
using namespace std; 

/* A utility function to check whether a word 
is present in dictionary or not. An array of 
strings is used for dictionary. Using array 
of strings for dictionary is definitely not 
a good idea. We have used for simplicity of 
the program*/
int dictionaryContains(string word) 
{ 
	string dictionary[] = { "mobile", "samsung", "sam", 
							"sung", "man", "mango", 
							"icecream", "and", "go", 
							"i", "like", "ice", "cream" }; 
	int size = sizeof(dictionary) / sizeof(dictionary[0]); 
	for (int i = 0; i < size; i++) 
		if (dictionary[i].compare(word) == 0) 
			return true; 
	return false; 
} 

// Returns true if string can be segmented into space 
// separated words, otherwise returns false 
bool wordBreak(string s) 
{ 
	int n = s.size(); 
	if (n == 0) 
		return true; 

	// Create the DP table to store results of subroblems. 
	// The value dp[i] will be true if str[0..i] can be 
	// segmented into dictionary words, otherwise false. 
	vector<bool> dp(n + 1, 0); // Initialize all values 
	// as false. 

	// matched_index array represents the indexes for which 
	// dp[i] is true. Initially only -1 element is present 
	// in this array. 
	vector<int> matched_index; 
	matched_index.push_back(-1); 

	for (int i = 0; i < n; i++) { 
		int msize = matched_index.size(); 

		// Flag value which tells that a substring matches 
		// with given words or not. 
		int f = 0; 

		// Check all the substring from the indexes matched 
		// earlier. If any of that substring matches than 
		// make flag value = 1; 
		for (int j = msize - 1; j >= 0; j--) { 

			// sb is substring starting from matched_index[j] 
			// + 1 and of length i - matched_index[j] 
			string sb = s.substr(matched_index[j] + 1, i - matched_index[j]); 

			if (dictionaryContains(sb)) { 
				f = 1; 
				break; 
			} 
		} 

		// If substring matches than do dp[i] = 1 and 
		// push that index in matched_index array. 
		if (f == 1) { 
			dp[i] = 1; 
			matched_index.push_back(i); 
		} 
	} 
	return dp[n - 1]; 
} 

// Driver code 
int main() 
{ 
	wordBreak("ilikesamsung") ? cout << "Yes\n" : cout << "No\n"; 
	wordBreak("iiiiiiii") ? cout << "Yes\n" : cout << "No\n"; 
	wordBreak("") ? cout << "Yes\n" : cout << "No\n"; 
	wordBreak("ilikelikeimangoiii") ? cout << "Yes\n" : cout << "No\n"; 
	wordBreak("samsungandmango") ? cout << "Yes\n" : cout << "No\n"; 
	wordBreak("samsungandmangok") ? cout << "Yes\n" : cout << "No\n"; 
	return 0; 
} 


10. sudoku
// // A recursive program in C++ 
// // to solve Sudoku problem 
// #include <bits/stdc++.h> 
// using namespace std; 

// // UNASSIGNED is used for empty 
// // cells in sudoku grid 
// #define UNASSIGNED 0 

// // N is used for the size of Sudoku grid. 
// // Size will be NxN 
// #define N 9 

// // Checks whether it will be legal 
// // to assign num to the given row, col 
// bool isSafe(int grid[N][N]) 
// { 
// 	// Hashmap for row column and boxes 
// 	unordered_map<int, int> 
// 		row_[9], column_[9], box[3][3]; 
// 	for (int row = 0; row < N; row++) { 
// 		for (int col = 0; col < N; col++) { 
// 			// mark the element in row column and box 
// 			row_[row][grid[row][col]] += 1; 
// 			column_[col][grid[row][col]] += 1; 
// 			box[row / 3][col / 3][grid[row][col]] += 1; 

// 			// if an element is already 
// 			// present in the hashmap 
// 			if ( 
// 				box[row / 3][col / 3][grid[row][col]] > 1 
// 				|| column_[col][grid[row][col]] > 1 
// 				|| row_[row][grid[row][col]] > 1) 
// 				return false; 
// 		} 
// 	} 
// 	return true; 
// } 

// /* A utility function to print grid */
// void printGrid(int grid[N][N]) 
// { 
// 	for (int row = 0; row < N; row++) { 
// 		for (int col = 0; col < N; col++) 
// 			cout << grid[row][col] << " "; 
// 		cout << endl; 
// 	} 
// } 

// /* Takes a partially filled-in grid and attempts 
// to assign values to all unassigned locations in 
// such a way to meet the requirements for 
// Sudoku solution (non-duplication across rows, 
// columns, and boxes) */
// bool SolveSudoku( 
// 	int grid[N][N], int i, int j) 
// { 
// 	// if the index reached the end 
// 	if (i == N - 1 && j == N) { 
// 		// if the matrix is safe 
// 		if (isSafe(grid)) { 
// 			// print and stop 
// 			printGrid(grid); 
// 			return true; 
// 		} 

// 		// else try other cases 
// 		return false; 
// 	} 

// 	// end of a row move to next row 
// 	if (j == N) { 
// 		i++; 
// 		j = 0; 
// 	} 

// 	// if the element is non zero keep as it is 
// 	if (grid[i][j] != UNASSIGNED) 
// 		return SolveSudoku(grid, i, j + 1); 

// 	// consider digits 1 to 9 
// 	for (int num = 1; num <= 9; num++) { 
// 		// assign and call recursively 
// 		grid[i][j] = num; 

// 		if (SolveSudoku(grid, i, j + 1)) 
// 			return true; 

// 		grid[i][j] = 0; 
// 	} 
// 	return false; 
// } 

// // Driver Code 
// int main() 
// { 
// 	// 0 means unassigned cells 
// 	int grid[N][N] = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 }, 
// 					{ 5, 2, 9, 1, 3, 4, 7, 6, 8 }, 
// 					{ 4, 8, 7, 6, 2, 9, 5, 3, 1 }, 
// 					{ 2, 6, 3, 0, 1, 5, 9, 8, 7 }, 
// 					{ 9, 7, 4, 8, 6, 0, 1, 2, 5 }, 
// 					{ 8, 5, 1, 7, 9, 2, 6, 4, 3 }, 
// 					{ 1, 3, 8, 0, 4, 7, 2, 0, 6 }, 
// 					{ 6, 9, 2, 3, 5, 1, 8, 7, 4 }, 
// 					{ 7, 4, 5, 0, 8, 6, 3, 1, 0 } }; 
// 	if (SolveSudoku(grid, 0, 0) != true) 
// 		cout << "No solution exists"; 

// 	return 0; 
// } 

// // This is code is contributed by Arnab Kundu 


// int main() {
// 	#ifndef ONLINE_JUDGE
//     	freopen("input.txt", "r", stdin);
//     	freopen("output.txt", "w", stdout);
// 	#endif
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	//ios_base& scientific (ios_base& str);
// 	int t,n,a; cin>>t;
// 	while(t--){
// 		int arr[N][N];
// 		for(int i=0;i<N;i++){
// 			for(int j=0;j<N;j++){
// 				cin>>arr[i][j];
// 			}
// 		}
// 		if(!SolveSudoku(arr,0,0))
// 			cout<<"no solution";
// 	}
// 	return 0;
// }

// Method 2
// A Backtracking program in 
// C++ to solve Sudoku problem 
#include <bits/stdc++.h> 
using namespace std; 

// UNASSIGNED is used for empty 
// cells in sudoku grid 
#define UNASSIGNED 0 

// N is used for the size of Sudoku grid. 
// Size will be NxN 
#define N 9 

// This function finds an entry in grid 
// that is still unassigned 
bool FindUnassignedLocation(int grid[N][N], 
							int& row, int& col); 

// Checks whether it will be legal 
// to assign num to the given row, col 
bool isSafe(int grid[N][N], int row, 
			int col, int num); 

/* Takes a partially filled-in grid and attempts 
to assign values to all unassigned locations in 
such a way to meet the requirements for 
Sudoku solution (non-duplication across rows, 
columns, and boxes) */
bool SolveSudoku(int grid[N][N]) 
{ 
	int row, col; 

	// If there is no unassigned location, 
	// we are done 
	if (!FindUnassignedLocation(grid, row, col)) 
		// success! 
		return true; 

	// Consider digits 1 to 9 
	for (int num = 1; num <= 9; num++) { 
		// if looks promising 
		if (isSafe(grid, row, col, num)) { 
			// make tentative assignment 
			grid[row][col] = num; 

			// return, if success, yay! 
			if (SolveSudoku(grid)) 
				return true; 

			// failure, unmake & try again 
			grid[row][col] = UNASSIGNED; 
		} 
	} 
	// this triggers backtracking 
	return false; 
} 

/* Searches the grid to find an entry that is 
still unassigned. If found, the reference 
parameters row, col will be set the location 
that is unassigned, and true is returned. 
If no unassigned entries remain, false is returned. */
bool FindUnassignedLocation(int grid[N][N], 
							int& row, int& col) 
{ 
	for (row = 0; row < N; row++) 
		for (col = 0; col < N; col++) 
			if (grid[row][col] == UNASSIGNED) 
				return true; 
	return false; 
} 

/* Returns a boolean which indicates whether 
an assigned entry in the specified row matches 
the given number. */
bool UsedInRow(int grid[N][N], int row, int num) 
{ 
	for (int col = 0; col < N; col++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

/* Returns a boolean which indicates whether 
an assigned entry in the specified column 
matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num) 
{ 
	for (int row = 0; row < N; row++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

/* Returns a boolean which indicates whether 
an assigned entry within the specified 3x3 box 
matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, 
			int boxStartCol, int num) 
{ 
	for (int row = 0; row < 3; row++) 
		for (int col = 0; col < 3; col++) 
			if (grid[row + boxStartRow] 
					[col + boxStartCol] 
				== num) 
				return true; 
	return false; 
} 

/* Returns a boolean which indicates whether 
it will be legal to assign num to the given 
row, col location. */
bool isSafe(int grid[N][N], int row, 
			int col, int num) 
{ 
	/* Check if 'num' is not already placed in 
	current row, current column and current 3x3 box */
	return !UsedInRow(grid, row, num) 
		&& !UsedInCol(grid, col, num) 
		&& !UsedInBox(grid, row - row % 3, 
						col - col % 3, num) 
		&& grid[row][col] == UNASSIGNED; 
} 

/* A utility function to print grid */
void printGrid(int grid[N][N]) 
{ 
	for (int row = 0; row < N; row++) { 
		for (int col = 0; col < N; col++) 
			cout << grid[row][col] << " "; 
		cout << endl; 
	} 
} 

// Driver Code 
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
		int arr[N][N];
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin>>arr[i][j];
			}
		}
		if(SolveSudoku(arr)==true) printGrid(arr);
		else cout<<"no solution";
	}
	return 0;
}

// This is code is contributed by rathbhupendra 

Day 10:(backtraking)

1. subsetsum1
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &taken,int n){
	for(int i=0;i<n;i++) cout<<taken[i]<<" ";
	cout<<endl;
}

void subsetsumutil(vector<int> &arr,vector<int> &taken,int arr_size,int t_size,int sum,int index,int actualsum){
	if(sum == actualsum){
		print(taken,t_size);
		if(index+1<arr_size && sum-arr[index]+arr[index+1]<=actualsum){
			subsetsumutil(arr,taken,arr_size,t_size-1,sum-arr[index],index+1,actualsum);
		}
	}else{
		if(index<arr_size && sum+arr[index]<=actualsum){
			for(int i=index;i<arr_size;i++){
				taken[t_size]=arr[i];
				if(sum+arr[i]<=actualsum)
					subsetsumutil(arr,taken,arr_size,t_size+1,sum+arr[i],i+1,actualsum);
			}
		}
	}
}

void subsetsum(vector<int> &arr,int n,int sum){
	vector<int>  taken(n,0);
	sort(arr.begin(),arr.end());
	int total=0;
	for(int i=0;i<n;i++) total += arr[i];
	if(arr[0]<=sum && total>=sum)
		subsetsumutil(arr,taken,n,0,0,0,sum);
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,s; cin>>t;
	while(t--){
		cin>>n>>s;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		subsetsum(arr,n,s);
	}
	return 0;
}

2. subsetsum 2
#include <bits/stdc++.h>
using namespace std;

// This is recursion Method but show timelimit for large input
bool subsetsumutil(vector<int> &arr,int arr_size,int sum,int index,int actualsum){
	if(sum == actualsum){
		return true;
	}
	if(index<arr_size && sum+arr[index]<=actualsum){
		for(int i=index;i<arr_size;i++){
			// actualsum -= arr[i];
			if(sum+arr[i]<=actualsum)
				if(subsetsumutil(arr,arr_size,sum+arr[i],i+1,actualsum)) return true;
			// actualsum += arr[i];
		}
	}
	return false;
}

bool subsetsum(vector<int> &arr,int n){
	sort(arr.begin(),arr.end());
	int total=0;
	for(int i=0;i<n;i++) total += arr[i];
	if(total%2==1) return false;
 	total = total/2;
	if(!subsetsumutil(arr,n,0,0,total)) return false;
	else return true;
}

// Method 2 :(using dp with 1D space)


bool subsetsum(vector<int> &arr,int n){
	sort(arr.begin(),arr.end());
	int total=0;
	for(int i=0;i<n;i++) total += arr[i];
	if(total%2==1) return false;
 	total = total/2;
	vector<bool> subset(total+1,false);
	subset[0]=true;
	for(auto x:arr){
		for(int i=total;i>=x;i--){
			subset[i] = subset[i] || subset[i-x];
		}
	}
	return subset[total];
}

// Method 3:(using dp with 2D space)

bool subsetsum(vector<int> &arr,int n){
	sort(arr.begin(),arr.end());
	int total=0;
	for(int i=0;i<n;i++) total += arr[i];
	if(total%2==1) return false;
 	total = total/2;
	vector<vector<bool> > dp(n+1 , vector<bool>(total+1 , false));
    for(int i = 0;i<=n;i++) dp[i][0] = true;
    for(int j = 0;j<=total; j++) dp[0][j] = false;    
    dp[0][0] = true;
    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=total; j++){
            if(j<arr[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
        }
    }
    return dp[n][total];
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,s; cin>>t;
	while(t--){
		cin>>n;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		cout<<subsetsum(arr,n)<<endl;
	}
	return 0;
}

3. kth permutation sequence
#include <bits/stdc++.h>
using namespace std;

// Check out this
// https://leetcode.com/problems/permutation-sequence/discuss/735287/Detailed-Explanation-with-Code-T(n2)


// Method 1:
string permutation(string &str,int n,int &k){
	    sort(str.begin(),str.end());
        do{
            if(k-- == 1){
                break;
            }
        }while(next_permutation(str.begin(),str.end()));
        return str;
 }

// Method 2:
 int factorial(int n, int out = 1)
    {
        if(n <= 1)
            return out;
        else
            return factorial(n-1, out*n);
    }
    
    string getPermutation(int n, int k)
    {
        k--;
        vector<int> out(n);
        for(int i = 1; i <= n; i++)
            out[i-1] = i;
        
        string answer = "";
        int size = n-1;
        while(k > 0)
        {
            int fact = factorial(size);
            int index = k / fact;
            
            answer += to_string(out[index]);
            out.erase(out.begin()+index);
            
            k -= fact * index;
            size--;
        }
        for(int i : out)
            answer += to_string(i);
        return answer;
    }

    // Method 3
    // Continually get the possible combinations for n-1, for example, if n = 3, the possible combination for 2 number is only 2. With that, we can use the modulo to get the desired index to be put in the string. Noted that the boundary condition occurs when the modulo return 0, which means the string is the last possible combination, under this condition the index to be put in the string is the last index.

    string getPermutation(int n, int k) {
        string ans;
        int total = 1; 
		//initialize a bool vector for the possible indexs
        vector<bool> table(n); 
		// first compute the (n-1)!
        for(int i = n-1; i > 0; total*=i, i--){}; 
		// after every loop, divide total combination with i, that is equal to (n-1)!
        for(int i = n-1; i > 0; total /= i, i--){ 
			// compute the index to be put in the string
            int start = k%(total) ? 1+ k/(total) : k/(total);
			// b.c! set the index to the last possible index
            if(!start) start = n; 
            int it = 0, idx = 0; 
            while(idx < start){
				// overlook the index that was already put in the string
                if(table[it] == false){ 
                    idx++;
                }
                it++;
            }
			//turn the status of the index to be already put in the string
            table[it-1] = true;
			//update k, using modulo
            k %= total; 
            ans += to_string(it);
            n--;
        }
		//put the last possible index in the string 
        for(int i = 0; i < table.size(); i++){ // 
            if(!table[i]){
                ans += to_string(i+1);
                break;
            }
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
	int t,n,k; cin>>t;
	while(t--){
		cin>>n>>k;
		string str;
		for(int i=1;i<=n;i++){
			str += '0'+i;
		}
		cout<<permutation(str,n,k)<<endl;
	}
	return 0;
}

// Efficient Method for this problem
Efficient Approach: Mathematical concept for solving this problem.

The total number of permutation of a string formed by N characters(all distinct) is N!
The Total number of permutation of a string formed by N characters (where the frequency of character C1 is M1, C2 is M2… and so the frequency of character Ck is Mk) is N!/(M1! * M2! *….Mk!).
The total number of permutation of a string formed by N characters(all distinct) after fixing the first character is (N-1)!
The following steps can be followed to reach the solution.




Count the frequencies of all characters in an array.
Now from the first smallest character present in the string(smallest index i such that freq[i] > 0), compute the number of maximum permutation possible after setting that particular i-th character as the first character.
If this sum value is more than given n, then set that character as the first result output character, and decrement freq[i]. Continue the same for the remaining n-1 characters.
On the other hand, if the count is less than the required n, then iterate for the next character in the frequency table and update the count over and over again until we find a character that produces a count greater than the required n.
// C++ program to print 
// n-th permutation 
#include <bits/stdc++.h> 
using namespace std; 
  
#define ll long long int 
  
const int MAX_CHAR = 26; 
const int MAX_FACT = 20; 
ll fact[MAX_FACT]; 
  
// Utility for calculating factorials 
void precomputeFactorials() 
{ 
    fact[0] = 1; 
    for (int i = 1; i < MAX_FACT; i++) 
        fact[i] = fact[i - 1] * i; 
} 
  
// Function for nth permutation 
void nPermute(char str[], int n) 
{ 
    precomputeFactorials(); 
  
    // Length of given string 
    int len = strlen(str); 
  
    // Count frequencies of all 
    // characters 
    int freq[MAX_CHAR] = { 0 }; 
    for (int i = 0; i < len; i++) 
        freq[str[i] - 'a']++; 
  
    // Out string for output string 
    char out[MAX_CHAR]; 
  
    // Iterate till sum equals n 
    int sum = 0; 
    int k = 0; 
  
    // We update both n and sum in this 
    // loop. 
    while (sum != n) { 
  
        sum = 0; 
        // Check for characters present in freq[] 
        for (int i = 0; i < MAX_CHAR; i++) { 
            if (freq[i] == 0) 
                continue; 
  
            // Remove character 
            freq[i]--; 
  
            // Calculate sum after fixing 
            // a particuar char 
            int xsum = fact[len - 1 - k]; 
            for (int j = 0; j < MAX_CHAR; j++) 
                xsum /= fact[freq[j]]; 
            sum += xsum; 
  
            // if sum > n fix that char as 
            // present char and update sum 
            // and required nth after fixing 
            // char at that position 
            if (sum >= n) { 
                out[k++] = i + 'a'; 
                n -= (sum - xsum); 
                break; 
            } 
  
            // if sum < n, add character back 
            if (sum < n) 
                freq[i]++; 
        } 
    } 
  
    // if sum == n means this 
    // char will provide its 
    // greatest permutation 
    // as nth permutation 
    for (int i = MAX_CHAR - 1; 
         k < len && i >= 0; i--) 
        if (freq[i]) { 
            out[k++] = i + 'a'; 
            freq[i++]--; 
        } 
  
    // append string termination 
    // character and print result 
    out[k] = '\0'; 
    cout << out; 
} 
  
// Driver program 
int main() 
{ 
    int n = 2; 
    char str[] = "geeksquiz"; 
  
    nPermute(str, n); 
    return 0; 
} 

Complexity Analysis:

Time Complexity: O(n), where n is the nth permutation.
Space Complexity: O(n) where n is the space required to store the frequency.



4. combination sum1
#include <bits/stdc++.h>
using namespace std;

// simple recursion print only count of ways
// int cominationsum1(vector<int> &arr,int n,int w){
// 	if(w==0) return 1;
// 	if(w<0) return 0;
// 	if(n<=0 && w>=1) return 0;
// 	if(arr[n-1]>w) return cominationsum1(arr,n-1,w);
// 	return cominationsum1(arr,n,w-arr[n-1]) + cominationsum1(arr,n-1,w);
// }
bool issafe(vector<int> &arr,int index,int n,int w){
	if(index<n && w-arr[index]>=0) return true;
	return false;
}

vector<vector<int>> finalcomb;

// bool cominationsum1(vector<int> &arr,int n,int w,vector<int> &comb){
// 	if(w==0){
// 		vector<int> trya=comb;
// 		sort(trya.begin(),trya.end());
// 		finalcomb.insert(trya);
// 		return true;
// 	}
// 	bool res = false;
// 	for(int i=0;i<n;i++){
// 		if(issafe(arr,i,n,w)){
// 			comb.push_back(arr[i]);
// 			res = cominationsum1(arr,n,w-arr[i],comb) || res;
// 			comb.pop_back();
// 		}
// 	}
// 	return res;
// }

void cominationsum1(vector<int> &arr,int n,int w,vector<int> &comb,int i){
	if(w<0) return;
	if(w==0){
		finalcomb.push_back(comb);
		return ;
	}
	while(i<n && w-arr[i]>=0){
		comb.push_back(arr[i]);
		cominationsum1(arr,n,w-arr[i],comb,i);
		i++;
		comb.pop_back();
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,w; cin>>t;
	while(t--){
		cin>>n>>w;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		sort(arr.begin(),arr.end());
		arr.erase(unique(arr.begin(),arr.end()),arr.end());
		vector<int> comb;
		cominationsum1(arr,n,w,comb,0);
		for(auto vec:finalcomb){
			for(int i=0;i<vec.size();i++){
				cout<<vec[i]<<" ";
			}
			cout<<endl;
		}
		finalcomb.clear();
		cout<<endl;
	}
	return 0;
}

5.combination sum2
#include <bits/stdc++.h>
using namespace std;

// simple recursion print only count of ways
// int cominationsum1(vector<int> &arr,int n,int w){
// 	if(w==0) return 1;
// 	if(w<0) return 0;
// 	if(n<=0 && w>=1) return 0;
// 	if(arr[n-1]>w) return cominationsum1(arr,n-1,w);
// 	return cominationsum1(arr,n,w-arr[n-1]) + cominationsum1(arr,n-1,w);
// }
// bool issafe(vector<int> &arr,int index,int n,int w){
// 	if(index<n && w-arr[index]>=0) return true;
// 	return false;
// }

vector<vector<int>> finalcomb;

// bool cominationsum1(vector<int> &arr,int n,int w,vector<int> &comb){
// 	if(w==0){
// 		vector<int> trya=comb;
// 		sort(trya.begin(),trya.end());
// 		finalcomb.insert(trya);
// 		return true;
// 	}
// 	bool res = false;
// 	for(int i=0;i<n;i++){
// 		if(issafe(arr,i,n,w)){
// 			comb.push_back(arr[i]);
// 			res = cominationsum1(arr,n,w-arr[i],comb) || res;
// 			comb.pop_back();
// 		}
// 	}
// 	return res;
// }

void cominationsum2(vector<int> &arr,int n,int w,vector<int> &comb,int index){
	if(w<0) return;
	if(w==0){
		finalcomb.push_back(comb);
		return ;
	}
	// while(i<n && w-arr[i]>=0){
	for(int i=index;i<n;i++){
		if(i!=index && arr[i]==arr[i-1]) continue;
		comb.push_back(arr[i]);
		cominationsum2(arr,n,w-arr[i],comb,i+1);
		comb.pop_back();
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,w; cin>>t;
	while(t--){
		cin>>n>>w;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		sort(arr.begin(),arr.end());
		// arr.erase(unique(arr.begin(),arr.end()),arr.end());
		vector<int> comb;
		cominationsum2(arr,n,w,comb,0);
		for(auto vec:finalcomb){
			for(int i=0;i<vec.size();i++){
				cout<<vec[i]<<" ";
			}
			cout<<endl;
		}
		finalcomb.clear();
		cout<<endl;
	}
	return 0;
}

Day 11:(divied and conquer)
1.element appears in single time in array and other appers 2twice
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

2. matrix median
#include <bits/stdc++.h>
using namespace std;

// Method 1
int matrixmedian(vector<vector<int>> &arr,int r,int c){
	int min=INT_MAX,max=INT_MIN;
	for(int i=0;i<r;i++){
		if(min>arr[i][0]) min = arr[i][0];
		if(max<arr[i][c-1]) max = arr[i][c-1];
	}

	int desire = (r*c +1)/2;
	while(min<max){
		int place=0;
		int mid = min+(max-min)/2;
		for(int i=0;i<r;i++) 
			place += upper_bound(arr[i].begin(),arr[i].end(),mid)- arr[i].begin();
		// this is if we are use arr
		// place += upper_bound(arr[i], arr[i]+c, mid) - arr[i]; 
		if(place<desire) min = mid+1;
		else max = mid;
	}
	return min;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,r,c,a; cin>>t;
	while(t--){
		cin>>r>>c;
		vector<vector<int>> arr;
		for(int i=0;i<r;i++){
			vector<int> v;
			for(int j=0;j<c;j++){
				cin>>a;
				v.push_back(a);
			}
			arr.push_back(v);
		}
		cout<<matrixmedian(arr,r,c)<<endl;
	}
	return 0;
}

3. nth root of integer
#include <bits/stdc++.h>
using namespace std;

// Method 1:
// In order to calculate nth root of a number, we can use the following procedure.

// If x lies in the range [0, 1) then we set the lower limit low = x and upper limit high = 1, because for this range of numbers the nth root is always greater than the given number and can never exceed 1.
// eg-  $\sqrt{0.09} = 0.3$.
// Otherwise, we take low = 1 and high = x.
// Declare a variable named epsilon and initialize it for accuracy you need.
// Say epsilon=0.01, then we can guarantee that our guess for nth root of the given number will be
// correct up to 2 decimal places.
// Declare a variable guess and initialize it to guess=(low+high)/2.
// Run a loop such that:
// if the absolute error of our guess is more than epsilon then do:
// if guessn > x, then high=x
// else low=x
// Making a new better guess i.e., guess=(low+high)/2.
// If the absolute error of our guess is less than epsilon then exit the loop.
// Absolute Error: Absolute Error can be calculated as abs(guessn -x)

void rootusingbinaryserch(double x ,int n ){
	double high,low;
	// if x is in range [0,1)
	if(x>=0 && x<1){
		low = x;
		high = 1;
	} else {
		low = 1;
		high = x;
	}

	double epsilon = 0.0001;
	double guess = low + (high-low)/2;

	while(abs(pow(guess,n)-x)>=epsilon){
		if(pow(guess,n)>x) high=guess;
		else low = guess;
		guess = low+(high-low)/2;
	}
	cout<<guess<<endl;
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
	double x;
	while(t--){
		cin>>x>>n;
		rootusingbinaryserch(x,n);
	}
	return 0;
}

4. search element in sorted and roated array
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

Day 12:(Bits)
1.check no is power of 2 or not
#include <bits/stdc++.h>
using namespace std;
// Method 1
bool isPowerOfTwo(int n) 
{ 
   if((n&(n-1)) == 0) return true;
   return false;
}

// Method 2
 // A simple method for this is to simply take the log of the 
 // number on base 2 and if you get an integer then number is power of 2.
bool isPowerOfTwo(int n) 
{ 
   if(n==0) 
   return false; 
  
   return (ceil(log2(n)) == floor(log2(n))); 
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
		(isPowerOfTwo(n))? cout<<n<<" is pow of 2 "<<endl:cout<<n<<" not a pow of 2 "<<endl;
	}
	return 0;
}

2.count total set bits
#include <bits/stdc++.h>
using namespace std;

// Method 1:
int countsetbits(int n){
	int count=0;
	for(int i=31;i>=0;i--){
		int k=n>>i;
		if(k&1) count++;
	}
	return count;
}

// Method 2:
int countsetbits(int n){
	int count=0;
	while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
	return count;
} 
// (logn) (Theta of logn)

// Method 3:
// this loop runs equals to no of setbits
int countsetbits(int n){
	int count=0;
	while (n) { 
        n = n&(n-1);
        count++;
    } 
	return count;
} 

// Method 4(using prebuit function)
int countsetbits(int n){
	return __builtin_popcount(n); 
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
		cout<<countsetbits(n)<<endl;
		
	}
	return 0;
}

3.count no of bits to change a to b
// Count number of bits to be flipped 
// to convert A into B 

// Input : a = 10, b = 20
// Output : 4
// Binary representation of a is 00001010
// Binary representation of b is 00010100
// We need to flip highlighted four bits in a
// to make it b.

// Input : a = 7, b = 10
// Output : 3
// Binary representation of a is 00000111
// Binary representation of b is 00001010
// We need to flip highlighted three bits in a
// to make it b.


//  1. Calculate XOR of A and B.      
//         a_xor_b = A ^ B
//   2. Count the set bits in the above 
//      calculated XOR result.
//         countSetBits(a_xor_b)
// XOR of two number will have set bits only at those places where A differs from B.

#include <iostream> 
using namespace std; 

// Function that count set bits 
int countSetBits(int n) 
{ 
	int count = 0; 
	while (n > 0) 
	{ 
		count++; 
		n &= (n-1); 
	} 
	return count; 
} 

// Function that return count of 
// flipped number 
int FlippedCount(int a, int b) 
{ 
	// Return count of set bits in 
	// a XOR b 
	return countSetBits(a^b); 
} 

// Driver code 
int main() 
{ 
	int a = 10; 
	int b = 20; 
	cout << FlippedCount(a, b)<<endl; 
	return 0; 
} 

4. divied no w/0 divied operator
#include <bits/stdc++.h>
using namespace std;


// Method 1:
// Approach : Keep subtracting the divisor from dividend until dividend becomes less than divisor. 
// The dividend becomes the remainder, and the number of times subtraction is done becomes the quotient.
// int divide(int n,int k){
// 	int sign = ((n<0) ^ (k<0))?-1:1;
// 	n=abs(n);
// 	k=abs(k);
// 	int count=0;
// 	while(n>=k){
// 		n -= k;
// 		count++;
// 	}
// 	return sign * count;
// }

// Time complexity : O(a)
// Auxiliary space : O(1)

//Method 2:
// Efficient Approach : Use bit manipulation in order to find the quotient. The divisor and dividend can be written as

// dividend = quotient * divisor + remainder

// As every number can be represented in base 2(0 or 1), represent the quotient in binary form by using shift operator as given below :

// Determine the most significant bit in the quotient. This can easily be calculated by iterating on the bit position i from 31 to 1.
// Find the first bit for which divisor << i is less than dividend and keep updating the ith bit position for which it is true.
// Add the result in temp variable for checking the next position such that (temp + (divisor << i) ) is less than dividend.
// Return the final answer of quotient after updating with corresponding sign.

int divide(long long n,long long k){
	int sign = ((n<0) ^ (k<0))?-1:1;
	n=abs(n);
	k=abs(k);
	int quotient=0,temp=0;
	for(int i=31;i>=0;i--){
		if((temp + (k<<i))<=n){
			temp += (k<<i);
			quotient |= 1<<i;
			// This for long long
			// quotient |= 1LL<<i;
		}
	}
	return sign * quotient;
}

// Time complexity : O(log(a))
// Auxiliary space : O(1)

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,k; cin>>t;
	while(t--){
		cin>>n>>k;
		cout<<divide(n,k)<<endl;
	}
	return 0;
}
5. find square w/o muliplication and division
#include <bits/stdc++.h>
using namespace std;

int squarewodivmul(int n){
	if(n<0) n=-n;
 	int count=0;
	for(int i=0;i<n;i++){
		count += n;
	}
	return count;
}
// Time complexity of above solution is O(n)

// We can do it in O(Logn) time using bitwise operators. The idea is based on the following fact.

//   square(n) = 0 if n == 0
//   if n is even 
//      square(n) = 4*square(n/2) 
//   if n is odd
//      square(n) = 4*square(floor(n/2)) + 4*floor(n/2) + 1 

// Examples
//   square(6) = 4*square(3)
//   square(3) = 4*(square(1)) + 4*1 + 1 = 9
//   square(7) = 4*square(3) + 4*3 + 1 = 4*9 + 4*3 + 1 = 49
// How does this work?

// If n is even, it can be written as
//   n = 2*x 
//   n2 = (2*x)2 = 4*x2
// If n is odd, it can be written as 
//   n = 2*x + 1
//   n2 = (2*x + 1)2 = 4*x2 + 4*x + 1
// floor(n/2) can be calculated using bitwise right shift operator. 2*x and 4*x can be calculated

int squarewodivmul(int n){
	if(n==0) return 0;
	if(n<0) n=-n;
 	int x =n>>1;
 	if(n&1) return ((squarewodivmul(x)<<2) + (x<<2) +1);
 	else return (squarewodivmul(x)<<2);
}

// complexity:O(Logn)

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
		cout<<squarewodivmul(n)<<endl;
	}
	return 0;
}

6. find msb in O(1)
#include <bits/stdc++.h>
using namespace std;

// Method 1
// An efficient solution for a fixed size integer (say 32 bits) is to one by one set bits, 
// then add 1 so that only the bit after MSB is set. Finally right shift by 1 and return the answer. 
// This solution does not require any condition checking.

int msb(int n){
	n |= n>>1;
	n |= n>>2;
	n |= n>>4;
	n |= n>>8;
	n |= n>>16;
	n=n+1;
	return (n>>1);
}
// Time complexity is O(1).

// Method 2
int msb(int n){
    if (n == 0) 
        return 0; 
  
    int msb = 0; 
    while (n != 0) { 
        n = n / 2; 
        msb++; 
    } 
  
    return (1 << msb); 
} 

// Method 3

int msb(int n){ 
  
    // To find the position 
    // of the most significant 
    // set bit 
    int k = (int)(log2(n)); 
  
    // To return the the value 
    // of the number with set 
    // bit at k-th position 
    return (int)(pow(2, k)); 
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
		cout<<msb(n)<<endl;
	}
	return 0;
}

7.powerset
#include <bits/stdc++.h>
using namespace std;

void powset(string str,int n){
	int powsetcount = pow(2,n);

	for(int i=0;i<powsetcount;i++){
		for(int j=0;j<n;j++){
			if(i & (1<<j)) cout<<str[j];
		}
		cout<<endl;
	}
}

// Method 2:
// The idea is to consider two cases for every character. 
// (i) Consider current character as part of current subset 
// (ii) Do not consider current character as part of current subset.

void powerset(string str,int n,int i,string curr){
	if(n==i){
		cout<<curr<<endl;
		return;
	}
	powerset(str,n,i+1,curr+str[i]);
	powerset(str,n,i+1,curr);
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
		string str;
		cin>>str;
		// powset(str,n);
		powerset(str,n,0,"");
	}
	return 0;
}

Day 13: stack and queue
1.check balance parenthisi
#include <bits/stdc++.h>
using namespace std;

bool validparenthese(string str){
	stack<char> stk;
	for(auto s:str){
		if(s == '(') stk.push(s);
		else{
			if(stk.empty()) return false;
			stk.pop();
		}
	}
	return true;
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
		string str;
		cin>>str;
		cout<<validparenthese(str)<<endl;
	}
	return 0;
}

2. implement queue
#include <bits/stdc++.h> 
using namespace std; 

struct QNode { 
	int data; 
	QNode* next; 
	QNode(int d) 
	{ 
		data = d; 
		next = NULL; 
	} 
}; 

struct Queue { 
	QNode *front, *rear; 
	Queue() 
	{ 
		front = rear = NULL; 
	} 

	void enQueue(int x) 
	{ 

		// Create a new LL node 
		QNode* temp = new QNode(x); 

		// If queue is empty, then 
		// new node is front and rear both 
		if (rear == NULL) { 
			front = rear = temp; 
			return; 
		} 

		// Add the new node at 
		// the end of queue and change rear 
		rear->next = temp; 
		rear = temp; 
	} 

	// Function to remove 
	// a key from given queue q 
	void deQueue() 
	{ 
		// If queue is empty, return NULL. 
		if (front == NULL) 
			return; 

		// Store previous front and 
		// move front one node ahead 
		QNode* temp = front; 
		front = front->next; 

		// If front becomes NULL, then 
		// change rear also as NULL 
		if (front == NULL) 
			rear = NULL; 

		delete (temp); 
	} 
}; 

// Driven Program 
int main() 
{ 

	Queue q; 
	q.enQueue(10); 
	q.enQueue(20); 
	q.deQueue(); 
	q.deQueue(); 
	q.enQueue(30); 
	q.enQueue(40); 
	q.enQueue(50); 
	q.deQueue(); 
	cout << "Queue Front : " << (q.front)->data << endl; 
	cout << "Queue Rear : " << (q.rear)->data; 
} 
// This code is contributed by rathbhupendra 
// Method 2:
// C++ program to implement a queue using an array 
#include <bits/stdc++.h> 
using namespace std; 

struct Queue { 
	int front, rear, capacity; 
	int* queue; 
	Queue(int c) 
	{ 
		front = rear = 0; 
		capacity = c; 
		queue = new int; 
	} 

	~Queue() { delete[] queue; } 

	// function to insert an element 
	// at the rear of the queue 
	void queueEnqueue(int data) 
	{ 
		// check queue is full or not 
		if (capacity == rear) { 
			printf("\nQueue is full\n"); 
			return; 
		} 

		// insert element at the rear 
		else { 
			queue[rear] = data; 
			rear++; 
		} 
		return; 
	} 

	// function to delete an element 
	// from the front of the queue 
	void queueDequeue() 
	{ 
		// if queue is empty 
		if (front == rear) { 
			printf("\nQueue is empty\n"); 
			return; 
		} 

		// shift all the elements from index 2 till rear 
		// to the left by one 
		else { 
			for (int i = 0; i < rear - 1; i++) { 
				queue[i] = queue[i + 1]; 
			} 

			// decrement rear 
			rear--; 
		} 
		return; 
	} 

	// print queue elements 
	void queueDisplay() 
	{ 
		int i; 
		if (front == rear) { 
			printf("\nQueue is Empty\n"); 
			return; 
		} 

		// traverse front to rear and print elements 
		for (i = front; i < rear; i++) { 
			printf(" %d <-- ", queue[i]); 
		} 
		return; 
	} 

	// print front of queue 
	void queueFront() 
	{ 
		if (front == rear) { 
			printf("\nQueue is Empty\n"); 
			return; 
		} 
		printf("\nFront Element is: %d", queue[front]); 
		return; 
	} 
}; 

// Driver code 
int main(void) 
{ 
	// Create a queue of capacity 4 
	Queue q(4); 

	// print Queue elements 
	q.queueDisplay(); 

	// inserting elements in the queue 
	q.queueEnqueue(20); 
	q.queueEnqueue(30); 
	q.queueEnqueue(40); 
	q.queueEnqueue(50); 

	// print Queue elements 
	q.queueDisplay(); 

	// insert element in the queue 
	q.queueEnqueue(60); 

	// print Queue elements 
	q.queueDisplay(); 

	q.queueDequeue(); 
	q.queueDequeue(); 

	printf("\n\nafter two node deletion\n\n"); 

	// print Queue elements 
	q.queueDisplay(); 

	// print front of the queue 
	q.queueFront(); 

	return 0; 
} 


3.implement stack
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Stack { 
    int top; 
  
public: 
    int a[MAX];
  
    Stack() { top = -1; } 
    void push(int x); 
    void pop(); 
    int peek(); 
    bool isEmpty(); 
};

void Stack::push(int x){
	if(top>=(MAX-1)) cout<<"stack is filled"<<endl;
	else a[++top]=x;
}
void Stack::pop(){
	if(top<0) cout<<"stack is empty"<<endl;
	else a[top--];
}
int Stack::peek(){
	if(top<0) return -1;
	return a[top];
}
bool Stack::isEmpty(){
	if(top==-1) return true;
	else return false;
}
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	class Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.peek() << " Popped from stack\n"; 
	return 0;
}

4. next greater element
#include <bits/stdc++.h>
using namespace std;

//Method 1:using stl
int nextgreaterelement(vector<int> arr,int n,int k){
	int h = (upper_bound(arr.begin(),arr.end(),k)-arr.begin());
	if(h>=n) return -1;
	return arr[h];
}

//Method 2:(using stack)
void printNGE(int arr[], int n) { 
  stack < int > s; 
  
  /* push the first element to stack */
  s.push(arr[0]); 
  
  // iterate for rest of the elements 
  for (int i = 1; i < n; i++) { 
  
    if (s.empty()) { 
      s.push(arr[i]); 
      continue; 
    } 
  
    /* if stack is not empty, then 
       pop an element from stack. 
       If the popped element is smaller 
       than next, then 
    a) print the pair 
    b) keep popping while elements are 
    smaller and stack is not empty */
    while (s.empty() == false && s.top() < arr[i]) 
    {          
        cout << s.top() << " --> " << arr[i] << endl; 
        s.pop(); 
    } 
  
    /* push next to stack so that we can find 
    next greater for it */
    s.push(arr[i]); 
  } 
  
  /* After iterating over the loop, the remaining 
  elements in stack do not have the next greater 
  element, so print -1 for them */
  while (s.empty() == false) { 
    cout << s.top() << " --> " << -1 << endl; 
    s.pop(); 
  } 
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
		cin>>n;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		cin>>k;
		cout<<nextgreaterelement(arr,n,k)<<endl;
	}
	return 0;
}

5. queue using stack
#include <bits/stdc++.h>
using namespace std;
stack<int> stk1,stk2;

void push(int x){
	stk1.push(x);
}

void pop() {
	if(stk2.empty()){
		while(!stk1.empty()){
			stk2.push(stk1.top());
			stk1.pop();
		}
	}
	cout<<"pop element "<<stk2.top();
	stk2.pop();
}
int front() {
	if(!stk1.empty()) return stk1.top();
	else return -1;
}
int back() {
	if(stk2.empty()) {
		while(!stk1.empty()){
			stk2.push(stk1.top());
			stk1.pop();
		}
	}
	return stk2.top();
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a; cin>>n;

	for(int i=0;i<n;i++){ cin>>a;push(a);}
	pop();
	
}

// Method
// CPP program to implement Queue using 
// two stacks with costly deQueue() 
#include <bits/stdc++.h> 
using namespace std; 

struct Queue { 
	stack<int> s1, s2; 

	// Enqueue an item to the queue 
	void enQueue(int x) 
	{ 
		// Push item into the first stack 
		s1.push(x); 
	} 

	// Dequeue an item from the queue 
	int deQueue() 
	{ 
		// if both stacks are empty 
		if (s1.empty() && s2.empty()) { 
			cout << "Q is empty"; 
			exit(0); 
		} 

		// if s2 is empty, move 
		// elements from s1 
		if (s2.empty()) { 
			while (!s1.empty()) { 
				s2.push(s1.top()); 
				s1.pop(); 
			} 
		} 

		// return the top item from s2 
		int x = s2.top(); 
		s2.pop(); 
		return x; 
	} 
}; 

// Driver code 
int main() 
{ 
	Queue q; 
	q.enQueue(1); 
	q.enQueue(2); 
	q.enQueue(3); 

	cout << q.deQueue() << '\n'; 
	cout << q.deQueue() << '\n'; 
	cout << q.deQueue() << '\n'; 

	return 0; 
} 

// Method 3 using recursive function in dequeue
// CPP program to implement Queue using 
// one stack and recursive call stack. 
#include <bits/stdc++.h> 
using namespace std; 

struct Queue { 
	stack<int> s; 

	// Enqueue an item to the queue 
	void enQueue(int x) 
	{ 
		s.push(x); 
	} 

	// Dequeue an item from the queue 
	int deQueue() 
	{ 
		if (s.empty()) { 
			cout << "Q is empty"; 
			exit(0); 
		} 

		// pop an item from the stack 
		int x = s.top(); 
		s.pop(); 

		// if stack becomes empty, return 
		// the popped item 
		if (s.empty()) 
			return x; 

		// recursive call 
		int item = deQueue(); 

		// push popped item back to the stack 
		s.push(x); 

		// return the result of deQueue() call 
		return item; 
	} 
}; 

// Driver code 
int main() 
{ 
	Queue q; 
	q.enQueue(1); 
	q.enQueue(2); 
	q.enQueue(3); 

	cout << q.deQueue() << '\n'; 
	cout << q.deQueue() << '\n'; 
	cout << q.deQueue() << '\n'; 

	return 0; 
} 

6. stack using queue
#include <bits/stdc++.h>
using namespace std;
queue<int> stk1,stk2;

void push(int x){
	stk2.push(x);
	while(!stk1.empty()){
		stk2.push(stk1.front());
		stk1.pop();
	}

	queue<int> q=stk1;
	stk1=stk2;
	stk2=q;
}

void pop() {
	cout<<"pop element "<<stk1.front();
	stk1.pop();
}
int top() {
	return stk1.front();
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a; cin>>n;

	for(int i=0;i<n;i++){ cin>>a;push(a);}
	pop();
	pop();
	cout<<top()<<endl;
	
}


Day 14(stack and queue)

1.largest rectangle in a histogram
#include <bits/stdc++.h>
using namespace std;


// Method 1;
// We have discussed a Divide and Conquer based O(nLogn) solution for this problem. In this post, O(n) time solution is discussed. 
// Like the previous post, width of all bars is assumed to be 1 for simplicity. For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle. 
// If we calculate such area for every bar ‘x’ and find the maximum of all areas, our task is done. How to calculate area with ‘x’ as smallest bar? 
// We need to know index of the first smaller (smaller than ‘x’) bar on left of ‘x’ and index of first smaller bar on right of ‘x’. Let us call these indexes as ‘left index’ and ‘right index’ respectively.
// We traverse all bars from left to right, maintain a stack of bars. Every bar is pushed to stack once. A bar is popped from stack when a bar of smaller height is seen. 
// When a bar is popped, we calculate the area with the popped bar as smallest bar. How do we get left and right indexes of the popped bar – the current index tells us the ‘right index’ and index of previous item in stack is the ‘left index’. 
// Following is the complete algorithm.

// 1) Create an empty stack.

// 2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.
// ……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
// ……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. 
// Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).

// 3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.


int histogramArea(vector<int> &arr,int n){
	stack<int> stk;

	int i=0,maxval=0;

	while(i<n){
		if(stk.empty() || arr[stk.top()]<=arr[i]) stk.push(i++);
		else{
			int tp = stk.top();
			stk.pop();
			int area = arr[tp] * (stk.empty()?i:i-stk.top()-1);
			maxval = max(area,maxval);
		}
	}
	while(!stk.empty()){
		int tp = stk.top();
		stk.pop();
		int area = arr[tp] * (stk.empty()?i:i-stk.top()-1);
		maxval = max(area,maxval);
	}
	return maxval;
}
// Time Complexity: Since every bar is pushed and popped only once, the time complexity of this method is O(n).
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
		for(int i=0;i<n;i++) {cin>>a;arr.push_back(a);}
		cout<<histogramArea(arr,n)<<endl;
	}
	return 0;
}

2. lru cache
#include <bits/stdc++.h>
using namespace std;



// We use two data structures to implement an LRU Cache.

// Queue which is implemented using a doubly linked list. The maximum size of the queue will be equal to the total number of frames available (cache size). 
// The most recently used pages will be near front end and least recently pages will be near the rear end.
// A Hash with page number as key and address of the corresponding queue node as value.
// When a page is referenced, the required page may be in the memory. If it is in the memory, we need to detach the node of the list and bring it to the front of the queue.
// If the required page is not in memory, we bring that in memory. In simple words, we add a new node to the front of the queue and update the corresponding node address in the hash. 
// If the queue is full, i.e. all the frames are full, 
// we remove a node from the rear of the queue, and add the new node to the front of the queue.


class LRU {
	list<int> dq;
	unordered_map<int,list<int>::iterator> mp;
	int cachesize;
public:
	LRU(int);
	void refer(int);
	void display();
};

LRU::LRU(int x){
	cachesize=x;
}
void LRU::refer(int x){
	if(mp.find(x)==mp.end()){
		// we have to check the cache it is full or not
		if(dq.size() == cachesize){
			int last = dq.back();
			dq.pop_back();
			mp.erase(last);
		}
	}
	else
		dq.erase(mp[x]);
	dq.push_front(x);
	mp[x]=dq.begin();

}

void LRU::display(){
	for(auto x:dq) cout<<x<<" ";
	cout<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
 	LRU ca(4); 
  
    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(1); 
    ca.refer(4); 
    ca.refer(5); 
    ca.display(); 
  
    return 0; 
}

3. minstack
#include <iostream> 
#include <stdlib.h> 

using namespace std; 

/* A simple stack class with 
basic stack funtionalities */
class Stack { 
private: 
	static const int max = 100; 
	int arr[max]; 
	int top; 

public: 
	Stack() { top = -1; } 
	bool isEmpty(); 
	bool isFull(); 
	int pop(); 
	void push(int x); 
}; 

/* Stack's member method to check 
if the stack is iempty */
bool Stack::isEmpty() 
{ 
	if (top == -1) 
		return true; 
	return false; 
} 

/* Stack's member method to check 
if the stack is full */
bool Stack::isFull() 
{ 
	if (top == max - 1) 
		return true; 
	return false; 
} 

/* Stack's member method to remove 
an element from it */
int Stack::pop() 
{ 
	if (isEmpty()) { 
		cout << "Stack Underflow"; 
		abort(); 
	} 
	int x = arr[top]; 
	top--; 
	return x; 
} 

/* Stack's member method to insert 
an element to it */
void Stack::push(int x) 
{ 
	if (isFull()) { 
		cout << "Stack Overflow"; 
		abort(); 
	} 
	top++; 
	arr[top] = x; 
} 

/* A class that supports all the stack 
operations and one additional 
operation getMin() that returns the 
minimum element from stack at 
any time. This class inherits from 
the stack class and uses an 
auxiliarry stack that holds minimum 
elements */
class SpecialStack : public Stack { 
	Stack min; 

public: 
	int pop(); 
	void push(int x); 
	int getMin(); 
}; 

/* SpecialStack's member method to 
insert an element to it. This method 
makes sure that the min stack is 
also updated with appropriate minimum 
values */
void SpecialStack::push(int x) 
{ 
	if (isEmpty() == true) { 
		Stack::push(x); 
		min.push(x); 
	} 
	else { 
		Stack::push(x); 
		int y = min.pop(); 
		min.push(y); 

		/* push only when the incoming element 
		of main stack is smaller 
		than or equal to top of auxiliary stack */
		if (x <= y) 
			min.push(x); 
	} 
} 

/* SpecialStack's member method to 
remove an element from it. This method 
removes top element from min stack also. */
int SpecialStack::pop() 
{ 
	int x = Stack::pop(); 
	int y = min.pop(); 

	/* Push the popped element y back 
	only if it is not equal to x */
	if (y != x) 
		min.push(y); 

	return x; 
} 
 

/* SpecialStack's member method to get 
minimum element from it. */
int SpecialStack::getMin() 
{ 
	int x = min.pop(); 
	min.push(x); 
	return x; 
} 

/* Driver program to test SpecialStack 
methods */
int main() 
{ 
	SpecialStack s; 
	s.push(10); 
	s.push(20); 
	s.push(30); 
	cout << s.getMin() << endl; 
	s.push(5); 
	cout << s.getMin(); 
	return 0; 
} 

// Method 2:(using an other element)
// C++ program to implement a stack that supports 
// getMinimum() in O(1) time and O(1) extra space. 
#include <bits/stdc++.h> 
using namespace std; 

// A user defined stack that supports getMin() in 
// addition to push() and pop() 
struct MyStack 
{ 
	stack<int> s; 
	int minEle; 

	// Prints minimum element of MyStack 
	void getMin() 
	{ 
		if (s.empty()) 
			cout << "Stack is empty\n"; 

		// variable minEle stores the minimum element 
		// in the stack. 
		else
			cout <<"Minimum Element in the stack is: "
				<< minEle << "\n"; 
	} 

	// Prints top element of MyStack 
	void peek() 
	{ 
		if (s.empty()) 
		{ 
			cout << "Stack is empty "; 
			return; 
		} 

		int t = s.top(); // Top element. 

		cout << "Top Most Element is: "; 

		// If t < minEle means minEle stores 
		// value of t. 
		(t < minEle)? cout << minEle: cout << t; 
	} 

	// Remove the top element from MyStack 
	void pop() 
	{ 
		if (s.empty()) 
		{ 
			cout << "Stack is empty\n"; 
			return; 
		} 

		cout << "Top Most Element Removed: "; 
		int t = s.top(); 
		s.pop(); 

		// Minimum will change as the minimum element 
		// of the stack is being removed. 
		if (t < minEle) 
		{ 
			cout << minEle << "\n"; 
			minEle = 2*minEle - t; 
		} 

		else
			cout << t << "\n"; 
	} 

	// Removes top element from MyStack 
	void push(int x) 
	{ 
		// Insert new number into the stack 
		if (s.empty()) 
		{ 
			minEle = x; 
			s.push(x); 
			cout << "Number Inserted: " << x << "\n"; 
			return; 
		} 

		// If new number is less than minEle 
		if (x < minEle) 
		{ 
			s.push(2*x - minEle); 
			minEle = x; 
		} 

		else
		s.push(x); 

		cout << "Number Inserted: " << x << "\n"; 
	} 
}; 

// Driver Code 
int main() 
{ 
	MyStack s; 
	s.push(3); 
	s.push(5); 
	s.getMin(); 
	s.push(2); 
	s.push(1); 
	s.getMin(); 
	s.pop(); 
	s.getMin(); 
	s.pop(); 
	s.peek(); 

	return 0; 
} 


4. next smaller element
#include <bits/stdc++.h>
using namespace std;

//Method 1:(using stack)
void nextlowerelement(vector<int> arr, int n) { 
  stack < int > s; 
  
  /* push the first element to stack */
  s.push(arr[0]); 
  
  // iterate for rest of the elements 
  for (int i = 1; i < n; i++) { 
  
    if (s.empty()) { 
      s.push(arr[i]); 
      continue; 
    } 
  
    //  if stack is not empty, then 
    //    pop an element from stack. 
    //    If the popped element is smaller 
    //    than next, then 
    // a) print the pair 
    // b) keep popping while elements are 
    // smaller and stack is not empty 
    while (s.empty() == false && s.top() > arr[i]) 
    {          
        cout << s.top() << " --> " << arr[i] << endl; 
        s.pop(); 
    } 
  
    /* push next to stack so that we can find 
    next greater for it */
    s.push(arr[i]); 
  } 
  
  /* After iterating over the loop, the remaining 
  elements in stack do not have the next greater 
  element, so print -1 for them */
  while (s.empty() == false) { 
    cout << s.top() << " --> " << -1 << endl; 
    s.pop(); 
  } 
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
		cin>>n;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		nextlowerelement(arr,n);
	}
	return 0;
}

5. rottenorange
#include <bits/stdc++.h>
using namespace std;
#define N 101
struct raxis{
	int x;
	int y;
};
int x_axis[]={-1,0,1,0};
int y_axis[]={0,1,0,-1};
int rottenorange(int arr[][N],int n,int m){
	raxis temp;
	queue<raxis> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j] == 2){
				temp.x=i;
				temp.y=j;
				q.push(temp);
			}
		}
	}
	// here we have a queue with axis containg all 2's
	int frame=-1;
	while(!q.empty()){
		int s = q.size();
		frame++;
		while(s--){
			raxis temp = q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int a = x_axis[i]+temp.x;
				int b = y_axis[i]+temp.y;
				if(a>=0&&a<n && b>=0 &&b<m && arr[a][b]==1){
					arr[a][b]=2;
					raxis temp1;
					temp1.x=a;
					temp1.y=b;
					q.push(temp1);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j] == 1) return -1;
		}
	}
	return frame;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,m; cin>>t;
	while(t--){
		cin>>n>>m;
		int arr[N][N];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		cout<<rottenorange(arr,n,m)<<endl;
		
	}
	return 0;
}
6.sliding window maximum
#include <bits/stdc++.h>
using namespace std;


// Method 1:(simple Method)
// void windowmax(vector<int> arr,int n,int k){
// 	for(int i=0;i<n-k+1;i++){
// 		int maxval=0;
// 		for(int j=i;j<k+i;j++){
// 			if(maxval<arr[j]) maxval = arr[j];
// 		}
// 		cout<<maxval<<" ";
// 	}
// 	cout<<endl;
// }

// Method 2:(using dequeue)
// Algorithm :
// Create a deque to store k elements.
// Run a loop and insert first k elements in the deque. While inserting the element if the element at the back of the queue is smaller than the current element remove all those elements and then insert the element.
// Now, run a loop from k to end of the array.
// Print the front element of the array
// Remove the element from the front of the queue if they are out of the current window.
// Insert the next element in the deque. While inserting the element if the element at the back of the queue is smaller than the current element remove all those elements and then insert the element.
// Print the maximum element of the last window.
void windowmax(vector<int> arr,int n,int k){
	deque<int> dq;
	for(int i=0;i<k;i++){
		while(!dq.empty() && arr[i]>=arr[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	for(int j=k;j<n;j++){
		cout<<arr[dq.front()]<< " ";
		while(!dq.empty() && dq.back() <= j-k) dq.pop_front();
		while(!dq.empty() && arr[j]>=arr[dq.back()]) dq.pop_back();
		dq.push_back(j);
	}
	cout<<arr[dq.front()]<<endl;
}

// Method 3:(using stack)
void print_max(int a[], int n, int k) 
{ 
    // max_upto array stores the index 
    // upto which the maximum element is a[i] 
    // i.e. max(a[i], a[i + 1], ... a[max_upto[i]]) = a[i] 
  
    int max_upto[n]; 
  
    // Update max_upto array similar to 
    // finding next greater element 
    stack<int> s; 
    s.push(0); 
    for (int i = 1; i < n; i++) { 
        while (!s.empty() && a[s.top()] < a[i]) { 
            max_upto[s.top()] = i - 1; 
            s.pop(); 
        } 
        s.push(i); 
    } 
    while (!s.empty()) { 
        max_upto[s.top()] = n - 1; 
        s.pop(); 
    } 
    int j = 0; 
    for (int i = 0; i <= n - k; i++) { 
  
        // j < i is to check whether the 
        // jth element is outside the window 
        while (j < i || max_upto[j] < i + k - 1) 
            j++; 
        cout << a[j] << " "; 
    } 
    cout << endl; 
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
		cin>>n;
		vector<int> arr;
		for(int i=0;i<n;i++) {cin>>a;arr.push_back(a);}
		cin>>k;
		windowmax(arr,n,k);
		
	}
	return 0;
}

Day 15:(string)
1. implement atoi and strstr
#include <bits/stdc++.h>
using namespace std;

int stringtoint(string str){
	int val=0,sign=1;
	for(auto s:str){
	    if(s == '-') {
	        sign = -1;
	        continue;
	    }
		int k = (s-'0');
		if(k>=0 && k<=9){
			val = val*10 + (s-'0');
		}else{
			return -1;
		}
	}
	return sign*val;
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
	string str;
	while(t--){
		cin>>str;
		cout<<stringtoint(str)<<endl;
	}
	return 0;
}

2.implement strstr
#include <bits/stdc++.h>
using namespace std;

int implementstrstr(string str1,string str2){
	if(str2.size()==0) return 0;
	int start=-1,j=0;
	int n=str1.size(),m=str2.size();
	for(int i=0;i<n;i++){
		if(j==m) break;
		if(str1[i]==str2[j]){
			if(j==0) start=i;
			j++;
		}else if(j>0 && str1[i] != str2[j]){
			j=0;
			i=start;
			start=-1;
		}
	}
	if(j!=m) start = -1; 
	return start;
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
	string str1,str2;
	while(t--){
		cin>>str1>>str2;

		cout<<implementstrstr(str1,str2)<<endl;
		
	}
	return 0;
}

3.longest pallidrone in a string
#include <bits/stdc++.h>
using namespace std;

void pallidrone(string str,int n) {
	int maxlen=1;
	int start=0;
	int l,r;
	for(int i=1;i<n;i++){
		//This is for  even length
		l=i-1;
		r=i;
		while(l>=0 && r<n && str[l]==str[r]) {
			if(r-l+1>maxlen){
				start = l;
				maxlen=(r-l+1);
			}
			l--;r++;
		}
		// This is for odd length
		l=i-1;
		r=i+1;
		while(l>=0 && r<n && str[l]==str[r]){
			if((r-l+1)>maxlen){
				start = l;
				maxlen = (r-l+1);
			}
			l--;r++;
		}
	}
	// cout<<start<<endl;
	for(int i=start;i<=start+maxlen-1;i++){
		cout<<str[i];
	}
	cout<<endl;
}

// Complexity Analysis:

// Time complexity: O(n^2), where n is the length of input string.
// Nested traversal of the string is needed. So time complexity is O(n^2).
// Auxiliary Space: O(1).
// No extra space is needed.

//Method 2:(using dp)

void pallidrone(string str,int n){
	bool dp[n][n];
	memset(dp,0,sizeof(dp));
	// this is for single char
	for(int i=0;i<n;i++) dp[i][i] = true;

	int maxlen = 1;
	int start=0;
	// this is for only 2 char
	for(int i=0;i<n;i++) {
		if(str[i]==str[i+1]) {
			start=i;
			dp[i][i+1] = true;
			maxlen = 2;
		}
	}
	// HERE L stand for the lenght of the string 
	for(int l=3;l<=n;l++) {
		for(int i=0;i<n-l+1;i++){
			int j=i+l-1;
			if(dp[i+1][j-1] && str[i]==str[j]){
				dp[i][j]=true;
				if(l>maxlen){
					start = i;
					maxlen = l;
				}
			}
		}
	}
	for(int i=start;i<=start+maxlen-1;i++){
		cout<<str[i];
	}
	cout<<endl;
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
	string str;
	while(t--){
		cin>>str;
		int n = str.size();
		pallidrone(str,n);
	}
	return 0;
}

4. interger to roman
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// map<ll,string> roman={{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}}; 

string integertoroman(int number){
	string s;
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
    int i=12;     
    while(number>0) 
    { 
      int div = number/num[i]; 
      number = number%num[i]; 
      while(div--) 
      { 
        s += sym[i];
      } 
      i--; 
    } 
    return s;
} 
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	
	while(t--){
		cin>>n;
		cout<<integertoroman(n)<<endl;
	}
	return 0;
}
// 3
// XL
// IL
// MCMIV
// 40
// 49
// 1904


5. longest common prefix
#include <bits/stdc++.h>
using namespace std;

// Method 1:(simple iterative way)
string lcp(vector<string> str,int n){
	if(str.size() == 0) return "";
	string sstr;
	int l=INT_MAX;
	for(auto s:str){
		if(s.size()<l){
			l = s.size();
			sstr = s;
		}
	}

	string finalstr="";
	int i=0,flag=0;
	for(auto s:sstr){
		for(auto word:str) {
			if(s != word[i] && i<word.size()){
				flag = 1;
				break;
			}
		}
		if(flag) break;
		finalstr += s;
		i++;
	}

	return finalstr;
}

// Method 2:(using recursion)
string commonPrefixUtil(string str1, string str2) 
{ 
    string result; 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Compare str1 and str2 
    for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++) 
    { 
        if (str1[i] != str2[j]) 
            break; 
        result.push_back(str1[i]); 
    } 
  
    return (result); 
} 
  
// A Function that returns the longest common prefix 
// from the array of strings 
string commonPrefix (string arr[], int n) 
{ 
    string prefix =  arr[0]; 
  
    for (int i=1; i<=n-1; i++) 
        prefix = commonPrefixUtil(prefix, arr[i]); 
  
    return (prefix); 
} 

// Method 3:(using binary search)
int findMinLength(string arr[], int n) 
{ 
    int min = INT_MAX; 
  
    for (int i=0; i<=n-1; i++) 
        if (arr[i].length() < min) 
            min = arr[i].length(); 
    return(min); 
} 
  
bool allContainsPrefix(string arr[], int n, string str, 
                       int start, int end) 
{ 
    for (int i=0; i<=n-1; i++) 
        for (int j=start; j<=end; j++) 
            if (arr[i][j] != str[j]) 
                return (false); 
    return (true); 
} 
  
// A Function that returns the longest common prefix 
// from the array of strings 
string commonPrefix(string arr[], int n) 
{ 
    int index = findMinLength(arr, n); 
    string prefix; // Our resultant string 
  
    // We will do an in-place binary search on the 
    // first string of the array in the range 0 to 
    // index 
    int low = 0, high = index; 
  
    while (low <= high) 
    { 
        // Same as (low + high)/2, but avoids overflow 
        // for large low and high 
        int mid = low + (high - low) / 2; 
  
        if (allContainsPrefix (arr, n, arr[0], low, mid)) 
        { 
            // If all the strings in the input array contains 
            // this prefix then append this substring to 
            // our answer 
            prefix = prefix + arr[0].substr(low, mid-low+1); 
  
            // And then go for the right part 
            low = mid + 1; 
        } 
  
        else // Go for the left part 
            high = mid - 1; 
    } 
  
    return (prefix); 
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
		vector<string> str;
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			str.push_back(s);
		}
		cout<<lcp(str,n)<<endl;
	}
	return 0;
}

6. reverse word in a string
#include <bits/stdc++.h>
using namespace std;

// Method 1:*using stl)
// string reversestring(string str){ 
// 	reverse(str.begin(),str.end());
// 	return str;
// }
// Method 2:*swaping the first and last
// string reversestring(string str){																																																								
// 	int n = str.size();
// 	int l = 0,r=n-1;
// 	while(l<r){
// 		swap(str[l++],str[r--]);
// 	}
// 	return str;
// }
// Method 3:
void reversestring(string &str){
	int start=0;
	for(int end=0;end<str.size();end++){
		if(str[end] == ' '){
			reverse(str.begin()+start,str.begin()+end);
			start = end+1;
		}
	}
	reverse(str.begin()+start,str.end());
	reverse(str.begin(),str.end());

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
	string str;
	while(t--){
		// cin>>str;
		// getline(cin,str);
		str="you like this program very much";
		reversestring(str);
		cout<<str<<endl;
	}
	return 0;
}

7. pattern serach rabinkarp kmp navie
#include <bits/stdc++.h>
using namespace std;
#define d 256

void naviasearch(string text,string pattern){
	int k = pattern.size();
	int n = text.size();
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			if(text[j+i] != pattern[j]){
				break;
			}
		}
		if(j == k) cout<<"index at "<<i<<endl;
	}
}
// we just create the hash and compare only the hash value
void rabinkarp(string text,string pattern){
	// this for module
	int m = 101;
	int thash =0,phash=0;

	int k = pattern.size();
	int n = text.size();
	int h=1;
	for(int i=0;i<k-1;i++)
		h = (d*h)%m;
	// hash for first k pattern and text

	for(int i=0;i<k;i++){
		thash = (d*thash + text[i])%m;
		phash = (d*phash + pattern[i])%m;
	}

	// cout<<thash<<" "<<phash<<endl;
	int i,j;
	for(i=0;i<=n-k;i++){
		if(thash == phash){
			for(j=0;j<k;j++){
				if(text[j+i] != pattern[j]){
					break;
				}
			}
			if(j == k) cout<<"index at "<<i<<endl;
		}
		if(i<(n-k)){
			thash = (d*(thash-text[i]*h) + text[i+k])%m;
			if(thash<0) thash += m;
		}
	}
}

void genratelcp(string pattern,int lcp[]){
	int m = pattern.size();
	lcp[0]=0;
	int i=1,len=0;
	while(i<m){
		if(pattern[i]==pattern[len]){
			len++;
			lcp[i]=len;
			i++;
		}else{
			if(len!=0) len = lcp[len-1];
			else{
				lcp[i]=0;i++;
			}
		}
	}
}

void kmpalgo(string text,string pattern){
	int m = pattern.size();
	int n = text.size();
	int lcp[m];
	genratelcp(pattern,lcp);
	int i=0,j=0;
	while(i<n){
		if(text[i] == pattern[j]){
			i++;j++;
		}
		if(j==m){
			cout<<"string at index "<<i-j<<endl;
			j=lcp[j-1];
		}else if(i<n && text[i] != pattern[j]){
			if(j!=0) j=lcp[j-1];
			else i++;
		}

	}
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
		string text,pattern;
		cin>>text>>pattern;
		kmpalgo(text,pattern);
		// cout<<endl;
	}
	return 0;
}

8. romanto interger
#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<char,ll> roman={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	string s;
	while(t--){
		cin>>s;
		n=s.length();
		ll sum=0;
		ll i;
		for(i=0;i<n-1;i++){
			if(roman[s[i]]<roman[s[i+1]]){
				sum += roman[s[i+1]]-roman[s[i]];
				i++;
			}else{
				sum += roman[s[i]];
			}
		}
		if(i==n-1) sum += roman[s[i]];
		cout<<sum<<endl;
	}
	return 0;
}
 

Day 16(string)
1. check for anagram
#include <bits/stdc++.h>
using namespace std;

// An anagram of a string is another string that contains same characters, 
// only the order of characters can be different. 
// For example, “abcd” and “dabc” are anagram of each other.

// Method 1:(using sorting)
// bool checkanagram(string str1,string str2){
// 	if(str1.size() != str2.size()) return false;
// 	sort(str1.begin(),str1.end());
// 	sort(str2.begin(),str2.end());
// 	for(int i=0;i<str1.size();i++){
// 		if(str1[i]!=str2[i]) return false;
// 	}
// 	return true;
// }

// Method 2:(using map)
// This contain extra space
bool checkanagram(string str1,string str2){
	if(str1.size() != str2.size()) return false;
	map<char,int> mp;
	for(auto s:str1) mp[s]++;
	for(auto s:str2) mp[s]--;
	for(auto x:mp){
		if(x.second) return false; 
	}
	return true;
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
		string str1,str2;
		cin>>str1>>str2;
		cout<<checkanagram(str1,str2)<<endl;
	}
	return 0;
}

2. min char need to insert in to make pallidrone
#include <bits/stdc++.h>
using namespace std;


// Method 1:(kmp method )
// But this method is not right 
// we have only check for the reference
void generatelps(string arr,int lps[],int n){
	int len =0;
	lps[0]=0;
	int i=1;
	while(i<n){
		if(arr[i] == arr[len]){
			len++;
			lps[i]=len;
			i++;
		}else{
			if(len !=0) len = lps[len-1];
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}


// int mininsertion(string str){
// 	string rstr = str;
// 	reverse(rstr.begin(),rstr.end());
// 	// cout<<rstr<<endl;
// 	string totalarr = str + "$" + rstr;
// 	int lps[totalarr.size()];
// 	generatelps(totalarr,lps,totalarr.size());

// 	return (str.size()-lps[totalarr.size()-1]);
// }

// Method 2 (using the recurrsion)
// int mininsertion(string str,int l,int r) {
// 	if(l>r) return INT_MAX;
// 	if(l == r) return 0;
// 	if(l == r-1) return (str[l]==str[r])? 0:1;

// 	if(str[l] == str[r]){
// 		return mininsertion(str,l+1,r-1);
// 	}
// 	return min(mininsertion(str,l,r-1),mininsertion(str,l+1,r))+1;
// }

// Method 3:(using dp)
// Dynamic Programming based Solution
// If we observe the above approach carefully, we can find that it exhibits overlapping subproblems.
// Suppose we want to find the minimum number of insertions in string “abcde”:

//                       abcde
//             /       |      \
//            /        |        \
//            bcde         abcd       bcd  <- case 3 is discarded as str[l] != str[h]
//        /   |   \       /   |   \
//       /    |    \     /    |    \
//      cde   bcd  cd   bcd abc bc
//    / | \  / | \ /|\ / | \
// de cd d cd bc c………………….
// The substrings in bold show that the recursion to be terminated and the recursion tree cannot originate from there. Substring in the same color indicates overlapping subproblems.

// How to re-use solutions of subproblems? Memoization technique is used to avoid similar subproblem recalls. We can create a table to store results of subproblems so that they can be used directly if same subproblem is encountered again.

// The below table represents the stored values for the string abcde.

// a b c d e
// ----------
// 0 1 2 3 4
// 0 0 1 2 3 
// 0 0 0 1 2 
// 0 0 0 0 1 
// 0 0 0 0 0
// How to fill the table?
// The table should be filled in diagonal fashion. For the string abcde, 0….4, the following should be order in which the table is filled:

// Gap = 1: (0, 1) (1, 2) (2, 3) (3, 4)

// Gap = 2: (0, 2) (1, 3) (2, 4)

// Gap = 3: (0, 3) (1, 4)

// Gap = 4: (0, 4)

int mininsertion(string str,int n){
	int dp[n][n];
	memset(dp,0,sizeof(dp));
	for(int gap=1;gap<n;gap++){
		for(int i=0,j=gap;j<n;i++,j++){
			if(str[i]==str[j]){
				dp[i][j]=dp[i+1][j-1];
			}else{
				dp[i][j] = min(dp[i][j-1],dp[i+1][j])+1;
			}
		}
	}
	return dp[0][n-1];
}
// Method 4 (using lcs)
int lcs( string X, string Y, int m, int n )  
{  
    int L[n+1][n+1];  
    int i, j;  
      
    /* Following steps build L[m+1][n+1] in bottom  
        up fashion. Note that L[i][j] contains length  
        of LCS of X[0..i-1] and Y[0..j-1] */
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
      
    /* L[m][n] contains length of LCS for X[0..n-1]  
        and Y[0..m-1] */
    return L[m][n];  
}  
  
void reverseStr(string& str)  
{  
    int n = str.length();  
  
    // Swap character starting from two  
    // corners  n
    for (int i = 0; i < n / 2; i++)  
        swap(str[i], str[n - i - 1]);  
}  
  
// LCS based function to find minimum number of  
// insertions  
int findMinInsertionsLCS(string str, int n)  
{  
    // Creata another string to store reverse of 'str'  
    string rev = "";  
    rev = str;  
    reverseStr(rev);  
      
    // The output is length of string minus length of lcs of  
    // str and it reverse  
    return (n - lcs(str, rev, n, n));  
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
		string str;
		cin>>str;
		int n = str.size();
		// cout<<mininsertion(str)<<endl;
		// cout<<mininsertion(str,0,n-1)<<endl;
		cout<<mininsertion(str,n)<<endl;
	}
	return 0;
}

3.compare version
// C/C++ program to compare 
// two version number 
#include <bits/stdc++.h> 
using namespace std; 

// Method to compare two versions. 
// Returns 1 if v2 is smaller, -1 
// if v1 is smaller, 0 if equal 
int versionCompare(string v1, string v2) 
{ 
	// vnum stores each numeric 
	// part of version 
	int vnum1 = 0, vnum2 = 0; 

	// loop untill both string are 
	// processed 
	for (int i = 0, j = 0; (i < v1.length() 
							|| j < v2.length());) { 
		// storing numeric part of 
		// version 1 in vnum1 
		while (i < v1.length() && v1[i] != '.') { 
			vnum1 = vnum1 * 10 + (v1[i] - '0'); 
			i++; 
		} 

		// storing numeric part of 
		// version 2 in vnum2 
		while (j < v2.length() && v2[j] != '.') { 
			vnum2 = vnum2 * 10 + (v2[j] - '0'); 
			j++; 
		} 

		if (vnum1 > vnum2) 
			return 1; 
		if (vnum2 > vnum1) 
			return -1; 

		// if equal, reset variables and 
		// go for next numeric part 
		vnum1 = vnum2 = 0; 
		i++; 
		j++; 
	} 
	return 0; 
} 

// Driver method to check above 
// comparison function 
int main() 
{ 
	string version1 = "1.0.3"; 
	string version2 = "1.0.7"; 

	if (versionCompare(version1, version2) < 0) 
		cout << version1 << " is smaller\n"; 
	else if (versionCompare(version1, version2) > 0) 
		cout << version2 << " is smaller\n"; 
	else
		cout << "Both version are equal\n"; 
	return 0; 
} 

4. zarray for patternsearch
#include <bits/stdc++.h>
using namespace std;

// for better reference watch this https://www.youtube.com/watch?v=z2pcwg82rOE

// Z algorithm (Linear time pattern searching Algorithm)
// This algorithm finds all occurrences of a pattern in a text in linear time. Let length of text be n and of pattern be m, then total time taken is O(m + n) with linear space complexity. Now we can see that both time and space complexity is same as KMP algorithm but this algorithm is Simpler to understand.

// In this algorithm, we construct a Z array.

// What is Z Array?
// For a string str[0..n-1], Z array is of same length as string. An element Z[i] of Z array stores length of the longest substring starting from str[i] which is also a prefix of str[0..n-1]. The first entry of Z array is meaning less as complete string is always prefix of itself.

// Example:
// Index            0   1   2   3   4   5   6   7   8   9  10  11 
// Text             a   a   b   c   a   a   b   x   a   a   a   z
// Z values         X   1   0   0   3   1   0   0   2   2   1   0 
// More Examples:
// str  = "aaaaaa"
// Z[]  = {x, 5, 4, 3, 2, 1}

// str = "aabaacd"
// Z[] = {x, 1, 0, 2, 1, 0, 0}

// str = "abababab"
// Z[] = {x, 0, 6, 0, 4, 0, 2, 0}
 
// How is Z array helpful in Searching Pattern in Linear time?
// The idea is to concatenate pattern and text, and create a string “P$T” where P is pattern, $ is a special character should not be present in pattern and text, and T is text. Build the Z array for concatenated string. In Z array, if Z value at any point is equal to pattern length, then pattern is present at that point.

// Example:
// Pattern P = "aab",  Text T = "baabaa"

// The concatenated string is = "aab$baabaa"

// Z array for above concatenated string is {x, 1, 0, 0, 0, 
//                                           3, 1, 0, 2, 1}.
// Since length of pattern is 3, the value 3 in Z array 
// indicates presence of pattern. 
// How to construct Z array?
//      A Simple Solution is two run two nested loops, the outer loop goes to every index and the inner loop finds length of the 
// longest prefix that matches substring starting at current index. The time complexity of this solution is O(n2).

//       We can construct Z array in linear time.

// The idea is to maintain an interval [L, R] which is the interval with max R
// such that [L,R] is prefix substring (substring which is also prefix). 

// Steps for maintaining this interval are as follows – 

// 1) If i > R then there is no prefix substring that starts before i and 
//    ends after i, so we reset L and R and compute new [L,R] by comparing 
//    str[0..] to str[i..] and get Z[i] (= R-L+1).

// 2) If i <= R then let K = i-L,  now Z[i] >= min(Z[K], R-i+1)  because 
//    str[i..] matches with str[K..] for atleast R-i+1 characters (they are in
//    [L,R] interval which we know is a prefix substring).     
//    Now two sub cases arise – 
//       a) If Z[K] < R-i+1  then there is no prefix substring starting at 
//          str[i] (otherwise Z[K] would be larger)  so  Z[i] = Z[K]  and 
//          interval [L,R] remains same.
//       b) If Z[K] >= R-i+1 then it is possible to extend the [L,R] interval
//          thus we will set L as i and start matching from str[R]  onwards  and
//          get new R then we will update interval [L,R] and calculate Z[i] (=R-L+1).
// For better understanding of above step by step procedure please check this animation – http://www.utdallas.edu/~besp/demo/John2010/z-algorithm.htm

// The algorithm runs in linear time because we never compare character less than R and with matching we increase R by one so there are at most T comparisons. 
// In mismatch case, mismatch happen only once for each i (because of which R stops), that’s another at most T comparison making overall linear complexity.


void zarray(string text,string pattern){
	int k = pattern.size();
	int n = text.size();
	string total = pattern + "$" + text;
	int zarr[total.size()];
	zarr[0]=0;
	int i=0,j=1;
	while(j<(total.size())){
		if(total[i] == total[j]){
			int a=i+1,b=j+1;
			while(a<(k+1) && a<(k+n+1)){
				if(total[a]==total[b]){a++;b++;}
				else{
					zarr[j]=a;
					break;
				}
			}
			j++;i=0;
		}else{
			zarr[j]=i;
			i=0;j++;
		}
		if(i>(k+1)) i=0;
	}
	for(int p=0;p<(k+n+1);p++){
		if(zarr[p]==k){
			cout<<"index at "<<p-(k+1)<<endl;
		}
	}
	// cout<<endl;

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
		string text,pattern;
		cin>>text>>pattern;
		zarray(text,pattern);
		// cout<<endl;
	}
	return 0;
}

5. group anagram
// #include <bits/stdc++.h>
// using namespace std;

// // An anagram of a string is another string that contains same characters, 
// // only the order of characters can be different. 
// // For example, “abcd” and “dabc” are anagram of each other.


// // Method 1:(using map)
// // This contain extra space

// void checkanagram(vector<string> str){
// 	vector<vector<string>> groupanagram;
//         // if(str.size() == 0) return groupanagram;
//         map<string,int> mp;
//         char p='+';
//         for(auto s:str){
//             int gp=0;
//             for(auto x:s){
//                 gp += (x-'a'); 
//             }
//             // if(mp[s]!=0) mp[s+p]=gp;
//             else mp[s]=gp;
//         }
//         int n = mp.size();
//         map<int,int> fmp;
//         int i=1;
//         for(auto x:mp){
//             // if(fmp[x.second]==0){
//             //     fmp[x.second]=i;
//             //     i++;
//             // }
//         	cout<<x.first<<" "<<x.second<<endl;
//         }
//  //        map<int,vector<string>> smp;
//  //        for(auto x:mp){
//  //            string st=x.first;
//  //            int hp=st.size();
//  //            if(st[hp-1] == '+') st.pop_back();
//  //            smp[(fmp[x.second]-1)].push_back(st);
//  //        }
//  //        for(int i=0;i<smp.size();i++){
//  //            vector<string> v;
//  //            for(auto ktp:smp[i]){
//  //                v.push_back(ktp);
//  //            }
//  //            groupanagram.push_back(v);
//  //        }
// 	// int a = groupanagram.size();
// 	// for(int i=0;i<a;i++){
// 	// 	for(int j=0;j<groupanagram[i].size();j++){
// 	// 		cout<<groupanagram[i][j]<<" ";
// 	// 	}
// 	// 	cout<<endl;
// 	// }
// }

// int main() {
	// #ifndef ONLINE_JUDGE
 //    	freopen("input.txt", "r", stdin);
 //    	freopen("output.txt", "w", stdout);
	// #endif
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	//ios_base& scientific (ios_base& str);
// 	int t,n; cin>>t;
// 	while(t--){
// 		cin>>n;
// 		vector<string> str;
// 		string s;
// 		for(int i=0;i<n;i++){
// 			cin>>s;
// 			str.push_back(s);
// 		}
// 		checkanagram(str);
// 	}
// 	return 0;
// }

// // Method 2

// CPP program for finding all anagram 
// pairs in the given array 
#include <algorithm> 
#include <iostream> 
#include <unordered_map> 
#include <vector> 
using namespace std; 
  
// Utility function for 
// printing anagram list 
void printAnagram( 
    unordered_map<string, 
                  vector<string> >& store) 
{ 
    unordered_map<string, 
                  vector<string> >::iterator it; 
    for (it = store.begin(); 
         it != store.end(); it++) { 
        vector<string> temp_vec(it->second); 
        int size = temp_vec.size(); 
        if (size > 1) { 
            for (int i = 0; i < size; i++) { 
                cout << temp_vec[i] << " "; 
            } 
            cout << "\n"; 
        } 
    } 
} 
  
// Utility function for storing 
// the vector of strings into HashMap 
void storeInMap(vector<string>& vec) 
{ 
    unordered_map<string, 
                  vector<string> > 
        store; 
    for (int i = 0; i < vec.size(); i++) { 
  
        string tempString(vec[i]); 
        sort(tempString.begin(), 
             tempString.end()); 
  
        // Check for sorted string 
        // if it already exists 
        if (store.find( 
                tempString) 
            == store.end()) { 
            vector<string> temp_vec; 
            temp_vec.push_back(vec[i]); 
            store.insert(make_pair( 
                tempString, temp_vec)); 
        } 
  
        else { 
            // Push new string to 
            // already existing key 
            vector<string> temp_vec( 
                store[tempString]); 
            temp_vec.push_back(vec[i]); 
            store[tempString] = temp_vec; 
        } 
    } 
  
    // print utility function for printing 
    // all the anagrams 
    printAnagram(store); 
} 
  
// Driver code 
int main() 
{ 
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    // initialize vector of strings 
    vector<string> arr; 
    arr.push_back("geeksquiz"); 
    arr.push_back("geeksforgeeks"); 
    arr.push_back("abcd"); 
    arr.push_back("forgeeksgeeks"); 
    arr.push_back("zuiqkeegs"); 
    arr.push_back("cat"); 
    arr.push_back("act"); 
    arr.push_back("tca"); 
  
    // utility function for storing 
    // strings into hashmap 
    storeInMap(arr); 
    return 0; 
} 

6. count and say
#include<bits/stdc++.h>
using namespace std;
#define ll long long

string solve(ll n){
    if(n == 1) return "1";
    else if(n==2) return "11";
    string str="11";
    for (ll i = 3; i<=n; i++) { 
        str += '$'; 
        ll len = str.size(); 
  
        ll cnt = 1;
        string  tmp = ""; 
        for (ll j = 1; j < len; j++) 
        { 
            if (str[j] != str[j-1]) 
            { 
                tmp += cnt + '0'; 
                tmp += str[j-1]; 
                cnt = 1; 
            } 
 
            else cnt++; 
        } 
        str = tmp; 
    } 
  
    return str;
}

int main()
{
    ll t,n; cin>>t;
    while(t--) {
        cin>>n;
        cout<<solve(n)<<endl;
    }
}
Day 17-18:(binary tree)
1.inorder traversal
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left,*right;
	Node(int x){
		data = x;
		left=NULL;right=NULL;
	}
};

void insert(struct Node *root,int a){
	queue<struct Node*> q;
	q.push(root);
	while(!q.empty()){
		struct Node *root = q.front();
		q.pop();
			if(!root->left){
				root->left = new Node(a);
				break;
			} 
			else q.push(root->left);
			if(!root->right){
				root->right = new Node(a);
				break;
			} 
			else q.push(root->right);
	}
}
void inorderprint(struct Node* root){
if(!root) return;
inorderprint(root->left);
cout<<root->data<<" ";
inorderprint(root->right);
}
void preorderprint(struct Node* root){
	if(!root) return;
	cout<<root->data<<" ";
	preorderprint(root->left);
	preorderprint(root->right);
}
void postorderprint(struct Node* root){
	if(!root) return;
	postorderprint(root->left);
	postorderprint(root->right);
	cout<<root->data<<" ";
}

void leftviewTree(struct Node* root){
	if(!root) return;
	queue<Node*> q;
	q.push(root);
	Node* temp;
	vector<int> v;
	while(!q.empty()){
		int k = q.size();
		temp = q.front();
		v.push_back(temp->data);
		while(k--){
			temp = q.front();
			q.pop();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
	for(auto x:v) cout<<x<<" ";
}
void rightviewTree(struct Node* root){
	if(!root) return;
	queue<Node*> q;
	q.push(root);
	Node* temp;
	vector<int> v;
	while(!q.empty()){
		int k = q.size();
		temp = q.back();
		v.push_back(temp->data);
		while(k--){
			temp = q.front();
			q.pop();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
	for(auto x:v) cout<<x<<" ";
}

// for bottom view or top view we use the horizontal distance for finding view
// for left we just decrease horizontal distance by 1
// for right we just increase horizontal distance by 1
void topviewTreeUtil(struct Node *root,map<int,int> &mp,int h){
	if(!root) return;
	if(mp[h]==0) mp[h]=root->data;
	topviewTreeUtil(root->left,mp,h-1);
	topviewTreeUtil(root->right,mp,h+1);
}

void topviewTree(struct Node* root){
	if(!root) return;
	map<int,int> mp;
	topviewTreeUtil(root,mp,0);
	// cout<<"dkd"<<endl;
	for(auto x:mp) cout<<x.second<<" ";
}
void bottomviewTreeUtil(struct Node *root,map<int,int> &mp,int h){
	if(!root) return;
	mp[h]=root->data;
	bottomviewTreeUtil(root->left,mp,h-1);
	bottomviewTreeUtil(root->right,mp,h+1);
}

void bottomviewTree(struct Node* root){
	if(!root) return;
	map<int,int> mp;
	bottomviewTreeUtil(root,mp,0);
	// cout<<"dkd"<<endl;
	for(auto x:mp) cout<<x.second<<" ";
}

void levelorder(Node *root){
	if(!root) return;
	queue<Node*> q;
	q.push(root);
	Node* temp;
	vector<int> v;
	while(!q.empty()){
		temp = q.front();
		v.push_back(temp->data);
		q.pop();
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
	for(auto x:v) cout<<x<<" ";
}

int height(Node *root){
	if(!root) return 0;
	int l=height(root->left);
	int r=height(root->right);
	return max(l,r)+1;
}
int diameterutil(Node* root,int &h){
	int lh=0,rh=0,ld=0,rd=0;
	if(!root){
		h=0;
		return 0;
	}
	ld = diameterutil(root->left,lh);
	rd = diameterutil(root->right,rh);
	h = max(lh,rh)+1;
	return max(lh+rh+1,max(ld,rd));
}

int diameter(Node* root){
	int h = 0;
	int k = diameterutil(root,h);
	return h;
}

// Method 1:
bool balancedornot(Node* root){
	if(!root)
        return true;
    if(root->left == NULL&&root->right==NULL)
        return true;
    int l = height(root->left);
    int r = height(root->right);
    // cout<<l<<" "<<r<<endl;
    if(abs(l-r)<=1 &&balancedornot(root->left)&&balancedornot(root->right))
        return true;
    else
        return false;	
}

bool balancedornotUtil(Node *root,int &h){
	int lh=0,rh=0;
	if(!root){
		h=0;
		return true;
	}

	bool l = balancedornotUtil(root->left,lh);
	bool r = balancedornotUtil(root->right,rh);

	h = max(l,r)+1;

	if(abs(lh-rh)>=2) return false;

	return l&&h;
}
// Method 2(finding height in same recursion)
// bool balancedornot(Node* root){
// 	int h=0;
// 	return balancedornotUtil(root,h);
// }

// Method 1: for finding lca in binarya tree (By Storing root to n1 and root to n2 paths):
// Following is simple O(n) algorithm to find LCA of n1 and n2.
// 1) Find path from root to n1 and store it in a vector or array.
// 2) Find path from root to n2 and store it in another vector or array.
// 3) Traverse both paths till the values in arrays are same. 
// Return the common element just before the mismatch
// lca for binary tree
// bool findpathrootton(Node* root,int n,vector<int> &vec) {
// 	if(!root) return false;
// 	vec.push_back(root->data);
// 	if(root->data == n) return true;

// 	if((root->left && findpathrootton(root->left,n,vec))||(root->right,findpathrootton(root->right,n,vec)))
// 		return true;
// 	vec.pop_back();
// 	return false;
// }

// int lcaBinaryTree(Node* root,int n1,int n2){
// 	vector<int> vec1,vec2;

// 	// path is not found from root
// 	if(!findpathrootton(root,n1,vec1) || !findpathrootton(root,n2,vec2)) return -1;

// 	int i;
// 	for(i=0;i<vec1.size()&&i<vec2.size();i++){
// 		if(vec1[i]!=vec2[i]) break;
// 	}
// 	// cout<<"hello"<<endl;
// 	return vec1[i-1];

// }

// Method 2 (Using Single Traversal)
// The method 1 finds LCA in O(n) time, but requires three tree traversals plus extra spaces for path arrays. 
// If we assume that the keys n1 and n2 are present in Binary Tree, 
// we can find LCA using single traversal of Binary Tree and without extra storage for path arrays.
Node* lcaBinaryTreeUtil(Node *root,int n1,int n2,bool &v1,bool &v2) {
	if(!root) return NULL;

	if(root->data == n1){
		v1=true;
		return root;
	}
	if(root->data == n2){
		v2 = true;
		return root;
	}

	Node *lroot = lcaBinaryTreeUtil(root->left,n1,n2,v1,v2);
	Node *rroot = lcaBinaryTreeUtil(root->right,n1,n2,v1,v2);

	if(lroot && rroot) return root;

	return (lroot!=NULL)?lroot:rroot;
}

bool find(Node *root,int n){
	if(!root) return NULL;

	if((root->data == n) || find(root->left,n) || find(root->right,n)){
		return true;
	}
	return false;
}

int lcaBinaryTree(Node* root,int n1,int n2){
	bool v1=false,v2=false;

	Node* lca = lcaBinaryTreeUtil(root,n1,n2,v1,v2);
	if((v1&&v2) || (v1 && find(lca,n2)) || (v2 && find(lca,n1))) return lca->data;

	return -1;
}

// 2 TREES ARE IDENTICAL OR NOT
 bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q== NULL) return true;
        if(p!=NULL && q!=NULL)
            if((p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right)) return true;
        return false;
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
		struct Node *root=NULL;
		for(int i=0;i<n;i++){
			cin>>a;
			if(root == NULL) root = new Node(a);
			else insert(root,a);
		}
		// cout<<"inorder: "; inorderprint(root); cout<<endl;
		// cout<<"preorder: "; preorderprint(root); cout<<endl;
		// cout<<"postorder: "; postorderprint(root); cout<<endl;
		// cout<<"left view: "; leftviewTree(root); cout<<endl;
		// cout<<"right view: "; rightviewTree(root); cout<<endl;
		// cout<<"top view: "; topviewTree(root); cout<<endl;
		// cout<<"bottom view: "; bottomviewTree(root); cout<<endl;
		// cout<<"level order: "; levelorder(root); cout<<endl;
		// cout<<"height: "<<height(root)<<endl;
		// cout<<"diameter: "<<diameter(root)<<endl;
		// cout<<"balancedornot: "<<balancedornot(root)<<endl;
		cout<<"lca binary tree: "<<lcaBinaryTree(root,5,4)<<endl;
	}
	return 0;
}

2. lcabinary tree using pinter
// C++ program to find lowest common ancestor using parent pointer 
#include <bits/stdc++.h> 
using namespace std; 

// Below are steps to find LCA.

// Create an empty hash table.
// Insert n1 and all of its ancestors in hash table.
// Check if n2 or any of its ancestors exist in hash table, 
// if yes return the first existing ancestor.


// A Tree Node 
struct Node 
{ 
	Node *left, *right, *parent; 
	int key; 
}; 

// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
	Node *temp = new Node; 
	temp->key = item; 
	temp->parent = temp->left = temp->right = NULL; 
	return temp; 
} 

/* A utility function to insert a new node with 
given key in Binary Search Tree */
Node *insert(Node *node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
	{ 
		node->left = insert(node->left, key); 
		node->left->parent = node; 
	} 
	else if (key > node->key) 
	{ 
		node->right = insert(node->right, key); 
		node->right->parent = node; 
	} 

	/* return the (unchanged) node pointer */
	return node; 
} 

// To find LCA of nodes n1 and n2 in Binary Tree 
Node *LCA(Node *n1, Node *n2) 
{ 
// Creata a map to store ancestors of n1 
map <Node *, bool> ancestors; 

// Insert n1 and all its ancestors in map 
while (n1 != NULL) 
{ 
	ancestors[n1] = true; 
	n1 = n1->parent; 
} 

// Check if n2 or any of its ancestors is in 
// map. 
while (n2 != NULL) 
{ 
	if (ancestors.find(n2) != ancestors.end()) 
		return n2; 
	n2 = n2->parent; 
} 

return NULL; 
} 

// Driver method to test above functions 
int main(void) 
{ 
	Node * root = NULL; 

	root = insert(root, 20); 
	root = insert(root, 8); 
	root = insert(root, 22); 
	root = insert(root, 4); 
	root = insert(root, 12); 
	root = insert(root, 10); 
	root = insert(root, 14); 

	Node *n1 = root->left->right->left; 
	Node *n2 = root->left; 
	Node *lca = LCA(n1, n2); 

	printf("LCA of %d and %d is %d \n", n1->key, n2->key, lca->key); 

	return 0; 
} 
// Time Complexity : O(h) where h is height of Binary Tree if we use hash table to implement the solution (Note that the above solution uses map which takes O(Log h) time to insert and find). So the time complexity of above implementation is O(h Log h).

// Auxiliary Space : O(h)


// Method 2:(in O(1))
// A O(h) time and O(1) Extra Space Solution:
// The above solution requires extra space because we need to use a hash table to store visited ancestors. We can solve the problem in O(1) extra space using following fact : If both nodes are at same level and if we traverse up using parent pointers of both nodes, the first common node in the path to root is lca.
// The idea is to find depths of given nodes and move up the deeper node pointer by the difference between depths. Once both nodes reach same level, traverse them up and return the first common node.


// A utility function to find depth of a node 
// (distance of it from root) 
int depth(Node *node) 
{ 
    int d = -1; 
    while (node) 
    { 
        ++d; 
        node = node->parent; 
    } 
    return d; 
} 
  
// To find LCA of nodes n1 and n2 in Binary Tree 
Node *LCA(Node *n1, Node *n2) 
{ 
    // Find depths of two nodes and differences 
    int d1 = depth(n1), d2 = depth(n2); 
    int diff = d1 - d2; 
  
    // If n2 is deeper, swap n1 and n2 
    if (diff < 0) 
    { 
        Node * temp = n1; 
        n1 = n2; 
        n2 = temp; 
        diff = -diff; 
    } 
  
    // Move n1 up until it reaches the same level as n2 
    while (diff--) 
        n1 = n1->parent; 
  
    // Now n1 and n2 are at same levels 
    while (n1 && n2) 
    { 
        if (n1 == n2) 
            return n1; 
        n1 = n1->parent; 
        n2 = n2->parent; 
    } 
  
    return NULL; 
}

Day 19 Binary Tree
1.max path sum
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left,*right;
	Node(int x){
		data = x;
		left=NULL;right=NULL;
	}
};

void insert(struct Node *root,int a){
	queue<struct Node*> q;
	q.push(root);
	while(!q.empty()){
		struct Node *root = q.front();
		q.pop();
			if(!root->left){
				root->left = new Node(a);
				break;
			} 
			else q.push(root->left);
			if(!root->right){
				root->right = new Node(a);
				break;
			} 
			else q.push(root->right);
	}
}

// max path sum b/w leaves

int maxpathsumleavesUtil(Node* root,int &sum){
	if(!root) return 0;
	if(root->left == NULL && root->right == NULL) return root->data;
	int lh = maxpathsumleavesUtil(root->left,sum);
	int rh = maxpathsumleavesUtil(root->right,sum);

	if(root->left && root->right) {
		sum = max(sum,lh+rh+root->data);
		return max(lh,rh)+root->data;
	}

	return (root->left==NULL)?rh+root->data:lh+root->data;
}

int maxpathsumleaves(Node* root){
	if(!root) return 0;
	int sum=INT_MIN;
	int h = maxpathsumleavesUtil(root,sum);
	return sum;
}

// max path sum in a tree

int maxpathsumUtil(Node* root,int &sum){
	if(!root) return 0;
	int lh = maxpathsumUtil(root->left,sum);
	int rh = maxpathsumUtil(root->right,sum);

	// we have to find this for -ve values
	int max_bw_top_and_node = max(max(lh,rh)+root->data,root->data);

	int max_path_in_one_iteration = max(max_bw_top_and_node,lh+rh+root->data);

	sum = max(sum,max_path_in_one_iteration);

	return max_bw_top_and_node;
}

int maxpathsum(Node* root){
	if(!root) return 0;
	int sum=INT_MIN;
	int h = maxpathsumUtil(root,sum);
	return sum;
}

// tree from inorder and preorder
int search(vector<int> &in,int l,int r,int key){
	for(int i=l;i<=r;i++){
   		if(in[i] == key) return i;
  	}
  	return -1;
}
// TreeNode* buildTreeUtil(vector<int> &pre,vector<int> &in, int l,int r,int &preindex){
// 	if(l>r) return NULL;
//  	TreeNode* temp = new TreeNode(pre[preindex++]);
//   	if(l == r) return temp;
  
//   	int index = search(in,l,r,temp->val);
  
//  	if(l<r){
//    		temp->left = buildTreeUtil(pre,in,l,index-1,preindex);
//    		temp->right = buildTreeUtil(pre,in,index+1,r,preindex);
//   	}
//   	return temp;
//  }
 
//  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//   	int i=0;
//   	int n = preorder.size();
//   	return buildTreeUtil(preorder,inorder,0,n-1,i);
//  }

//  // we can make the above function more efficient if we remove the search function
//  // we can use a map to remove the search function 
// // we just store value corresponding to their index in map 

//  // Method 2:
//  1. Do below until you reach the leftmost node.
// Keep creating the nodes from PreOrder traversal
// If the stack’s topmost element is not in the set, link the created node to the left child of stack’s topmost element (if any), without popping the element.
// Else link the created node to the right child of stack’s topmost element. Remove the stack’s topmost element from the set and the stack.
// Push the node to a stack.

// 1

// 2. Keep popping the nodes from the stack until either the stack is empty, or the topmost element of stack compares to the current element of InOrder traversal. Once the loop is over, push the last node back into the stack and into the set.

// 2

// 3. Goto Step 1.
// set<TreeNode*> s; 
// stack<TreeNode*> st; 
  
// // Function to build tree using given traversal 
// TreeNode* buildTree(int preorder[], int inorder[],int n) 
// { 
  
//     TreeNode* root = NULL; 
//     for (int pre = 0, in = 0; pre < n;)  
//     { 
  
//         TreeNode* node = NULL; 
//         do
//         { 
//             node = new TreeNode(preorder[pre]); 
//             if (root == NULL) 
//             { 
//                 root = node; 
//             } 
//             if (st.size() > 0)  
//             { 
//                 if (s.find(st.top()) != s.end()) 
//                 { 
//                     s.erase(st.top()); 
//                     st.top()->right = node; 
//                     st.pop(); 
//                 } 
//                 else
//                 { 
//                     st.top()->left = node; 
//                 } 
//             } 
//             st.push(node); 
//         } while (preorder[pre++] != inorder[in] && pre < n); 
  
//         node = NULL; 
//         while (st.size() > 0 && in < n &&  
//                 st.top()->val == inorder[in])  
//         { 
//             node = st.top(); 
//             st.pop(); 
//             in++; 
//         } 
  
//         if (node != NULL)  
//         { 
//             s.insert(node); 
//             st.push(node); 
//         } 
//     } 
  
//     return root; 
// } 

// for Symmetric purpose
bool isSymmetricUtil(Node* root1,Node* root2){
    if(root1==NULL && root2 ==NULL) return true;
    if(root1 && root2)
    	return ((root1->data == root2->data)&&isSymmetricUtil(root1->left,root2->right)&&isSymmetricUtil(root1->right,root2->left));
	return false;
}


// return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node* root){
    if(!root) return true;
    return isSymmetricUtil(root,root);
}

// flatten the binary tree
void preorderprint(struct Node* root){
	if(!root) return;
	cout<<root->data<<" ";
	preorderprint(root->left);
	preorderprint(root->right);
}

void flattenUtil(Node *root,Node **flat) {
	if(!root) return;
	Node* fleft = root->left; 
    Node* fright = root->right; 
	if(root != *flat){
		(*flat)->right = root;
		(*flat)->left = NULL;
		(*flat)=root;
	}
	flattenUtil(fleft,flat);
	flattenUtil(fright,flat);
	if(fleft == NULL && fright == NULL) (*flat)=root;
}

void flatten(Node *root){
	if(!root) return;
	Node *flat = root;
	flattenUtil(root,&flat);
	preorderprint(root);
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
		struct Node *root=NULL;
		for(int i=0;i<n;i++){
			cin>>a;
			if(root == NULL) root = new Node(a);
			else insert(root,a);
		}

		// cout<<"max path sum: "<<maxpathsumleaves(root)<<endl;
		// cout<<"max path sum: "<<maxpathsum(root)<<endl;
		//inorder or preorder to tree
		// inorder or postorder to tree just change the index and positon of right left
		// check for symmetric(mirror) of tree
		cout<<"flatten binary tree: "; flatten(root); cout<<endl;
	}
	return 0;
}

2. preorder post order
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define pii pair<ll,ll>
#define vec1 vector<ll>
#define vec2 vector<ll,ll>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep1(i,b) for(ll i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((ll)(x).size())
#define S(x) scanf("%d",&(x))
#define S2(x,y) scanf("%d%d",&(x),&(y))
#define SL(x) scanf("%lld",&(x))
#define SL2(x) scanf("%lld%lld",&(x),&(y))
#define P(x) printf("%d\n",(x))
#define FT first
#define SN second

void postorderutil(ll in[],ll pre[],ll l,ll r,map<ll,ll> &mp,ll &index){
	if(l>r) return;
	ll ind = mp[pre[index++]];
	postorderutil(in,pre,l,ind-1,mp,index);
	postorderutil(in,pre,ind+1,r,mp,index);
	cout<<in[ind]<<" ";
}

void postorder(ll in[],ll pre[],ll n){
	map<ll,ll> mp;
	rep(i,n){
		mp[in[i]] = i;
	}
	ll c=0;
	postorderutil(in,pre,0,n-1,mp,c);
}

int main() {
// 	#ifndef ONLINE_JUDGE
//     	freopen("input.txt", "r", stdin);
//     	freopen("output.txt", "w", stdout);
// 	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		ll pre[n],in[n];
		rep(i,n) {
			cin>>pre[i];
			in[i]=pre[i];
		}
		sort(in,in+n);
		postorder(in,pre,n);
		cout<<endl;
	}
	return 0;
}

Day 20:
1. inorder presucceser
// C++ program to find predecessor 
// and successor in a BST 
#include <bits/stdc++.h> 
using namespace std; 
  
// BST Node 
struct Node { 
    int key; 
    struct Node *left, *right; 
}; 
  
// Function that finds predecessor and successor of key in BST. 
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) 
{ 
    if (root == NULL) 
        return; 
  
    // Search for given key in BST. 
    while (root != NULL) { 
  
        // If root is given key. 
        if (root->key == key) { 
  
            // the minimum value in right subtree 
            // is predecessor. 
            if (root->right) { 
                suc = root->right; 
                while (suc->left) 
                    suc = suc->left; 
            } 
  
            // the maximum value in left subtree 
            // is successor. 
            if (root->left) { 
                pre = root->left; 
                while (pre->right) 
                    pre = pre->right; 
            } 
  
            return; 
        } 
  
        // If key is greater than root, then 
        // key lies in right subtree. Root 
        // could be predecessor if left 
        // subtree of key is null. 
        else if (root->key < key) { 
            pre = root; 
            root = root->right; 
        } 
  
        // If key is smaller than root, then 
        // key lies in left subtree. Root 
        // could be successor if right 
        // subtree of key is null. 
        else { 
            suc = root; 
            root = root->left; 
        } 
    } 
} 
  
// A utility function to create a new BST node 
Node* newNode(int item) 
{ 
    Node* temp = new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// A utility function to insert 
// a new node with given key in BST 
Node* insert(Node* node, int key) 
{ 
    if (node == NULL) 
        return newNode(key); 
    if (key < node->key) 
        node->left = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 
    return node; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int key = 65; // Key to be searched in BST 
  
    /* Let us create following BST 
                 50 
                /  \ 
               /    \ 
              30     70 
             / \     / \ 
            /   \   /   \ 
           20   40 60   80 
*/
    Node* root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
  
    Node *pre = NULL, *suc = NULL; 
  
    findPreSuc(root, pre, suc, key); 
    if (pre != NULL) 
        cout << "Predecessor is " << pre->key << endl; 
    else
        cout << "-1"; 
  
    if (suc != NULL) 
        cout << "Successor is " << suc->key; 
    else
        cout << "-1"; 
    return 0; 
} 
Output:
Predecessor is 60
Successor is 70

Time Complexity: O(N)
Auxiliary Space: O(1)

2.populate next right pointer
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

Node* insert(Node* root,int a){
	if(root == 	NULL) return new Node(a);
	
	if(root->data>a){
		root->left = insert(root->left,a);
	}else{
		root->right = insert(root->right,a);
	}
	return root;
}

void inorderprint(struct Node* root){
	if(!root) return;
	inorderprint(root->left);
	cout<<root->data<<" ";
	inorderprint(root->right);
}

void nextpointer(Node* root,int key){
	// cout<<"hello1";
	if(!root) return;
	queue<Node*> q;
	q.push(root);
	queue<Node*> temp;
	while(!q.empty()){
		int k = q.size();
		bool flag = false;
		temp = q;
		while(!temp.empty()){
			Node* tp = temp.front();
			if(tp->data == key){
				temp.pop();
				if(!temp.empty()){
					tp = temp.front();
					cout<<tp->data<<endl;
					flag = true;
					break;
				}else{
					cout<<"-1"<<endl;
					flag = true;
					break;
				}
			}
			if(flag) break;
			// cout<<"kp"<<tp->data<<endl;
			temp.pop();
		}
		// cout<<"hello2";
		if(flag) break;
		while(k--){
			Node* tp = q.front();
			// cout<<tp->data<<endl;
			q.pop();
			if(tp->left) q.push(tp->left);
			if(tp->right) q.push(tp->right);
		}
	}
}

bool search(Node* root,int key) {
	if(!root) return false;
	if(root->data == key) return true;
	if(key<root->data) return search(root->left,key);
	else return search(root->right,key);
	return false;
}

// constract a bst from preorder array
Node* constractPreorderTreeUtil(vector<int> &preorder,int &preIndex,int key,int min,int max,int n){
	if(preIndex>n) return NULL;
	Node* root=NULL;
	if(key>min && key<max){
		root = new Node(key);
		preIndex++;
		if(preIndex<n){
			root->left = constractPreorderTreeUtil(preorder,preIndex,preorder[preIndex],min,key,n);
			root->right = constractPreorderTreeUtil(preorder,preIndex,preorder[preIndex],key,max,n);
		}
	}
	return root;
}

Node* constractPreorderTree(vector<int> &preorder){
	int n = preorder.size();
	int preIndex=0;
	return constractPreorderTreeUtil(preorder,preIndex,preorder[0],INT_MIN,INT_MAX,n);
}
// preorder tree in O(n) time
// Node* constructTree ( int pre[], int size )  
// {  
//     // Create a stack of capacity equal to size  
//     Stack* stack = createStack( size );  
  
//     // The first element of pre[] is always root  
//     Node* root = newNode( pre[0] );  
  
//     // Push root  
//     push( stack, root );  
  
//     int i;  
//     Node* temp;  
  
//     // Iterate through rest of the size-1 items of given preorder array  
//     for ( i = 1; i < size; ++i )  
//     {  
//         temp = NULL;  
  
//         /* Keep on popping while the next value is greater than  
//         stack's top value. */
//         while ( !isEmpty( stack ) && pre[i] > peek( stack )->data )  
//             temp = pop( stack );  
  
//         // Make this greater value as the right child 
//                 // and push it to the stack 
//         if ( temp != NULL)  
//         {  
//             temp->right = newNode( pre[i] );  
//             push( stack, temp->right );  
//         }  
  
//         // If the next value is less than the stack's top 
//                 // value, make this value as the left child of the 
//                 // stack's top node. Push the new node to stack 
//         else
//         {  
//             peek( stack )->left = newNode( pre[i] );  
//             push( stack, peek( stack )->left );  
//         }  
//     }  
  
//     return root;  
// }  

// constract a bst from postorder array
Node* constractPostorderTreeUtil(vector<int> &postorder,int &postIndex,int key,int min,int max,int n){
	if(postIndex<0) return NULL;
	Node* root=NULL;
	if(key>min && key<max){
		root = new Node(key);
		postIndex--;
		if(postIndex>=0){
			root->right = constractPostorderTreeUtil(postorder,postIndex,postorder[postIndex],key,max,n);
			root->left = constractPostorderTreeUtil(postorder,postIndex,postorder[postIndex],min,key,n);
		}
	}
	return root;
}

Node* constractPostorderTree(vector<int> &postorder){
	int n = postorder.size();
	int postIndex=n-1;
	return constractPostorderTreeUtil(postorder,postIndex,postorder[n-1],INT_MIN,INT_MAX,n);
}

// constract a tree from level order
Node* constractLevelorderTreeUtil(Node* root,int key){
	if(root == NULL) return new Node(key);
	if(key<root->data) 
		root->left = constractLevelorderTreeUtil(root->left,key);
	else
		root->right = constractLevelorderTreeUtil(root->right,key);
	return root;
}

Node* constractLevelorderTree(vector<int> &levelorder){
	int n = levelorder.size();

	Node* root = NULL;

	for(int i=0;i<n;i++){
		root = constractLevelorderTreeUtil(root,levelorder[i]);
	}
	return root;
}
// constract level order in O(n) time
// Node* getNode(int data) 
// { 
//     Node* temp = new Node(0); 
//     temp->data = data; 
//     temp->left = NULL; 
//     temp->right = NULL; 
//     return temp; 
// } 
  
// // Function to construct the BST 
// Node* constructBst(int arr[], int n) 
// { 
//     if (n == 0) 
//         return NULL; 
  
//     Node* root; 
  
//     queue<NodeDetails> q; 
  
//     // index variable to 
//     // access array elements 
//     int i = 0; 
  
//     // Node details for the 
//     // root of the BST 
//     NodeDetails newNode; 
//     newNode.ptr = getNode(arr[i++]); 
//     newNode.min = INT_MIN; 
//     newNode.max = INT_MAX; 
//     q.push(newNode); 
  
//     // Getting the root of the BST 
//     root = newNode.ptr; 
  
//     // Until there are no more 
//     // elements in arr[] 
//     while (i != n) { 
  
//         // Extracting NodeDetails of a 
//         // node from the queue 
//         NodeDetails temp = q.front(); 
//         q.pop(); 
  
//         // Check whether there are more elements 
//         // in the arr[] and arr[i] can be  
//         // left child of 'temp.ptr' or not 
//         if (i < n && (arr[i] < temp.ptr->data  
//                         && arr[i] > temp.min)) { 
  
//             // Create NodeDetails for newNode 
//             // and add it to the queue 
//             newNode.ptr = getNode(arr[i++]); 
//             newNode.min = temp.min; 
//             newNode.max = temp.ptr->data; 
//             q.push(newNode); 
  
//             // Make this 'newNode' as left child 
//             // of 'temp.ptr' 
//             temp.ptr->left = newNode.ptr; 
//         } 
  
//         // Check whether there are more elements 
//         // in the arr[] and arr[i] can be  
//         // right child of 'temp.ptr' or not 
//         if (i < n && (arr[i] > temp.ptr->data 
//                           && arr[i] < temp.max)) { 
  
//             // Create NodeDetails for newNode 
//             // and add it to the queue 
//             newNode.ptr = getNode(arr[i++]); 
//             newNode.min = temp.ptr->data; 
//             newNode.max = temp.max; 
//             q.push(newNode); 
  
//             // Make this 'newNode' as right  
//             // child of 'temp.ptr' 
//             temp.ptr->right = newNode.ptr; 
//         } 
//     } 
  
//     // Root of the required BST 
//     return root; 
// }

// finding tree is bst or not
bool isBSTUtil(Node* root,int min,int max){
	if(!root) return true;  
    if (root->data < min || root->data > max)  return false; 

    return
        isBSTUtil(node->left, min, root->data-1) && 
        isBSTUtil(node->right, root->data+1, max);
}
bool isBST(Node* root){
	if(!root) true;
	// [-2147483648] fails on this output on leetcode
	return isBSTUtil(root,INT_MIN,INT_MAX);
}
Node* LCA(Node* root,int n1,int n2){
	if(!root) return NULL;
	if(root->data>n1 && root->data >n2) return LCA(root->left,n1,n2);
	if(root->data <n1 && root->data <n2) return LCA(root->right,n1,n2);
	return root;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a;cin>>t;
	while(t--){
		cin>>n;
		struct Node* root = NULL;
		vector<int> vec;
		for(int i=0;i<n;i++){
			cin>>a;
			root = insert(root,a);
			// vec.push_back(a);
		}
		// cout<<"bst: ";inorderprint(root);cout<<endl;
		// cout<<"nextpointer: ";nextpointer(root,4);cout<<endl;
		// cout<<"search: "<<search(root,7)<<endl;
		// root = constractPreorderTree(vec);
		// root = constractPostorderTree(vec);
		// root = constractLevelorderTree(vec);
		// inorderprint(root);
		cout<<"isbst: "<<isBST(root)<<endl;
	}
	return 0;
}

Day 21:(binary serach tree)
1.floor and ceil and tree
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

Node* insert(Node* root,int a){
	if(root == 	NULL) return new Node(a);
	
	if(root->data>a){
		root->left = insert(root->left,a);
	}else{
		root->right = insert(root->right,a);
	}
	return root;
}
void inorderprint(struct Node* root){
	if(!root) return;
	inorderprint(root->left);
	cout<<root->data<<" ";
	inorderprint(root->right);
}

int ceil(Node* root,int k){
	if(!root) return -1;
	if(root->data  == k){
		return root->data;
	}
	if(root->data < k){
		return ceil(root->right,k);
	}
	
	int val = ceil(root->left,k);
	return (val>=k)?val:root->data;
}
int floor(Node* root,int k){
	if(!root) return INT_MAX;
	if(root->data  == k){
		return root->data;
	}
	if(root->data > k){
		return floor(root->left,k);
	}
	
	int val = floor(root->right,k);
	return (val<=k)?val:root->data;
}
int kthsmallestDistance(Node* root,int &k){
	if(!root) return -1;
        int l = kthsmallestDistance(root->left,k);
        if(l!=-1) return l;
        if(k == 1) return root->data;
        k--;
        return kthsmallestDistance(root->right,k);
}
int kthlargestDistance(Node* root,int &k){
	if(!root) return INT_MAX;
        int r = kthlargestDistance(root->right,k);
        if(r!=INT_MAX) return r;
        if(k == 1) return root->data;
        k--;
        return kthlargestDistance(root->left,k);
}

// This method take O(n) extra space
// this also not return all pair
// we have to find more space efficient
bool pairsumUtil(Node* root,int sum,set<int> &s){
	if(!root) return false;
	if(pairsumUtil(root->left,sum,s)) return true;

	if(s.find((sum-root->data))!=s.end()){
		cout<<root->data<<" "<<(sum-root->data)<<endl;
		return true;
	}else{
		s.insert(root->data);
	}
	return pairsumUtil(root->right,sum,s);

}

// bool pairsum(Node* root,int sum){
// 	set<int> s;
// 	return pairsumUtil(root,sum,s);
// }

// there is a itertive solution for the above recursive approach

bool pairsum(Node* root,int sum){
	stack<Node*> stk1,stk2;

	Node* temp = root;
	while(temp!=NULL){
		stk1.push(temp);temp = temp->left;
	}
	temp = root;
	while(temp!=NULL){
		stk2.push(temp);temp = temp->right;
	}
	while(stk1.top() != stk2.top()){
		int n1 = (stk1.top())->data,n2 = (stk2.top())->data;
		if(n1 + n2 == sum){
			cout<<n1<<" "<<n2<<endl;
			return true;
		}
		if(n1+n2<sum){
			temp = stk1.top();
			stk1.pop();
			temp = temp->right;
			while(temp!=NULL){
				stk1.push(temp);temp = temp->left;
			}
		}else{
			temp = stk2.top();
			stk2.pop();
			temp = temp->left;
			while(temp!=NULL){
				stk2.push(temp);temp = temp->right;
			}
		}
	}
	return false;
}
// This is for the iterator purpose(forward iterator)(in sorted order)
class bstit {
private:
	stack<Node*> stk;
public:
	bstit(Node* root){
		Node* temp = root;
		while(temp!=NULL){
			stk.push(temp);temp = temp->left;
		}
	}
	Node* curr(){
		return stk.top();
	}
	void next(){
		Node* temp = stk.top();
		stk.pop();
		temp = temp->right;
		while(temp != NULL){
			stk.push(temp);temp = temp->left;
		}
	}

	bool isEnd(){
		return !(stk.size());
	}
};

void iterators(bstit it){
	while(!it.isEnd()){
		cout<<(it.curr())->data<<" ";
		it.next();
	}
}
// for forward iterator question

// This is for the iterator purpose(backward iterator)(in sorted order)
class bstitb {
private:
	stack<Node*> stk;
public:
	bstitb(Node* root){
		Node* temp = root;
		while(temp!=NULL){
			stk.push(temp);temp = temp->right;
		}
	}
	Node* curr(){
		return stk.top();
	}
	void next(){
		Node* temp = stk.top();
		stk.pop();
		temp = temp->left;
		while(temp != NULL){
			stk.push(temp);temp = temp->right;
		}
	}

	bool isEnd(){
		return !(stk.size());
	}
};

void iteratorb(bstitb it){
	while(!it.isEnd()){
		cout<<(it.curr())->data<<" ";
		it.next();
	}
}
// for forward iterator question

// for finding largest bst size in a binary tree
bool isBSTUtil(Node* root,int min,int max){
	if(root==NULL) return true;
	if(root->data < min || root->data > max) return false;
	return isBSTUtil(root->left,min,root->data-1) &&
		   isBSTUtil(root->right,root->data+1,max);
}
bool isBST(Node* root){
	return isBSTUtil(root,INT_MIN,INT_MAX);
}

int size(Node* root){
	if(root==NULL) return 0;
	return 1+size(root->left)+size(root->right);
}

// int largestBSTBT(Node* root){
// 	if(isBST(root)){
// 		return size(root);
// 	}
// 	return max(largestBSTBT(root->left),largestBSTBT(root->right));
// }
// Method 2 for largestbstin bt (more effiecient)\
// Method 2 (Tricky and Efficient)
// In method 1, we traverse the tree in top down manner and do BST test for every node. If we traverse the tree in bottom up manner, then we can pass information about subtrees to the parent. The passed information can be used by the parent to do BST test (for parent node) only in constant time (or O(1) time). A left subtree need to tell the parent whether it is BST or not and also need to pass maximum value in it. So that we can compare the maximum value with the parent’s data to check the BST property. Similarly, the right subtree need to pass the minimum value up the tree. The subtrees need to pass the following information up the tree for the finding the largest BST.
// 1) Whether the subtree itself is BST or not (In the following code, is_bst_ref is used for this purpose)
// 2) If the subtree is left subtree of its parent, then maximum value in it. And if it is right subtree then minimum value in it.
// 3) Size of this subtree if this subtree is BST (In the following code, return value of largestBSTtil() is used for this purpose)
int largestBSTSTUtil(Node* root,int &minval,int &maxval,int &finalmax,bool &isbst){
	if(root == NULL){
		isbst = true;
		return 0;
	}
	int min = INT_MAX;

	bool left_flag = false;
	bool right_flag = false;

	maxval = INT_MIN;

	int ls,rs;

	ls = largestBSTSTUtil(root->left,minval,maxval,finalmax,isbst);
	if(isbst && root->data > maxval) left_flag=true;

	min = minval;
	minval = INT_MAX;

	rs = largestBSTSTUtil(root->right,minval,maxval,finalmax,isbst);
	if(isbst && root->data < minval) right_flag=true;

	if(min < minval) minval = min;
	if(root->data < minval) minval = root->data; // for leaves
	if(root->data > maxval) maxval = root->data;

	if(left_flag && right_flag) {
		if(finalmax<(ls+rs+1)) finalmax = ls+rs+1;
		return ls+rs+1;
	}else{
		isbst = false;
		return 0;
	}

}

int largestBSTBT(Node* root){
	int min = INT_MAX;
	int max = INT_MIN;
	int maxsize = 0;
	bool isbst = false;
	return largestBSTSTUtil(root,min,max,maxsize,isbst);
}


int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a;cin>>t;
	while(t--){
		cin>>n;
		struct Node* root = NULL;
		vector<int> vec;
		for(int i=0;i<n;i++){
			cin>>a;
			root = insert(root,a);
			// vec.push_back(a);
		}
		// for(int i=0;i<16;i++){
		// 	// cout<<"ceil of "<<i<<" :"<<ceil(root,i)<<endl;
		// 	cout<<"floor of "<<i<<" :"<<floor(root,i)<<endl;
		// }
		// int k = 2;
		// cout<<"kth smallest: "<<kthsmallestDistance(root,k)<<endl;
		// cout<<"kth largest: "<<kthlargestDistance(root,k)<<endl;
		// cout<<"pair sum: "<<pairsum(root,24)<<endl;
		// bstit it(root);
		// iterators(it);
		// bstitb it(root);
		// iteratorb(it);
		cout<<"largest bst in bt: "<<largestBSTBT(root)<<endl;

	}
	return 0;
}

2. serialize and deserialze tree
#include <bits/stdc++.h>
using namespace std;
#define leaf -1

// Following are some simpler versions of the problem:

// If given Tree is Binary Search Tree?
// If the given Binary Tree is Binary Search Tree, we can store it by either storing preorder or postorder traversal. In case of Binary Search Trees, only preorder or postorder traversal is sufficient to store structure information.

// If given Binary Tree is Complete Tree?
// A Binary Tree is complete if all levels are completely filled except possibly the last level and all nodes of last level are as left as possible (Binary Heaps are complete Binary Tree). For a complete Binary Tree, level order traversal is sufficient to store the tree. We know that the first node is root, next two nodes are nodes of next level, next four nodes are nodes of 2nd level and so on.




// If given Binary Tree is Full Tree?
// A full Binary is a Binary Tree where every node has either 0 or 2 children. It is easy to serialize such trees as every internal node has 2 children. We can simply store preorder traversal and store a bit with every node to indicate whether the node is an internal node or a leaf node.

// How to store a general Binary Tree?
// A simple solution is to store both Inorder and Preorder traversals. This solution requires requires space twice the size of Binary Tree.
// We can save space by storing Preorder traversal and a marker for NULL pointers.


struct Node {
	int data;
	struct Node *left,*right;
	Node(int x){
		data = x;
		left=NULL;right=NULL;
	}
};

void insert(struct Node *root,int a){
	queue<struct Node*> q;
	q.push(root);
	while(!q.empty()){
		struct Node *root = q.front();
		q.pop();
			if(!root->left){
				root->left = new Node(a);
				break;
			} 
			else q.push(root->left);
			if(!root->right){
				root->right = new Node(a);
				break;
			} 
			else q.push(root->right);
	}
}
void inorderprint(struct Node* root){
if(!root) return;
inorderprint(root->left);
cout<<root->data<<" ";
inorderprint(root->right);
}

void serialize(Node* root,FILE *fp){
	if(root == NULL){
		fprintf(fp, "%d", leaf);
		return;
	}
	fprintf(fp, "%d", root->data);
	serialize(root->left,fp);
	serialize(root->right,fp);
}

void deSerialize(Node* root,FILE* fp){
	int val;
	if(!fscanf(fp, "%d ", &val) || val == leaf) return;
	root = new Node(val);
	deSerialize(root->left,fp);
	deSerialize(root->right,fp);
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a; cin>>t;
	while(t--){
		cin>>n;
		struct Node *root=NULL;
		for(int i=0;i<n;i++){
			cin>>a;
			if(root == NULL) root = new Node(a);
			else insert(root,a);
		}
		FILE *fp = fopen("tree.txt", "w"); 
	    if (fp == NULL) 
	    { 
	        puts("Could not open file"); 
	        return 0; 
	    } 
	    serialize(root, fp); 
	    fclose(fp);
	    Node *root1 = NULL; 
	    fp = fopen("tree.txt", "r"); 
	    deSerialize(root1, fp); 


	    cout<<"inorderprint: "; inorderprint(root1);cout<<endl;
	}
	return 0;
}

Day 22:(mixed question)

1.kth element in sorted array
// C++ implementation of randomized quickSelect 
#include<iostream> 
#include<climits> 
#include<cstdlib> 
using namespace std; 

int randomPartition(int arr[], int l, int r); 

// This function returns k'th smallest element in arr[l..r] using 
// QuickSort based method. ASSUMPTION: ELEMENTS IN ARR[] ARE DISTINCT 
int kthSmallest(int arr[], int l, int r, int k) 
{ 
	// If k is smaller than number of elements in array 
	if (k > 0 && k <= r - l + 1) 
	{ 
		// Partition the array around a random element and 
		// get position of pivot element in sorted array 
		int pos = randomPartition(arr, l, r); 

		// If position is same as k 
		if (pos-l == k-1) 
			return arr[pos]; 
		if (pos-l > k-1) // If position is more, recur for left subarray 
			return kthSmallest(arr, l, pos-1, k); 

		// Else recur for right subarray 
		return kthSmallest(arr, pos+1, r, k-pos+l-1); 
	} 

	// If k is more than the number of elements in the array 
	return INT_MAX; 
} 

void swap(int *a, int *b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

// Standard partition process of QuickSort(). It considers the last 
// element as pivot and moves all smaller element to left of it and 
// greater elements to right. This function is used by randomPartition() 
int partition(int arr[], int l, int r) 
{ 
	int x = arr[r], i = l; 
	for (int j = l; j <= r - 1; j++) 
	{ 
		if (arr[j] <= x) 
		{ 
			swap(&arr[i], &arr[j]); 
			i++; 
		} 
	} 
	swap(&arr[i], &arr[r]); 
	return i; 
} 

// Picks a random pivot element between l and r and partitions 
// arr[l..r] around the randomly picked element using partition() 
int randomPartition(int arr[], int l, int r) 
{ 
	int n = r-l+1; 
	int pivot = rand() % n; 
	swap(&arr[l + pivot], &arr[r]); 
	return partition(arr, l, r); 
} 

// Driver program to test above methods 
int main() 
{ 
	int arr[] = {12, 3, 5, 7, 4, 19, 26}; 
	int n = sizeof(arr)/sizeof(arr[0]), k = 3; 
	cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, k); 
	return 0; 
}


// C++ program for the above approach 
#include <iostream> 
using namespace std; 

// Function to find the Kth smallest 
// element in Unsorted Array 
int findKthSmallest(int arr[], int n, 
					int k) 
{ 

	// Initialize the max Element as 0 
	int max = 0; 

	// Iterate arr[] and find the maximum 
	// element in it 
	for (int i = 0; i < n; i++) { 

		if (arr[i] > max) 
			max = arr[i]; 
	} 

	// Frequenncy array to store 
	// the frequencies 
	int counter[max + 1] = { 0 }; 

	// Counter variable 
	int smallest = 0; 

	// Counting the frequencies 
	for (int i = 0; i < n; i++) { 
		counter[arr[i]]++; 
	} 

	// Iterate through the freq[] 
	for (int num = 1; num <= max; num++) { 

		// Check if num is present 
		// in the array 
		if (counter[num] > 0) { 

			// Increment the counter 
			// with the frequency 
			// of num 
			smallest += counter[num]; 
		} 

		// Checking if we have reached 
		// the Kth smallest element 
		if (smallest >= k) { 

			// Return the Kth 
			// smallest element 
			return num; 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	// Given array 
	int arr[] = { 7, 1, 4, 4, 20, 15, 8 }; 

	int N = sizeof(arr) / sizeof(arr[0]); 

	int K = 5; 

	// Function Call 
	cout << findKthSmallest(arr, N, K); 

	return 0; 
} 


2. floodfill
#include <bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<int>> &arr,int n,int m,int x,int y,int c,int newcolor){
	if(x<0 || x>=n || y<0 || y>=m) return;
	if(arr[x][y] != c) return;
	arr[x][y] = newcolor;
	floodfill(arr,n,m,x-1,y,c,newcolor);
	floodfill(arr,n,m,x,y+1,c,newcolor);
	floodfill(arr,n,m,x+1,y,c,newcolor);
	floodfill(arr,n,m,x,y-1,c,newcolor);
}

void print(vector<vector<int>> &arr,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,m,a,x,y,newcolor; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<vector<int>> arr;
		for(int i=0;i<n;i++){
			vector<int> v;
			for(int j=0;j<m;j++){
				cin>>a;
				v.push_back(a);
			}
			arr.push_back(v);
		}
		cin>>x>>y>>newcolor;
		int c = arr[x][y];
		floodfill(arr,n,m,x,y,c,newcolor);
		print(arr,n,m);
	}
	return 0;
}

3. binarytodoublelinkedlist
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left,*right;
	Node(int x){
		data = x;
		left=NULL;right=NULL;
	}
};

void insert(struct Node *root,int a){
	queue<struct Node*> q;
	q.push(root);
	while(!q.empty()){
		struct Node *root = q.front();
		q.pop();
			if(!root->left){
				root->left = new Node(a);
				break;
			} 
			else q.push(root->left);
			if(!root->right){
				root->right = new Node(a);
				break;
			} 
			else q.push(root->right);
	}
}
void inorderprint(struct Node* root){
if(!root) return;
inorderprint(root->left);
cout<<root->data<<" ";
inorderprint(root->right);
}

// Method 1:
// 1. If left subtree exists, process the left subtree
// …..1.a) Recursively convert the left subtree to DLL.
// …..1.b) Then find inorder predecessor of root in left subtree (inorder predecessor is rightmost node in left subtree).
// …..1.c) Make inorder predecessor as previous of root and root as next of inorder predecessor.
// 2. If right subtree exists, process the right subtree (Below 3 steps are similar to left subtree).
// …..2.a) Recursively convert the right subtree to DLL.
// …..2.b) Then find inorder successor of root in right subtree (inorder successor is leftmost node in right subtree).
// …..2.c) Make inorder successor as next of root and root as previous of inorder successor.
// 3. Find the leftmost node and return it (the leftmost node is always head of converted DLL).
Node* binarytolistUtil1(Node* root){
	if(root == NULL) return root;

	if(root->left != NULL){
		Node* left = binarytolistUtil1(root->left);
		while(left->right!=NULL) left = left->right;
		left->right = root;
		root->left = left;
	}
	if(root->right != NULL){
		Node* right = binarytolistUtil1(root->right);
		while(right->left!=NULL) right = right->left;
		right->left = root;
		root->right = right;
	}
	return root;
}


Node* binarytolist1(Node* root){
	if(root == NULL) return root;
	root = binarytolistUtil1(root);
	while(root->left!=NULL) root = root->left;
	return root;
}


// Method 2:
// 1) Fix Left Pointers: In this step, we change left pointers to point to previous nodes in DLL. The idea is simple, we do inorder traversal of tree. In inorder traversal, we keep track of previous visited node and change left pointer to the previous node. See fixPrevPtr() in below implementation.

// 2) Fix Right Pointers: The above is intuitive and simple. 
// How to change right pointers to point to next node in DLL? 
// The idea is to use left pointers fixed in step 1. 
// We start from the rightmost node in Binary Tree (BT). 
// The rightmost node is the last node in DLL. 
// Since left pointers are changed to point to previous node in DLL, 
// we can linearly traverse the complete DLL using these pointers. 
// The traversal would be from last to first node. While traversing the DLL, we keep track of the previously visited node and change the right pointer to the previous node. 
// See fixNextPtr() in below implementation.

void fixprevpionter(Node* root,Node** prev){
	if(root == NULL) return;
	fixprevpionter(root->left,prev);
	root->left = (*prev);
	(*prev) = root;
	fixprevpionter(root->right,prev);
}

Node* fixnextpointer(Node* root){
	Node* pre=NULL;
	while(root && root->right!=NULL) root = root->right;

	while(root && root->left != NULL){
		pre = root;
		root = root->left;
		root->right = pre;
	}
	return root;
}

Node* binarytolist2(Node* root){
	Node* pre = NULL;
	fixprevpionter(root,&pre);

	return fixnextpointer(root);
}

// Time Complexity: O(n) where n is the number of nodes in given Binary Tree. 
// The solution simply does two traversals of all Binary Tree nodes.

// Method 3:
// In this post, a third solution is discussed which seems to be the simplest of all. 
// The idea is to do inorder traversal of the binary tree. 
// While doing inorder traversal, keep track of the previously visited node in a variable 
// say prev. For every visited node, make it next of prev and previous of this node as prev.
void binarytolistUtil3(Node* root,Node** head,Node** prev){
	if(root == NULL) return;

	binarytolistUtil3(root->left,head,prev);
	if(*prev == NULL){
		*head = root;
	}else{
		root->left = *prev;
		(*prev)->right = root;
	}
	*prev = root;
	binarytolistUtil3(root->right,head,prev);
}

Node* binarytolist3(Node* root){
	Node *head = NULL,*pre = NULL;

	binarytolistUtil3(root,&head,&pre);

	return head;
}
// Time Complexity: The above program does a simple inorder traversal, 
// so time complexity is O(n) where n is the number of nodes in given binary tree.

// Method 4:(only single varible (2 variable used in method 3))
// we start from the right node
// n the following implementation, we traverse the tree in inorder fashion. We add nodes at the beginning of current linked list and update head of the list using pointer to head pointer. Since we insert at the beginning, we need to process leaves in reverse order. 
// For reverse order, we first traverse the right subtree before the left subtree. i.e. do a reverse inorder traversal.
void binarytolistUtil4(Node* root,Node** head){
	if(root == NULL) return;

	binarytolistUtil4(root->right,head);
	root->right = (*head);
	if(*head != NULL){
		(*head)->left = root;
	}
	*head = root;
	binarytolistUtil4(root->left,head);

}

Node* binarytolist4(Node* root){
	Node *head = NULL;
	binarytolistUtil4(root,&head);
	return head;
}
// Time Complexity: O(n), as the solution does a single traversal of given Binary Tree.

void printlist(Node* root){
	while(root!=NULL){
		cout<<root->data<<" ";
		root = root->right;
	}
}
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a; cin>>t;
	while(t--){
		cin>>n;
		struct Node *root=NULL;
		for(int i=0;i<n;i++){
			cin>>a;
			if(root == NULL) root = new Node(a);
			else insert(root,a);
		}
		root = binarytolist4(root);

	    cout<<"binarytolist: "; printlist(root);cout<<endl;
	}
	return 0;
}

4. distantno in a window
#include <bits/stdc++.h>
using namespace std;

void distantelement(vector<int> arr,int k){
	int n = arr.size();
	map<int,int> mp;
	int dist_count=0;
	for(int i=0;i<k;i++){
		if(mp[arr[i]]==0) dist_count++;
		mp[arr[i]]++;
	}
	cout<<dist_count<<" ";
	for(int i = k;i<n;i++){
		if(mp[arr[i-k]] == 1) dist_count--;
		mp[arr[i-k]] -= 1;
		if(mp[arr[i]]==0) dist_count++;
		mp[arr[i]] += 1;
		cout<<dist_count<<" ";
	}
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
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		distantelement(arr,k);
		
	}
	return 0;
} 
5. kth largest no in a stream
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t,n,k; cin>>t;
    while(t--) {
        cin>>k>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        
        for(ll i=0;i<n;i++){
            if(pq.size() < (k)) {
                pq.push(arr[i]);
                if(pq.size()==k) cout<<pq.top()<<" ";
                else cout<<"-1"<<" ";
            }
            else{
                if(arr[i]>pq.top()){
                    pq.pop();
                    pq.push(arr[i]);
                }
                cout<<pq.top()<<" ";
            }
        }
        cout<<endl;
    }
}

6. median in a stream
#include <bits/stdc++.h>
using namespace std;


// The idea is to use max heap and min heap to store the elements of higher half and lower half. Max heap and min heap can be implemented using priority_queue in C++ STL. Below is the step by step algorithm to solve this problem.
// Algorithm:

// Create two heaps. One max heap to maintain elements of lower half and one min heap to maintain elements of higher half at any point of time..
// Take initial value of median as 0.
// For every newly read element, insert it into either max heap or min heap and calculate the median based on the following conditions:
// If the size of max heap is greater than size of min heap and the element is less than previous median then pop the top element from max heap and insert into min heap and insert the new element to max heap else insert the new element to min heap. Calculate the new median as average of top of elements of both max and min heap.
// If the size of max heap is less than size of min heap and the element is greater than previous median then pop the top element from min heap and insert into max heap and insert the new element to min heap else insert the new element to max heap. Calculate the new median as average of top of elements of both max and min heap.
// If the size of both heaps are same. Then check if current is less than previous median or not. If the current element is less than previous median then insert it to max heap and new median will be equal to top element of max heap. If the current element is greater than previous median then insert it to min heap and new median will be equal to top element of min heap.
void streamMedian(vector<int> pq){
	int n = pq.size();
	priority_queue<int> maxpq;
	priority_queue<int,vector<int>,greater<int>> minpq;
	int median = pq[0];
	maxpq.push(median);
	cout<<median<<" ";

	for(int i=1;i<n;i++){
		int x = pq[i];
		if(maxpq.size()>minpq.size()){
			if(x < median){
				minpq.push(maxpq.top());
				maxpq.pop();
				maxpq.push(x);
			}else{
				minpq.push(x);
			}
			median = (minpq.top()+maxpq.top())/2;
		}else if(maxpq.size() == minpq.size()){
			if(x<median){
				maxpq.push(x);
				median = maxpq.top();
			}else{
				minpq.push(x);
				median = minpq.top();
			}
		}else{
			if(x>median){
				maxpq.push(minpq.top());
				minpq.pop();
				minpq.push(x);
			}else{
				maxpq.push(x);
			}
			median = (minpq.top()+maxpq.top())/2;
		}
		cout<<median<<" ";
	}

}
// Time Complexity: O(n Log n)
// Auxiliary Space : O(n)
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
		vector<int> pq;
		for(int i=0;i<n;i++){
			cin>>a;
			pq.push_back(a);
		}
		streamMedian(pq);
		cout<<endl;
	}
	return 0;
}

DAy 23
1. cycle detetion
#include <bits/stdc++.h>
using namespace std;

// this is the dfs approach for finding cycle
// bool iscyclicUtil(vector<list<int>> &adj,int v,int i,vector<bool> &visited,int parent){
// 	visited[i]=true;
// 	// cout<<i<<" ";
// 	for(auto it=adj[i].begin();it!=adj[i].end();it++){
// 		if(!visited[*it]) {
// 			if(iscyclicUtil(adj,v,*it,visited,i)) return true;
// 		}
// 		else if(*it != parent){
// 			return true;
// 		}
// 	}
// 	return false;
// }

// bool iscyclic(vector<list<int>> &adj,int v){
// 	vector<bool> visited(v,false);
// 	for(int i=0;i<v;i++){
// 		if(!visited[i]) {
// 			if(iscyclicUtil(adj,v,i,visited,-1)) return true;
// 		}
// 	}
// 	return false;
// }

// This is the bfs approach for finding cycle
// bool iscyclicUtil(vector<list<int>> &adj,int v,int i,vector<bool> &visited){
// 	vector<int> parent(v,-1);
// 	queue<int> q;
// 	q.push(i);
// 	while(!q.empty()){
// 		int u = q.front();
// 		q.pop();
// 		for(auto it = adj[u].begin();it!=adj[u].end();it++){
// 			if(!visited[*it]){
// 				visited[*it]=true;
// 				parent[*it]=u;
// 				q.push(*it);
// 			}
// 			else if(*it != parent[u]){
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }

// bool iscyclic(vector<list<int>> &adj,int v){
// 	vector<bool> visited(v,false);
// 	for(int i=0;i<v;i++){
// 		if(!visited[i]) {
// 			if(iscyclicUtil(adj,v,i,visited)) return true;
// 		}
// 	}
// 	return false;
// }

// detact cycle in directed graph (taking a recursionstk in place of a parent )
bool iscyclicUtil(vector<list<int>> &adj,int v,int i,vector<bool> &visited,vector<bool> &recursionstk){
	if(!visited[i]){
		visited[i]=true;
		recursionstk[i]=true;
		for(auto it=adj[i].begin();it!=adj[i].end();it++){
			if(!visited[*it]) {
				if(iscyclicUtil(adj,v,*it,visited,recursionstk)) return true;
			}
			else if(recursionstk[*it]){
				return true;
			}
		}
	}
	recursionstk[i]=false;
	return false;
}

bool iscyclic(vector<list<int>> &adj,int v){
	vector<bool> visited(v,false),recursionstk(v,false);
	for(int i=0;i<v;i++){
		if(!visited[i]) {
			if(iscyclicUtil(adj,v,i,visited,recursionstk)) return true;
		}
	}
	return false;
}

// union and find method for cycle detection
int find(int parent[], int i)  
{  
    if (parent[i] == -1)  
        return i;  
    return find(parent, parent[i]);  
}  
  
// A utility function to do union of two subsets  
void Union(int parent[], int x, int y)  
{  
    int xset = find(parent, x);  
    int yset = find(parent, y);  
    if(xset != yset) 
    {  
        parent[xset] = yset;  
    }  
}  
  
// The main function to check whether a given graph contains  
// cycle or not  
int isCycle( Graph* graph )  
{  
    // Allocate memory for creating V subsets  
    int *parent = new int[graph->V * sizeof(int)];  
  
    // Initialize all subsets as single element sets  
    memset(parent, -1, sizeof(int) * graph->V);  
  
    // Iterate through all edges of graph, find subset of both  
    // vertices of every edge, if both subsets are same, then  
    // there is cycle in graph.  
    for(int i = 0; i < graph->E; ++i)  
    {  
        int x = find(parent, graph->edge[i].src);  
        int y = find(parent, graph->edge[i].dest);  
  
        if (x == y)  
            return 1;  
  
        Union(parent, x, y);  
    }  
    return 0;  
} 

// this is using the color scheme
bool Graph::DFSUtil(int u, int color[]) 
{ 
    // GRAY :  This vertex is being processed (DFS 
    //         for this vertex has started, but not 
    //         ended (or this vertex is in function 
    //         call stack) 
    color[u] = GRAY; 
  
    // Iterate through all adjacent vertices 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // An adjacent of u 
  
        // If there is 
        if (color[v] == GRAY) 
          return true; 
  
        // If v is not processed and there is a back 
        // edge in subtree rooted with v 
        if (color[v] == WHITE && DFSUtil(v, color)) 
          return true; 
    } 
  
    // Mark this vertex as processed 
    color[u] = BLACK; 
  
    return false; 
} 
  
// Returns true if there is a cycle in graph 
bool Graph::isCyclic() 
{ 
    // Initialize color of all vertices as WHITE 
    int *color = new int[V]; 
    for (int i = 0; i < V; i++) 
        color[i] = WHITE; 
  
    // Do a DFS traversal beginning with all 
    // vertices 
    for (int i = 0; i < V; i++) 
        if (color[i] == WHITE) 
           if (DFSUtil(i, color) == true) 
              return true; 
  
    return false; 
} 

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,v,e,v1,v2; cin>>t;
	while(t--){
		cin>>v>>e;
		vector<list<int>> adj(v); 
		for(int i=0;i<e;i++){
			cin>>v1>>v2;
			adj[v1].push_back(v2);
			// adj[v2].push_back(v1);
		}
		cout<<iscyclic(adj,v)<<endl;
	}
	return 0;
}

2. connected compoent 
#include <bits/stdc++.h>
using namespace std;

void dfsUtil(vector<list<int>> &adj,int v,int i,vector<bool> &visited){
	visited[i]=true;
	cout<<i<<" ";
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]) dfsUtil(adj,v,*it,visited);
	}
}

int connectedComponent(vector<list<int>> &adj,int v){
	vector<bool> visited(v,false);
	int count=0;
	for(int i=0;i<v;i++){
		if(!visited[i]){
			dfsUtil(adj,v,i,visited);
			count++;
		}
	}
	return count;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,v,e,v1,v2; cin>>t;
	while(t--){
		cin>>v>>e;
		vector<list<int>> adj(v); 
		for(int i=0;i<e;i++){
			cin>>v1>>v2;
			adj[v1].push_back(v2);
			adj[v2].push_back(v1);
		}
		dfs(adj,v);
		cout<<endl;
	}
	return 0;
}

3. bipirate graph
// C++ program to find out whether 
// a given graph is Bipartite or not. 
// It works for disconnected graph also. 
#include <bits/stdc++.h> 

using namespace std; 

const int V = 4; 

// This function returns true if 
// graph G[V][V] is Bipartite, else false 
bool isBipartiteUtil(int G[][V], int src, int colorArr[]) 
{ 
	colorArr[src] = 1; 

	// Create a queue (FIFO) of vertex numbers a 
	// nd enqueue source vertex for BFS traversal 
	queue <int> q; 
	q.push(src); 

	// Run while there are vertices in queue (Similar to BFS) 
	while (!q.empty()) 
	{ 
		// Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 ) 
		int u = q.front(); 
		q.pop(); 

		// Return false if there is a self-loop 
		if (G[u][u] == 1) 
		return false; 

		// Find all non-colored adjacent vertices 
		for (int v = 0; v < V; ++v) 
		{ 
			// An edge from u to v exists and 
			// destination v is not colored 
			if (G[u][v] && colorArr[v] == -1) 
			{ 
				// Assign alternate color to this 
				// adjacent v of u 
				colorArr[v] = 1 - colorArr[u]; 
				q.push(v); 
			} 

			// An edge from u to v exists and destination 
			// v is colored with same color as u 
			else if (G[u][v] && colorArr[v] == colorArr[u]) 
				return false; 
		} 
	} 

	// If we reach here, then all adjacent vertices can 
	// be colored with alternate color 
	return true; 
} 

// Returns true if G[][] is Bipartite, else false 
bool isBipartite(int G[][V]) 
{ 
	// Create a color array to store colors assigned to all 
	// veritces. Vertex/ number is used as index in this 
	// array. The value '-1' of colorArr[i] is used to 
	// ndicate that no color is assigned to vertex 'i'. 
	// The value 1 is used to indicate first color is 
	// assigned and value 0 indicates second color is 
	// assigned. 
	int colorArr[V]; 
	for (int i = 0; i < V; ++i) 
		colorArr[i] = -1; 

	// This code is to handle disconnected graoh 
	for (int i = 0; i < V; i++) 
	if (colorArr[i] == -1) 
		if (isBipartiteUtil(G, i, colorArr) == false) 
		return false; 

	return true; 
} 

// Driver program to test above function 
int main() 
{ 
	int G[][V] = {{0, 1, 0, 1}, 
		{1, 0, 1, 0}, 
		{0, 1, 0, 1}, 
		{1, 0, 1, 0} 
	}; 

	isBipartite(G) ? cout << "Yes" : cout << "No"; 
	return 0; 
} 


4. dfs
#include <bits/stdc++.h>
using namespace std;

void dfsUtil(vector<list<int>> &adj,int v,int i,vector<bool> &visited){
	visited[i]=true;
	cout<<i<<" ";
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]) dfsUtil(adj,v,*it,visited);
	}
}

void dfs(vector<list<int>> &adj,int v){
	vector<bool> visited(v,false);
	for(int i=0;i<v;i++){
		if(!visited[i]) dfsUtil(adj,v,i,visited);
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,v,e,v1,v2; cin>>t;
	while(t--){
		cin>>v>>e;
		vector<list<int>> adj(v); 
		for(int i=0;i<e;i++){
			cin>>v1>>v2;
			adj[v1].push_back(v2);
			adj[v2].push_back(v1);
		}
		dfs(adj,v);
		cout<<endl;
	}
	return 0;
}

5. topologicalsort
#include <bits/stdc++.h>
using namespace std;

void toposortUtil(vector<list<int>> &adj,int v,int i,vector<bool> &visited,stack<int> &top){
	visited[i]=true;
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]) toposortUtil(adj,v,*it,visited,top);
	}
	top.push(i);
}

void toposort(vector<list<int>> &adj,int v){
	vector<bool> visited(v,false);
	stack<int> top;
	for(int i=0;i<v;i++){
		if(!visited[i]) toposortUtil(adj,v,i,visited,top);
	}
	while(!top.empty()){
		cout<<top.top()<<" ";
		top.pop();
	}
}

//Kahn’s algorithm for Topological Sorting

void khantoposort(vector<list<int>> &adj,int v){
	vector<int> inorder(v,0);
	for(int i=0;i<v;i++){
		for(auto it=adj[i].begin();it!=adj[i].end();it++){
			inorder[*it]++;
		}
	}
	vector<int> topsort;
	int count=0;
	queue<int> q;
	for(int i=0;i<v;i++){
		if(inorder[i] == 0) q.push(i);
	} 

	while(!q.empty()){
		int u = q.front();
		q.pop();
		topsort.push_back(u);
		for(auto it=adj[u].begin();it!=adj[u].end();it++){
			if(--inorder[*it] == 0)
				q.push(*it);
		}
		count++;
	}
	if(count != v) {
		cout<<"not possible "<<endl;
		return;
	}
	for(auto x:topsort) cout<<x<<" ";
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,v,e,v1,v2; cin>>t;
	while(t--){
		cin>>v>>e;
		vector<list<int>> adj(v); 
		for(int i=0;i<e;i++){
			cin>>v1>>v2;
			adj[v1].push_back(v2);
			// adj[v2].push_back(v1);
		}
		khantoposort(adj,v);
		cout<<endl;
	}
	return 0;
}

6. noofisland
#include <bits/stdc++.h>
using namespace std;

int x_axis[] = {-1,-1,-1,0,0,1,1,1};
int y_axis[] = {0,1,-1,-1,1,-1,0,1};

void dfsutil(vector<int> arr[],int n,int m,int x,int y,vector<vector<bool>> &visited){
    visited[x][y]=true;
    for(int i=0;i<8;i++){
        int a = x+x_axis[i];
        int b = y+y_axis[i];
        if(a>=0 &&a<n && b>=0 && b<m){
            if(arr[a][b]!=0 && !visited[a][b])
                dfsutil(arr,n,m,a,b,visited);
        }
    }
    
}

int findIslands(vector<int> arr[], int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    int count=0;
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            if(arr[i][j]!=0 && !visited[i][j]){
                dfsutil(arr,n,m,i,j,visited);
                count++;
            }
        }
    }
    return count;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_ base& str);
	int t,n,m,a; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<int> arr[n];
		for(int i=0;i<n;i++){
			vector<int> temp(m);
			arr[i]=temp;
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		cout<<findIslands(arr,n,m)<<endl;
	}
	return 0;
}

7. bfs
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<list<int>> &adj,int v,int i){
	vector<bool> visited(v,false);
	queue<int> q;
	visited[i]=true;
	q.push(i);
	while(!q.empty()){
		int u = q.front();
		cout<<u<<" ";
		q.pop();
		for(auto it = adj[u].begin();it!=adj[u].end();it++){
			if(!visited[*it]){
				// cout<<"kd "<<(*it)<<" ";
				visited[*it]=true;
				q.push(*it);
			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,v,e,v1,v2; cin>>t;
	while(t--){
		cin>>v>>e;
		vector<list<int>> adj(v); 
		for(int i=0;i<e;i++){
			cin>>v1>>v2;
			adj[v1].push_back(v2);
			// adj[v2].push_back(v1);
		}
		bfs(adj,v,2);
	}
	return 0;
}

Day 24;
1.FLOYD warshell
// C++ Program for Floyd Warshall Algorithm 
#include <bits/stdc++.h> 
using namespace std; 

// Number of vertices in the graph 
#define V 4 

/* Define Infinite as a large enough 
value.This value will be used for 
vertices not connected to each other */
#define INF 99999 

// A function to print the solution matrix 
void printSolution(int dist[][V]); 

// Solves the all-pairs shortest path 
// problem using Floyd Warshall algorithm 
void floydWarshall (int graph[][V]) 
{ 
	/* dist[][] will be the output matrix 
	that will finally have the shortest 
	distances between every pair of vertices */
	int dist[V][V], i, j, k; 

	/* Initialize the solution matrix same 
	as input graph matrix. Or we can say 
	the initial values of shortest distances 
	are based on shortest paths considering 
	no intermediate vertex. */
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 

	/* Add all vertices one by one to 
	the set of intermediate vertices. 
	---> Before start of an iteration, 
	we have shortest distances between all 
	pairs of vertices such that the 
	shortest distances consider only the 
	vertices in set {0, 1, 2, .. k-1} as 
	intermediate vertices. 
	----> After the end of an iteration, 
	vertex no. k is added to the set of 
	intermediate vertices and the set becomes {0, 1, 2, .. k} */
	for (k = 0; k < V; k++) 
	{ 
		// Pick all vertices as source one by one 
		for (i = 0; i < V; i++) 
		{ 
			// Pick all vertices as destination for the 
			// above picked source 
			for (j = 0; j < V; j++) 
			{ 
				// If vertex k is on the shortest path from 
				// i to j, then update the value of dist[i][j] 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 

	// Print the shortest distance matrix 
	printSolution(dist); 
} 

/* A utility function to print solution */
void printSolution(int dist[][V]) 
{ 
	cout<<"The following matrix shows the shortest distances"
			" between every pair of vertices \n"; 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INF) 
				cout<<"INF"<<"	 "; 
			else
				cout<<dist[i][j]<<"	 "; 
		} 
		cout<<endl; 
	} 
} 

// Driver code 
int main() 
{ 
	/* Let us create the following weighted graph 
			10 
	(0)------->(3) 
		|	 /|\ 
	5 |	 | 
		|	 | 1 
	\|/	 | 
	(1)------->(2) 
			3	 */
	int graph[V][V] = { {0, 5, INF, 10}, 
						{INF, 0, 3, INF}, 
						{INF, INF, 0, 1}, 
						{INF, INF, INF, 0} 
					}; 

	// Print the solution 
	floydWarshall(graph); 
	return 0; 
} 

// This code is contributed by rathbhupendra 


2. dikastra
#include <bits/stdc++.h>
using namespace std;

int mindist(bool pathset[],int dist[],int v){
	int minval = INT_MAX,minindex;
	for(int i=0;i<v;i++){
		if(!pathset[i] && dist[i]<minval){
			minval = dist[i];
			minindex=i;
		}
	}
	return minindex;
}

void dikastra(vector<vector<int>> &arr,int v,int src){
	bool pathset[v];
	int dist[v];
	for(int i=0;i<v;i++){ dist[i]=INT_MAX; pathset[i]=false;}

	dist[src]=0;
	for(int count =0;count<(v-1);count++){
		int u = mindist(pathset,dist,v);
		// we just add this vertex in pathset
		pathset[u]=true;
		for(int i=0;i<v;i++){
			if(!pathset[i] && arr[u][i]!=0 && dist[u]!=INT_MAX && dist[u]+arr[u][i]<dist[i])
				dist[i]=dist[u]+arr[u][i];
		}
	}
	for(int i=0;i<v;i++){
		cout<<i<<" "<<dist[i]<<endl;
	}

}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,v,e,v1,v2,a; cin>>t;
	while(t--){
		cin>>v;
		vector<vector<int>> arr;
		for(int i=0;i<v;i++){
			vector<int> vec;
			for(int j=0;j<v;j++){
				cin>>a;
				vec.push_back(a);
			}
			arr.push_back(vec);
		}
		dikastra(arr,v,0);
		cout<<endl;
	}
	return 0;
}

// adjciency list representation in decrease the complexity upto O(ElogV) using binary heap
// C / C++ program for Dijkstra's shortest path algorithm for adjacency 
// list representation of graph 

#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

// A structure to represent a node in adjacency list 
struct AdjListNode 
{ 
	int dest; 
	int weight; 
	struct AdjListNode* next; 
}; 

// A structure to represent an adjacency list 
struct AdjList 
{ 
	struct AdjListNode *head; // pointer to head node of list 
}; 

// A structure to represent a graph. A graph is an array of adjacency lists. 
// Size of array will be V (number of vertices in graph) 
struct Graph 
{ 
	int V; 
	struct AdjList* array; 
}; 

// A utility function to create a new adjacency list node 
struct AdjListNode* newAdjListNode(int dest, int weight) 
{ 
	struct AdjListNode* newNode = 
			(struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
	newNode->dest = dest; 
	newNode->weight = weight; 
	newNode->next = NULL; 
	return newNode; 
} 

// A utility function that creates a graph of V vertices 
struct Graph* createGraph(int V) 
{ 
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); 
	graph->V = V; 

	// Create an array of adjacency lists. Size of array will be V 
	graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList)); 

	// Initialize each adjacency list as empty by making head as NULL 
	for (int i = 0; i < V; ++i) 
		graph->array[i].head = NULL; 

	return graph; 
} 

// Adds an edge to an undirected graph 
void addEdge(struct Graph* graph, int src, int dest, int weight) 
{ 
	// Add an edge from src to dest. A new node is added to the adjacency 
	// list of src. The node is added at the beginning 
	struct AdjListNode* newNode = newAdjListNode(dest, weight); 
	newNode->next = graph->array[src].head; 
	graph->array[src].head = newNode; 

	// Since graph is undirected, add an edge from dest to src also 
	newNode = newAdjListNode(src, weight); 
	newNode->next = graph->array[dest].head; 
	graph->array[dest].head = newNode; 
} 

// Structure to represent a min heap node 
struct MinHeapNode 
{ 
	int v; 
	int dist; 
}; 

// Structure to represent a min heap 
struct MinHeap 
{ 
	int size;	 // Number of heap nodes present currently 
	int capacity; // Capacity of min heap 
	int *pos;	 // This is needed for decreaseKey() 
	struct MinHeapNode **array; 
}; 

// A utility function to create a new Min Heap Node 
struct MinHeapNode* newMinHeapNode(int v, int dist) 
{ 
	struct MinHeapNode* minHeapNode = 
		(struct MinHeapNode*) malloc(sizeof(struct MinHeapNode)); 
	minHeapNode->v = v; 
	minHeapNode->dist = dist; 
	return minHeapNode; 
} 

// A utility function to create a Min Heap 
struct MinHeap* createMinHeap(int capacity) 
{ 
	struct MinHeap* minHeap = 
		(struct MinHeap*) malloc(sizeof(struct MinHeap)); 
	minHeap->pos = (int *)malloc(capacity * sizeof(int)); 
	minHeap->size = 0; 
	minHeap->capacity = capacity; 
	minHeap->array = 
		(struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*)); 
	return minHeap; 
} 

// A utility function to swap two nodes of min heap. Needed for min heapify 
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) 
{ 
	struct MinHeapNode* t = *a; 
	*a = *b; 
	*b = t; 
} 

// A standard function to heapify at given idx 
// This function also updates position of nodes when they are swapped. 
// Position is needed for decreaseKey() 
void minHeapify(struct MinHeap* minHeap, int idx) 
{ 
	int smallest, left, right; 
	smallest = idx; 
	left = 2 * idx + 1; 
	right = 2 * idx + 2; 

	if (left < minHeap->size && 
		minHeap->array[left]->dist < minHeap->array[smallest]->dist ) 
	smallest = left; 

	if (right < minHeap->size && 
		minHeap->array[right]->dist < minHeap->array[smallest]->dist ) 
	smallest = right; 

	if (smallest != idx) 
	{ 
		// The nodes to be swapped in min heap 
		MinHeapNode *smallestNode = minHeap->array[smallest]; 
		MinHeapNode *idxNode = minHeap->array[idx]; 

		// Swap positions 
		minHeap->pos[smallestNode->v] = idx; 
		minHeap->pos[idxNode->v] = smallest; 

		// Swap nodes 
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 

		minHeapify(minHeap, smallest); 
	} 
} 

// A utility function to check if the given minHeap is ampty or not 
int isEmpty(struct MinHeap* minHeap) 
{ 
	return minHeap->size == 0; 
} 

// Standard function to extract minimum node from heap 
struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{ 
	if (isEmpty(minHeap)) 
		return NULL; 

	// Store the root node 
	struct MinHeapNode* root = minHeap->array[0]; 

	// Replace root node with last node 
	struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1]; 
	minHeap->array[0] = lastNode; 

	// Update position of last node 
	minHeap->pos[root->v] = minHeap->size-1; 
	minHeap->pos[lastNode->v] = 0; 

	// Reduce heap size and heapify root 
	--minHeap->size; 
	minHeapify(minHeap, 0); 

	return root; 
} 

// Function to decreasy dist value of a given vertex v. This function 
// uses pos[] of min heap to get the current index of node in min heap 
void decreaseKey(struct MinHeap* minHeap, int v, int dist) 
{ 
	// Get the index of v in heap array 
	int i = minHeap->pos[v]; 

	// Get the node and update its dist value 
	minHeap->array[i]->dist = dist; 

	// Travel up while the complete tree is not hepified. 
	// This is a O(Logn) loop 
	while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) 
	{ 
		// Swap this node with its parent 
		minHeap->pos[minHeap->array[i]->v] = (i-1)/2; 
		minHeap->pos[minHeap->array[(i-1)/2]->v] = i; 
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]); 

		// move to parent index 
		i = (i - 1) / 2; 
	} 
} 

// A utility function to check if a given vertex 
// 'v' is in min heap or not 
bool isInMinHeap(struct MinHeap *minHeap, int v) 
{ 
if (minHeap->pos[v] < minHeap->size) 
	return true; 
return false; 
} 

// A utility function used to print the solution 
void printArr(int dist[], int n) 
{ 
	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < n; ++i) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

// The main function that calulates distances of shortest paths from src to all 
// vertices. It is a O(ELogV) function 
void dijkstra(struct Graph* graph, int src) 
{ 
	int V = graph->V;// Get the number of vertices in graph 
	int dist[V];	 // dist values used to pick minimum weight edge in cut 

	// minHeap represents set E 
	struct MinHeap* minHeap = createMinHeap(V); 

	// Initialize min heap with all vertices. dist value of all vertices 
	for (int v = 0; v < V; ++v) 
	{ 
		dist[v] = INT_MAX; 
		minHeap->array[v] = newMinHeapNode(v, dist[v]); 
		minHeap->pos[v] = v; 
	} 

	// Make dist value of src vertex as 0 so that it is extracted first 
	minHeap->array[src] = newMinHeapNode(src, dist[src]); 
	minHeap->pos[src] = src; 
	dist[src] = 0; 
	decreaseKey(minHeap, src, dist[src]); 

	// Initially size of min heap is equal to V 
	minHeap->size = V; 

	// In the followin loop, min heap contains all nodes 
	// whose shortest distance is not yet finalized. 
	while (!isEmpty(minHeap)) 
	{ 
		// Extract the vertex with minimum distance value 
		struct MinHeapNode* minHeapNode = extractMin(minHeap); 
		int u = minHeapNode->v; // Store the extracted vertex number 

		// Traverse through all adjacent vertices of u (the extracted 
		// vertex) and update their distance values 
		struct AdjListNode* pCrawl = graph->array[u].head; 
		while (pCrawl != NULL) 
		{ 
			int v = pCrawl->dest; 

			// If shortest distance to v is not finalized yet, and distance to v 
			// through u is less than its previously calculated distance 
			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && 
										pCrawl->weight + dist[u] < dist[v]) 
			{ 
				dist[v] = dist[u] + pCrawl->weight; 

				// update distance value in min heap also 
				decreaseKey(minHeap, v, dist[v]); 
			} 
			pCrawl = pCrawl->next; 
		} 
	} 

	// print the calculated shortest distances 
	printArr(dist, V); 
} 


// Driver program to test above functions 
int main() 
{ 
	// create the graph given in above fugure 
	int V = 9; 
	struct Graph* graph = createGraph(V); 
	addEdge(graph, 0, 1, 4); 
	addEdge(graph, 0, 7, 8); 
	addEdge(graph, 1, 2, 8); 
	addEdge(graph, 1, 7, 11); 
	addEdge(graph, 2, 3, 7); 
	addEdge(graph, 2, 8, 2); 
	addEdge(graph, 2, 5, 4); 
	addEdge(graph, 3, 4, 9); 
	addEdge(graph, 3, 5, 14); 
	addEdge(graph, 4, 5, 10); 
	addEdge(graph, 5, 6, 2); 
	addEdge(graph, 6, 7, 1); 
	addEdge(graph, 6, 8, 6); 
	addEdge(graph, 7, 8, 7); 

	dijkstra(graph, 0); 

	return 0; 
} 

3. bellman ford
// dikastra can't find the shortest path when -ve number is present 
// so we use the bellmonford algo here to find shortest distance when -ve no is present
// bellmon ford algo is dp wherease dikartra is  greddy algo
// But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra.

// A C++ program for Bellman-Ford's single source 
// shortest path algorithm. 
#include <bits/stdc++.h> 

// a structure to represent a weighted edge in graph 
struct Edge { 
	int src, dest, weight; 
}; 

// a structure to represent a connected, directed and 
// weighted graph 
struct Graph { 
	// V-> Number of vertices, E-> Number of edges 
	int V, E; 

	// graph is represented as an array of edges. 
	struct Edge* edge; 
}; 

// Creates a graph with V vertices and E edges 
struct Graph* createGraph(int V, int E) 
{ 
	struct Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 
	graph->edge = new Edge[E]; 
	return graph; 
} 

// A utility function used to print the solution 
void printArr(int dist[], int n) 
{ 
	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < n; ++i) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

// The main function that finds shortest distances from src to 
// all other vertices using Bellman-Ford algorithm. The function 
// also detects negative weight cycle 
void BellmanFord(struct Graph* graph, int src) 
{ 
	int V = graph->V; 
	int E = graph->E; 
	int dist[V]; 

	// Step 1: Initialize distances from src to all other vertices 
	// as INFINITE 
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX; 
	dist[src] = 0; 

	// Step 2: Relax all edges |V| - 1 times. A simple shortest 
	// path from src to any other vertex can have at-most |V| - 1 
	// edges 
	for (int i = 1; i <= V - 1; i++) { 
		for (int j = 0; j < E; j++) { 
			int u = graph->edge[j].src; 
			int v = graph->edge[j].dest; 
			int weight = graph->edge[j].weight; 
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
				dist[v] = dist[u] + weight; 
		} 
	} 

	// Step 3: check for negative-weight cycles. The above step 
	// guarantees shortest distances if graph doesn't contain 
	// negative weight cycle. If we get a shorter path, then there 
	// is a cycle. 
	for (int i = 0; i < E; i++) { 
		int u = graph->edge[i].src; 
		int v = graph->edge[i].dest; 
		int weight = graph->edge[i].weight; 
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { 
			printf("Graph contains negative weight cycle"); 
			return; // If negative cycle is detected, simply return 
		} 
	} 

	printArr(dist, V); 

	return; 
} 

// Driver program to test above functions 
int main() 
{ 
	/* Let us create the graph given in above example */
	int V = 5; // Number of vertices in graph 
	int E = 8; // Number of edges in graph 
	struct Graph* graph = createGraph(V, E); 

	// add edge 0-1 (or A-B in above figure) 
	graph->edge[0].src = 0; 
	graph->edge[0].dest = 1; 
	graph->edge[0].weight = -1; 

	// add edge 0-2 (or A-C in above figure) 
	graph->edge[1].src = 0; 
	graph->edge[1].dest = 2; 
	graph->edge[1].weight = 4; 

	// add edge 1-2 (or B-C in above figure) 
	graph->edge[2].src = 1; 
	graph->edge[2].dest = 2; 
	graph->edge[2].weight = 3; 

	// add edge 1-3 (or B-D in above figure) 
	graph->edge[3].src = 1; 
	graph->edge[3].dest = 3; 
	graph->edge[3].weight = 2; 

	// add edge 1-4 (or A-E in above figure) 
	graph->edge[4].src = 1; 
	graph->edge[4].dest = 4; 
	graph->edge[4].weight = 2; 

	// add edge 3-2 (or D-C in above figure) 
	graph->edge[5].src = 3; 
	graph->edge[5].dest = 2; 
	graph->edge[5].weight = 5; 

	// add edge 3-1 (or D-B in above figure) 
	graph->edge[6].src = 3; 
	graph->edge[6].dest = 1; 
	graph->edge[6].weight = 1; 

	// add edge 4-3 (or E-D in above figure) 
	graph->edge[7].src = 4; 
	graph->edge[7].dest = 3; 
	graph->edge[7].weight = -3; 

	BellmanFord(graph, 0); 

	return 0; 
} 


4. kruskal
// C++ program for Kruskal's algorithm to find Minimum Spanning Tree 
// of a given connected, undirected and weighted graph 
#include <bits/stdc++.h> 
using namespace std; 

// a structure to represent a weighted edge in graph 
class Edge 
{ 
	public: 
	int src, dest, weight; 
}; 

// a structure to represent a connected, undirected 
// and weighted graph 
class Graph 
{ 
	public: 
	// V-> Number of vertices, E-> Number of edges 
	int V, E; 

	// graph is represented as an array of edges. 
	// Since the graph is undirected, the edge 
	// from src to dest is also edge from dest 
	// to src. Both are counted as 1 edge here. 
	Edge* edge; 
}; 

// Creates a graph with V vertices and E edges 
Graph* createGraph(int V, int E) 
{ 
	Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 

	graph->edge = new Edge[E]; 

	return graph; 
} 

// A structure to represent a subset for union-find 
class subset 
{ 
	public: 
	int parent; 
	int rank; 
}; 

// A utility function to find set of an element i 
// (uses path compression technique) 
int find(subset subsets[], int i) 
{ 
	// find root and make root as parent of i 
	// (path compression) 
	if (subsets[i].parent != i) 
		subsets[i].parent = find(subsets, subsets[i].parent); 

	return subsets[i].parent; 
} 

// A function that does union of two sets of x and y 
// (uses union by rank) 
void Union(subset subsets[], int x, int y) 
{ 
	int xroot = find(subsets, x); 
	int yroot = find(subsets, y); 

	// Attach smaller rank tree under root of high 
	// rank tree (Union by Rank) 
	if (subsets[xroot].rank < subsets[yroot].rank) 
		subsets[xroot].parent = yroot; 
	else if (subsets[xroot].rank > subsets[yroot].rank) 
		subsets[yroot].parent = xroot; 

	// If ranks are same, then make one as root and 
	// increment its rank by one 
	else
	{ 
		subsets[yroot].parent = xroot; 
		subsets[xroot].rank++; 
	} 
} 

// Compare two edges according to their weights. 
// Used in qsort() for sorting an array of edges 
int myComp(const void* a, const void* b) 
{ 
	Edge* a1 = (Edge*)a; 
	Edge* b1 = (Edge*)b; 
	return a1->weight > b1->weight; 
} 

// The main function to construct MST using Kruskal's algorithm 
void KruskalMST(Graph* graph) 
{ 
	int V = graph->V; 
	Edge result[V]; // Tnis will store the resultant MST 
	int e = 0; // An index variable, used for result[] 
	int i = 0; // An index variable, used for sorted edges 

	// Step 1: Sort all the edges in non-decreasing 
	// order of their weight. If we are not allowed to 
	// change the given graph, we can create a copy of 
	// array of edges 
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); 

	// Allocate memory for creating V ssubsets 
	subset *subsets = new subset[( V * sizeof(subset) )]; 

	// Create V subsets with single elements 
	for (int v = 0; v < V; ++v) 
	{ 
		subsets[v].parent = v; 
		subsets[v].rank = 0; 
	} 

	// Number of edges to be taken is equal to V-1 
	while (e < V - 1 && i < graph->E) 
	{ 
		// Step 2: Pick the smallest edge. And increment 
		// the index for next iteration 
		Edge next_edge = graph->edge[i++]; 

		int x = find(subsets, next_edge.src); 
		int y = find(subsets, next_edge.dest); 

		// If including this edge does't cause cycle, 
		// include it in result and increment the index 
		// of result for next edge 
		if (x != y) 
		{ 
			result[e++] = next_edge; 
			Union(subsets, x, y); 
		} 
		// Else discard the next_edge 
	} 

	// print the contents of result[] to display the 
	// built MST 
	cout<<"Following are the edges in the constructed MST\n"; 
	for (i = 0; i < e; ++i) 
		cout<<result[i].src<<" -- "<<result[i].dest<<" == "<<result[i].weight<<endl; 
	return; 
} 

// Driver code 
int main() 
{ 
	/* Let us create following weighted graph 
			10 
		0--------1 
		| \ | 
	6| 5\ |15 
		| \ | 
		2--------3 
			4 */
	int V = 4; // Number of vertices in graph 
	int E = 5; // Number of edges in graph 
	Graph* graph = createGraph(V, E); 


	// add edge 0-1 
	graph->edge[0].src = 0; 
	graph->edge[0].dest = 1; 
	graph->edge[0].weight = 10; 

	// add edge 0-2 
	graph->edge[1].src = 0; 
	graph->edge[1].dest = 2; 
	graph->edge[1].weight = 6; 

	// add edge 0-3 
	graph->edge[2].src = 0; 
	graph->edge[2].dest = 3; 
	graph->edge[2].weight = 5; 

	// add edge 1-3 
	graph->edge[3].src = 1; 
	graph->edge[3].dest = 3; 
	graph->edge[3].weight = 15; 

	// add edge 2-3 
	graph->edge[4].src = 2; 
	graph->edge[4].dest = 3; 
	graph->edge[4].weight = 4; 

	KruskalMST(graph); 

	return 0; 
} 

// This code is contributed by rathbhupendra 
// C++ program for Kruskal's algorithm to find Minimum 
// Spanning Tree of a given connected, undirected and 
// weighted graph 
#include<bits/stdc++.h> 
using namespace std; 

// Creating shortcut for an integer pair 
typedef pair<int, int> iPair; 

// Structure to represent a graph 
struct Graph 
{ 
	int V, E; 
	vector< pair<int, iPair> > edges; 

	// Constructor 
	Graph(int V, int E) 
	{ 
		this->V = V; 
		this->E = E; 
	} 

	// Utility function to add an edge 
	void addEdge(int u, int v, int w) 
	{ 
		edges.push_back({w, {u, v}}); 
	} 

	// Function to find MST using Kruskal's 
	// MST algorithm 
	int kruskalMST(); 
}; 

// To represent Disjoint Sets 
struct DisjointSets 
{ 
	int *parent, *rnk; 
	int n; 

	// Constructor. 
	DisjointSets(int n) 
	{ 
		// Allocate memory 
		this->n = n; 
		parent = new int[n+1]; 
		rnk = new int[n+1]; 

		// Initially, all vertices are in 
		// different sets and have rank 0. 
		for (int i = 0; i <= n; i++) 
		{ 
			rnk[i] = 0; 

			//every element is parent of itself 
			parent[i] = i; 
		} 
	} 

	// Find the parent of a node 'u' 
	// Path Compression 
	int find(int u) 
	{ 
		/* Make the parent of the nodes in the path 
		from u--> parent[u] point to parent[u] */
		if (u != parent[u]) 
			parent[u] = find(parent[u]); 
		return parent[u]; 
	} 

	// Union by rank 
	void merge(int x, int y) 
	{ 
		x = find(x), y = find(y); 

		/* Make tree with smaller height 
		a subtree of the other tree */
		if (rnk[x] > rnk[y]) 
			parent[y] = x; 
		else // If rnk[x] <= rnk[y] 
			parent[x] = y; 

		if (rnk[x] == rnk[y]) 
			rnk[y]++; 
	} 
}; 

/* Functions returns weight of the MST*/

int Graph::kruskalMST() 
{ 
	int mst_wt = 0; // Initialize result 

	// Sort edges in increasing order on basis of cost 
	sort(edges.begin(), edges.end()); 

	// Create disjoint sets 
	DisjointSets ds(V); 

	// Iterate through all sorted edges 
	vector< pair<int, iPair> >::iterator it; 
	for (it=edges.begin(); it!=edges.end(); it++) 
	{ 
		int u = it->second.first; 
		int v = it->second.second; 

		int set_u = ds.find(u); 
		int set_v = ds.find(v); 

		// Check if the selected edge is creating 
		// a cycle or not (Cycle is created if u 
		// and v belong to same set) 
		if (set_u != set_v) 
		{ 
			// Current edge will be in the MST 
			// so print it 
			cout << u << " - " << v << endl; 

			// Update MST weight 
			mst_wt += it->first; 

			// Merge two sets 
			ds.merge(set_u, set_v); 
		} 
	} 

	return mst_wt; 
} 

// Driver program to test above functions 
int main() 
{ 
	/* Let us create above shown weighted 
	and unidrected graph */
	int V = 9, E = 14; 
	Graph g(V, E); 

	// making above shown graph 
	g.addEdge(0, 1, 4); 
	g.addEdge(0, 7, 8); 
	g.addEdge(1, 2, 8); 
	g.addEdge(1, 7, 11); 
	g.addEdge(2, 3, 7); 
	g.addEdge(2, 8, 2); 
	g.addEdge(2, 5, 4); 
	g.addEdge(3, 4, 9); 
	g.addEdge(3, 5, 14); 
	g.addEdge(4, 5, 10); 
	g.addEdge(5, 6, 2); 
	g.addEdge(6, 7, 1); 
	g.addEdge(6, 8, 6); 
	g.addEdge(7, 8, 7); 

	cout << "Edges of MST are \n"; 
	int mst_wt = g.kruskalMST(); 

	cout << "\nWeight of MST is " << mst_wt; 

	return 0; 
} 



5. prims
// A C++ program for Prim's Minimum 
// Spanning Tree (MST) algorithm. The program is 
// for adjacency matrix representation of the graph 
#include <bits/stdc++.h> 
using namespace std; 

// Number of vertices in the graph 
#define V 5 

// A utility function to find the vertex with 
// minimum key value, from the set of vertices 
// not yet included in MST 
int minKey(int key[], bool mstSet[]) 
{ 
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (mstSet[v] == false && key[v] < min) 
			min = key[v], min_index = v; 

	return min_index; 
} 

// A utility function to print the 
// constructed MST stored in parent[] 
void printMST(int parent[], int graph[V][V]) 
{ 
	cout<<"Edge \tWeight\n"; 
	for (int i = 1; i < V; i++) 
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 

// Function to construct and print MST for 
// a graph represented using adjacency 
// matrix representation 
void primMST(int graph[V][V]) 
{ 
	// Array to store constructed MST 
	int parent[V]; 
	
	// Key values used to pick minimum weight edge in cut 
	int key[V]; 
	
	// To represent set of vertices included in MST 
	bool mstSet[V]; 

	// Initialize all keys as INFINITE 
	for (int i = 0; i < V; i++) 
		key[i] = INT_MAX, mstSet[i] = false; 

	// Always include first 1st vertex in MST. 
	// Make key 0 so that this vertex is picked as first vertex. 
	key[0] = 0; 
	parent[0] = -1; // First node is always root of MST 

	// The MST will have V vertices 
	for (int count = 0; count < V - 1; count++) 
	{ 
		// Pick the minimum key vertex from the 
		// set of vertices not yet included in MST 
		int u = minKey(key, mstSet); 

		// Add the picked vertex to the MST Set 
		mstSet[u] = true; 

		// Update key value and parent index of 
		// the adjacent vertices of the picked vertex. 
		// Consider only those vertices which are not 
		// yet included in MST 
		for (int v = 0; v < V; v++) 

			// graph[u][v] is non zero only for adjacent vertices of m 
			// mstSet[v] is false for vertices not yet included in MST 
			// Update the key only if graph[u][v] is smaller than key[v] 
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	} 

	// print the constructed MST 
	printMST(parent, graph); 
} 

// Driver code 
int main() 
{ 
	/* Let us create the following graph 
		2 3 
	(0)--(1)--(2) 
	| / \ | 
	6| 8/ \5 |7 
	| / \ | 
	(3)-------(4) 
			9	 */
	int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
						{ 2, 0, 3, 8, 5 }, 
						{ 0, 3, 0, 0, 7 }, 
						{ 6, 8, 0, 0, 9 }, 
						{ 0, 5, 7, 9, 0 } }; 

	// Print the solution 
	primMST(graph); 

	return 0; 
} 

// This code is contributed by rathbhupendra 


6. scc
#include <bits/stdc++.h>
using namespace std;

void dfsUtil1(vector<list<int>> &adj,int v,int i,vector<bool> &visited,stack<int> &stk){
	visited[i]=true;
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]) dfsUtil1(adj,v,*it,visited,stk);
	}
	stk.push(i);
}
void dfsUtil2(vector<list<int>> &adj,int v,int i,vector<bool> &visited){
	visited[i]=true;
	cout<<i<<" ";
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]) dfsUtil2(adj,v,*it,visited);
	}
}
void transposegraph(vector<list<int>> &transgrp,vector<list<int>> &adj,int v) {
	for(int i=0;i<v;i++){
		// cout<<"kdd";
		for(auto it = adj[i].begin();it!=adj[i].end();it++){
			transgrp[*it].push_back(i);
			// cout<<(*it)<<" "<<i<<endl;
		}
	}
}

void scc(vector<list<int>> &adj,int v){
	vector<bool> visited(v,false);
	stack<int> stk;
	for(int i=0;i<v;i++){
		if(!visited[i]) dfsUtil1(adj,v,i,visited,stk);
	}
	vector<list<int>> transgrp(v);
	transposegraph(transgrp,adj,v);
	for(int i=0;i<v;i++) visited[i]=false;
	while(!stk.empty()){
		int u = stk.top();
		// cout<<u<<endl;
		stk.pop();
		if(!visited[u])
			dfsUtil2(transgrp,v,u,visited);
		cout<<endl;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,v,e,v1,v2; cin>>t;
	while(t--){
		cin>>v>>e;
		vector<list<int>> adj(v); 
		for(int i=0;i<e;i++){
			cin>>v1>>v2;
			adj[v1].push_back(v2);
			// adj[v2].push_back(v1);
		}
		scc(adj,v);
		cout<<endl;
	}
	return 0;
}

Day 25(DP)
1. edit distance
#include <bits/stdc++.h>
using namespace std;


int editdistance(string str1,string str2,int n,int m){
	if(n==0) return m;
	if(m==0) return n;
	if(str1[n-1]==str2[m-1]) return editdistance(str1,str2,n-1,m-1);
	return 1+min(min(editdistance(str1,str2,n-1,m),editdistance(str1,str2,n,m-1)),editdistance(str1,str2,n-1,m-1));
}
int editdistance(string str1,string str2,int n,int m){
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0) dp[i][j]=j;
			else if(j==0) dp[i][j]=i;
			else if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
		}
	}
	return dp[n][m];
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
		string str1,str2;
		cin>>str1>>str2;
		int n = str1.size();
		int m = str2.size();
		cout<<editdistance(str1,str2,n,m)<<endl;
	}
	return 0;
}

2. 0-1 knapsack
/* A Naive recursive implementation of 
0-1 Knapsack problem */
#include <bits/stdc++.h> 
using namespace std; 

// A utility function that returns 
// maximum of two integers 
int max(int a, int b) { return (a > b) ? a : b; } 

// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 

	// Base Case 
	if (n == 0 || W == 0) 
		return 0; 

	// If weight of the nth item is more 
	// than Knapsack capacity W, then 
	// this item cannot be included 
	// in the optimal solution 
	if (wt[n - 1] > W) 
		return knapSack(W, wt, val, n - 1); 

	// Return the maximum of two cases: 
	// (1) nth item included 
	// (2) not included 
	else
		return max( 
			val[n - 1] + knapSack(W - wt[n - 1], 
									wt, val, n - 1), 
			knapSack(W, wt, val, n - 1)); 
} 

// Driver code 
int main() 
{ 
	int val[] = { 60, 100, 120 }; 
	int wt[] = { 10, 20, 30 }; 
	int W = 50; 
	int n = sizeof(val) / sizeof(val[0]); 
	cout << knapSack(W, wt, val, n); 
	return 0; 
} 

// This code is contributed by rathbhupendra 
// A Dynamic Programming based 
// solution for 0-1 Knapsack problem 
#include <stdio.h> 

// A utility function that returns 
// maximum of two integers 
int max(int a, int b) 
{ 
	return (a > b) ? a : b; 
} 

// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
	int i, w; 
	int K[n + 1][W + 1]; 

	// Build table K[][] in bottom up manner 
	for (i = 0; i <= n; i++) { 
		for (w = 0; w <= W; w++) { 
			if (i == 0 || w == 0) 
				K[i][w] = 0; 
			else if (wt[i - 1] <= w) 
				K[i][w] = max( 
					val[i - 1] + K[i - 1][w - wt[i - 1]], 
					K[i - 1][w]); 
			else
				K[i][w] = K[i - 1][w]; 
		} 
	} 

	return K[n][W]; 
} 

int main() 
{ 
	int val[] = { 60, 100, 120 }; 
	int wt[] = { 10, 20, 30 }; 
	int W = 50; 
	int n = sizeof(val) / sizeof(val[0]); 
	printf("%d", knapSack(W, wt, val, n)); 
	return 0; 
} 


3. max common sequence
#include <bits/stdc++.h>
using namespace std;
// this is same as kadane'algo but different in when 2 -ve value are come the product is +ve

// int maxcommonsequence(string str1,string str2,int n,int m){
// 	if(n<=0 || m<=0) return 0;

// 	if(str1[n-1] == str2[m-1]) return 1+maxcommonsequence(str1,str2,n-1,m-1);
// 	return max(maxcommonsequence(str1,str2,n-1,m),maxcommonsequence(str1,str2,n,m-1));
// }

// using dp
int maxcommonsequence(string str1,string str2,int n,int m){
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0) dp[i][j]=0;
			else if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];
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
		string str1,str2;
		cin>>str1>>str2;
		int n = str1.size();
		int m = str2.size();
		cout<<maxcommonsequence(str1,str2,n,m)<<endl;
	}
	return 0;
}

4. max incresing sequecnce
#include <bits/stdc++.h>
using namespace std;
// this is same as kadane'algo but different in when 2 -ve value are come the product is +ve

int maxincresingsequence(vector<int> &arr,int n){
    int lis[n]={0};
    lis[0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    sort(lis,lis+n);
    return lis[n-1];
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
		cout<<maxincresingsequence(arr,n)<<endl;
	}
	return 0;
}

6. max product subarray
#include <bits/stdc++.h>
using namespace std;
// this is same as kadane'algo but different in when 2 -ve value are come the product is +ve

int maxproductsum(vector<int> &arr,int n){
	int maxval=1,minval=1;
	int finalmax=1,flag=0;
	for(int i=0;i<n;i++){
		// normal add
		if(arr[i]>0){
			maxval *= arr[i];
			minval = min(minval*arr[i],1);
			flag=1;
		}else if(arr[i]==0){
			maxval=1;
			minval=1;
		}else{
			int temp = maxval;
			maxval = max(minval*arr[i],1);
			minval=temp*arr[i];
		}
		finalmax = max(finalmax,maxval);
	}
	if(flag==0&&maxval==1) return 0;
	return finalmax;
}

//Method 2
int max_product(int arr[], int n) 
{ 
    // Initialize maximum products in forward and 
    // backward directions 
    int max_fwd = INT_MIN, max_bkd = INT_MIN; 
  
    // Initialize current product 
    int max_till_now = 1; 
  
    //check if zero is present in an array or not 
    bool isZero=false; 
      
    // max_fwd for maximum contiguous product in 
    // forward direction 
    // max_bkd for maximum contiguous product in 
    // backward direction 
    // iterating within forward direction in array 
    for (int i=0; i<n; i++) 
    { 
        // if arr[i]==0, it is breaking condition 
        // for contiguous subarray 
        max_till_now = max_till_now*arr[i]; 
        if (max_till_now == 0) 
        {    
             isZero=true; 
             max_till_now = 1; 
            continue; 
        } 
        if (max_fwd < max_till_now) // update max_fwd 
            max_fwd = max_till_now; 
    } 
  
     max_till_now = 1; 
  
    // iterating within backward direction in array 
    for (int i=n-1; i>=0; i--) 
    { 
        max_till_now = max_till_now * arr[i]; 
        if (max_till_now == 0) 
        { 
            isZero=true; 
            max_till_now = 1; 
            continue; 
        } 
  
        // update max_bkd 
        if (max_bkd < max_till_now) 
            max_bkd = max_till_now; 
    } 
  
    // return max of max_fwd and max_bkd 
    int res =  max(max_fwd, max_bkd); 
  
    // Product should not be nagative. 
    // (Product of an empty subarray is 
    // considered as 0) 
    if(isZero) 
    return max(res, 0); 
  
    return res; 
} 
  
 // Method 3
int maxProduct(int* arr, int n) 
{ 
    // Variables to store maximum and minimum 
    // product till ith index. 
    int minVal = arr[0]; 
    int maxVal = arr[0]; 
  
    int maxProduct = arr[0]; 
  
    for (int i = 1; i < n; i++) { 
  
        // When multiplied by -ve number, 
        // maxVal becomes minVal 
        // and minVal becomes maxVal. 
        if (arr[i] < 0) 
            swap(maxVal, minVal); 
  
        // maxVal and minVal stores the 
        // product of subarray ending at arr[i]. 
        maxVal = max(arr[i], maxVal * arr[i]); 
        minVal = min(arr[i], minVal * arr[i]); 
  
        // Max Product of array. 
        maxProduct = max(maxProduct, maxVal); 
    } 
  
    // Return maximum product found in array. 
    return maxProduct; 
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
		cout<<maxproductsum(arr,n)<<endl;
	}
	return 0;
}

7. max incresing sum sequemce
#include <bits/stdc++.h>
using namespace std;
// this is same as kadane'algo but different in when 2 -ve value are come the product is +ve

int maxincresingsequence(vector<int> &arr,int n){
    int lis[n]={0};
    // lis[0]=1;
    for(int i=0;i<n;i++){
    	lis[i]=arr[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && lis[i]<lis[j]+arr[i])
                lis[i]=lis[j]+arr[i];
        }
    }
    sort(lis,lis+n);
    return lis[n-1];
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
		cout<<maxincresingsequence(arr,n)<<endl;
	}
	return 0;
}

6. mcm
#include <bits/stdc++.h>
using namespace std;


// same have 0 value of multipication
int mcm(vector<int> &arr,int i,int j){
    if(i == j) return 0;
    int count,minval = INT_MAX;
    for(int k = i;k<j;k++){
    	count = mcm(arr,i,k)+mcm(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]); 
    	minval  = min(minval,count);
    }
    return minval;
}
int MatrixChainOrder(int p[], int n) 
{ 
  
    /* For simplicity of the program, one  
    extra row and one extra column are  
    allocated in m[][]. 0th row and 0th 
    column of m[][] are not used */
    int m[n][n]; 
  
    int i, j, k, L, q; 
  
    /* m[i,j] = Minimum number of scalar  
    multiplications needed to compute the 
    matrix A[i]A[i+1]...A[j] = A[i..j] where 
    dimension of A[i] is p[i-1] x p[i] */
  
    // cost is zero when multiplying 
    // one matrix. 
    for (i = 1; i < n; i++) 
        m[i][i] = 0; 
  
    // L is chain length. 
    for (L = 2; L < n; L++) 
    { 
        for (i = 1; i < n - L + 1; i++) 
        { 
            j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) 
            { 
                // q = cost/scalar multiplications 
                q = m[i][k] + m[k + 1][j] +  
                    p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n - 1]; 
} 

int mcm(vector<int> &arr,int i,int j){
    if(i == j) return 0;
    int count,minval = INT_MAX;
    for(int k = i;k<j;k++){
    	count = mcm(arr,i,k)+mcm(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]); 
    	minval  = min(minval,count);
    }
    return minval;
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
		cout<<mcm(arr,1,n-1)<<endl;
	}
	return 0;
}

Day 26:(DP)
1.cut rod
// A Naive recursive solution for Rod cutting problem 
#include<stdio.h> 
#include<limits.h> 

// A utility function to get the maximum of two integers 
int max(int a, int b) { return (a > b)? a : b;} 

/* Returns the best obtainable price for a rod of length n and 
price[] as prices of different pieces */
int cutRod(int price[], int n) 
{ 
if (n <= 0) 
	return 0; 
int max_val = INT_MIN; 

// Recursively cut the rod in different pieces and compare different 
// configurations 
for (int i = 0; i<n; i++) 
		max_val = max(max_val, price[i] + cutRod(price, n-i-1)); 

return max_val; 
} 

// Method 2
int cutRod(int price[], int n) 
{ 
   int val[n+1]; 
   val[0] = 0; 
   int i, j; 
  
   // Build the table val[] in bottom up manner and return the last entry 
   // from the table 
   for (i = 1; i<=n; i++) 
   { 
       int max_val = INT_MIN; 
       for (j = 0; j < i; j++) 
         max_val = max(max_val, price[j] + val[i-j-1]); 
       val[i] = max_val; 
   } 
  
   return val[n]; 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
	int size = sizeof(arr)/sizeof(arr[0]); 
	printf("Maximum Obtainable Value is %dn", cutRod(arr, size)); 
	getchar(); 
	return 0; 
} 


2. egg problem
#include <bits/stdc++.h> 
using namespace std; 

// A utility function to get 
// maximum of two integers 
int max(int a, int b) 
{ 
	return (a > b) ? a : b; 
} 

// Function to get minimum 
// number of trials needed in worst 
// case with n eggs and k floors 
int eggDrop(int n, int k) 
{ 
	// If there are no floors, 
	// then no trials needed. 
	// OR if there is one floor, 
	// one trial needed. 
	if (k == 1 || k == 0) 
		return k; 

	// We need k trials for one 
	// egg and k floors 
	if (n == 1) 
		return k; 

	int min = INT_MAX, x, res; 

	// Consider all droppings from 
	// 1st floor to kth floor and 
	// return the minimum of these 
	// values plus 1. 
	for (x = 1; x <= k; x++) { 
		res = max( 
			eggDrop(n - 1, x - 1), 
			eggDrop(n, k - x)); 
		if (res < min) 
			min = res; 
	} 

	return min + 1; 
} 

// Method 2
int eggDrop(int n, int k) 
{ 
    /* A 2D table where entery  
    eggFloor[i][j] will represent  
    minimum number of trials needed for 
    i eggs and j floors. */
    int eggFloor[n + 1][k + 1]; 
    int res; 
    int i, j, x; 
  
    // We need one trial for one floor and 0 
    // trials for 0 floors 
    for (i = 1; i <= n; i++) { 
        eggFloor[i][1] = 1; 
        eggFloor[i][0] = 0; 
    } 
  
    // We always need j trials for one egg 
    // and j floors. 
    for (j = 1; j <= k; j++) 
        eggFloor[1][j] = j; 
  
    // Fill rest of the entries in table using 
    // optimal substructure property 
    for (i = 2; i <= n; i++) { 
        for (j = 2; j <= k; j++) { 
            eggFloor[i][j] = INT_MAX; 
            for (x = 1; x <= j; x++) { 
                res = 1 + max( 
                              eggFloor[i - 1][x - 1], 
                              eggFloor[i][j - x]); 
                if (res < eggFloor[i][j]) 
                    eggFloor[i][j] = res; 
            } 
        } 
    } 
  
    // eggFloor[n][k] holds the result 
    return eggFloor[n][k]; 
} 
// Driver program to test 
// to pront printDups 
int main() 
{ 
	int n = 2, k = 10; 
	cout << "Minimum number of trials "
			"in worst case with "
		<< n << " eggs and " << k 
		<< " floors is "
		<< eggDrop(n, k) << endl; 
	return 0; 
} 

// This code is contributed 
// by Akanksha Rai 

// efficient method
// C++ program to find minimum 
// number of trials in worst case. 
#include <bits/stdc++.h> 

using namespace std; 

// Find sum of binomial coefficients xCi 
// (where i varies from 1 to n). 
int binomialCoeff(int x, int n) 
{ 
	int sum = 0, term = 1; 
	for (int i = 1; i <= n; ++i) { 
		term *= x - i + 1; 
		term /= i; 
		sum += term; 
	} 
	return sum; 
} 

// Do binary search to find minimum 
// number of trials in worst case. 
int minTrials(int n, int k) 
{ 
	// Initialize low and high as 1st 
	// and last floors 
	int low = 1, high = k; 

	// Do binary search, for every mid, 
	// find sum of binomial coefficients and 
	// check if the sum is greater than k or not. 
	while (low < high) { 
		int mid = (low + high) / 2; 
		if (binomialCoeff(mid, n) < k) 
			low = mid + 1; 
		else
			high = mid; 
	} 

	return low; 
} 

/* Driver program to test above function*/
int main() 
{ 
	cout << minTrials(2, 10); 
	return 0; 
} 


3. coin change
// Recursive C program for 
// coin change problem. 
#include<stdio.h> 

// Returns the count of ways we can 
// sum S[0...m-1] coins to get sum n 
int count( int S[], int m, int n ) 
{ 
	// If n is 0 then there is 1 solution 
	// (do not include any coin) 
	if (n == 0) 
		return 1; 
	
	// If n is less than 0 then no 
	// solution exists 
	if (n < 0) 
		return 0; 

	// If there are no coins and n 
	// is greater than 0, then no 
	// solution exist 
	if (m <=0 && n >= 1) 
		return 0; 

	// count is sum of solutions (i) 
	// including S[m-1] (ii) excluding S[m-1] 
	return count( S, m - 1, n ) + count( S, m, n-S[m-1] ); 
} 

// Method 2
int count( int S[], int m, int n ) 
{ 
    int i, j, x, y; 
  
    // We need n+1 rows as the table  
    // is constructed in bottom up 
    // manner using the base case 0 
    // value case (n = 0) 
    int table[n + 1][m]; 
      
    // Fill the enteries for 0 
    // value case (n = 0) 
    for (i = 0; i < m; i++) 
        table[0][i] = 1; 
  
    // Fill rest of the table entries  
    // in bottom up manner  
    for (i = 1; i < n + 1; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            // Count of solutions including S[j] 
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 
  
            // Count of solutions excluding S[j] 
            y = (j >= 1) ? table[i][j - 1] : 0; 
  
            // total count 
            table[i][j] = x + y; 
        } 
    } 
    return table[n][m - 1]; 
} 

// Method 3
int count( int S[], int m, int n ) 
{ 
    // table[i] will be storing the number of solutions for 
    // value i. We need n+1 rows as the table is constructed 
    // in bottom up manner using the base case (n = 0) 
    int table[n+1]; 
  
    // Initialize all table values as 0 
    memset(table, 0, sizeof(table)); 
  
    // Base case (If given value is 0) 
    table[0] = 1; 
  
    // Pick all coins one by one and update the table[] values 
    // after the index greater than or equal to the value of the 
    // picked coin 
    for(int i=0; i<m; i++) 
        for(int j=S[i]; j<=n; j++) 
            table[j] += table[j-S[i]]; 
  
    return table[n]; 
} 

// Driver program to test above function 
int main() 
{ 
	int i, j; 
	int arr[] = {1, 2, 3}; 
	int m = sizeof(arr)/sizeof(arr[0]); 
	printf("%d ", count(arr, m, 4)); 
	getchar(); 
	return 0; 
} 


4. maxsum path in subarray
// CPP prorgam for finding max path in matrix 
#include <bits/stdc++.h> 
#define N 4 
#define M 6 
using namespace std; 

// To calculate max path in matrix 
int findMaxPath(int mat[][M]) 
{ 

	for (int i = 1; i < N; i++) { 
		for (int j = 0; j < M; j++) { 

			// When all paths are possible 
			if (j > 0 && j < M - 1) 
				mat[i][j] += max(mat[i - 1][j], 
							max(mat[i - 1][j - 1], 
							mat[i - 1][j + 1])); 

			// When diagonal right is not possible 
			else if (j > 0) 
				mat[i][j] += max(mat[i - 1][j], 
							mat[i - 1][j - 1]); 

			// When diagonal left is not possible 
			else if (j < M - 1) 
				mat[i][j] += max(mat[i - 1][j], 
							mat[i - 1][j + 1]); 

			// Store max path sum 
		} 
	} 
	int res = 0; 
	for (int j = 0; j < M; j++) 
		res = max(mat[N-1][j], res); 
	return res; 
} 

// Driver program to check findMaxPath 
int main() 
{ 
	
	int mat1[N][M] = { { 10, 10, 2, 0, 20, 4 }, 
					{ 1, 0, 0, 30, 2, 5 }, 
					{ 0, 10, 4, 0, 2, 0 }, 
					{ 1, 0, 2, 20, 0, 4 } }; 
			
	cout << findMaxPath(mat1) << endl; 
	return 0; 
} 


// C++ implementation to find the maximum sum 
// path in a matrix 
#include <bits/stdc++.h> 
using namespace std; 

#define SIZE 10 

// function to find the maximum sum 
// path in a matric 
int maxSum(int mat[SIZE][SIZE], int n) 
{ 
	// if there is a single element only 
	if (n == 1) 
		return mat[0][0]; 

	// dp[][] matrix to store the results 
	// of each iteration 
	int dp[n][n]; 
	int maxSum = INT_MIN, max; 

	// base case, copying elements of 
	// last row 
	for (int j = 0; j < n; j++) 
		dp[n - 1][j] = mat[n - 1][j]; 

	// building up the dp[][] matrix from 
	// bottom to the top row 
	for (int i = n - 2; i >= 0; i--) { 
		for (int j = 0; j < n; j++) { 
			max = INT_MIN; 

			// finding the maximum diagonal element in the 
			// (i+1)th row if that cell exists 
			if (((j - 1) >= 0) && (max < dp[i + 1][j - 1])) 
				max = dp[i + 1][j - 1]; 
			if (((j + 1) < n) && (max < dp[i + 1][j + 1])) 
				max = dp[i + 1][j + 1]; 

			// adding that 'max' element to the 
			// mat[i][j] element 
			dp[i][j] = mat[i][j] + max; 
		} 
	} 

	// finding the maximum value from the 
	// first row of dp[][] 
	for (int j = 0; j < n; j++) 
		if (maxSum < dp[0][j]) 
			maxSum = dp[0][j]; 

	// required maximum sum 
	return maxSum; 
} 

// Driver program to test above 
int main() 
{ 
	int mat[SIZE][SIZE] = { { 5, 6, 1, 7 }, 
							{ -2, 10, 8, -1 }, 
							{ 3, -7, -9, 11 }, 
							{ 12, -4, 2, 6 } }; 
	int n = 4; 

	cout << "Maximum Sum = "
		<< maxSum(mat, n); 

	return 0; 
} 

#include <bits/stdc++.h> 
using namespace std; 
#define N 100 

// No of rows and columns 
int n, m; 

// Declaring the matrix of maximum 
// 100 rows and 100 columns 
int a[N][N]; 

// Variable visited is used to keep 
// track of all the visited positions 
// Variable dp is used to store 
// maximum sum till current position 
vector<vector<int> > dp(N, vector<int>(N)), 
	visited(N, vector<int>(N)); 

// For storing current sum 
int current_sum = 0; 

// For continuous update of 
// maximum sum required 
int total_sum = 0; 

// Function to Input the matrix of size n*m 
void inputMatrix() 
{ 
	n = 3; 
	m = 3; 
	a[0][0] = 500; 
	a[0][1] = 100; 
	a[0][2] = 230; 
	a[1][0] = 1000; 
	a[1][1] = 300; 
	a[1][2] = 100; 
	a[2][0] = 200; 
	a[2][1] = 1000; 
	a[2][2] = 200; 
} 

// Function to calculate maximum sum of path 
int maximum_sum_path(int i, int j) 
{ 
	// Checking boundary condition 
	if (i == n - 1 && j == m - 1) 
		return a[i][j]; 

	// Checking whether or not (i, j) is visited 
	if (visited[i][j]) 
		return dp[i][j]; 

	// Marking (i, j) is visited 
	visited[i][j] = 1; 

	// Updating the maximum sum till 
	// the current position in the dp 
	int& total_sum = dp[i][j]; 

	// Checking whether the position hasn't 
	// visited the last row or the last column. 
	// Making recursive call for all the possible 
	// moves from the current cell and then adding the 
	// maximum returned by the calls and updating it. 
	if (i < n - 1 & j < m - 1) { 
		int current_sum = max(maximum_sum_path(i, j + 1), 
							max( 
								maximum_sum_path(i + 1, j + 1), 
								maximum_sum_path(i + 1, j))); 
		total_sum = a[i][j] + current_sum; 
	} 

	// Checking whether 
	// position has reached last row 
	else if (i == n - 1) 
		total_sum = a[i][j] 
					+ maximum_sum_path(i, j + 1); 

	// If the position is in the last column 
	else
		total_sum = a[i][j] 
					+ maximum_sum_path(i + 1, j); 

	// Returning the updated maximum value 
	return total_sum; 
} 

// Driver Code 
int main() 
{ 
	inputMatrix(); 

	// Calling the implemented function 
	int maximum_sum = maximum_sum_path(0, 0); 

	cout << maximum_sum; 
	return 0; 
} 


5. subsetsum
// A recursive solution for subset sum problem 
#include <stdio.h> 

// Returns true if there is a subset 
// of set[] with sum equal to given sum 
bool isSubsetSum(int set[], int n, int sum) 
{ 
	// Base Cases 
	if (sum == 0) 
		return true; 
	if (n == 0 && sum != 0) 
		return false; 

	// If last element is greater than sum, 
	// then ignore it 
	if (set[n - 1] > sum) 
		return isSubsetSum(set, n - 1, sum); 

	/* else, check if sum can be obtained by any 
of the following: 
	(a) including the last element 
	(b) excluding the last element */
	return isSubsetSum(set, n - 1, sum) 
		|| isSubsetSum(set, n - 1, sum - set[n - 1]); 
} 

// Method 2
bool isSubsetSum(int set[], int n, int sum) 
{ 
    // The value of subset[i][j] will be true if 
    // there is a subset of set[0..j-1] with sum 
    // equal to i 
    bool subset[n + 1][sum + 1]; 
  
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
  
    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i <= sum; i++) 
        subset[0][i] = false; 
  
    // Fill the subset table in botton up manner 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
            if (j < set[i - 1]) 
                subset[i][j] = subset[i - 1][j]; 
            if (j >= set[i - 1]) 
                subset[i][j] = subset[i - 1][j] 
                               || subset[i - 1][j - set[i - 1]]; 
        } 
    } 
  
    /*   // uncomment this code to print table 
     for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", subset[i][j]); 
       printf("\n"); 
     }*/
  
    return subset[n][sum]; 
} 

// Driver program to test above function 
int main() 
{ 
	int set[] = { 3, 34, 4, 12, 5, 2 }; 
	int sum = 9; 
	int n = sizeof(set) / sizeof(set[0]); 
	if (isSubsetSum(set, n, sum) == true) 
		printf("Found a subset with given sum"); 
	else
		printf("No subset with given sum"); 
	return 0; 
} 


6. wordbreak
// A recursive program to test whether a given 
// string can be segmented into space separated 
// words in dictionary 
#include <iostream> 
using namespace std; 

/* A utility function to check whether a word is 
present in dictionary or not. An array of strings 
is used for dictionary. Using array of strings for 
dictionary is definitely not a good idea. We have 
used for simplicity of the program*/
int dictionaryContains(string word) 
{ 
	string dictionary[] = {"mobile","samsung","sam","sung", 
							"man","mango","icecream","and", 
							"go","i","like","ice","cream"}; 
	int size = sizeof(dictionary)/sizeof(dictionary[0]); 
	for (int i = 0; i < size; i++) 
		if (dictionary[i].compare(word) == 0) 
		return true; 
	return false; 
} 

// returns true if string can be segmented into space 
// separated words, otherwise returns false 
bool wordBreak(string str) 
{ 
	int size = str.size(); 

	// Base case 
	if (size == 0) return true; 

	// Try all prefixes of lengths from 1 to size 
	for (int i=1; i<=size; i++) 
	{ 
		// The parameter for dictionaryContains is 
		// str.substr(0, i) which is prefix (of input 
		// string) of length 'i'. We first check whether 
		// current prefix is in dictionary. Then we 
		// recursively check for remaining string 
		// str.substr(i, size-i) which is suffix of 
		// length size-i 
		if (dictionaryContains( str.substr(0, i) ) && 
			wordBreak( str.substr(i, size-i) )) 
			return true; 
	} 

	// If we have tried all prefixes and 
	// none of them worked 
	return false; 
} 

// Method 2
bool wordBreak(string str) 
{ 
    int size = str.size(); 
    if (size == 0)   return true; 
  
    // Create the DP table to store results of subroblems. The value wb[i] 
    // will be true if str[0..i-1] can be segmented into dictionary words, 
    // otherwise false. 
    bool wb[size+1]; 
    memset(wb, 0, sizeof(wb)); // Initialize all values as false. 
  
    for (int i=1; i<=size; i++) 
    { 
        // if wb[i] is false, then check if current prefix can make it true. 
        // Current prefix is "str.substr(0, i)" 
        if (wb[i] == false && dictionaryContains( str.substr(0, i) )) 
            wb[i] = true; 
  
        // wb[i] is true, then check for all substrings starting from 
        // (i+1)th character and store their results. 
        if (wb[i] == true) 
        { 
            // If we reached the last prefix 
            if (i == size) 
                return true; 
  
            for (int j = i+1; j <= size; j++) 
            { 
                // Update wb[j] if it is false and can be updated 
                // Note the parameter passed to dictionaryContains() is 
                // substring starting from index 'i' and length 'j-i' 
                if (wb[j] == false && dictionaryContains( str.substr(i, j-i) )) 
                    wb[j] = true; 
  
                // If we reached the last character 
                if (j == size && wb[j] == true) 
                    return true; 
            } 
        } 
    } 
  
    /* Uncomment these lines to print DP table "wb[]" 
     for (int i = 1; i <= size; i++) 
        cout << " " << wb[i]; */
  
    // If we have tried all prefixes and none of them worked 
    return false; 
} 

// Method 3
bool wordBreak(string s) 
{ 
    int n = s.size(); 
    if (n == 0) 
        return true; 
  
    // Create the DP table to store results of subroblems. 
    // The value dp[i] will be true if str[0..i] can be 
    // segmented into dictionary words, otherwise false. 
    vector<bool> dp(n + 1, 0); // Initialize all values 
    // as false. 
  
    // matched_index array represents the indexes for which 
    // dp[i] is true. Initially only -1 element is present 
    // in this array. 
    vector<int> matched_index; 
    matched_index.push_back(-1); 
  
    for (int i = 0; i < n; i++) { 
        int msize = matched_index.size(); 
  
        // Flag value which tells that a substring matches 
        // with given words or not. 
        int f = 0; 
  
        // Check all the substring from the indexes matched 
        // earlier. If any of that substring matches than 
        // make flag value = 1; 
        for (int j = msize - 1; j >= 0; j--) { 
  
            // sb is substring starting from matched_index[j] 
            // + 1  and of length i - matched_index[j] 
            string sb = s.substr(matched_index[j] + 1, i - matched_index[j]); 
  
            if (dictionaryContains(sb)) { 
                f = 1; 
                break; 
            } 
        } 
  
        // If substring matches than do dp[i] = 1 and 
        // push that index in matched_index array. 
        if (f == 1) { 
            dp[i] = 1; 
            matched_index.push_back(i); 
        } 
    } 
    return dp[n - 1]; 
} 

// Driver program to test above functions 
int main() 
{ 
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n"; 
	return 0; 
} 


7 . pallidrone
// Dynamic Programming Solution for 
// Palindrome Partitioning Problem 
#include <bits/stdc++.h> 
using namespace std; 

// A utility function to get minimum of two integers 
int min(int a, int b) { return (a < b) ? a : b; } 

// Returns the minimum number of cuts needed to partition a string 
// such that every part is a palindrome 
int minPalPartion(char* str) 
{ 
	// Get the length of the string 
	int n = strlen(str); 

	/* Create two arrays to build the solution in bottom up manner 
	C[i][j] = Minimum number of cuts needed for palindrome partitioning 
				of substring str[i..j] 
	P[i][j] = true if substring str[i..j] is palindrome, else false 
	Note that C[i][j] is 0 if P[i][j] is true */
	int C[n][n]; 
	bool P[n][n]; 

	int i, j, k, L; // different looping variables 

	// Every substring of length 1 is a palindrome 
	for (i = 0; i < n; i++) 
	{ 
		P[i][i] = true; 
		C[i][i] = 0; 
	} 

	/* L is substring length. Build the 
	solution in bottom up manner by 
	considering all substrings of 
	length starting from 2 to n. 
	The loop structure is same as Matrx 
	Chain Multiplication problem 
	( See https:// www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/ )*/
	for (L = 2; L <= n; L++) 
	{ 
		// For substring of length L, set 
		// different possible starting indexes 
		for (i = 0; i < n - L + 1; i++) 
		{ 
			j = i + L - 1; // Set ending index 

			// If L is 2, then we just need to 
			// compare two characters. Else 
			// need to check two corner characters 
			// and value of P[i+1][j-1] 
			if (L == 2) 
				P[i][j] = (str[i] == str[j]); 
			else
				P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1]; 

			// IF str[i..j] is palindrome, then C[i][j] is 0 
			if (P[i][j] == true) 
				C[i][j] = 0; 
			else
			{ 
				// Make a cut at every possible 
				// location starting from i to j, 
				// and get the minimum cost cut. 
				C[i][j] = INT_MAX; 
				for (k = i; k <= j - 1; k++) 
					C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j] + 1); 
			} 
		} 
	} 

	// Return the min cut value for 
	// complete string. i.e., str[0..n-1] 
	return C[0][n - 1]; 
} 

// Driver code 
int main() 
{ 
	char str[] = "ababbbabbababa"; 
	cout<<"Min cuts needed for Palindrome Partitioning is "<<minPalPartion(str); 
	return 0; 
} 

// This code is contributed by rathbhupendra 







 
