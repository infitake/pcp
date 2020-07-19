#include <bits/stdc++.h>
using namespace std;

void powset(string str,int n){
	int powsetcount = pow(2,n);

	for(int i=0;i<powsetcount;i++){
		for(int j=0;j<n;j++){
			if(i & (1<<j)) cout<<str[j];
		}
		cout<<endl;
	}
}

// Method 2:
// The idea is to consider two cases for every character. 
// (i) Consider current character as part of current subset 
// (ii) Do not consider current character as part of current subset.

void powerset(string str,int n,int i,string curr){
	if(n==i){
		cout<<curr<<endl;
		return;
	}
	powerset(str,n,i+1,curr+str[i]);
	powerset(str,n,i+1,curr);
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
		string str;
		cin>>str;
		// powset(str,n);
		powerset(str,n,0,"");
	}
	return 0;
}