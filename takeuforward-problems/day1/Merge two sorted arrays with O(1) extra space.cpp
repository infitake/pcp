#include <bits/stdc++.h>
using namespace std;
#define ll int

// Method 1:(using insertion sort like technique from last element of both array)
// The idea is to begin from last element of ar2[] and search it in ar1[]. If there is a greater element in ar1[], then we move last element of ar1[] to ar2[]. To keep ar1[] and ar2[] sorted, we need to place last element of ar2[] at correct place in ar1[]. We can use Insertion Sort type of insertion for this. Below is algorithm:

// 1) Iterate through every element of ar2[] starting from last 
//    element. Do following for every element ar2[i]
//     a) Store last element of ar1[i]: last = ar1[i]
//     b) Loop from last element of ar1[] while element ar1[j] is 
//        smaller than ar2[i].
//           ar1[j+1] = ar1[j] // Move element one position ahead
//           j--
//     c) If any element of ar1[] was moved or (j != m-1)
//           ar1[j+1] = ar2[i] 
//           ar2[i] = last  
// In above loop, elements in ar1[] and ar2[] are always kept sorted.
// void merge(ll arr1[],ll arr2[],ll n,ll m){
// 	for(ll i=m-1;i>=0;i--){
// 		ll j,last=arr1[n-1];
// 		for(j=n-2;j>=0 && arr1[j]>arr2[i];j--)
// 			arr1[j+1]=arr1[j];
// 		if(j!=n-2 || last>arr2[i]){
// 			arr1[j+1]=arr2[i];
// 			arr2[i]=last;
// 		}
// 	}
// 	for(ll i=0;i<n;i++) cout<<arr1[i]<<" ";
// 	for(ll i=0;i<m;i++) cout<<arr2[i]<<" ";
// }
// Method 2:(swap in a particular gap)
// The idea: we start comparing elements that are far from each other rather than adjacent.
// For every pass, we calculate the gap and compare the elements towards the right of the gap. Every pass, the gap reduces to the ceiling value of dividing by 2.

// Examples:

// First example: a1[] = {3 27 38 43}, a2[] = {9 10 82}
// Start with gap =  ceiling of n/2 = 4 [This gap is for 
//                                   whole merged array]
//         3 27 38 43   9 10 82 
//         3 27 38 43   9 10 82
//         3 10 38 43   9 27 82
//         gap = 2:
//         3 10 38 43   9 27 82
//         3 10 38 43   9 27 82
//         3 10 38 43   9 27 82 
//         3 27 9 10   38 43 82
//         3 27 9 10   38 43 82
//         gap = 1:
//         3 27 9 10   38 43 82
//         3 27 9 10   38 43 82
//         3 9 27 10   38 43 82
//         3 9 10 27   38 43 82
//         3 9 10 27   38 43 82
//         3 9 10 27   38 43 82
// Output : 3 9 10 27 38 43 82

// Second Example: a1[] = {10 27 38 43 82}, a2[] = {3 9}
// Start with gap = ceiling of n/2 (4):
// 10 27 38 43 82   3 9 
// 10 27 38 43 82   3 9
// 10 3 38 43 82   27 9
// 10 3 9 43 82   27 38
// gap = 2:
// 10 3 9 43 82   27 38
// 9 3 10 43 82   27 38
// 9 3 10 43 82   27 38
// 9 3 10 43 82   27 38
// 9 3 10 27 82   43 38
// 9 3 10 27 38   43 82
// gap = 1
// 9 3 10 27 38   43 82
// 3 9 10 27 38   43 82
// 3 9 10 27 38   43 82
// 3 9 10 27 38   43 82
// 3 9 10 27 38   43 82
// 3 9 10 27 38   43 82
// Output : 3 9 10 27 38   43 82
int nextGap(int gap) 
{ 
    if (gap <= 1) 
        return 0; 
    return (gap / 2) + (gap % 2); 
} 

void merge(int arr1[], int arr2[], int n, int m) 
{ 
    int i, j, gap = n + m; 
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
    { 
        // comparing elements in the first array. 
        for (i = 0; i + gap < n; i++) 
            if (arr1[i] > arr1[i + gap]) 
                swap(arr1[i], arr1[i + gap]); 
  
        //comparing elements in both arrays. 
        for (j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++) 
            if (arr1[i] > arr2[j]) 
                swap(arr1[i], arr2[j]); 
  
        if (j < m) 
        { 
            //comparing elements in the second array. 
            for (j = 0; j + gap < m; j++) 
                if (arr2[j] > arr2[j + gap]) 
                    swap(arr2[j], arr2[j + gap]); 
        } 
    } 
    for(ll i=0;i<n;i++) cout<<arr1[i]<<" ";
	for(ll i=0;i<m;i++) cout<<arr2[i]<<" ";
} 

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n,m; cin>>t;
	while(t--){
		cin>>n>>m;
		ll arr1[n],arr2[m];
		for(ll i=0;i<n;i++) cin>>arr1[i];
		for(ll i=0;i<m;i++) cin>>arr2[i];
		merge(arr1,arr2,n,m);
		cout<<endl;
	}
	return 0;
}