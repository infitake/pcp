#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
	double r1=(double)a.first/a.second;
	double r2 = (double)b.first/b.second;
	return r1>r2;
}

int fractionalknapsack(vector<pair<int,int>> arr,int n,int w){
	sort(arr.begin(),arr.end(),comp);
	int curWeight = 0; 
    double finalvalue = 0.0; 
    for (int i = 0; i < n; i++) { 
        if (curWeight + arr[i].second <= w) { 
            curWeight += arr[i].second; 
            finalvalue += arr[i].first; 
        } else { 
            int remain = w - curWeight; 
            finalvalue += arr[i].first * ((double) remain / arr[i].second); 
            break; 
        } 
    } 
	return finalvalue;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,w,a,b; cin>>t;
	while(t--){
		cin>>n>>w;
		vector<pair<int,int>> arr;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			arr.push_back({a,b});
		}
		cout<<fractionalknapsack(arr,n,w)<<endl;
		
	}
	return 0;
}