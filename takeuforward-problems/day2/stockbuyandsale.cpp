#include <bits/stdc++.h>
using namespace std;

// Method 1:
int maxPrice(int arr[],int start,int end){
	if(end<=start) return 0;
	int maxprofit=0;
	for(int i=start;i<end;i++){
		for(int j=i+1;j<=end;j++){
			if(arr[j]>arr[i]){
				int max_curr = (arr[j]-arr[i])
								+maxPrice(arr,start,i-1)
								+maxPrice(arr,j+1,end);
				maxprofit = max(max_curr,maxprofit);
			}
		}
	}
	return maxprofit;
}

// Method 2:
// Find the local minima and store it as starting index. If not exists, return.
// Find the local maxima. and store it as ending index. If we reach the end, set the end as ending index.
// Update the solution (Increment count of buy sell pairs)
// Repeat the above steps if end is not reached

void stockBuySell(int price[], int n) 
{ 
    // Prices must be given for at least two days 
    if (n == 1) 
        return; 
  
    // Traverse through given price array 
    int i = 0; 
    while (i < n - 1) { 
  
        // Find Local Minima 
        // Note that the limit is (n-2) as we are 
        // comparing present element to the next element 
        while ((i < n - 1) && (price[i + 1] <= price[i])) 
            i++; 
  
        // If we reached the end, break 
        // as no further solution possible 
        if (i == n - 1) 
            break; 
  
        // Store the index of minima 
        int buy = i++; 
  
        // Find Local Maxima 
        // Note that the limit is (n-1) as we are 
        // comparing to previous element 
        while ((i < n) && (price[i] >= price[i - 1])) 
            i++; 
  
        // Store the index of maxima 
        int sell = i - 1; 
  
        cout << "Buy on day: " << buy 
             << "\t Sell on day: " << sell << endl; 
    } 
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
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		cout<<maxPrice(arr,0,n-1)<<endl;
		
	}
	return 0;
}