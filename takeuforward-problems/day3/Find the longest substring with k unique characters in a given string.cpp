#include <bits/stdc++.h>
using namespace std;

bool isvalid(int count[],int k){
	int u=0;
	for(int i=0;i<26;i++){
		if(count[i]!=0) u++;
		if(u>k) return false;
	}
	return true;
}

int kUnique(string str,int n,int k){
	int count[26],unique=0;
	memset(count,0,sizeof(count));
	for(int i=0;i<n;i++){
		if(count[str[i]-'a']==0) unique++;
		count[str[i]-'a']++;
	}
	if(unique<k) return -1;

	int start_u=0,end_u=0,max_window=INT_MIN;

	memset(count,0,sizeof(count));

	count[str[0]-'a']++;
	for(int i=1;i<n;i++){
		count[str[i]-'a']++;
		end_u++;
		if(!isvalid(count,k)){
			count[str[start_u]-'a']--;
			start_u++;
		}

		if((end_u-start_u +1)>max_window) max_window = (end_u-start_u+1);
	}
	return max_window;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,k; cin>>t;
	while(t--){
		string str;
		cin>>str>>k;
		int n = str.size();
		cout<<kUnique(str,n,k)<<endl;
	}
	return 0;
}