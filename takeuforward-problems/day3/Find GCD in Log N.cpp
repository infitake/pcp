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