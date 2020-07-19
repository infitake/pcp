#include <bits/stdc++.h>
using namespace std;

// simple recursion print only count of ways
// int cominationsum1(vector<int> &arr,int n,int w){
// 	if(w==0) return 1;
// 	if(w<0) return 0;
// 	if(n<=0 && w>=1) return 0;
// 	if(arr[n-1]>w) return cominationsum1(arr,n-1,w);
// 	return cominationsum1(arr,n,w-arr[n-1]) + cominationsum1(arr,n-1,w);
// }
// bool issafe(vector<int> &arr,int index,int n,int w){
// 	if(index<n && w-arr[index]>=0) return true;
// 	return false;
// }

vector<vector<int>> finalcomb;

// bool cominationsum1(vector<int> &arr,int n,int w,vector<int> &comb){
// 	if(w==0){
// 		vector<int> trya=comb;
// 		sort(trya.begin(),trya.end());
// 		finalcomb.insert(trya);
// 		return true;
// 	}
// 	bool res = false;
// 	for(int i=0;i<n;i++){
// 		if(issafe(arr,i,n,w)){
// 			comb.push_back(arr[i]);
// 			res = cominationsum1(arr,n,w-arr[i],comb) || res;
// 			comb.pop_back();
// 		}
// 	}
// 	return res;
// }

void cominationsum2(vector<int> &arr,int n,int w,vector<int> &comb,int index){
	if(w<0) return;
	if(w==0){
		finalcomb.push_back(comb);
		return ;
	}
	// while(i<n && w-arr[i]>=0){
	for(int i=index;i<n;i++){
		if(i!=index && arr[i]==arr[i-1]) continue;
		comb.push_back(arr[i]);
		cominationsum2(arr,n,w-arr[i],comb,i+1);
		comb.pop_back();
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
	int t,n,a,w; cin>>t;
	while(t--){
		cin>>n>>w;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		sort(arr.begin(),arr.end());
		// arr.erase(unique(arr.begin(),arr.end()),arr.end());
		vector<int> comb;
		cominationsum2(arr,n,w,comb,0);
		for(auto vec:finalcomb){
			for(int i=0;i<vec.size();i++){
				cout<<vec[i]<<" ";
			}
			cout<<endl;
		}
		finalcomb.clear();
		cout<<endl;
	}
	return 0;
}