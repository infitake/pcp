// A C++ program to find the closesr leaf of a given key in Binary Tree 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree Node has key, pocharer to left and right children */
struct Node 
{ 
	char key; 
	struct Node* left, *right; 
}; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pocharers. */
Node *newNode(char k) 
{ 
	Node *node = new Node; 
	node->key = k; 
	node->right = node->left = NULL; 
	return node; 
} 
Node* search(Node* root,Node **parent,char k){
	if(root == NULL) return root;

	if(root->key == k) return root;
	(*parent) = root;
	return search(root->left,parent,k) search(root->right,parent,k);
}

int minheight(Node* root) {
	if(root == NULL) return 0;

	int l = minheight(root->left);
	int r = minheight(root->right);

	return min(l,r)+1;
}

int findClosest(Node* root,char k){
	Node* parent = NULL,*curr;
	curr = search(root,&parent,k);
	int ans1,ans2;
	ans1 = minheight(curr);
	if(parent->left == curr) ans2 = minheight(parent->right)+1;
	else ans2 = minheight(parent->left)+1;
	cout<<curr->key<<" "<<parent->key<<" "<<ans1<<" "<<ans2<<endl;
	return min(ans1,ans2); 
}
/* Driver program to test above functions*/
int main() 
{ 
	// Let us construct the BST shown in the above figure 
	struct Node *root	 = newNode('A'); 
	root->left			 = newNode('B'); 
	root->right			 = newNode('C'); 
	root->right->left	 = newNode('E'); 
	root->right->right	 = newNode('F'); 
	root->right->left->left = newNode('G'); 
	root->right->left->left->left = newNode('I'); 
	root->right->left->left->right = newNode('J'); 
	root->right->right->right	 = newNode('H'); 
	root->right->right->right->left = newNode('K'); 

	char k = 'H'; 
	cout << "Distance of the closest key from " << k << " is "
		<< findClosest(root, k) << endl; 
	k = 'C'; 
	cout << "Distance of the closest key from " << k << " is "
		<< findClosest(root, k) << endl; 
	k = 'E'; 
	cout << "Distance of the closest key from " << k << " is "
		<< findClosest(root, k) << endl; 
	// k = 'B'; 
	// cout << "Distance of the closest key from " << k << " is "
	// 	<< findClosest(root, k) << endl; 

	return 0; 
} 
