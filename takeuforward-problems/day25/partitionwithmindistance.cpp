// we have to do the partiiton b/w the array so that 2 subset have same sum

#include <bits/stdc++.h>
using namespace std;

int sumpartion(vector<int> arr,int n,int calculatedsum,int totalsum){
	
	if(n==0) return abs((totalsum-calculatedsum)-calculatedsum);

	return min(sumpartion(arr,n-1,calculatedsum+arr[n-1],totalsum), sumpartion(arr,n-1,calculatedsum,totalsum));
}

int partiiton(vector<int> arr){
	int n = arr.size();
	int sum=0;
	for(int i=0;i<n;i++) sum += arr[i];
	return sumpartion(arr,n,0,sum);
}


// dp method
int findMin(int arr[], int n) 
{ 
    // Calculate sum of all elements 
    int sum = 0;  
    for (int i = 0; i < n; i++) 
        sum += arr[i]; 
  
    // Create an array to store results of subproblems 
    bool dp[n+1][sum+1]; 
  
    // Initialize first column as true. 0 sum is possible  
    // with all elements. 
    for (int i = 0; i <= n; i++) 
        dp[i][0] = true; 
  
    // Initialize top row, except dp[0][0], as false. With 
    // 0 elements, no other sum except 0 is possible 
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = false; 
  
    // Fill the partition table in bottom up manner 
    for (int i=1; i<=n; i++) 
    { 
        for (int j=1; j<=sum; j++) 
        { 
            // If i'th element is excluded 
            dp[i][j] = dp[i-1][j]; 
  
            // If i'th element is included 
            if (arr[i-1] <= j) 
                dp[i][j] |= dp[i-1][j-arr[i-1]]; 
        } 
    } 
   
    // Initialize difference of two sums.  
    int diff = INT_MAX; 
      
    // Find the largest j such that dp[n][j] 
    // is true where j loops from sum/2 t0 0 
    for (int j=sum/2; j>=0; j--) 
    { 
        // Find the  
        if (dp[n][j] == true) 
        { 
            diff = sum-2*j; 
            break; 
        } 
    } 
    return diff; 
} 
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a; cin>>t;
	while(t--){
		cin>>n;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		cout<<partiiton(arr)<<endl;
	}
	return 0;
}