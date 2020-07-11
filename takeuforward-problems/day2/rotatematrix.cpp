#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N 101

// Method 1:
// Algorithm:

// To solve the given problem there are two tasks. 1st is finding the transpose and second is reversing the columns without using extra space
// A transpose of a matrix is when the matrix is flipped over its diagonal, i.e the row index of an element becomes the column index and vice versa.
// So to find the transpose interchange the elements at position (i, j) with (j, i).
// Run two loops, the outer loop from 0 to row count and inner loop from 0 to index of the outer loop.
// To reverse the column of the transposed matrix, run two nested loops, the outer loop from 0 to column count and inner loop from 0 to row count/2, 
// interchange elements at (i, j) with (i, row[count-1-j]), where i and j are indices of inner and outer loop respectively.
void transpose(int arr[N][N],ll n){
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			swap(arr[i][j],arr[j][i]);
		}
	}
}
void reverse(int arr[N][N],int n) {
	for(int i=0;i<n;i++){
		int l=0,r=n-1;
		while(l<r){
			swap(arr[l][i],arr[r][i]);
			l++;r--;
		}
	}
}
void printmat(int arr[N][N],ll n){
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

void rotatematrix(int arr[N][N],ll n){
	transpose(arr,n);
	reverse(arr,n);
	printmat(arr,n);
}

// Method 2:
// Approach: To solve the question without any extra space, rotate the array in form of squares, dividing the matrix into squares or cycles. For example,
// A 4 X 4 matrix will have 2 cycles. The first cycle is formed by its 1st row, last column, last row and 1st column. The second cycle is formed by 2nd row, 
// second-last column, second-last row and 2nd column. The idea is for each square cycle, swap the elements involved with the corresponding cell in the matrix in anti-clockwise direction i.e. 
// from top to left, left to bottom, bottom to right and from right to top one at a time using nothing but a temporary variable to achieve this.

// Demonstration:

// First Cycle (Involves Red Elements)
//  1  2  3 4 
//  5  6  7 8 
//  9 10 11 12 
//  13 14 15 16 

// Moving first group of four elements (First
// elements of 1st row, last row, 1st column 
// and last column) of first cycle in counter
// clockwise. 
//  4  2  3 16
//  5  6  7 8 
//  9 10 11 12 
//  1 14  15 13 
 
// Moving next group of four elements of 
// first cycle in counter clockwise 
//  4  8  3 16 
//  5  6  7  15  
//  2  10 11 12 
//  1  14  9 13 

// Moving final group of four elements of 
// first cycle in counter clockwise 
//  4  8 12 16 
//  3  6  7 15 
//  2 10 11 14 
//  1  5  9 13 


// Second Cycle (Involves Blue Elements)
//  4  8 12 16 
//  3  6 7  15 
//  2  10 11 14 
//  1  5  9 13 

// Fixing second cycle
//  4  8 12 16 
//  3  7 11 15 
//  2  6 10 14 
//  1  5  9 13
// Algorithm:

// There is N/2 squares or cycles in a matrix of side N. Process a square one at a time. Run a loop to traverse the matrix a cycle at a time, 
// i.e loop from 0 to N/2 – 1, loop counter is i
// Consider elements in group of 4 in current square, rotate the 4 elements at a time. So the number of such groups in a cycle is N – 2*i.
// So run a loop in each cycle from x to N – x – 1, loop counter is y
// The elements in the current group is (x, y), (y, N-1-x), (N-1-x, N-1-y), (N-1-y, x), now rotate the these 4 elements, 
// i.e (x, y) <- (y, N-1-x), (y, N-1-x)<- (N-1-x, N-1-y), (N-1-x, N-1-y)<- (N-1-y, x), (N-1-y, x)<- (x, y)
// Print the matrix.
// filter_none
void rotateMatrix(int mat[][N]) 
{ 
    // Consider all squares one by one 
    for (int x = 0; x < N / 2; x++) { 
        // Consider elements in group 
        // of 4 in current square 
        for (int y = x; y < N - x - 1; y++) { 
            // Store current cell in 
            // temp variable 
            int temp = mat[x][y]; 
  
            // Move values from right to top 
            mat[x][y] = mat[y][N - 1 - x]; 
  
            // Move values from bottom to right 
            mat[y][N - 1 - x] 
                = mat[N - 1 - x][N - 1 - y]; 
  
            // Move values from left to bottom 
            mat[N - 1 - x][N - 1 - y] 
                = mat[N - 1 - y][x]; 
  
            // Assign temp to left 
            mat[N - 1 - y][x] = temp; 
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
	int t,n,a; cin>>t;
	while(t--){
		cin>>n;
		int arr[N][N];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		} 
		rotatematrix(arr,n);

		cout<<endl;
	}
	return 0;
}