#include <bits/stdc++.h>
using namespace std;

int inversionCount(int arr[],int n){
	multiset<int> s;

	s.insert(arr[0]);

	int invcount=0;

	for(int i=1;i<n;i++){
		s.insert(arr[i]);

		auto index = s.upper_bound(arr[i]);

		invcount += distance(index,s.end());
	}
	return invcount;
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
		cout<<inversionCount(arr,n)<<endl;
	}
	return 0;
}