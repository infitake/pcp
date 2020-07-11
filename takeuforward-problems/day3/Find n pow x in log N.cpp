#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 1000000007

// Method 1:
// using fast exponent with module
ll fastexpo(ll a,ll b){
	if(b==0) return 1;
	ll d = fastexpo(a,b/2);
	if(b&1) {
		if(b>0) return ((d*d)%N*a)%N;
		else return (((d%N)*(d%N))%N)/a;
	}
	else return ((d%N)*(d%N))%N;
}
// Method 2:
// here p is modular value
int power(int x, unsigned int y, int p)  
{  
    int res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
} 

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,a,b; cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<fastexpo(a,b)<<endl;	
	}
	return 0;
}