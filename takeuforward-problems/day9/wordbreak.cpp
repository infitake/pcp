// A recursive program to print all possible 
// partitions of a given string into dictionary 
// words 
#include <iostream> 
using namespace std; 

/* A utility function to check whether a word 
is present in dictionary or not. An array of 
strings is used for dictionary. Using array 
of strings for dictionary is definitely not 
a good idea. We have used for simplicity of 
the program*/
int dictionaryContains(string &word) 
{ 
	string dictionary[] = {"mobile","samsung","sam","sung", 
							"man","mango", "icecream","and", 
							"go","i","love","ice","cream"}; 
	int n = sizeof(dictionary)/sizeof(dictionary[0]); 
	for (int i = 0; i < n; i++) 
		if (dictionary[i].compare(word) == 0) 
			return true; 
	return false; 
} 

//prototype of wordBreakUtil 
void wordBreakUtil(string str, int size, string result); 

// Prints all possible word breaks of given string 
void wordBreak(string str) 
{ 
	// last argument is prefix 
	wordBreakUtil(str, str.size(), ""); 
} 

// result store the current prefix with spaces 
// between words 
void wordBreakUtil(string str, int n, string result) 
{ 
	//Process all prefixes one by one 
	for (int i=1; i<=n; i++) 
	{ 
		//extract substring from 0 to i in prefix 
		string prefix = str.substr(0, i); 

		// if dictionary conatins this prefix, then 
		// we check for remaining string. Otherwise 
		// we ignore this prefix (there is no else for 
		// this if) and try next 
		if (dictionaryContains(prefix)) 
		{ 
			// if no more elements are there, print it 
			if (i == n) 
			{ 
				// add this element to previous prefix 
				result += prefix; 
				cout << result << endl; //print result 
				return; 
			} 
			wordBreakUtil(str.substr(i, n-i), n-i, 
								result + prefix + " "); 
		} 
	}	 //end for 
}//end function 

int main() 
{ 
	cout << "First Test:\n"; 
	wordBreak("iloveicecreamandmango"); 

	cout << "\nSecond Test:\n"; 
	wordBreak("ilovesamsungmobile"); 
	return 0; 
} 

// Method 2:(using dp and simple recursion)
// A recursive program to test whether a given 
// string can be segmented into space separated 
// words in dictionary 
#include <iostream> 
using namespace std; 

/* A utility function to check whether a word is 
present in dictionary or not. An array of strings 
is used for dictionary. Using array of strings for 
dictionary is definitely not a good idea. We have 
used for simplicity of the program*/
int dictionaryContains(string word) 
{ 
	string dictionary[] = {"mobile","samsung","sam","sung", 
							"man","mango","icecream","and", 
							"go","i","like","ice","cream"}; 
	int size = sizeof(dictionary)/sizeof(dictionary[0]); 
	for (int i = 0; i < size; i++) 
		if (dictionary[i].compare(word) == 0) 
		return true; 
	return false; 
} 

// returns true if string can be segmented into space 
// separated words, otherwise returns false 
bool wordBreak(string str) 
{ 
	int size = str.size(); 

	// Base case 
	if (size == 0) return true; 

	// Try all prefixes of lengths from 1 to size 
	for (int i=1; i<=size; i++) 
	{ 
		// The parameter for dictionaryContains is 
		// str.substr(0, i) which is prefix (of input 
		// string) of length 'i'. We first check whether 
		// current prefix is in dictionary. Then we 
		// recursively check for remaining string 
		// str.substr(i, size-i) which is suffix of 
		// length size-i 
		if (dictionaryContains( str.substr(0, i) ) && 
			wordBreak( str.substr(i, size-i) )) 
			return true; 
	} 

	// If we have tried all prefixes and 
	// none of them worked 
	return false; 
} 

// Driver program to test above functions 
int main() 
{ 
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n"; 
	return 0; 
} 

// Method 3
// A Dynamic Programming based program to test whether a given string can 
// be segmented into space separated words in dictionary 
#include <iostream> 
#include <string.h> 
using namespace std; 

/* A utility function to check whether a word is present in dictionary or not. 
An array of strings is used for dictionary. Using array of strings for 
dictionary is definitely not a good idea. We have used for simplicity of 
the program*/
int dictionaryContains(string word) 
{ 
	string dictionary[] = {"mobile","samsung","sam","sung","man","mango", 
						"icecream","and","go","i","like","ice","cream"}; 
	int size = sizeof(dictionary)/sizeof(dictionary[0]); 
	for (int i = 0; i < size; i++) 
		if (dictionary[i].compare(word) == 0) 
		return true; 
	return false; 
} 

