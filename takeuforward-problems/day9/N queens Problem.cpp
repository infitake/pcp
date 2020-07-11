#include <bits/stdc++.h>
using namespace std;

// Method 1:
bool issafe(vector<vector<int>> &arr,int n,int row,int col){
	int i,j;
	for(i=0;i<n;i++) if(arr[row][i]) return false;
	for(i=0;i<n;i++) if(arr[i][col]) return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (arr[i][j]) 
            return false; 
    for (i = row, j = col; j >= 0 && i < n; i++, j--) 
        if (arr[i][j]) 
            return false; 
    for (i = row, j = col; i<n && j<n; i++, j++) 
        if (arr[i][j]) 
            return false; 
    for (i = row, j = col; i >= 0 && j < n; i--, j++) 
        if (arr[i][j]) 
            return false; 
    return true;
}

bool nqueenproblem(vector<vector<int>> &arr,int n,int row){
	if(row>=n) return true;
	for(int col=0;col<n;col++){
		if(issafe(arr,n,row,col)){
			arr[row][col]=1;
			if(nqueenproblem(arr,n,row+1)) return true;
			arr[row][col]=0;
		}
	}
	return false;
}

// Method2:Backtracking with efficiency
// bool solveNQUtil(int board[N][N], int col) 
// { 
//     /* base case: If all queens are placed 
//       then return true */
//     if (col >= N) 
//         return true; 
  
//     /* Consider this column and try placing 
//        this queen in all rows one by one */
//     for (int i = 0; i < N; i++) { 
//         /* Check if the queen can be placed on 
//           board[i][col] */
//         /* A check if a queen can be placed on  
//            board[row][col].We just need to check 
//            ld[row-col+n-1] and rd[row+coln] where 
//            ld and rd are for left and right  
//            diagonal respectively*/
//         if ((ld[i - col + N - 1] != 1 && 
//                   rd[i + col] != 1) && cl[i] != 1) { 
//              Place this queen in board[i][col] 
//             board[i][col] = 1; 
//             ld[i - col + N - 1] = 
//                           rd[i + col] = cl[i] = 1; 
  
//             /* recur to place rest of the queens */
//             if (solveNQUtil(board, col + 1)) 
//                 return true; 
  
//             /* If placing queen in board[i][col] 
//                doesn't lead to a solution, then 
//                remove queen from board[i][col] */
//             board[i][col] = 0; // BACKTRACK 
//             ld[i - col + N - 1] = 
//                          rd[i + col] = cl[i] = 0; 
//         } 
//     } 
  
//     /* If the queen cannot be placed in any row in 
//         this colum col  then return false */
//     return false; 
// } 

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
		vector<vector<int>> arr;
		for(int i=0;i<n;i++){
			vector<int> v;
			for(int j=0;j<n;j++){
				a=0;
				v.push_back(a);
			}
			arr.push_back(v);
		}
		cout<<nqueenproblem(arr,n,0)<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}