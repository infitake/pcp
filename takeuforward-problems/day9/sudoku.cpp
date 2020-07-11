// // A recursive program in C++ 
// // to solve Sudoku problem 
// #include <bits/stdc++.h> 
// using namespace std; 

// // UNASSIGNED is used for empty 
// // cells in sudoku grid 
// #define UNASSIGNED 0 

// // N is used for the size of Sudoku grid. 
// // Size will be NxN 
// #define N 9 

// // Checks whether it will be legal 
// // to assign num to the given row, col 
// bool isSafe(int grid[N][N]) 
// { 
// 	// Hashmap for row column and boxes 
// 	unordered_map<int, int> 
// 		row_[9], column_[9], box[3][3]; 
// 	for (int row = 0; row < N; row++) { 
// 		for (int col = 0; col < N; col++) { 
// 			// mark the element in row column and box 
// 			row_[row][grid[row][col]] += 1; 
// 			column_[col][grid[row][col]] += 1; 
// 			box[row / 3][col / 3][grid[row][col]] += 1; 

// 			// if an element is already 
// 			// present in the hashmap 
// 			if ( 
// 				box[row / 3][col / 3][grid[row][col]] > 1 
// 				|| column_[col][grid[row][col]] > 1 
// 				|| row_[row][grid[row][col]] > 1) 
// 				return false; 
// 		} 
// 	} 
// 	return true; 
// } 

// /* A utility function to print grid */
// void printGrid(int grid[N][N]) 
// { 
// 	for (int row = 0; row < N; row++) { 
// 		for (int col = 0; col < N; col++) 
// 			cout << grid[row][col] << " "; 
// 		cout << endl; 
// 	} 
// } 

// /* Takes a partially filled-in grid and attempts 
// to assign values to all unassigned locations in 
// such a way to meet the requirements for 
// Sudoku solution (non-duplication across rows, 
// columns, and boxes) */
// bool SolveSudoku( 
// 	int grid[N][N], int i, int j) 
// { 
// 	// if the index reached the end 
// 	if (i == N - 1 && j == N) { 
// 		// if the matrix is safe 
// 		if (isSafe(grid)) { 
// 			// print and stop 
// 			printGrid(grid); 
// 			return true; 
// 		} 

// 		// else try other cases 
// 		return false; 
// 	} 

// 	// end of a row move to next row 
// 	if (j == N) { 
// 		i++; 
// 		j = 0; 
// 	} 

// 	// if the element is non zero keep as it is 
// 	if (grid[i][j] != UNASSIGNED) 
// 		return SolveSudoku(grid, i, j + 1); 

// 	// consider digits 1 to 9 
// 	for (int num = 1; num <= 9; num++) { 
// 		// assign and call recursively 
// 		grid[i][j] = num; 

// 		if (SolveSudoku(grid, i, j + 1)) 
// 			return true; 

// 		grid[i][j] = 0; 
// 	} 
// 	return false; 
// } 

// // Driver Code 
// int main() 
// { 
// 	// 0 means unassigned cells 
// 	int grid[N][N] = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 }, 
// 					{ 5, 2, 9, 1, 3, 4, 7, 6, 8 }, 
// 					{ 4, 8, 7, 6, 2, 9, 5, 3, 1 }, 
// 					{ 2, 6, 3, 0, 1, 5, 9, 8, 7 }, 
// 					{ 9, 7, 4, 8, 6, 0, 1, 2, 5 }, 
// 					{ 8, 5, 1, 7, 9, 2, 6, 4, 3 }, 
// 					{ 1, 3, 8, 0, 4, 7, 2, 0, 6 }, 
// 					{ 6, 9, 2, 3, 5, 1, 8, 7, 4 }, 
// 					{ 7, 4, 5, 0, 8, 6, 3, 1, 0 } }; 
// 	if (SolveSudoku(grid, 0, 0) != true) 
// 		cout << "No solution exists"; 

// 	return 0; 
// } 

// // This is code is contributed by Arnab Kundu 