// Returns true if string can be segmented into space separated 
// words, otherwise returns false 
bool wordBreak(string str) 
{ 
	int size = str.size(); 
	if (size == 0) return true; 

	// Create the DP table to store results of subroblems. The value wb[i] 
	// will be true if str[0..i-1] can be segmented into dictionary words, 
	// otherwise false. 
	bool wb[size+1]; 
	memset(wb, 0, sizeof(wb)); // Initialize all values as false. 

	for (int i=1; i<=size; i++) 
	{ 
		// if wb[i] is false, then check if current prefix can make it true. 
		// Current prefix is "str.substr(0, i)" 
		if (wb[i] == false && dictionaryContains( str.substr(0, i) )) 
			wb[i] = true; 

		// wb[i] is true, then check for all substrings starting from 
		// (i+1)th character and store their results. 
		if (wb[i] == true) 
		{ 
			// If we reached the last prefix 
			if (i == size) 
				return true; 

			for (int j = i+1; j <= size; j++) 
			{ 
				// Update wb[j] if it is false and can be updated 
				// Note the parameter passed to dictionaryContains() is 
				// substring starting from index 'i' and length 'j-i' 
				if (wb[j] == false && dictionaryContains( str.substr(i, j-i) )) 
					wb[j] = true; 

				// If we reached the last character 
				if (j == size && wb[j] == true) 
					return true; 
			} 
		} 
	} 

	/* Uncomment these lines to print DP table "wb[]" 
	for (int i = 1; i <= size; i++) 
		cout << " " << wb[i]; */

	// If we have tried all prefixes and none of them worked 
	return false; 
} 

// Driver program to test above functions 
int main() 
{ 
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n"; 
	return 0; 
} 

// Method 4(optimised dp)
// A Dynamic Programming based program to test 
// whether a given string can be segmented into 
// space separated words in dictionary 
#include <bits/stdc++.h> 
using namespace std; 

/* A utility function to check whether a word 
is present in dictionary or not. An array of 
strings is used for dictionary. Using array 
of strings for dictionary is definitely not 
a good idea. We have used for simplicity of 
the program*/
int dictionaryContains(string word) 
{ 
	string dictionary[] = { "mobile", "samsung", "sam", 
							"sung", "man", "mango", 
							"icecream", "and", "go", 
							"i", "like", "ice", "cream" }; 
	int size = sizeof(dictionary) / sizeof(dictionary[0]); 
	for (int i = 0; i < size; i++) 
		if (dictionary[i].compare(word) == 0) 
			return true; 
	return false; 
} 

// Returns true if string can be segmented into space 
// separated words, otherwise returns false 
bool wordBreak(string s) 
{ 
	int n = s.size(); 
	if (n == 0) 
		return true; 

	// Create the DP table to store results of subroblems. 
	// The value dp[i] will be true if str[0..i] can be 
	// segmented into dictionary words, otherwise false. 
	vector<bool> dp(n + 1, 0); // Initialize all values 
	// as false. 

	// matched_index array represents the indexes for which 
	// dp[i] is true. Initially only -1 element is present 
	// in this array. 
	vector<int> matched_index; 
	matched_index.push_back(-1); 

	for (int i = 0; i < n; i++) { 
		int msize = matched_index.size(); 

		// Flag value which tells that a substring matches 
		// with given words or not. 
		int f = 0; 

		// Check all the substring from the indexes matched 
		// earlier. If any of that substring matches than 
		// make flag value = 1; 
		for (int j = msize - 1; j >= 0; j--) { 

			// sb is substring starting from matched_index[j] 
			// + 1 and of length i - matched_index[j] 
			string sb = s.substr(matched_index[j] + 1, i - matched_index[j]); 

			if (dictionaryContains(sb)) { 
				f = 1; 
				break; 
			} 
		} 

		// If substring matches than do dp[i] = 1 and 
		// push that index in matched_index array. 
		if (f == 1) { 
			dp[i] = 1; 
			matched_index.push_back(i); 
		} 
	} 
	return dp[n - 1]; 
} 

// Driver code 
int main() 
{ 
	wordBreak("ilikesamsung") ? cout << "Yes\n" : cout << "No\n"; 
	wordBreak("iiiiiiii") ? cout << "Yes\n" : cout << "No\n"; 
	wordBreak("") ? cout << "Yes\n" : cout << "No\n"; 
	wordBreak("ilikelikeimangoiii") ? cout << "Yes\n" : cout << "No\n"; 
	wordBreak("samsungandmango") ? cout << "Yes\n" : cout << "No\n"; 
	wordBreak("samsungandmangok") ? cout << "Yes\n" : cout << "No\n"; 
	return 0; 
} 
