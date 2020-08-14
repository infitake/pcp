#include <bits/stdc++.h>
using namespace std;
#define N 1000

// Approach: In this post an interesting method is discussed that uses largest rectangle under histogram as a subroutine.
// If the height of bars of the histogram is given then the largest area of the histogram can be found. This way in each row, the largest area of bars of the histogram can be found. To get the largest rectangle full of 1’s, update the next row with the previous row and find the largest area under the histogram, i.e. consider each 1’s as filled squares and 0’s with an empty square and consider each row as the base.

// Illustration:

// Input :
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0
// Step 1: 
//     0 1 1 0  maximum area  = 2
// Step 2:
//     row 1  1 2 2 1  area = 4, maximum area becomes 4
//     row 2  2 3 3 2  area = 8, maximum area becomes 8
//     row 3  3 4 0 0  area = 6, maximum area remains 8
// Algorithm:




// Run a loop to traverse through the rows.
// Now If the current row is not the first row then update the row as follows, if matrix[i][j] is not zero then matrix[i][j] = matrix[i-1][j] + matrix[i][j].
// Find the maximum rectangular area under the histogram, consider the ith row as heights of bars of a histogram. This can be calculated as given in this article Largest Rectangular Area in a Histogram
// Do the previous two steps for all rows and print the maximum area of all the rows.


int maxhistogramarea(int arr[],int n) {
	int i=0;
	stack<int> stk;
	int maxval = 0;
	while(i<n){
		if(stk.empty() || arr[stk.top()]<=arr[i]) stk.push(i++);
		else{
			int ind = stk.top();
			stk.pop();
			int area =  arr[ind] * (stk.empty()?i:i-stk.top()-1);
			maxval = max(maxval,area);
		}
	}
	while(!stk.empty()){
		int ind = stk.top();
			stk.pop();
			int area =  arr[ind] * (stk.empty()?i:i-stk.top()-1);
			maxval = max(maxval,area);
	}
	return maxval;
}

int mxbinaryareamatrix(int arr[][N],int n,int m){
	int maxval = maxhistogramarea(arr[0],m);
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]!=0)
				arr[i][j] += arr[i-1][j];
		}

		maxval = max(maxval,maxhistogramarea(arr[i],m));
	}
	return maxval;
}

// Time Complexity: O(R x C).
// Only one traversal of the matrix is required, so the time complexity is O(R X C)
// Space Complexity: O(C).
// Stack is required to store the columns, so so space complexity is O(C)

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,m; cin>>t;
	while(t--){
		cin>>n>>m;
		int arr[N][N];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		cout<<mxbinaryareamatrix(arr,n,m)<<endl;
		
	}
	return 0;
}