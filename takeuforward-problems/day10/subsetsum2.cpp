#include <bits/stdc++.h>
using namespace std;

// This is recursion Method but show timelimit for large input
bool subsetsumutil(vector<int> &arr,int arr_size,int sum,int index,int actualsum){
	if(sum == actualsum){
		return true;
	}
	if(index<arr_size && sum+arr[index]<=actualsum){
		for(int i=index;i<arr_size;i++){
			// actualsum -= arr[i];
			if(sum+arr[i]<=actualsum)
				if(subsetsumutil(arr,arr_size,sum+arr[i],i+1,actualsum)) return true;
			// actualsum += arr[i];
		}
	}
	return false;
}

bool subsetsum(vector<int> &arr,int n){
	sort(arr.begin(),arr.end());
	int total=0;
	for(int i=0;i<n;i++) total += arr[i];
	if(total%2==1) return false;
 	total = total/2;
	if(!subsetsumutil(arr,n,0,0,total)) return false;
	else return true;
}

// Method 2 :(using dp with 1D space)


bool subsetsum(vector<int> &arr,int n){
	sort(arr.begin(),arr.end());
	int total=0;
	for(int i=0;i<n;i++) total += arr[i];
	if(total%2==1) return false;
 	total = total/2;
	vector<bool> subset(total+1,false);
	subset[0]=true;
	for(auto x:arr){
		for(int i=total;i>=x;i--){
			subset[i] = subset[i] || subset[i-x];
		}
	}
	return subset[total];
}

// Method 3:(using dp with 2D space)

bool subsetsum(vector<int> &arr,int n){
	sort(arr.begin(),arr.end());
	int total=0;
	for(int i=0;i<n;i++) total += arr[i];
	if(total%2==1) return false;
 	total = total/2;
	vector<vector<bool> > dp(n+1 , vector<bool>(total+1 , false));
    for(int i = 0;i<=n;i++) dp[i][0] = true;
    for(int j = 0;j<=total; j++) dp[0][j] = false;    
    dp[0][0] = true;
    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=total; j++){
            if(j<arr[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
        }
    }
    return dp[n][total];
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
		cin>>n;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		cout<<subsetsum(arr,n)<<endl;
	}
	return 0;
}