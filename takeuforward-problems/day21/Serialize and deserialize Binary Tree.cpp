#include <bits/stdc++.h>
using namespace std;
#define leaf -1

// Following are some simpler versions of the problem:

// If given Tree is Binary Search Tree?
// If the given Binary Tree is Binary Search Tree, we can store it by either storing preorder or postorder traversal. In case of Binary Search Trees, only preorder or postorder traversal is sufficient to store structure information.

// If given Binary Tree is Complete Tree?
// A Binary Tree is complete if all levels are completely filled except possibly the last level and all nodes of last level are as left as possible (Binary Heaps are complete Binary Tree). For a complete Binary Tree, level order traversal is sufficient to store the tree. We know that the first node is root, next two nodes are nodes of next level, next four nodes are nodes of 2nd level and so on.




// If given Binary Tree is Full Tree?
// A full Binary is a Binary Tree where every node has either 0 or 2 children. It is easy to serialize such trees as every internal node has 2 children. We can simply store preorder traversal and store a bit with every node to indicate whether the node is an internal node or a leaf node.

// How to store a general Binary Tree?
// A simple solution is to store both Inorder and Preorder traversals. This solution requires requires space twice the size of Binary Tree.
// We can save space by storing Preorder traversal and a marker for NULL pointers.


struct Node {
	int data;
	struct Node *left,*right;
	Node(int x){
		data = x;
		left=NULL;right=NULL;
	}
};

void insert(struct Node *root,int a){
	queue<struct Node*> q;
	q.push(root);
	while(!q.empty()){
		struct Node *root = q.front();
		q.pop();
			if(!root->left){
				root->left = new Node(a);
				break;
			} 
			else q.push(root->left);
			if(!root->right){
				root->right = new Node(a);
				break;
			} 
			else q.push(root->right);
	}
}
void inorderprint(struct Node* root){
if(!root) return;
inorderprint(root->left);
cout<<root->data<<" ";
inorderprint(root->right);
}

void serialize(Node* root,FILE *fp){
	if(root == NULL){
		fprintf(fp, "%d", leaf);
		return;
	}
	fprintf(fp, "%d", root->data);
	serialize(root->left,fp);
	serialize(root->right,fp);
}

void deSerialize(Node* root,FILE* fp){
	int val;
	if(!fscanf(fp, "%d ", &val) || val == leaf) return;
	root = new Node(val);
	deSerialize(root->left,fp);
	deSerialize(root->right,fp);
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a; cin>>t;
	while(t--){
		cin>>n;
		struct Node *root=NULL;
		for(int i=0;i<n;i++){
			cin>>a;
			if(root == NULL) root = new Node(a);
			else insert(root,a);
		}
		FILE *fp = fopen("tree.txt", "w"); 
	    if (fp == NULL) 
	    { 
	        puts("Could not open file"); 
	        return 0; 
	    } 
	    serialize(root, fp); 
	    fclose(fp);
	    Node *root1 = NULL; 
	    fp = fopen("tree.txt", "r"); 
	    deSerialize(root1, fp); 


	    cout<<"inorderprint: "; inorderprint(root1);cout<<endl;
	}
	return 0;
}