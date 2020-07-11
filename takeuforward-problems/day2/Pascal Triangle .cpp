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