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