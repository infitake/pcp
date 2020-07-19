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