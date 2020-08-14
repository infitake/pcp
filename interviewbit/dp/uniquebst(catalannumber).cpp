#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
// Catalan numbers satisfy the following recursive formula.
// C_0=1 \ and \ C_n_+_1=\sum_{i=0}^{n}C_iC_n_-_i \ for \ n\geq 0;
// Following is the implementation of above recursive formula.

// unsigned long int catalan(unsigned int n) 
// { 
//     // Base case 
//     if (n <= 1) return 1; 
  
//     // catalan(n) is sum of catalan(i)*catalan(n-i-1) 
//     unsigned long int res = 0; 
//     for (int i=0; i<n; i++) 
//         res += catalan(i)*catalan(n-i-1); 
  
//     return res; 
// } 

// Time complexity of above implementation is equivalent to nth catalan number.
// T(n)=\sum_{i=0}^{n-1}T(i)*T(n-i-1) \ for \ n\geq 1;

// The value of nth catalan number is exponential that makes the time complexity exponential.


// ime Complexity: Time complexity of above implementation is O(n).

// We can also use below formula to find nth catalan number in O(n) time.
// C_n=\frac{(2n)!}{(n+1)!n!}=\prod_{k=2}^{n}\frac{n+k}{k}  \ for \ n\geq 0



int numTrees(int n) {
    // catalan number
    vector<int> dp(n+1,0);
    
    dp[0]=1;dp[1]=1;
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i] += dp[j] + dp[i-j-1];
        }
    }
    return dp[n];
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
		cout<<numTrees(n)<<endl;
	}
	return 0;
}