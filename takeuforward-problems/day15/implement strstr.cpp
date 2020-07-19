#include <bits/stdc++.h>
using namespace std;

int implementstrstr(string str1,string str2){
	if(str2.size()==0) return 0;
	int start=-1,j=0;
	int n=str1.size(),m=str2.size();
	for(int i=0;i<n;i++){
		if(j==m) break;
		if(str1[i]==str2[j]){
			if(j==0) start=i;
			j++;
		}else if(j>0 && str1[i] != str2[j]){
			j=0;
			i=start;
			start=-1;
		}
	}
	if(j!=m) start = -1; 
	return start;
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
	string str1,str2;
	while(t--){
		cin>>str1>>str2;

		cout<<implementstrstr(str1,str2)<<endl;
		
	}
	return 0;
}