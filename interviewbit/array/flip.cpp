#include <bits/stdc++.h>
using namespace std;

void fliparr(vector<int> &arr,int n) {
	for(int i=0;i<n;i++){
		arr[i] = (arr[i]==1)?0:1;
	}
}
// 2
// 7
// 0 1 0 0 1 1 0
// 1 0 1 1 0 0 1
// 6
// 0 0 0 1 0 1
// 1 1 1 0 1 0

void flip(vector<int> &arr,int n) {
	fliparr(arr,n);
	int maxval=INT_MIN,start=0,end=0,val,sum=0,s=0;
	// we take value of 0 as -1;
	for(int i=0;i<n;i++){
		val = (arr[i]==1)?1:-1;
		// sum = max(sum,sum+val);
		// if lexographically smaller than remove the equal sign
		sum += val;
		if(sum<=0){
			sum = 0;
			s = i+1;
		}
		if(sum>maxval){
			start = s;
			end = i;
			maxval=sum;
		}
	}
	cout<<maxval<<" "<<start<<" "<<end<<" "<<endl;
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
		for(int i=0;i<n;i++) {
			cin>>a;
			arr.push_back(a);
		}
		flip(arr,n);
	}
	return 0;
}