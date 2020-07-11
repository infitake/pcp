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