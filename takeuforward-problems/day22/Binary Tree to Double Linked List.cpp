#include <bits/stdc++.h>
using namespace std;

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

// Method 1:
// 1. If left subtree exists, process the left subtree
// …..1.a) Recursively convert the left subtree to DLL.
// …..1.b) Then find inorder predecessor of root in left subtree (inorder predecessor is rightmost node in left subtree).
// …..1.c) Make inorder predecessor as previous of root and root as next of inorder predecessor.
// 2. If right subtree exists, process the right subtree (Below 3 steps are similar to left subtree).
// …..2.a) Recursively convert the right subtree to DLL.
// …..2.b) Then find inorder successor of root in right subtree (inorder successor is leftmost node in right subtree).
// …..2.c) Make inorder successor as next of root and root as previous of inorder successor.
// 3. Find the leftmost node and return it (the leftmost node is always head of converted DLL).
Node* binarytolistUtil1(Node* root){
	if(root == NULL) return root;

	if(root->left != NULL){
		Node* left = binarytolistUtil1(root->left);
		while(left->right!=NULL) left = left->right;
		left->right = root;
		root->left = left;
	}
	if(root->right != NULL){
		Node* right = binarytolistUtil1(root->right);
		while(right->left!=NULL) right = right->left;
		right->left = root;
		root->right = right;
	}
	return root;
}


Node* binarytolist1(Node* root){
	if(root == NULL) return root;
	root = binarytolistUtil1(root);
	while(root->left!=NULL) root = root->left;
	return root;
}


// Method 2:
// 1) Fix Left Pointers: In this step, we change left pointers to point to previous nodes in DLL. The idea is simple, we do inorder traversal of tree. In inorder traversal, we keep track of previous visited node and change left pointer to the previous node. See fixPrevPtr() in below implementation.

// 2) Fix Right Pointers: The above is intuitive and simple. 
// How to change right pointers to point to next node in DLL? 
// The idea is to use left pointers fixed in step 1. 
// We start from the rightmost node in Binary Tree (BT). 
// The rightmost node is the last node in DLL. 
// Since left pointers are changed to point to previous node in DLL, 
// we can linearly traverse the complete DLL using these pointers. 
// The traversal would be from last to first node. While traversing the DLL, we keep track of the previously visited node and change the right pointer to the previous node. 
// See fixNextPtr() in below implementation.

void fixprevpionter(Node* root,Node** prev){
	if(root == NULL) return;
	fixprevpionter(root->left,prev);
	root->left = (*prev);
	(*prev) = root;
	fixprevpionter(root->right,prev);
}

Node* fixnextpointer(Node* root){
	Node* pre=NULL;
	while(root && root->right!=NULL) root = root->right;

	while(root && root->left != NULL){
		pre = root;
		root = root->left;
		root->right = pre;
	}
	return root;
}

Node* binarytolist2(Node* root){
	Node* pre = NULL;
	fixprevpionter(root,&pre);

	return fixnextpointer(root);
}

// Time Complexity: O(n) where n is the number of nodes in given Binary Tree. 
// The solution simply does two traversals of all Binary Tree nodes.

// Method 3:
// In this post, a third solution is discussed which seems to be the simplest of all. 
// The idea is to do inorder traversal of the binary tree. 
// While doing inorder traversal, keep track of the previously visited node in a variable 
// say prev. For every visited node, make it next of prev and previous of this node as prev.
void binarytolistUtil3(Node* root,Node** head,Node** prev){
	if(root == NULL) return;

	binarytolistUtil3(root->left,head,prev);
	if(*prev == NULL){
		*head = root;
	}else{
		root->left = *prev;
		(*prev)->right = root;
	}
	*prev = root;
	binarytolistUtil3(root->right,head,prev);
}

Node* binarytolist3(Node* root){
	Node *head = NULL,*pre = NULL;

	binarytolistUtil3(root,&head,&pre);

	return head;
}
// Time Complexity: The above program does a simple inorder traversal, 
// so time complexity is O(n) where n is the number of nodes in given binary tree.

// Method 4:(only single varible (2 variable used in method 3))
// we start from the right node
// n the following implementation, we traverse the tree in inorder fashion. We add nodes at the beginning of current linked list and update head of the list using pointer to head pointer. Since we insert at the beginning, we need to process leaves in reverse order. 
// For reverse order, we first traverse the right subtree before the left subtree. i.e. do a reverse inorder traversal.
void binarytolistUtil4(Node* root,Node** head){
	if(root == NULL) return;

	binarytolistUtil4(root->right,head);
	root->right = (*head);
	if(*head != NULL){
		(*head)->left = root;
	}
	*head = root;
	binarytolistUtil4(root->left,head);

}

Node* binarytolist4(Node* root){
	Node *head = NULL;
	binarytolistUtil4(root,&head);
	return head;
}
// Time Complexity: O(n), as the solution does a single traversal of given Binary Tree.

void printlist(Node* root){
	while(root!=NULL){
		cout<<root->data<<" ";
		root = root->right;
	}
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
		root = binarytolist4(root);

	    cout<<"binarytolist: "; printlist(root);cout<<endl;
	}
	return 0;
}