#include <bits/stdc++.h>
using namespace std;

void preivousMax(int arr[],int n){
	stack<int> s;
	for(int i=0;i<n;i++){
		if(!s.empty() && arr[i]<s.top()){
			cout<<s.top()<<" ";
		}else if(s.empty()){
			cout<<"-1"<<" ";
		}else if(arr[i]>s.top()){
			while(!s.empty() && s.top()<arr[i]) s.pop();
			if(s.empty()) cout<<"-1"<<" ";
			else cout<<s.top()<<" ";
		}
		s.push(arr[i]);
	}
}
// -1 10 4 -1 -1 40 40

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

		preivousMax(arr,n);
		
	}
	return 0;
}