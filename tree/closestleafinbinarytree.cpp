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

// A utility function to find minimum of x and y 
int min(int x, int y) 
{ 
	return (x < y)? x :y; 
} 
    	//       A
        //     /    \    
        //    B       C
        //          /   \  
        //         E     F   
        //        /       \
        //       G         H
        //      / \       /
        //     I   J     K

// A utility function to find distance of closest leaf of the tree 
// rooted under given root 
int closestLeafFromRoot(struct Node* root){
	if(root == NULL) return INT_MAX;

	if(root->left == NULL && root->right == NULL) return 0;

	return 1+min(closestLeafFromRoot(root->left),closestLeafFromRoot(root->right));
}


int findClosestUtil(struct Node* root,char k,struct Node* ancestor[],int index){
	if(root==NULL) return INT_MAX;

	// current root is k then
	if(root->key == k){
		int res = closestLeafFromRoot(root);

		// Now check for their ancestors and update res value;
		// distance from kth root to min leaf ancestor (index-i)
		// distance from min leaf ancestor from leaf by using function cloestleafromroot
		for(int i=index-1;i>=0;i--){
			res = min(res,(index-i)+closestLeafFromRoot(ancestor[i]));
		}

		return res;
	}

	ancestor[index]= root;
	return min(findClosestUtil(root->left,k,ancestor,index+1),findClosestUtil(root->right,k,ancestor,index+1));

}


int findClosest(struct Node* root,char k){
	struct Node* ancestor[100];
	return findClosestUtil(root,k,ancestor,0);
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
	k = 'B'; 
	cout << "Distance of the closest key from " << k << " is "
		<< findClosest(root, k) << endl; 

	return 0; 
} 
