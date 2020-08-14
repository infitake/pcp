#include <bits/stdc++.h>
using namespace std;

struct Node {
	char data;
	struct Node* next;
	Node(char x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,char key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}

string findStr(Node* root,int k){
	Node* temp = root;
	int len=0;
	string str="";
	while(temp!=NULL){
		len++;
		str += temp->data;
		if(len%k==0){
			str += " ";
		}
		temp = temp->next;
	}
	return str;
}

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}

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
		char a;
		struct Node *root=NULL;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
        cout<<findStr(root,k)<<endl;
	}
	return 0;
}