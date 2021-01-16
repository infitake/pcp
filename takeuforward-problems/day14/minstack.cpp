// #include <iostream> 
// #include <stdlib.h> 

// using namespace std; 

// /* A simple stack class with 
// basic stack funtionalities */
// class Stack { 
// private: 
// 	static const int max = 100; 
// 	int arr[max]; 
// 	int top; 

// public: 
// 	Stack() { top = -1; } 
// 	bool isEmpty(); 
// 	bool isFull(); 
// 	int pop(); 
// 	void push(int x); 
// }; 

// /* Stack's member method to check 
// if the stack is iempty */
// bool Stack::isEmpty() 
// { 
// 	if (top == -1) 
// 		return true; 
// 	return false; 
// } 

// /* Stack's member method to check 
// if the stack is full */
// bool Stack::isFull() 
// { 
// 	if (top == max - 1) 
// 		return true; 
// 	return false; 
// } 

// /* Stack's member method to remove 
// an element from it */
// int Stack::pop() 
// { 
// 	if (isEmpty()) { 
// 		cout << "Stack Underflow"; 
// 		abort(); 
// 	} 
// 	int x = arr[top]; 
// 	top--; 
// 	return x; 
// } 

// /* Stack's member method to insert 
// an element to it */
// void Stack::push(int x) 
// { 
// 	if (isFull()) { 
// 		cout << "Stack Overflow"; 
// 		abort(); 
// 	} 
// 	top++; 
// 	arr[top] = x; 
// } 

// /* A class that supports all the stack 
// operations and one additional 
// operation getMin() that returns the 
// minimum element from stack at 
// any time. This class inherits from 
// the stack class and uses an 
// auxiliarry stack that holds minimum 
// elements */
// class SpecialStack : public Stack { 
// 	Stack min; 

// public: 
// 	int pop(); 
// 	void push(int x); 
// 	int getMin(); 
// }; 

// /* SpecialStack's member method to 
// insert an element to it. This method 
// makes sure that the min stack is 
// also updated with appropriate minimum 
// values */
// void SpecialStack::push(int x) 
// { 
// 	if (isEmpty() == true) { 
// 		Stack::push(x); 
// 		min.push(x); 
// 	} 
// 	else { 
// 		Stack::push(x); 
// 		int y = min.pop(); 
// 		min.push(y); 

// 		/* push only when the incoming element 
// 		of main stack is smaller 
// 		than or equal to top of auxiliary stack */
// 		if (x <= y) 
// 			min.push(x); 
// 	} 
// } 

// /* SpecialStack's member method to 
// remove an element from it. This method 
// removes top element from min stack also. */
// int SpecialStack::pop() 
// { 
// 	int x = Stack::pop(); 
// 	int y = min.pop(); 

// 	/* Push the popped element y back 
// 	only if it is not equal to x */
// 	if (y != x) 
// 		min.push(y); 

// 	return x; 
// } 
 

// /* SpecialStack's member method to get 
// minimum element from it. */
// int SpecialStack::getMin() 
// { 
// 	int x = min.pop(); 
// 	min.push(x); 
// 	return x; 
// } 

// /* Driver program to test SpecialStack 
// methods */
// int main() 
// { 
// 	SpecialStack s; 
// 	s.push(10); 
// 	s.push(20); 
// 	s.push(30); 
// 	cout << s.getMin() << endl; 
// 	s.push(5); 
// 	cout << s.getMin(); 
// 	return 0; 
// } 

// Method 2:(using an other element)
// C++ program to implement a stack that supports 
// getMinimum() in O(1) time and O(1) extra space. 
#include <bits/stdc++.h> 
using namespace std; 

// A user defined stack that supports getMin() in 
// addition to push() and pop() 
struct MyStack 
{ 
	stack<int> s; 
	int minEle; 

	// Prints minimum element of MyStack 
	void getMin() 
	{ 
		if (s.empty()) 
			cout << "Stack is empty\n"; 

		// variable minEle stores the minimum element 
		// in the stack. 
		else
			cout <<"Minimum Element in the stack is:6 "
				<< minEle << "\n"; 
	} 

	// Prints top element of MyStack 
	void peek() 
	{ 
		if (s.empty()) 
		{ 
			cout << "Stack is empty "; 
			return; 
		} 

		int t = s.top(); // Top element. 

		cout << "Top Most Element is: "; 

		// If t < minEle means minEle stores 
		// value of t. 
		(t < minEle)? cout << minEle: cout << t; 
	} 

	// Remove the top element from MyStack 
	void pop() 
	{ 
		if (s.empty()) 
		{ 
			cout << "Stack is empty\n"; 
			return; 
		} 

		cout << "Top Most Element Removed: "; 
		int t = s.top(); 
		s.pop(); 

		// Minimum will change as the minimum element 
		// of the stack is being removed. 
		if (t < minEle) 
		{ 
			cout << minEle << "\n"; 
			minEle = 2*minEle - t; 
		} 

		else
			cout << t << "\n"; 
	} 

	// Removes top element from MyStack 
	void push(int x) 
	{ 
		// Insert new number into the stack 
		if (s.empty()) 
		{ 
			minEle = x; 
			s.push(x); 
			cout << "Number Inserted: " << x << "\n"; 
			return; 
		} 

		// If new number is less than minEle 
		if (x < minEle) 
		{ 
			s.push(2*x - minEle); 
			minEle = x; 
		} 

		else
		s.push(x); 

		cout << "Number Inserted: " << x << "\n"; 
	} 
}; 

// Driver Code 
int main() 
{ 
	MyStack s; 
	s.push(3); 
	s.push(5); 
	s.getMin(); 
	s.push(2); 
	s.push(1); 
	s.getMin(); 
	s.pop(); 
	s.getMin(); 
	s.pop(); 
	s.peek(); 

	return 0; 
} 
