#include <bits/stdc++.h>
using namespace std;

// Method 1:(simple traversing and get max sum) 
void kadanes(int arr[],int n){
	int sum=0,max = INT_MIN;
	for(int i=0;i<n;i++){
		sum += arr[i];
		if(sum<0) sum = 0;
		else if(sum > max) max = sum;
	}
	cout<<max<<endl;
}

// Method 2:(print max sum with start and last index)
void kadanes(int arr[],int n){
	int sum=0,max = INT_MIN,start=0,last=0,s=0;
	for(int i=0;i<n;i++){
		sum += arr[i];
		if(sum<0){
			sum=0;
			s=i+1;
			// start = i+1;	
			// last = i+1;
		}
		else if(sum > max){
			max = sum;
			last=i;
			start=s;
		} 
	}
	cout<<max<<" "<<start<<" "<<last<<endl;
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
		kadanes(arr,n);
	}
	return 0;
}