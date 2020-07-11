#include <bits/stdc++.h>
using namespace std;

// Method 1:
void sort012(int arr[],int n){
	int c0=0,c1=0,c2=0;
	for(int i=0;i<n;i++){
		if(arr[i]==0) c0++;
		else if(arr[i]==1) c1++;
		else if(arr[i]==2) c2++; 
	}
	for(int i=0;i<n;i++){
		if(c0>0){
			arr[i]=0;
			c0--;
		}else if(c1>0){
			arr[i]=1;
			c1--;
		}else if(c2>0){
			arr[i]=2;
			c2--;
		}
	}
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

// Method 2:
// Dutch National Flag Algorithm OR 3-way Partitioning:
// At first, the full array is unknown. There are three indices – low, mid and high. Initially, the value of low = mid = 1 and high = N.
// If the ith element is 0 then swap the element to the low range, thus shrinking the unknown range.
// Similarly, if the element is 1 then keep it as it is but shrink the unknown range.
// If the element is 2 then swap it with an element in high range.
void sort012(int a[], int arr_size) 
{ 
    int lo = 0; 
    int hi = arr_size - 1; 
    int mid = 0; 
  
    // Iterate till all the elements 
    // are sorted 
    while (mid <= hi) { 
        switch (a[mid]) { 
  
        // If the element is 0 
        case 0: 
            swap(a[lo++], a[mid++]); 
            break; 
  
        // If the element is 1 . 
        case 1: 
            mid++; 
            break; 
  
        // If the element is 2 
        case 2: 
            swap(a[mid], a[hi--]); 
            break; 
        } 
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
		sort012(arr,n);
		cout<<endl;
	}
	return 0;
}