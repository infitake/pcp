#include <bits/stdc++.h>
using namespace std;

// int distance(int x1, int y1, int x2, int y2) { 
//     int dx ,dy;
//     dx = abs(x2-x1);
//     dy = abs(y2-y1);
//     return max(dx,dy);
// } 
// int coverPoints(vector<int> &arr1, vector<int> &arr2) {
//     int n = arr1.size(),count=0;
//     for(int i=0;i<n-1;i++){
//         count+=distance(arr1[i],arr2[i],arr1[i+1],arr2[i+1]);
//     }
//     return count;
// }
vector<int> plusOne(vector<int> &arr) {
    int n = arr.size();
    string num = "";
    int k,carry=0;
    reverse(arr.begin(),arr.end());
    k=arr[0];
    k++;
    if(k>=10){
    	carry = 1;
    }
    arr[0]=k%10;
    for(int i=1;i<n;i++){
    	if(carry == 1){
    		arr[i]++;
    		if(arr[i]>=10){
    			carry = 1;
	    	}else{
	    		carry=0;
	    		break;
	    	}
	    	arr[i]=k%10;
    	}else{
    		carry=0;
    		break;
    	}
    }
    if(carry==1){
    	arr.push_back(1);
    }
    n = arr.size();
    // if(arr[n-1] == 0) arr.pop_back();
    int h = n-1;
    while(arr[h]==0){
    	arr.pop_back();
    	h--;
    }
    reverse(arr.begin(),arr.end());
    return arr;

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
		vector<int> arr1,arr2;
		for(int i=0;i<n;i++){
			cin>>a;
			arr1.push_back(a);
		}
		// for(int i=0;i<n;i++){
		// 	cin>>a;
		// 	arr2.push_back(a);
		// }
		// cout<<plusOne(arr1)<<endl;
		arr2 = plusOne(arr1);
		for(auto x:arr2) cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}