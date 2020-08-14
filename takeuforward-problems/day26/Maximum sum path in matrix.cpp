// CPP prorgam for finding max path in matrix 
#include <bits/stdc++.h> 
#define N 4 
#define M 6 
using namespace std; 

// To calculate max path in matrix 
int findMaxPath(int mat[][M]) 
{ 

	for (int i = 1; i < N; i++) { 
		for (int j = 0; j < M; j++) { 

			// When all paths are possible 
			if (j > 0 && j < M - 1) 
				mat[i][j] += max(mat[i - 1][j], 
							max(mat[i - 1][j - 1], 
							mat[i - 1][j + 1])); 

			// When diagonal right is not possible 
			else if (j > 0) 
				mat[i][j] += max(mat[i - 1][j], 
							mat[i - 1][j - 1]); 

			// When diagonal left is not possible 
			else if (j < M - 1) 
				mat[i][j] += max(mat[i - 1][j], 
							mat[i - 1][j + 1]); 

			// Store max path sum 
		} 
	} 
	int res = 0; 
	for (int j = 0; j < M; j++) 
		res = max(mat[N-1][j], res); 
	return res; 
} 

// Driver program to check findMaxPath 
int main() 
{ 
	
	int mat1[N][M] = { { 10, 10, 2, 0, 20, 4 }, 
					{ 1, 0, 0, 30, 2, 5 }, 
					{ 0, 10, 4, 0, 2, 0 }, 
					{ 1, 0, 2, 20, 0, 4 } }; 
			
	cout << findMaxPath(mat1) << endl; 
	return 0; 
} 


// C++ implementation to find the maximum sum 
// path in a matrix 
#include <bits/stdc++.h> 
using namespace std; 

#define SIZE 10 

// function to find the maximum sum 
// path in a matric 
int maxSum(int mat[SIZE][SIZE], int n) 
{ 
	// if there is a single element only 
	if (n == 1) 
		return mat[0][0]; 

	// dp[][] matrix to store the results 
	// of each iteration 
	int dp[n][n]; 
	int maxSum = INT_MIN, max; 

	// base case, copying elements of 
	// last row 
	for (int j = 0; j < n; j++) 
		dp[n - 1][j] = mat[n - 1][j]; 

	// building up the dp[][] matrix from 
	// bottom to the top row 
	for (int i = n - 2; i >= 0; i--) { 
		for (int j = 0; j < n; j++) { 
			max = INT_MIN; 

			// finding the maximum diagonal element in the 
			// (i+1)th row if that cell exists 
			if (((j - 1) >= 0) && (max < dp[i + 1][j - 1])) 
				max = dp[i + 1][j - 1]; 
			if (((j + 1) < n) && (max < dp[i + 1][j + 1])) 
				max = dp[i + 1][j + 1]; 

			// adding that 'max' element to the 
			// mat[i][j] element 
			dp[i][j] = mat[i][j] + max; 
		} 
	} 

	// finding the maximum value from the 
	// first row of dp[][] 
	for (int j = 0; j < n; j++) 
		if (maxSum < dp[0][j]) 
			maxSum = dp[0][j]; 

	// required maximum sum 
	return maxSum; 
} 

// Driver program to test above 
int main() 
{ 
	int mat[SIZE][SIZE] = { { 5, 6, 1, 7 }, 
							{ -2, 10, 8, -1 }, 
							{ 3, -7, -9, 11 }, 
							{ 12, -4, 2, 6 } }; 
	int n = 4; 

	cout << "Maximum Sum = "
		<< maxSum(mat, n); 

	return 0; 
} 

#include <bits/stdc++.h> 
using namespace std; 
#define N 100 

// No of rows and columns 
int n, m; 

// Declaring the matrix of maximum 
// 100 rows and 100 columns 
int a[N][N]; 

// Variable visited is used to keep 
// track of all the visited positions 
// Variable dp is used to store 
// maximum sum till current position 
vector<vector<int> > dp(N, vector<int>(N)), 
	visited(N, vector<int>(N)); 

// For storing current sum 
int current_sum = 0; 

// For continuous update of 
// maximum sum required 
int total_sum = 0; 

// Function to Input the matrix of size n*m 
void inputMatrix() 
{ 
	n = 3; 
	m = 3; 
	a[0][0] = 500; 
	a[0][1] = 100; 
	a[0][2] = 230; 
	a[1][0] = 1000; 
	a[1][1] = 300; 
	a[1][2] = 100; 
	a[2][0] = 200; 
	a[2][1] = 1000; 
	a[2][2] = 200; 
} 

// Function to calculate maximum sum of path 
int maximum_sum_path(int i, int j) 
{ 
	// Checking boundary condition 
	if (i == n - 1 && j == m - 1) 
		return a[i][j]; 

	// Checking whether or not (i, j) is visited 
	if (visited[i][j]) 
		return dp[i][j]; 

	// Marking (i, j) is visited 
	visited[i][j] = 1; 

	// Updating the maximum sum till 
	// the current position in the dp 
	int& total_sum = dp[i][j]; 

	// Checking whether the position hasn't 
	// visited the last row or the last column. 
	// Making recursive call for all the possible 
	// moves from the current cell and then adding the 
	// maximum returned by the calls and updating it. 
	if (i < n - 1 & j < m - 1) { 
		int current_sum = max(maximum_sum_path(i, j + 1), 
							max( 
								maximum_sum_path(i + 1, j + 1), 
								maximum_sum_path(i + 1, j))); 
		total_sum = a[i][j] + current_sum; 
	} 

	// Checking whether 
	// position has reached last row 
	else if (i == n - 1) 
		total_sum = a[i][j] 
					+ maximum_sum_path(i, j + 1); 

	// If the position is in the last column 
	else
		total_sum = a[i][j] 
					+ maximum_sum_path(i + 1, j); 

	// Returning the updated maximum value 
	return total_sum; 
} 

// Driver Code 
int main() 
{ 
	inputMatrix(); 

	// Calling the implemented function 
	int maximum_sum = maximum_sum_path(0, 0); 

	cout << maximum_sum; 
	return 0; 
} 
