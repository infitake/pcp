#include <bits/stdc++.h>
using namespace std;
stack<int> stk1,stk2;

void push(int x){
	stk1.push(x);
}

void pop() {
	if(stk2.empty()){
		while(!stk1.empty()){
			stk2.push(stk1.top());
			stk1.pop();
		}
	}
	cout<<"pop element "<<stk2.top();
	stk2.pop();
}
int front() {
	if(!stk1.empty()) return stk1.top();
	else return -1;
}
int back() {
	if(stk2.empty()) {
		while(!stk1.empty()){
			stk2.push(stk1.top());
			stk1.pop();
		}
	}
	return stk2.top();
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a; cin>>n;

	for(int i=0;i<n;i++){ cin>>a;push(a);}
	pop();
	
}

// Method
// CPP program to implement Queue using 
// two stacks with costly deQueue() 
#include <bits/stdc++.h> 
using namespace std; 

struct Queue { 
	stack<int> s1, s2; 

	// Enqueue an item to the queue 
	void enQueue(int x) 
	{ 
		// Push item into the first stack 
		s1.push(x); 
	} 

	// Dequeue an item from the queue 
	int deQueue() 
	{ 
		// if both stacks are empty 
		if (s1.empty() && s2.empty()) { 
			cout << "Q is empty"; 
			exit(0); 
		} 

		// if s2 is empty, move 
		// elements from s1 
		if (s2.empty()) { 
			while (!s1.empty()) { 
				s2.push(s1.top()); 
				s1.pop(); 
			} 
		} 

		// return the top item from s2 
		int x = s2.top(); 
		s2.pop(); 
		return x; 
	} 
}; 

// Driver code 
int main() 
{ 
	Queue q; 
	q.enQueue(1); 
	q.enQueue(2); 
	q.enQueue(3); 

	cout << q.deQueue() << '\n'; 
	cout << q.deQueue() << '\n'; 
	cout << q.deQueue() << '\n'; 

	return 0; 
} 

// Method 3 using recursive function in dequeue
// CPP program to implement Queue using 
// one stack and recursive call stack. 
#include <bits/stdc++.h> 
using namespace std; 

struct Queue { 
	stack<int> s; 

	// Enqueue an item to the queue 
	void enQueue(int x) 
	{ 
		s.push(x); 
	} 

	// Dequeue an item from the queue 
	int deQueue() 
	{ 
		if (s.empty()) { 
			cout << "Q is empty"; 
			exit(0); 
		} 

		// pop an item from the stack 
		int x = s.top(); 
		s.pop(); 

		// if stack becomes empty, return 
		// the popped item 
		if (s.empty()) 
			return x; 

		// recursive call 
		int item = deQueue(); 

		// push popped item back to the stack 
		s.push(x); 

		// return the result of deQueue() call 
		return item; 
	} 
}; 

// Driver code 
int main() 
{ 
	Queue q; 
	q.enQueue(1); 
	q.enQueue(2); 
	q.enQueue(3); 

	cout << q.deQueue() << '\n'; 
	cout << q.deQueue() << '\n'; 
	cout << q.deQueue() << '\n'; 

	return 0; 
} 
