#include <bits/stdc++.h>
using namespace std;

// this is for all cases
// int lis(string str){
// 	int n = str.size();
// 	int dp[n];
// 	memset(dp,0,sizeof(dp));
// 	dp[0]=1;
// 	// for(int i=0;i<n;i++) cout<<(str[i]-'a')<<" ";
// 	for(int i=1;i<n;i++){
// 		dp[i]=1;
// 		for(int j = 0;j<i;j++){
// 			if(((str[i]-'a'+1)%26)>((str[j]-'a'+1)%26) && dp[i] < dp[j]+1)
// 				dp[i] = dp[j]+1;
// 		}
// 	}
// 	sort(dp,dp+n);
// 	return dp[n-1];
// }

// this is only for consective
int lis(string str){
	int n = str.size();
	int maxlen=INT_MIN;
	int count=1;
	for(int i=1;i<n;i++){
		if(((str[i]-'a'+1)%26)>((str[i-1]-'a'+1)%26)){
			count++;
		}else{
			maxlen = max(maxlen,count);
			count=1;
		}
	}
	maxlen = max(maxlen,count);
	return maxlen;
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
		string str;
		cin>>str;
		cout<<lis(str)<<endl;
		
	}
	return 0;
}