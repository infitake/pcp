#include <bits/stdc++.h>
using namespace std;

// Method 1: (make string of all the i and j index in which element are 0.)
void setZeroes(vector<vector<int>>& arr) {
        int n=arr.size();
        int m = arr[0].size();
        string str="";
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]==0) {
					if(i>=10 && i<=99){
						str += "ti"+to_string(i);
					}else if(i>=100 && i<=999){
						str += "di"+to_string(i);
					}else{
						str += to_string(i);
					}
					if(j>=10 && j<=99) {
						str += "tj"+to_string(j);
					}else if(j>=100 && j<=999) {
						str += "dj"+to_string(j);
					}else{
						str += to_string(j);
					}
				}
			}
		}
		int len = str.size(),k=0;
		// cout<<str<<endl;
		// for(int i=0;i<len;i++) cout<<str[i]<<" ";
		while(k<len){
			int l,r;
			if(str[k]=='t' && str[k+1]=='i'){
				k=k+2;
				l=(str[k]-'0')*10+(str[++k]-'0');

			}else if(str[k]=='d' && str[k+1]=='i'){
				k=k+2;
				l= (str[k]-'0')*100+(str[++k]-'0')*10+(str[++k]-'0');
			}else{
				l=str[k]-'0';	
			}
			++k;
			if(str[k]=='t' && str[k+1]=='j'){
				k=k+2;
				r=(str[k]-'0')*10+(str[++k]-'0');

			}else if(str[k]=='d' && str[k+1]=='j'){
				k=k+2;
				r= (str[k]-'0')*100+(str[++k]-'0')*10+(str[++k]-'0');
			}else{
				r=str[k]-'0';	
			}
			++k;
			// cout<<l<<" "<<r<<endl;
			for(int i=0;i<m;i++){
				arr[l][i]=0;
			}
			for(int i=0;i<n;i++){
				arr[i][r]=0;
			}
		}
    }
// complexity = O(n*m+k(n+m))

// Method 2: Brute O(1) space.
// Intuition

// In the above approach we use additional memory to keep a track of rows and columns which need to be set to zero. This additional use of space can be avoided by manipulating the original array instead.

// Algorithm
class Solution {
  public void setZeroes(int[][] matrix) {
    int MODIFIED = -1000000;
    int R = matrix.length;
    int C = matrix[0].length;

    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        if (matrix[r][c] == 0) {
          // We modify the corresponding rows and column elements in place.
          // Note, we only change the non zeroes to MODIFIED
          for (int k = 0; k < C; k++) {
            if (matrix[r][k] != 0) {
              matrix[r][k] = MODIFIED;
            }
          }
          for (int k = 0; k < R; k++) {
            if (matrix[k][c] != 0) {
              matrix[k][c] = MODIFIED;
            }
          }
        }
      }
    }

    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        // Make a second pass and change all MODIFIED elements to 0 """
        if (matrix[r][c] == MODIFIED) {
          matrix[r][c] = 0;
        }
      }
    }
  }
}

// Iterate over the original array and if we find an entry, say cell[i][j] to be 0, then we iterate over row i and column j separately and set all the non zero elements to some high negative dummy value (say -1000000). 
    // Note, choosing the right dummy value for your solution is dependent on the constraints of the problem. 
    // Any value outside the range of permissible values in the matrix will work as a dummy value.
// Finally, we iterate over the original matrix and if we find an entry to be equal to the high negative value (constant defined initially in the code as MODIFIED), then we set the value in the cell to 0.

// Complexity Analysis

// Time Complexity : O((M \times N) \times (M + N))O((M×N)×(M+N)) where M and N are the number of rows and columns respectively. Even though this solution avoids using space, but is very inefficient since in worst case 
    // for every cell we might have to zero out its corresponding row and column. Thus for all (M \times N)(M×N) cells zeroing out (M + N)(M+N) cells.
// Space Complexity : O(1)O(1)

// Method 3:O(1) Space, Efficient Solution
// Intuition

// The inefficiency in the second approach is that we might be repeatedly setting a row or column even if it was set to zero already. We can avoid this by postponing the step of setting a row or a column to zeroes.

// We can rather use the first cell of every row and column as a flag. This flag would determine whether a row or column has been set to zero. This means for every cell instead of going to M+NM+N cells and setting it to zero we just set the flag in two cells.

// if cell[i][j] == 0 {
//     cell[i][0] = 0
//     cell[0][j] = 0
// }
// These flags are used later to update the matrix. If the first cell of a row is set to zero this means the row should be marked zero. If the first cell of a column is set to zero this means the column should be marked zero.

// Algorithm
class Solution {
  public void setZeroes(int[][] matrix) {
    Boolean isCol = false;
    int R = matrix.length;
    int C = matrix[0].length;

    for (int i = 0; i < R; i++) {

      // Since first cell for both first row and first column is the same i.e. matrix[0][0]
      // We can use an additional variable for either the first row/column.
      // For this solution we are using an additional variable for the first column
      // and using matrix[0][0] for the first row.
      if (matrix[i][0] == 0) {
        isCol = true;
      }

      for (int j = 1; j < C; j++) {
        // If an element is zero, we set the first element of the corresponding row and column to 0
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    // Iterate over the array once again and using the first row and first column, update the elements.
    for (int i = 1; i < R; i++) {
      for (int j = 1; j < C; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    // See if the first row needs to be set to zero as well
    if (matrix[0][0] == 0) {
      for (int j = 0; j < C; j++) {
        matrix[0][j] = 0;
      }
    }

    // See if the first column needs to be set to zero as well
    if (isCol) {
      for (int i = 0; i < R; i++) {
        matrix[i][0] = 0;
      }
    }
  }
}

// We iterate over the matrix and we mark the first cell of a row i and first cell of a column j, if the condition in the pseudo code above is satisfied. i.e. if cell[i][j] == 0.

// The first cell of row and column for the first row and first column is the same i.e. cell[0][0]. Hence, we use an additional variable to tell us if the first column had been marked or not and the cell[0][0] would be used to tell the same for the first row.

// Now, we iterate over the original matrix starting from second row and second column i.e. matrix[1][1] onwards. For every cell we check if the row r or column c had been marked earlier by checking the respective first row cell or first column cell. 
// If any of them was marked, we set the value in the cell to 0. Note the first row and first column serve as the row_set and column_set that we used in the first approach.

// We then check if cell[0][0] == 0, if this is the case, we mark the first row as zero.

// And finally, we check if the first column was marked, we make all entries in it as zeros.

// Current
// 1 / 18
// In the above animation we iterate all the cells and mark the corresponding first row/column cell incase of a cell with zero value.


// We iterate the matrix we got from the above steps and mark respective cells zeroes.




// Complexity Analysis

// Time Complexity : O(M \times N)O(M×N)
// Space Complexity : O(1)
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,m; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<vector<int>> arr;
		for(int i=0;i<n;i++){
			vector<int> v;
			for(int j=0;j<m;j++){
				cin>>a;
				v.push_back(a);
			}
			arr.push_back(v);
		}
		setZeroes(arr);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		
	}
	return 0;
}