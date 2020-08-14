// Given two sequences A and B(target). Count the number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.
// Subsequence: A subsequence of a string is a new string which is formed from the original string by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters.
// E.g. “ABE” is subsequence of string “ABCDE”, while “AED” is not a subsequence of “ABCDE”.
// Let say we have two arguments, A and B as “rabbbit” and “rabbit” respectively.
// Number of ways in which we an get B from A are:
// a) “ra_bbit” (Removing first b at index 2)
// b) “rab_bit” (Removing second b at index 3)
// c) “rabb_it” (Removing third b at index 4)
// So there are 3 ways in which we can get “rabbit” from “rabbbit”.
// Click here to try this problem with your approach.
// Approach
// Let’s consider a state of problem where we are dealing of substrings of A[0..i-1] and B[0..j-1], say distinctSubsequence(i, j). We need to keep in mind that B is fixed subsequence and A the longer subsequence from which we want to derive B.
// We now check whether we can derive the solution of current state from the solution of previous states.
// There are two cases for this problem:
// Case 1: When A[i-1] != B[j-1]
// Here, when current character of A is not equal to current character of B, we will not be able to increase the number of distinct subsequences. So this situation is same as the situation when we were at A[i-2]. So,
// distinctSubsequence(i, j) = distinctSubsequence(i-1, j)
// Case II: When A[i-1] == B[j]
// In case when current character of A and B are same, we can visualise this subproblem consisting of two cases again:
// 1) We don’t match the current two characters, which means that it still has original number of distinct subsequences, So
// distinctSubsequence(i, j) = distinctSubsequence(i-1, j)
// 2) We match both current characters. So in this way:
// distinctSubsequence(i, j) = distinctSubsequence(i-1, j-1)
// So including both the cases,
// distinctSubsequence(i, j) = distinctSubsequence(i-1, j) + distinctSubsequence(i-1, j-1)
// Edge Cases
// If both A and B are empty, we will return 1 because the empty string is also the subsequence of empty string.
// If A is empty and B is not empty, we will return 0 because the non-empty string cannot be subsequence of empty string.
// If A is not empty and B is empty, then we will again return 1, because the empty string is also a subsequence of any string.
// Code
// Recursive Code
int numDistinctUtil(string S, string T, int i, int j) { 
  if (i < 0 || j < 0 || i < j) 
    return 0; 
 
  if (S[i]==T[j]) { 
    if (j == 0) 
      return numDistinctUtil(S, T, i-1, j) + 1; 
    else {
      return numDistinctUtil(S, T, i-1, j) +         numDistinctUtil(S, T, i-1, j-1);
    }      
  } 
  return numDistinctUtil(S, T, i-1, j); 
}
int Solution::numDistinct(string A, string B) {
 return numDistinctUtil(A, B, A.length()-1, B.length()-1); 
}
// Above recursive code is inefficient and it will give TLE every time, as it’s time complexity is exponential.
// From above code we can see that the problem of current state is derivable from it’s previous state, so it has optimal substructure property. Also, when we build the recursive tree, we will see the subproblems are solved repeatedly, so it has overlapping subproblems property.
// Since this problem has both optimal substructure an overlapping subproblems property, We can solve this using dynamic programming approach.
// Dynamic Programming — Top Down Approach (Using memoization)
int numDistinctUtil(vector<vector<int>> &memo, int i, int j, const string A, const string B) {
  
  if(memo[i][j] != -1) {
    return memo[i][j];
  }
  // B has no more characters left, so solution will be 1
  if(j == 0) { memo[i][j] = 1; }
  // If A has no more characters left but B still has characters,
  // solution will be 0
  else if(i == 0) { memo[i][j] = 0; }
    
  else {
    // Solution getting from previous state, i.e. 
    // ignoring current   character of A
    
    int soln1 = numDistinctUtil(memo, i - 1, j, A, B);
    int soln2 = 0;
    
    // Case when characters are same
    if(A[i-1] == B[j-1]) { soln2 = numDistinctUtil(memo, i-1, j-1, A, B); }
    
    memo[i][j] = soln1 + soln2;
  }
  return memo[i][j];
}
int Solution::numDistinct(string A, string B) {
  int n = A.size();
  int m = B.size();
  if(n < m)   
    return 0;
  vector<vector<int>> memo(n + 1, vector<int> (m + 1, -1));
  return numDistinctUtil(memo, n, m, A, B);
}
Dynamic Programming — Bottom Up Approach (Using tabulation)
int Solution::numDistinct(string A, string B) {
  int m = A.length();
  int n = B.length();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  // filling the first row: with 1s
  for (int j = 0; j <= m; ++j) 
    dp[0][j] = 1;
  
  // the first column is 0 by default in every other rows 
  // except first row.
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int soln1 = dp[i][j-1];
      int soln2 = 0;
      if(B[i - 1] == A[j - 1]) {
        soln2 = dp[i - 1][j - 1];
      }
      dp[i][j] = soln2 + soln1;
    }
  }
  return dp[n][m];
}
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
// Catch
// We can observe from above approaches that in the inner loop, we only consider values of the previous iteration, i.e. the values in the previous row of the dp/memo matrix. Therefore, to optimise the space complexity of algorithm, we could use by keeping only two arrays, instead of the entire matrix. Following is the algorithm using two arrays only:
// Dynamic Programming — Space Optimised Version (Using 2 arrays)
int Solution::numDistinct(string A, string B) {
  int n = A.length();
  int m = B.length();
vector<int> prevRowVal(n+1);
  vector<int> curRowVal(n+1);
  
  for(int i = 0; i <= n; i++)
    prevRowVal[i] = 1;  
  
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      if(B[i-1] != A[j-1]) {
        curRowVal[j] = curRowVal[j-1];
      } else {
        curRowVal[j] = curRowVal[j-1] + prevRowVal[j-1];
      }
    }
    for(int i = 0; i <= n; ++i) {
      prevRowVal[i] = curRowVal[i];
    }
  }
  return curRowVal[n];
}
// Time Complexity: O(m*n)
// Space Complexity: O(n)
// Catch once again !!!
// According to further analysis of above algorithm, we could reduce the space to one array.
// When we set prevRowVal[i] = curRowVal[i], we do not set the value again, so we should remove the usage of prevRowVal[] also.
// Trickiest part here is that in the inner iteration (with “j” as the iterator), we should do the reverse order (i.e. from the end index to the beginning). Think why? Otherwise, the result would not be correct !!!
// Here comes the further optimised solution using one array only. :)
// Dynamic Programming — Space Optimised Version (Using 1 array)
int Solution::numDistinct(string A, string B) {
  int n = A.length();
  int m = B.length();
  vector<int> dp(m+1);
  dp[0] = 1;
  
  for(int i = 1; i <= n; i++) {
    for(int j = m; j >= 1; j--) {
      if(A[i-1] == B[j-1])
        dp[j] += dp[j-1];
    }
  }
  return dp[m];
}
// Time Complexity: O(m*n)
// Space Complexity: O(m)