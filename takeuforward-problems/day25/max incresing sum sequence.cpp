#include <bits/stdc++.h>
using namespace std;
// this is same as kadane'algo but different in when 2 -ve value are come the product is +ve

int maxincresingsequence(vector<int> &arr,int n){
    int lis[n]={0};
    // lis[0]=1;
    for(int i=0;i<n;i++){
    	lis[i]=arr[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && lis[i]<lis[j]+arr[i])
                lis[i]=lis[j]+arr[i];
        }
    }
    sort(lis,lis+n);
    return lis[n-1];
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
		cout<<maxincresingsequence(arr,n)<<endl;
	}
	return 0;
}