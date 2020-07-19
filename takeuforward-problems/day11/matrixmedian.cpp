#include <bits/stdc++.h>
using namespace std;

// Method 1
int matrixmedian(vector<vector<int>> &arr,int r,int c){
	int min=INT_MAX,max=INT_MIN;
	for(int i=0;i<r;i++){
		if(min>arr[i][0]) min = arr[i][0];
		if(max<arr[i][c-1]) max = arr[i][c-1];
	}

	int desire = (r*c +1)/2;
	while(min<max){
		int place=0;
		int mid = min+(max-min)/2;
		for(int i=0;i<r;i++) 
			place += upper_bound(arr[i].begin(),arr[i].end(),mid)- arr[i].begin();
		// this is if we are use arr
		// place += upper_bound(arr[i], arr[i]+c, mid) - arr[i]; 
		if(place<desire) min = mid+1;
		else max = mid;
	}
	return min;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,r,c,a; cin>>t;
	while(t--){
		cin>>r>>c;
		vector<vector<int>> arr;
		for(int i=0;i<r;i++){
			vector<int> v;
			for(int j=0;j<c;j++){
				cin>>a;
				v.push_back(a);
			}
			arr.push_back(v);
		}
		cout<<matrixmedian(arr,r,c)<<endl;
	}
	return 0;
}