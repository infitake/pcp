#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Method 0:
// we can visualize the string "AB" as (26pow1)*1+(26pow0)*2
// so first we reverese and then increase value of pow 

// get number from the string
int titleToNumber(string s) {
    reverse(s.begin(),s.end());
    long long p=1,res=0;
    for(auto x:s){
        res += (x-'A'+1) * p;
        p = p*26;
    }
    return res;
}

// Method 1:
// If remainder with 26 comes out to be 0 (meaning 26, 52 and so on)
 // then we put ‘Z’ in the output string and new n becomes n/26 -1 because here we are considering 26 to be ‘Z’ while in actual it’s 25th with respect to ‘A’.

// Similarly if the remainder comes out to be non zero. (like 1, 2, 3 and so on) then we need to just insert the char accordingly in the string and do n = n/26.

// Finally we reverse the string and print.
string colnumber(ll n){
	ll k= n;
	string str;
	while(k>0){
		ll rem = k%26;
		if(rem ==0) {
			k = k/26-1;
			str += 'Z';
		}
		else {
			k = k/26;
			str += 'A'+(rem-1);
		}
	}
	reverse(str.begin(),str.end());
	return str;
}

// Method 2:
// The problem is similar to converting a decimal number to its binary representation but instead of binary base system where we have two digits only 0 and 1, here we have 26 characters from A-Z .

// So, we are dealing with base 26 instead of base binary.

// That’s not where the fun ends, we don’t have zero in this number system, as A represents 1, B represents 2 and so on Z represents 26.

// To make the problem easily understandable, we approach the problem in two steps:

// Convert the number to base 26 representation, considering we have 0 also in the system.
// Change the representation to the one without having 0 in its system.
// HOW? Here is an example

// Step 1:
// Consider we have number 676, How to get its representation in base 26 system ? Same way we do for binary system, Instead of division and remainder by 2, we do division and remainder by 26.

// Base 26 representation of 676 is : 100 
// Step2

// But Hey, we can’t have zero in our representation. right? Because its not part of our number system. How do we get rid of zero? Well its simple, but before doing that lets remind one simple math trick:


// Subtraction: 
// 5000 - 9, How do you subtract 9 from 0 ? You borrow
// from next significant bit, right.  

// In decimal number system to deal with zero we borrow 10, and subtract 1 from next significant.
// In Base 26 Number System to deal with zero we borrow 26 and subtract 1 from next significant bit.
// So Convert 10026 to number system which does not have ‘0’, we get (25 26)26
// Symbolic representation of the same is : YZ
void printString(int n) 
{ 
    int arr[10000]; 
    int i = 0; 
  
    // Step 1: Converting to number assuming 
    // 0 in number system 
    while (n) { 
        arr[i] = n % 26; 
        n = n / 26; 
        i++; 
    } 
  
    // Step 2: Getting rid of 0, as 0 is 
    // not part of number system 
    for (int j = 0; j < i - 1; j++) { 
        if (arr[j] <= 0) { 
            arr[j] += 26; 
            arr[j + 1] = arr[j + 1] - 1; 
        } 
    } 
  
    for (int j = i; j >= 0; j--) { 
        if (arr[j] > 0) 
            cout << char('A' + arr[j] - 1); 
    } 
  
    cout << endl; 
} 
  

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		cout<<colnumber(n)<<endl;
		
	}
	return 0;
}