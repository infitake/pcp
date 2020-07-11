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