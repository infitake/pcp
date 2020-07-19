#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Stack { 
    int top; 
  
public: 
    int a[MAX];
  
    Stack() { top = -1; } 
    void push(int x); 
    void pop(); 
    int peek(); 
    bool isEmpty(); 
};

void Stack::push(int x){
	if(top>=(MAX-1)) cout<<"stack is filled"<<endl;
	else a[++top]=x;
}
void Stack::pop(){
	if(top<0) cout<<"stack is empty"<<endl;
	else a[top--];
}
int Stack::peek(){
	if(top<0) return -1;
	return a[top];
}
bool Stack::isEmpty(){
	if(top==-1) return true;
	else return false;
}
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	class Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.peek() << " Popped from stack\n"; 
	return 0;
}