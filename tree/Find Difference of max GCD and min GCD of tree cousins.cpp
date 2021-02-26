// A C++ program to find the closesr leaf of a given key in Binary Tree 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree Node has key, pocharer to left and right children */
struct Node 
{ 
	int key; 
	struct Node* left, *right; 
}; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pocharers. */
Node *newNode(int k) 
{ 
	Node *node = new Node; 
	node->key = k; 
	node->right = node->left = NULL; 
	return node; 
} 
int gcd(int a,int b){ if(!a) return b; return gcd(b%a,a);}
int maxgcd(Node* root,int &maxval,int &minval){
	if(root == NULL) return 0;

	int l = maxgcd(root->left,maxval,minval);
	int r = maxgcd(root->right,maxval,minval);
	int d = gcd(l,r);
	maxval = max(maxval,d);
	minval = min(maxval,d);
	return root->key;
}

/* Driver program to test above functions*/
int main() 
{ 
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif
	// Let us construct the BST shown in the above figure 
	struct Node *root	 = newNode(5); 
	root->left			 = newNode(4); 
	root->right			 = newNode(8);
	root->left->left	 = newNode(6); 
	root->left->right	 = newNode(9);
	root->right->left	 = newNode(10); 
	root->right->left->left = newNode(20); 
	root->right->left->right = newNode(30); 
	int maxval = 0,minval=INT_MAX,ans=INT_MAX;
	int d = maxgcd(root,maxval,minval);
	ans = abs(maxval-minval);
	cout<<maxval<<" "<<minval<<" "<<ans<<endl;
	return 0; 
} 
