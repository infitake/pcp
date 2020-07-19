#include <bits/stdc++.h>
using namespace std;
#define d 256

void naviasearch(string text,string pattern){
	int k = pattern.size();
	int n = text.size();
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			if(text[j+i] != pattern[j]){
				break;
			}
		}
		if(j == k) cout<<"index at "<<i<<endl;
	}
}
// we just create the hash and compare only the hash value
void rabinkarp(string text,string pattern){
	// this for module
	int m = 101;
	int thash =0,phash=0;

	int k = pattern.size();
	int n = text.size();
	int h=1;
	for(int i=0;i<k-1;i++)
		h = (d*h)%m;
	// hash for first k pattern and text

	for(int i=0;i<k;i++){
		thash = (d*thash + text[i])%m;
		phash = (d*phash + pattern[i])%m;
	}

	// cout<<thash<<" "<<phash<<endl;
	int i,j;
	for(i=0;i<=n-k;i++){
		if(thash == phash){
			for(j=0;j<k;j++){
				if(text[j+i] != pattern[j]){
					break;
				}
			}
			if(j == k) cout<<"index at "<<i<<endl;
		}
		if(i<(n-k)){
			thash = (d*(thash-text[i]*h) + text[i+k])%m;
			if(thash<0) thash += m;
		}
	}
}

void genratelcp(string pattern,int lcp[]){
	int m = pattern.size();
	lcp[0]=0;
	int i=1,len=0;
	while(i<m){
		if(pattern[i]==pattern[len]){
			len++;
			lcp[i]=len;
			i++;
		}else{
			if(len!=0) len = lcp[len-1];
			else{
				lcp[i]=0;i++;
			}
		}
	}
}

void kmpalgo(string text,string pattern){
	int m = pattern.size();
	int n = text.size();
	int lcp[m];
	genratelcp(pattern,lcp);
	int i=0,j=0;
	while(i<n){
		if(text[i] == pattern[j]){
			i++;j++;
		}
		if(j==m){
			cout<<"string at index "<<i-j<<endl;
			j=lcp[j-1];
		}else if(i<n && text[i] != pattern[j]){
			if(j!=0) j=lcp[j-1];
			else i++;
		}

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
	int t,n; cin>>t;
	while(t--){
		string text,pattern;
		cin>>text>>pattern;
		kmpalgo(text,pattern);
		// cout<<endl;
	}
	return 0;
}