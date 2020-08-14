// Count number of bits to be flipped 
// to convert A into B 

// Input : a = 10, b = 20
// Output : 4
// Binary representation of a is 00001010
// Binary representation of b is 00010100
// We need to flip highlighted four bits in a
// to make it b.

// Input : a = 7, b = 10
// Output : 3
// Binary representation of a is 00000111
// Binary representation of b is 00001010
// We need to flip highlighted three bits in a
// to make it b.


//  1. Calculate XOR of A and B.      
//         a_xor_b = A ^ B
//   2. Count the set bits in the above 
//      calculated XOR result.
//         countSetBits(a_xor_b)
// XOR of two number will have set bits only at those places where A differs from B.

#include <iostream> 
using namespace std; 

// Function that count set bits 
int countSetBits(int n) 
{ 
	int count = 0; 
	while (n > 0) 
	{ 
		count++; 
		n &= (n-1); 
	} 
	return count; 
} 

// Function that return count of 
// flipped number 
int FlippedCount(int a, int b) 
{ 
	// Return count of set bits in 
	// a XOR b 
	return countSetBits(a^b); 
} 

// Driver code 
int main() 
{ 
	int a = 15; 
	int b = 16; 
	cout << FlippedCount(a, b)<<endl; 
	return 0; 
} 
