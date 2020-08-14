#include <bits/stdc++.h>
using namespace std;

void minSwap(int arr[],int n){
	vector<pair<int,int>> vec(n);

	for(int i=0;i<n;i++){
		vec[i].first = arr[i];
		vec[i].second = i;
	}

	// sort wrt first
	sort(vec.begin(),vec.end());
	int count=0;
	for(int i=0;i<n;i++){
		if(vec[i].second == i) continue;
		else{
			swap(vec[i].first,vec[vec[i].second].first);
			swap(vec[i].second,vec[vec[i].second].second);
		}

		if(vec[i].second != i) --i;

		count++;
	}

	cout<<count<<endl;
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

		minSwap(arr,n);
		
	}
	return 0;
}