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