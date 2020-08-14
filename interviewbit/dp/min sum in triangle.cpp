Minimum Sum Path in a Triangle
Given a triangular structure of numbers, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

Examples :

Input : 
   2
  3 7
 8 5 6
6 1 9 3
Output : 11
Explanation : 2 + 3 + 5 + 1 = 11

Input :
   3
  6 4
 5 2 7
9 1 8 6
Output : 10
Explanation : 3 + 4 + 2 + 1 = 10
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Naive Approach : Going through the Naive approach by traversing every possible path. But, this is costly. So, use Dynamic Programming here in order to reduce the time complexity.

There are two ways to reach the solution :
1. Memoization – Starting from the top node, traverse recursively with each node, till the pathsum of that node is calculated. And then store the result in an array. But this will take O(N^2) space to maintain the array.




2. Bottom up – Start from the nodes on the bottom row; the min pathsum for these nodes are the values of the nodes themselves. And after that, minimum pathsum at the ith node of kth row would be the minimum of the pathsum of its two children + the node’s value, i.e.:

memo[k][i] = min( memo[k+1][i], memo[k+1][i+1]) + A[k][i];
OR
Simply set memo as a 1D array, and update it
this will be space efficient also :

For the row k :

memo[i] = min( memo[i], memo[i+1]) + A[k][i];
Below is the implementation of above dynamic programming approach :
filter_none
edit
play_arrow

brightness_4
// C++ program for Dynamic 
// Programming implementation of 
// Min Sum Path in a Triangle 
#include <bits/stdc++.h> 
using namespace std; 
  
// Util function to find minimum sum for a path 
int minSumPath(vector<vector<int> >& A) 
{ 
    // For storing the result in a 1-D array, 
    // and simultaneously updating the result. 
    int memo[A.size()]; 
    int n = A.size() - 1; 
  
    // For the bottom row 
    for (int i = 0; i < A[n].size(); i++)  
        memo[i] = A[n][i];     
  
    // Calculation of the remaining rows, 
    // in bottom up manner. 
    for (int i = A.size() - 2; i >= 0; i--)  
        for (int j = 0; j < A[i].size(); j++)  
            memo[j] = A[i][j] + min(memo[j], 
                                    memo[j + 1]); 
  
    // return the top element 
    return memo[0]; 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    vector<vector<int> > A{ { 2 }, 
                            { 3, 9 }, 
                            { 1, 6, 7 } }; 
    cout << minSumPath(A); 
    return 0; 
} 
Output:
6