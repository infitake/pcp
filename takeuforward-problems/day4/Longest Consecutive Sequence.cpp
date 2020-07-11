#include <bits/stdc++.h>
using namespace std;
// Method 1:(using sort)
int lcs(vector<int> arr,int n){
	sort(arr.begin(),arr.end());
    int val = arr[0];
    int sum=1,maxsum=INT_MIN;
    for(int i=1;i<n;i++){
        if(arr[i] == val) continue;
        if(arr[i]==val+1){
            val += 1;
            sum++;
        }else {
            if(maxsum<sum){
                maxsum=sum;
            }
            val = arr[i];
            //cout<<"else"<<val<<endl;
            sum=1;
        }
    }
    if(maxsum<sum){
        maxsum=sum;
    }
    return maxsum;
}
// complexity O(nlogn)
// space O(1)

// Method 2: (using Hash)
int lcs(vector<int> arr,int n){
	map<int,int> mp;
	sort(arr.begin(),arr.end());
	// for(auto x:arr) cout<<x<<" ";
	for(int i=0;i<n;i++) mp[arr[i]]=i;
	int sam,i=0,count=1,maxval=1;
	for(auto x:mp){
		if(i==0) { sam = x.first; i++; continue;}
		i++;
		if(x.first == sam +1){
			count++;
			sam=x.first;
		}else{
			maxval = max(maxval,count);
			count=1;
			sam=x.first;
		}
	}
	maxval=max(maxval,count);
	return maxval;
}
// complexity O(n)
// space O(n)


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
		cout<<lcs(arr,n)<<endl;
	}
	return 0;
}