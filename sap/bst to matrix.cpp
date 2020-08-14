#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

// A utility function to create a new BST node 
// A utility function to insert 
// a new node with given key in BST 
Node* insert(Node* node, int key) 
{ 
    if (node == NULL) 
        return new Node(key); 
    if (key < node->data) 
        node->left = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 
    return node; 
} 
void inorderprint(struct Node* root,Node* pre,vector<pair<int,int>> &vp){
	if(!root) return;
	inorderprint(root->left,root,vp);
	// cout<<root->data<<" ";
	if(pre!=NULL)
		vp.push_back({(pre)->data,root->data});
	inorderprint(root->right,root,vp);
}

void matrix(Node* root) {
	vector<pair<int,int>> vp;
	Node* pre=NULL;
	inorderprint(root,pre,vp);
	for(auto x:vp) cout<<x.first<<" "<<x.second<<endl;
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
		 Node* root = NULL; 
	    root = insert(root, 50); 
	    insert(root, 30); 
	    insert(root, 20); 
	    insert(root, 40); 
	    insert(root, 70); 
	    insert(root, 60); 
	    insert(root, 80);
		matrix(root);

	}
	return 0;
}