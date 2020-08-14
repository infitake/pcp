#include <bits/stdc++.h>
using namespace std;

// Given input: ((A+B)*C) Expected output: (A+B)*C

// Assumptions:

// Peek (queue) just tells the element in front end of queue without deleting it.
// precedence( ) is a function which looks a precedence table of operators
// Pseudo code below:

// Convert infix expression to RPN (e.g. Shunting-yard algo O(n))

// AB+C*

// Insert only operators in queue Q

// (front)+ -------- *(rear)

// Parse postfix expression
// If operand, push to stack 'S'
// If operator
// y=Delete(Q)
// If precedence(y) > precedence(peek(Q)), then Push (S, "Pop(S) y Pop(S)")
// If precedence(y) < precedence(peek(Q)), then Push (S, "( Pop(S) y Pop(S) )")
// Final result on top of S
// All should be O(n).

bool isOperator(char str) {
	if(str == '(' || str == ')' || str == '*' || str =='+'|| str =='-' || str =='/' || str =='^') 
		return true;
	return false;
}

int isPrecedence(char str) {
	if(str == '+' || str =='-') return 1;
	if(str == '*' || str == '/') return 2;
	if(str == '^') return 3;
	return 0;
}

string infixToPostfix(string str) {\
	int n = str.size();
	stack<char> opretor;
	stack<string> oprend;

	for(int i=0;i<n;i++){
		if(str[i]=='(') opretor.push(str[i]);
		else if(str[i] == ')'){
			while(!opretor.empty() && opretor.top() != '(') {
				char opratr = opretor.top();opretor.pop();
				string oprend1 = oprend.top();oprend.pop();
				string oprend2 = oprend.top();oprend.pop();
				string ans = oprend2 + oprend1 + opratr;
				oprend.push(ans);
			}
			opretor.pop();
		}else if(isOperator(str[i])){
			while(!opretor.empty() && isPrecedence(str[i])<=isPrecedence(opretor.top())){
				char opratr = opretor.top();opretor.pop();
				string oprend1 = oprend.top();oprend.pop();
				string oprend2 = oprend.top();oprend.pop();
				string ans = oprend2 + oprend1 + opratr;
				oprend.push(ans);
			}
			opretor.push(str[i]);
		}else{
			oprend.push(string(1,str[i]));
		}
	}
	while(!opretor.empty()){
		char opratr = opretor.top();opretor.pop();
		string oprend1 = oprend.top();oprend.pop();
		string oprend2 = oprend.top();oprend.pop();
		string ans = oprend2 + oprend1 + opratr;
		oprend.push(ans);
	}
	return oprend.top();
}

void removeUnneccessaryBrackets(string str) {
	str = infixToPostfix(str);
	queue<char> q;
	for(auto x:str) if(isOperator(x)) q.push(x);
	stack<string> res;
	for(auto x:str) {
		if(isOperator(x)){
			char op = q.front();q.pop();
			if(isPrecedence(op)<=isPrecedence(q.front())){
				string oprend1 = res.top();res.pop();
				string oprend2 = res.top();res.pop();
				string ans = "(" + oprend2 + op + oprend1 + ")";
				res.push(ans);
			}else{
				string oprend1 = res.top();res.pop();
				string oprend2 = res.top();res.pop();
				string ans = oprend2 + op + oprend1;
				res.push(ans);
			}
		}else{
			res.push(string(1,x));
		}
	}
	cout<<res.top()<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n; cin>>t;
	while(t--){
		string str;
		cin>>str;
		removeUnneccessaryBrackets(str);
	}
	return 0;
}