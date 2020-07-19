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