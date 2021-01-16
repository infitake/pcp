#include <bits/stdc++.h>
using namespace std;

// Check out this
// https://leetcode.com/problems/permutation-sequence/discuss/735287/Detailed-Explanation-with-Code-T(n2)


// Method 1:
string permutation(string &str,int n,int &k){
	    sort(str.begin(),str.end());
        do{
            if(k-- == 1){
                break;
            }
        }while(next_permutation(str.begin(),str.end()));
        return str;
 }

// Method 2:
 int factorial(int n, int out = 1)
    {
        if(n <= 1)
            return out;
        else
            return factorial(n-1, out*n);
    }
    
    string getPermutation(int n, int k)
    {
        k--;
        vector<int> out(n);
        for(int i = 1; i <= n; i++)
            out[i-1] = i;
        
        string answer = "";
        int size = n-1;
        while(k > 0)
        {
            int fact = factorial(size);
            int index = k / fact;
            
            answer += to_string(out[index]);
            out.erase(out.begin()+index);
            
            k -= fact * index;
            size--;
        }
        for(int i : out)
            answer += to_string(i);
        return answer;
    }

    // Method 3
    // Continually get the possible combinations for n-1, for example, if n = 3, the possible combination for 2 number is only 2. With that, we can use the modulo to get the desired index to be put in the string. 
    // Noted that the boundary condition occurs when the modulo return 0, which means the string is the last possible combination, under this condition the index to be put in the string is the last index.

  //   string getPermutation(int n, int k) {
  //       string ans;
  //       int total = 1; 
		// //initialize a bool vector for the possible indexs
  //       vector<bool> table(n); 
		// // first compute the (n-1)!
  //       for(int i = n-1; i > 0; total*=i, i--){}; 
		// // after every loop, divide total combination with i, that is equal to (n-1)!
  //       for(int i = n-1; i > 0; total /= i, i--){ 
		// 	// compute the index to be put in the string
  //           int start = k%(total) ? 1+ k/(total) : k/(total);
		// 	// b.c! set the index to the last possible index
  //           if(!start) start = n; 
  //           int it = 0, idx = 0; 
  //           while(idx < start){
		// 		// overlook the index that was already put in the string
  //               if(table[it] == false){ 
  //                   idx++;
  //               }
  //               it++;
  //           }
		// 	//turn the status of the index to be already put in the string
  //           table[it-1] = true;
		// 	//update k, using modulo
  //           k %= total; 
  //           ans += to_string(it);
  //           n--;
  //       }
		// //put the last possible index in the string 
  //       for(int i = 0; i < table.size(); i++){ // 
  //           if(!table[i]){
  //               ans += to_string(i+1);
  //               break;
  //           }
  //       }
  //       return ans;
  //   }

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,k; cin>>t;
	while(t--){
		cin>>n>>k;
		string str;
		for(int i=1;i<=n;i++){
			str += '0'+i;
		}
		cout<<permutation(str,n,k)<<endl;
	}
	return 0;
}

// // Efficient Method for this problem
// Efficient Approach: Mathematical concept for solving this problem.

// The total number of permutation of a string formed by N characters(all distinct) is N!
// The Total number of permutation of a string formed by N characters (where the frequency of character C1 is M1, C2 is M2… and so the frequency of character Ck is Mk) is N!/(M1! * M2! *….Mk!).
// The total number of permutation of a string formed by N characters(all distinct) after fixing the first character is (N-1)!
// The following steps can be followed to reach the solution.




// Count the frequencies of all characters in an array.
// Now from the first smallest character present in the string(smallest index i such that freq[i] > 0), compute the number of maximum permutation possible after setting that particular i-th character as the first character.
// If this sum value is more than given n, then set that character as the first result output character, and decrement freq[i]. Continue the same for the remaining n-1 characters.
// On the other hand, if the count is less than the required n, then iterate for the next character in the frequency table and update the count over and over again until we find a character that produces a count greater than the required n.
// C++ program to print 
// n-th permutation 
// #include <bits/stdc++.h> 
// using namespace std; 
  
// #define ll long long int 
  
// const int MAX_CHAR = 26; 
// const int MAX_FACT = 20; 
// ll fact[MAX_FACT]; 
  
// // Utility for calculating factorials 
// void precomputeFactorials() 
// { 
//     fact[0] = 1; 
//     for (int i = 1; i < MAX_FACT; i++) 
//         fact[i] = fact[i - 1] * i; 
// } 
  
// // Function for nth permutation 
// void nPermute(char str[], int n) 
// { 
//     precomputeFactorials(); 
  
//     // Length of given string 
//     int len = strlen(str); 
  
//     // Count frequencies of all 
//     // characters 
//     int freq[MAX_CHAR] = { 0 }; 
//     for (int i = 0; i < len; i++) 
//         freq[str[i] - 'a']++; 
  
//     // Out string for output string 
//     char out[MAX_CHAR]; 
  
//     // Iterate till sum equals n 
//     int sum = 0; 
//     int k = 0; 
  
//     // We update both n and sum in this 
//     // loop. 
//     while (sum != n) { 
  
//         sum = 0; 
//         // Check for characters present in freq[] 
//         for (int i = 0; i < MAX_CHAR; i++) { 
//             if (freq[i] == 0) 
//                 continue; 
  
//             // Remove character 
//             freq[i]--; 
  
//             // Calculate sum after fixing 
//             // a particuar char 
//             int xsum = fact[len - 1 - k]; 
//             for (int j = 0; j < MAX_CHAR; j++) 
//                 xsum /= fact[freq[j]]; 
//             sum += xsum; 
  
//             // if sum > n fix that char as 
//             // present char and update sum 
//             // and required nth after fixing 
//             // char at that position 
//             if (sum >= n) { 
//                 out[k++] = i + 'a'; 
//                 n -= (sum - xsum); 
//                 break; 
//             } 
  
//             // if sum < n, add character back 
//             if (sum < n) 
//                 freq[i]++; 
//         } 
//     } 
  
//     // if sum == n means this 
//     // char will provide its 
//     // greatest permutation 
//     // as nth permutation 
//     for (int i = MAX_CHAR - 1; 
//          k < len && i >= 0; i--) 
//         if (freq[i]) { 
//             out[k++] = i + 'a'; 
//             freq[i++]--; 
//         } 
  
//     // append string termination 
//     // character and print result 
//     out[k] = '\0'; 
//     cout << out; 
// } 
  
// // Driver program 
// int main() 
// { 
//     int n = 2; 
//     char str[] = "geeksquiz"; 
  
//     nPermute(str, n); 
//     return 0; 
// } 

// Complexity Analysis:

// Time Complexity: O(n), where n is the nth permutation.
// Space Complexity: O(n) where n is the space required to store the frequency.


