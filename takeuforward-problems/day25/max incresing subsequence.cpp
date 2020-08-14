#include <bits/stdc++.h>
using namespace std;
// this is same as kadane'algo but different in when 2 -ve value are come the product is +ve

int maxincresingsequence(vector<int> &arr,int n){
    int lis[n]={0};
    lis[0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    sort(lis,lis+n);
    return lis[n-1];
}
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
		cout<<maxincresingsequence(arr,n)<<endl;
	}
	return 0;
}

// method 2
#include <iostream> 
#include <vector> 

// Binary search (note boundaries in the caller) 
int CeilIndex(std::vector<int>& v, int l, int r, int key) 
{ 
	while (r - l > 1) { 
		int m = l + (r - l) / 2; 
		if (v[m] >= key) 
			r = m; 
		else
			l = m; 
	} 

	return r; 
} 

int LongestIncreasingSubsequenceLength(std::vector<int>& v) 
{ 
	if (v.size() == 0) 
		return 0; 

	std::vector<int> tail(v.size(), 0); 
	int length = 1; // always points empty slot in tail 

	tail[0] = v[0]; 
	for (size_t i = 1; i < v.size(); i++) { 

		// new smallest value 
		if (v[i] < tail[0]) 
			tail[0] = v[i]; 

		// v[i] extends largest subsequence 
		else if (v[i] > tail[length - 1]) 
			tail[length++] = v[i]; 

		// v[i] will become end candidate of an existing 
		// subsequence or Throw away larger elements in all 
		// LIS, to make room for upcoming grater elements 
		// than v[i] (and also, v[i] would have already 
		// appeared in one of LIS, identify the location 
		// and replace it) 
		else
			tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
	} 

	return length; 
} 

int main() 
{ 
	std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 }; 
	std::cout << "Length of Longest Increasing Subsequence is "
			<< LongestIncreasingSubsequenceLength(v) << '\n'; 
	return 0; 
} 
