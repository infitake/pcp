#include <bits/stdc++.h>
using namespace std;
// this is same as kadane'algo but different in when 2 -ve value are come the product is +ve

int maxproductsum(vector<int> &arr,int n){
	int maxval=1,maxend=1,minend=1,flag=0,minval=0;
    int n= arr.size();
    int nvesum=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            maxend *= arr[i];
            minend = min(arr[i]*minend,1);
            flag=1;
        }else if(arr[i]==0){
            maxend=1;
            minend=1;
            
        }else{
            int temp = maxend;
            maxend = max(arr[i]*minend,1);
            minend = temp*arr[i];
            nvesum++;
            minval = min(minval,arr[i]);
        }
        maxval = max(maxval,maxend);
    }
    if(nvesum == n && maxval==1) return minval;
    if(flag==0 && maxval==1) return 0;
    return maxval;
}

//Method 2
int max_product(int arr[], int n) 
{ 
    // Initialize maximum products in forward and 
    // backward directions 
    int max_fwd = INT_MIN, max_bkd = INT_MIN; 
  
    // Initialize current product 
    int max_till_now = 1; 
  
    //check if zero is present in an array or not 
    bool isZero=false; 
      
    // max_fwd for maximum contiguous product in 
    // forward direction 
    // max_bkd for maximum contiguous product in 
    // backward direction 
    // iterating within forward direction in array 
    for (int i=0; i<n; i++) 
    { 
        // if arr[i]==0, it is breaking condition 
        // for contiguous subarray 
        max_till_now = max_till_now*arr[i]; 
        if (max_till_now == 0) 
        {    
             isZero=true; 
             max_till_now = 1; 
            continue; 
        } 
        if (max_fwd < max_till_now) // update max_fwd 
            max_fwd = max_till_now; 
    } 
  
     max_till_now = 1; 
  
    // iterating within backward direction in array 
    for (int i=n-1; i>=0; i--) 
    { 
        max_till_now = max_till_now * arr[i]; 
        if (max_till_now == 0) 
        { 
            isZero=true; 
            max_till_now = 1; 
            continue; 
        } 
  
        // update max_bkd 
        if (max_bkd < max_till_now) 
            max_bkd = max_till_now; 
    } 
  
    // return max of max_fwd and max_bkd 
    int res =  max(max_fwd, max_bkd); 
  
    // Product should not be nagative. 
    // (Product of an empty subarray is 
    // considered as 0) 
    if(isZero) 
    return max(res, 0); 
  
    return res; 
} 
  
 // Method 3
int maxProduct(int* arr, int n) 
{ 
    // Variables to store maximum and minimum 
    // product till ith index. 
    int minVal = arr[0]; 
    int maxVal = arr[0]; 
  
    int maxProduct = arr[0]; 
  
    for (int i = 1; i < n; i++) { 
  
        // When multiplied by -ve number, 
        // maxVal becomes minVal 
        // and minVal becomes maxVal. 
        if (arr[i] < 0) 
            swap(maxVal, minVal); 
  
        // maxVal and minVal stores the 
        // product of subarray ending at arr[i]. 
        maxVal = max(arr[i], maxVal * arr[i]); 
        minVal = min(arr[i], minVal * arr[i]); 
  
        // Max Product of array. 
        maxProduct = max(maxProduct, maxVal); 
    } 
  
    // Return maximum product found in array. 
    return maxProduct; 
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
		cout<<maxproductsum(arr,n)<<endl;
	}
	return 0;
}