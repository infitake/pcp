#include <bits/stdc++.h>
using namespace std;

// using vector erase function
// void rmduplicate(vector<int> &arr){
// 	arr.erase(unique(arr.begin(),arr.end()),arr.end());
// 	for(auto x:arr) cout<<x<<" ";
// 	cout<<endl;
// 	cout<<arr.size()<<endl;
// }

// Method 2: using a set
// void rmduplicate(vector<int> arr){
// 	unordered_set<int> st;
// 	for(auto x:arr) st.insert(x);
// 	for(auto x:st) cout<<x<<" ";
// 	cout<<endl;
// 	cout<<st.size()<<endl;

// }
// Method 3: constant space
// void rmduplicate(vector<int> &arr){
// 	int n = arr.size();
  
//     // To store index of next unique element 
//     int j = 0; 
  
//     // Doing same as done in Method 1 
//     // Just maintaining another updated index i.. j 
//     for (int i=0; i < n-1; i++) 
//         if (arr[i] != arr[i+1]) 
//             arr[j++] = arr[i]; 
  
//     arr[j++] = arr[n-1]; 
//     for(int i=0;i<j;i++) cout<<arr[i]<<" ";
// 	cout<<endl;
// 	cout<<j<<endl;
  
// } 

// This is take 2 duplicate and rm remaining
// this is second part of rm duplicte|| on leetcode
void rmduplicate(vector<int> &arr){
	if ( arr.empty() ) return 0;
        int n = arr.size();
	    int j=0,count=1,prev;
        arr[j++]=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i-1] == arr[i]){
                if(count==2) continue;
                arr[j++]=arr[i];
                count++;
                // prev=arr[i];
            }else{
                arr[j++]=arr[i];
                count=1;
            }
        }
        // if(arr[n-1]!=arr[n-2]) arr[j++]=arr[n-1];
        // if(arr[n-1]==arr[n-2] && count<2) arr[j++]=arr[n-1];
    for(int i=0;i<j;i++) cout<<arr[i]<<" ";
	cout<<endl;
	cout<<j<<endl;
  
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
		rmduplicate(arr);
	}
	return 0;
}