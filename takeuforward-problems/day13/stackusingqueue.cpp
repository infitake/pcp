#include <bits/stdc++.h>
using namespace std;
queue<int> stk1,stk2;

void push(int x){
	stk2.push(x);
	while(!stk1.empty()){
		stk2.push(stk1.front());
		stk1.pop();
	}

	queue<int> q=stk1;
	stk1=stk2;
	stk2=q;
}

void pop() {
	cout<<"pop element "<<stk1.front();
	stk1.pop();
}
int top() {
	return stk1.front();
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
	pop();
	cout<<top()<<endl;
	
}