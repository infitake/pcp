#include <bits/stdc++.h>
using namespace std;
#define N 1000

// Algorithm:
// Let the given binary matrix be M[R][C]. The idea of the algorithm is to construct an auxiliary size matrix S[][] in which each entry S[i][j] represents size of the square sub-matrix with all 1s including M[i][j] where M[i][j] is the rightmost and bottommost entry in sub-matrix.

// 1) Construct a sum matrix S[R][C] for the given M[R][C].
//      a)    Copy first row and first columns as it is from M[][] to S[][]
//      b)    For other entries, use following expressions to construct S[][]
//          If M[i][j] is 1 then
//             S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
//          Else /*If M[i][j] is 0*/
//             S[i][j] = 0
// 2) Find the maximum entry in S[R][C]
// 3) Using the value and coordinates of maximum entry in S[i], print 
//    sub-matrix of M[][]
// For the given M[R][C] in above example, constructed S[R][C] would be:

//    0  1  1  0  1
//    1  1  0  1  0
//    0  1  1  1  0
//    1  1  2  2  0
//    1  2  2  3  1
//    0  0  0  0  0
// The value of maximum entry in above matrix is 3 and coordinates of the entry are (4, 3). Using the maximum value and its coordinates, we can find out the required sub-matrix.

int maxsquaresubmatrix(int arr[][N],int n,int m){
	int submatrix[n][m];
	// first we have to copy first row and column in submatrix;
	for(int i=0;i<m;i++) submatrix[0][i] = arr[0][i];
	for(int i=0;i<n;i++) submatrix[i][0] = arr[i][0];

	// now we just find the min of(i-1,j) (i-1,j-1) (i,j-1) and add one
	// we put this min value in submatrix

	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			submatrix[i][j]=min(min(arr[i-1][j],arr[i][j-1]),arr[i-1][j-1])+1;
		}
	}
	int maxval = 0,maxx=0,maxy=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(submatrix[i][j]>maxval){
				maxval = submatrix[i][j];
				maxx=i;
				maxy=j;
			}
		}
	}
	for(int i=maxx;i>(maxx-maxval);i--){
		for(int j=maxy;j>(maxy-maxval);j--){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return maxval;
}

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
		cout<<maxsquaresubmatrix(arr,n,m)<<endl;
		
	}
	return 0;
}