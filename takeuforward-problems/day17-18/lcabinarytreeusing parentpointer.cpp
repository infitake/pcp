// C++ program to find lowest common ancestor using parent pointer 
#include <bits/stdc++.h> 
using namespace std; 

// Below are steps to find LCA.

// Create an empty hash table.
// Insert n1 and all of its ancestors in hash table.
// Check if n2 or any of its ancestors exist in hash table, 
// if yes return the first existing ancestor.


// A Tree Node 
struct Node 
{ 
	Node *left, *right, *parent; 
	int key; 
}; 

// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
	Node *temp = new Node; 
	temp->key = item; 
	temp->parent = temp->left = temp->right = NULL; 
	return temp; 
} 

/* A utility function to insert a new node with 
given key in Binary Search Tree */
Node *insert(Node *node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
	{ 
		node->left = insert(node->left, key); 
		node->left->parent = node; 
	} 
	else if (key > node->key) 
	{ 
		node->right = insert(node->right, key); 
		node->right->parent = node; 
	} 

	/* return the (unchanged) node pointer */
	return node; 
} 

// To find LCA of nodes n1 and n2 in Binary Tree 
Node *LCA(Node *n1, Node *n2) 
{ 
// Creata a map to store ancestors of n1 
map <Node *, bool> ancestors; 

// Insert n1 and all its ancestors in map 
while (n1 != NULL) 
{ 
	ancestors[n1] = true; 
	n1 = n1->parent; 
} 

// Check if n2 or any of its ancestors is in 
// map. 
while (n2 != NULL) 
{ 
	if (ancestors.find(n2) != ancestors.end()) 
		return n2; 
	n2 = n2->parent; 
} 

return NULL; 
} 

// Driver method to test above functions 
int main(void) 
{ 
	Node * root = NULL; 

	root = insert(root, 20); 
	root = insert(root, 8); 
	root = insert(root, 22); 
	root = insert(root, 4); 
	root = insert(root, 12); 
	root = insert(root, 10); 
	root = insert(root, 14); 

	Node *n1 = root->left->right->left; 
	Node *n2 = root->left; 
	Node *lca = LCA(n1, n2); 

	printf("LCA of %d and %d is %d \n", n1->key, n2->key, lca->key); 

	return 0; 
} 
// Time Complexity : O(h) where h is height of Binary Tree if we use hash table to implement the solution (Note that the above solution uses map which takes O(Log h) time to insert and find). So the time complexity of above implementation is O(h Log h).

// Auxiliary Space : O(h)


// Method 2:(in O(1))
// A O(h) time and O(1) Extra Space Solution:
// The above solution requires extra space because we need to use a hash table to store visited ancestors. We can solve the problem in O(1) extra space using following fact : If both nodes are at same level and if we traverse up using parent pointers of both nodes, the first common node in the path to root is lca.
// The idea is to find depths of given nodes and move up the deeper node pointer by the difference between depths. Once both nodes reach same level, traverse them up and return the first common node.


// A utility function to find depth of a node 
// (distance of it from root) 
int depth(Node *node) 
{ 
    int d = -1; 
    while (node) 
    { 
        ++d; 
        node = node->parent; 
    } 
    return d; 
} 
  
// To find LCA of nodes n1 and n2 in Binary Tree 
Node *LCA(Node *n1, Node *n2) 
{ 
    // Find depths of two nodes and differences 
    int d1 = depth(n1), d2 = depth(n2); 
    int diff = d1 - d2; 
  
    // If n2 is deeper, swap n1 and n2 
    if (diff < 0) 
    { 
        Node * temp = n1; 
        n1 = n2; 
        n2 = temp; 
        diff = -diff; 
    } 
  
    // Move n1 up until it reaches the same level as n2 
    while (diff--) 
        n1 = n1->parent; 
  
    // Now n1 and n2 are at same levels 
    while (n1 && n2) 
    { 
        if (n1 == n2) 
            return n1; 
        n1 = n1->parent; 
        n2 = n2->parent; 
    } 
  
    return NULL; 
}