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