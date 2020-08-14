#include <bits/stdc++.h>
using namespace std;

// Algorithm: (Example 12(1100))
// Let I/P be 12 (1100)

// 1. Take two's complement of the given no as all bits are reverted
// except the first '1' from right to left (0100)

// 2  Do a bit-wise & with original no, this will return no with the
// required one only (0100)

// 3  Take the log2 of the no, you will get (position - 1) (2)

// 4  Add 1 (3)

int rightmost(int n){
	return log2(n & -n) + 1; 
}

// position of msb from right to left
int leftmost(int n) {
	return log2(n)+1;
}

// count no of set bits
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
		cout<<leftmost(n)<<endl;
		// cout<<rightmost(n)<<endl;
		
	}
	return 0;
}