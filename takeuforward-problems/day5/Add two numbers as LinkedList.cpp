#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
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
int len(struct Node *root){
	int a=0;
	while(root!=NULL) {
		root=root->next;
		a++;
	}
	return a;
}

struct Node* revs(struct Node *root){
	struct Node *pre=NULL,*curr=root;
	struct Node *h=NULL;
	while(curr != NULL){
		h = curr->next;
		curr->next = pre;
		pre = curr;
		curr = h;
	}
	root = pre;
	return root;
}

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}

struct Node* sumlinklist(struct Node *node1,struct Node *node2){
	struct Node *temp1=node1,*temp2=node2;
	temp1 = revs(temp1);
	temp2 = revs(temp2);
	struct Node *root1=temp1,*root2=temp2;
	int carry=0;
	while(root2!=NULL){
		int count = root1->data+root2->data+carry;
		carry = (count>=10)? 1:0;
		root1->data=count%10;
		if(root1->next == NULL && carry==1) {
			root1->next = new Node(carry);
			root1=root1->next;
		}
		root1=root1->next;
		root2=root2->next;
	}
	while(root1!=NULL){
		int count = root1->data+carry;
		carry = (count>=10)? 1:0;
		root1->data=count%10;
		if(root1->next == NULL && carry==1) {
			root1->next = new Node(carry);
			root1=root1->next;
		}
		root1=root1->next;
	}
	temp1 = revs(temp1);
	return temp1;
}
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,m; cin>>t;
	while(t--){
		struct Node *root1=NULL,*root2=NULL;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a;
			root1=insert(root1,a);
		}
		for(int i=0;i<m;i++){
			cin>>a;
			root2=insert(root2,a);
		}
		int len1=len(root1);
		int len2=len(root2);
		if(len1>len2){
			root1 = sumlinklist(root1,root2);
			print(root1);
		}
		else {
			root2 = sumlinklist(root2,root1);
			print(root2);
		}
        
	}
	return 0;
}