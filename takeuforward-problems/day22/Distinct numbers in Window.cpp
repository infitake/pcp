#include <bits/stdc++.h>
using namespace std;

void distantelement(vector<int> arr,int k){
	int n = arr.size();
	map<int,int> mp;
	int dist_count=0;
	for(int i=0;i<k;i++){
		if(mp[arr[i]]==0) dist_count++;
		mp[arr[i]]++;
	}
	cout<<dist_count<<" ";
	for(int i = k;i<n;i++){
		if(mp[arr[i-k]] == 1) dist_count--;
		mp[arr[i-k]] -= 1;
		if(mp[arr[i]]==0) dist_count++;
		mp[arr[i]] += 1;
		cout<<dist_count<<" ";
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
	int t,n,a,k; cin>>t;
	while(t--){
		cin>>n>>k;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		distantelement(arr,k);
		
	}
	return 0;
} 