#include <bits/stdc++.h>
using namespace std;

// Method 1:(using stl function)
void permutation(string str){
	bool val = next_permutation(str.begin(),str.end());
		if(val == false) cout<<"not exists"<<endl;
		else cout<<str<<endl;
}

// Method 2:
// . The idea is based on the following facts:
// 1) An sequence sorted in descending order does not have next permutation. For example edcba” does not have next permutation.
// 2) For a sequence which is not sorted in descending order for example “abedc”, we can follow below steps.
// ……….a) Traverse from right and find the first item that is not following the descending order. For example in “abedc”, the character ‘b’ does not follow the descending order.
// ……….b) Swap the found character with closest greater (or smallest greater) element on right side of it. In case of “abedc”, we have ‘c’ as the closest greater element. After swapping ‘b’ and ‘c’, string becomes “acedb”.
// ……….c) After swapping, sort the string after the position of character found in step a. After sorting the substring “edb” of “acedb”, we get “acbde” which is the required next permutation.

// Optimizations in step b) and c)
// a) Since the sequence is sorted in decreasing order, we can use binary search to find the closest greater element.
// c) Since the sequence is already sorted in decreasing order (even after swapping as we swapped with the closest greater), we can get the sequence sorted (in increasing order) after reversing it.
void swap(char* a, char* b) 
{ 
    if (*a == *b) 
        return; 
    *a ^= *b; 
    *b ^= *a; 
    *a ^= *b; 
} 
void rev(string& s, int l, int r) 
{ 
    while (l < r) 
        swap(&s[l++], &s[r--]); 
} 
  
int bsearch(string str,int l,int r,int key){
	int index=-1;
	while(l<=r){
		int mid = l+(r-l)/2;
		if(str[mid]<=key){
			r=mid-1;
		}else{
			l=mid+1;
			if(index == -1 || str[index]>=str[mid])
				index = mid;
		}
	}
	return index;
}

void permutation(string str){
	int l = str.size(),i=l-2;
	while(i>=0 && str[i]>str[i+1])
		i--;
	if(i<0) cout<<"nahi mile";
	else{
		int index = bsearch(str,i+1,l-1,str[i]);
		swap(&str[i],&str[index]);
		rev(str,i+1,l-1);
	}
	cout<<str;
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
	string str;
	// permutation(str);
	while(t--){
		cin>>str;
		permutation(str);
		cout<<endl;
	}
	return 0;
}