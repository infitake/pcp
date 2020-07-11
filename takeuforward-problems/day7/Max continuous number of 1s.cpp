#include <bits/stdc++.h>
using namespace std;

int count1(vector<int> arr){
	int n= arr.size();
	int l=0,r=0,count=0,maxval=0;
	for (int i = 0; i < n; i++) {  
        if (arr[i] == 0) count = 0;  
        else{ 
            count++;
            maxval = max(maxval, count); 
        } 
    } 
	return maxval;
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
		cout<<count1(arr)<<endl;
	}
	return 0;
}