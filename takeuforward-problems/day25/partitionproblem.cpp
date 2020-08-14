// we have to do the partiiton b/w the array so that 2 subset have same sum

#include <bits/stdc++.h>
using namespace std;

bool sumpartion(vector<int> arr,int n,int sum){
	if(sum == 0) return true;
	if(n<=0 && sum>=1) return false;

	if(arr[n-1]>sum){
		return sumpartion(arr,n-1,sum);
	}
	return sumpartion(arr,n-1,sum-arr[n-1]) || sumpartion(arr,n-1,sum);
}

bool partiiton(vector<int> arr){
	int n = arr.size();
	int sum=0;
	for(int i=0;i<n;i++) sum += arr[i];
	if(sum&1) return false;
	sum = sum/2;
	return sumpartion(arr,n,sum);
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
		cout<<partiiton(arr)<<endl;
	}
	return 0;
}