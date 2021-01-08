#include <bits/stdc++.h>
using namespace std;



// Method 1:
// Find the local minima and store it as starting index. If not exists, return.
// Find the local maxima. and store it as ending index. If we reach the end, set the end as ending index.
// Update the solution (Increment count of buy sell pairs)
// Repeat the above steps if end is not reached

int stockBuySell(int arr[], int n) 
{ 
    int profit = 0;
        int lastindex=0;
        int n = arr.size();
        int i=0;
        while (i < n - 1) { 
  
        // Find Local Minima 
        // Note that the limit is (n-2) as we are 
        // comparing present element to the next element 
        while ((i < n - 1) && (arr[i + 1] <= arr[i])) 
            i++; 
        if (i == n - 1) 
            break; 
  
        // Store the index of minima 
        int buy = i++; 
            
        int k=buy+1;
        while(k<n){
            if(arr[k]>=arr[k-1]) k++;
            else{
                profit = max(profit,(arr[k-1]-arr[buy]));
                k++;
            }
        }
        profit = max(profit,(arr[k-1]-arr[buy]));
    } 
    return profit;
}

// Method 2:
int maxPrice(int arr[],int n){
	int minprofit = INT_MAX;
	int maxprofit = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]<minprofit) minprofit = arr[i];
        else if((arr[i]-minprofit)>maxprofit) maxprofit = (arr[i]-minprofit);
    }
    return maxprofit;
}
// time complexity:O(n)
// space :O(1)

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
		cout<<stockBuySell(arr,n)<<endl;
		
	}
	return 0;
}