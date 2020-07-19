#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &taken,int n){
	for(int i=0;i<n;i++) cout<<taken[i]<<" ";
	cout<<endl;
}

void subsetsumutil(vector<int> &arr,vector<int> &taken,int arr_size,int t_size,int sum,int index,int actualsum){
	if(sum == actualsum){
		print(taken,t_size);
		if(index+1<arr_size && sum-arr[index]+arr[index+1]<=actualsum){
			subsetsumutil(arr,taken,arr_size,t_size-1,sum-arr[index],index+1,actualsum);
		}
	}else{
		if(index<arr_size && sum+arr[index]<=actualsum){
			for(int i=index;i<arr_size;i++){
				taken[t_size]=arr[i];
				if(sum+arr[i]<=actualsum)
					subsetsumutil(arr,taken,arr_size,t_size+1,sum+arr[i],i+1,actualsum);
			}
		}
	}
}

void subsetsum(vector<int> &arr,int n,int sum){
	vector<int>  taken(n,0);
	sort(arr.begin(),arr.end());
	int total=0;
	for(int i=0;i<n;i++) total += arr[i];
	if(arr[0]<=sum && total>=sum)
		subsetsumutil(arr,taken,n,0,0,0,sum);
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,s; cin>>t;
	while(t--){
		cin>>n>>s;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		subsetsum(arr,n,s);
	}
	return 0;
}