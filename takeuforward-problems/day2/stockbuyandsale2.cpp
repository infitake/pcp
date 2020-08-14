#include <bits/stdc++.h>
using namespace std;

// Method 2:
int maxPrice(int arr[],int n){
    int profit = 0;
    int minindex = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<minindex) minindex = arr[i];
        else{
            profit += (arr[i]-minindex);
            minindex = arr[i];
        }
    }
    return profit;
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