// int main() {
// 	#ifndef ONLINE_JUDGE
//     	freopen("input.txt", "r", stdin);
//     	freopen("output.txt", "w", stdout);
// 	#endif
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	//ios_base& scientific (ios_base& str);
// 	int t,n,a; cin>>t;
// 	while(t--){
// 		int arr[N][N];
// 		for(int i=0;i<N;i++){
// 			for(int j=0;j<N;j++){
// 				cin>>arr[i][j];
// 			}
// 		}
// 		if(!SolveSudoku(arr,0,0))
// 			cout<<"no solution";
// 	}
// 	return 0;
// }

// Method 2
// A Backtracking program in 
// C++ to solve Sudoku problem 
#include <bits/stdc++.h> 
using namespace std; 

// UNASSIGNED is used for empty 
// cells in sudoku grid 
#define UNASSIGNED 0 

// N is used for the size of Sudoku grid. 
// Size will be NxN 
#define N 9 

// This function finds an entry in grid 
// that is still unassigned 
bool FindUnassignedLocation(int grid[N][N], 
							int& row, int& col); 

// Checks whether it will be legal 
// to assign num to the given row, col 
bool isSafe(int grid[N][N], int row, 
			int col, int num); 

/* Takes a partially filled-in grid and attempts 
to assign values to all unassigned locations in 
such a way to meet the requirements for 
Sudoku solution (non-duplication across rows, 
columns, and boxes) */
bool SolveSudoku(int grid[N][N]) 
{ 
	int row, col; 

	// If there is no unassigned location, 
	// we are done 
	if (!FindUnassignedLocation(grid, row, col)) 
		// success! 
		return true; 

	// Consider digits 1 to 9 
	for (int num = 1; num <= 9; num++) { 
		// if looks promising 
		if (isSafe(grid, row, col, num)) { 
			// make tentative assignment 
			grid[row][col] = num; 

			// return, if success, yay! 
			if (SolveSudoku(grid)) 
				return true; 

			// failure, unmake & try again 
			grid[row][col] = UNASSIGNED; 
		} 
	} 
	// this triggers backtracking 
	return false; 
} 

/* Searches the grid to find an entry that is 
still unassigned. If found, the reference 
parameters row, col will be set the location 
that is unassigned, and true is returned. 
If no unassigned entries remain, false is returned. */
bool FindUnassignedLocation(int grid[N][N], 
							int& row, int& col) 
{ 
	for (row = 0; row < N; row++) 
		for (col = 0; col < N; col++) 
			if (grid[row][col] == UNASSIGNED) 
				return true; 
	return false; 
} 

/* Returns a boolean which indicates whether 
an assigned entry in the specified row matches 
the given number. */
bool UsedInRow(int grid[N][N], int row, int num) 
{ 
	for (int col = 0; col < N; col++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

/* Returns a boolean which indicates whether 
an assigned entry in the specified column 
matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num) 
{ 
	for (int row = 0; row < N; row++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

/* Returns a boolean which indicates whether 
an assigned entry within the specified 3x3 box 
matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, 
			int boxStartCol, int num) 
{ 
	for (int row = 0; row < 3; row++) 
		for (int col = 0; col < 3; col++) 
			if (grid[row + boxStartRow] 
					[col + boxStartCol] 
				== num) 
				return true; 
	return false; 
} 

/* Returns a boolean which indicates whether 
it will be legal to assign num to the given 
row, col location. */
bool isSafe(int grid[N][N], int row, 
			int col, int num) 
{ 
	/* Check if 'num' is not already placed in 
	current row, current column and current 3x3 box */
	return !UsedInRow(grid, row, num) 
		&& !UsedInCol(grid, col, num) 
		&& !UsedInBox(grid, row - row % 3, 
						col - col % 3, num) 
		&& grid[row][col] == UNASSIGNED; 
} 

/* A utility function to print grid */
void printGrid(int grid[N][N]) 
{ 
	for (int row = 0; row < N; row++) { 
		for (int col = 0; col < N; col++) 
			cout << grid[row][col] << " "; 
		cout << endl; 
	} 
} 

// Driver Code 
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
		int arr[N][N];
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin>>arr[i][j];
			}
		}
		if(SolveSudoku(arr)==true) printGrid(arr);
		else cout<<"no solution";
	}
	return 0;
}

// This is code is contributed by rathbhupendra 
