#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* next;
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
		next = NULL;
	}
};

Node* insert(Node* root,int a){
	if(root == 	NULL) return new Node(a);
	
	if(root->data>a){
		root->left = insert(root->left,a);
	}else{
		root->right = insert(root->right,a);
	}
	return root;
}

void inorderprint(struct Node* root){
	if(!root) return;
	inorderprint(root->left);
	cout<<root->data<<" ";
	inorderprint(root->right);
}

void nextpointer(struct Node* root){
	queue<Node*> q;
	q.push(root);
	bool flag=false;
	while(!q.empty()){
		int k = q.size();
		Node* temp = NULL;
		while(k--){
			Node* node = q.front();q.pop();
			if(node->left!=NULL){
				q.push(node->left);
				if(temp==NULL) temp = node->left;
				else { temp->next = node->left; temp = temp->next;}
			}
			if(node->right != NULL){
				q.push(node->right);
				if(temp==NULL) temp = node->right;
				else { temp->next = node->right; temp = temp->next;}
			}
		}
		temp->next = NULL;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a;cin>>t;
	while(t--){
		cin>>n;
		struct Node* root = NULL;
		vector<int> vec;
		for(int i=0;i<n;i++){
			cin>>a;
			root = insert(root,a);
			// vec.push_back(a);
		}
		// cout<<"bst: ";inorderprint(root);cout<<endl;
		cout<<"nextpointer: ";nextpointer(root);cout<<endl;
		// cout<<"search: "<<search(root,7)<<endl;
		// root = constractPreorderTree(vec);
		// root = constractPostorderTree(vec);
		// root = constractLevelorderTree(vec);
		// inorderprint(root);
	}
	return 0;
}