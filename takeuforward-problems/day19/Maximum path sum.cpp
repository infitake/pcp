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

// max path sum b/w leaves

int maxpathsumleavesUtil(Node* root,int &sum){
	if(!root) return 0;
	if(root->left == NULL && root->right == NULL) return root->data;
	int lh = maxpathsumleavesUtil(root->left,sum);
	int rh = maxpathsumleavesUtil(root->right,sum);

	if(root->left && root->right) {
		sum = max(sum,lh+rh+root->data);
		return max(lh,rh)+root->data;
	}

	return (root->left==NULL)?rh+root->data:lh+root->data;
}

int maxpathsumleaves(Node* root){
	if(!root) return 0;
	int sum=INT_MIN;
	int h = maxpathsumleavesUtil(root,sum);
	return sum;
}

// max path sum in a tree

int maxpathsumUtil(Node* root,int &sum){
	if(!root) return 0;
	int lh = maxpathsumUtil(root->left,sum);
	int rh = maxpathsumUtil(root->right,sum);

	// we have to find this for -ve values
	int max_bw_top_and_node = max(max(lh,rh)+root->data,root->data);

	int max_path_in_one_iteration = max(max_bw_top_and_node,lh+rh+root->data);

	sum = max(sum,max_path_in_one_iteration);

	return max_bw_top_and_node;
}

int maxpathsum(Node* root){
	if(!root) return 0;
	int sum=INT_MIN;
	int h = maxpathsumUtil(root,sum);
	return sum;
}

// tree from inorder and preorder
int search(vector<int> &in,int l,int r,int key){
	for(int i=l;i<=r;i++){
   		if(in[i] == key) return i;
  	}
  	return -1;
}
// TreeNode* buildTreeUtil(vector<int> &pre,vector<int> &in, int l,int r,int &preindex){
// 	if(l>r) return NULL;
//  	TreeNode* temp = new TreeNode(pre[preindex++]);
//   	if(l == r) return temp;
  
//   	int index = search(in,l,r,temp->val);
  
//  	if(l<r){
//    		temp->left = buildTreeUtil(pre,in,l,index-1,preindex);
//    		temp->right = buildTreeUtil(pre,in,index+1,r,preindex);
//   	}
//   	return temp;
//  }
 
//  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//   	int i=0;
//   	int n = preorder.size();
//   	return buildTreeUtil(preorder,inorder,0,n-1,i);
//  }

//  // we can make the above function more efficient if we remove the search function
//  // we can use a map to remove the search function 
// // we just store value corresponding to their index in map 

//  // Method 2:
//  1. Do below until you reach the leftmost node.
// Keep creating the nodes from PreOrder traversal
// If the stack’s topmost element is not in the set, link the created node to the left child of stack’s topmost element (if any), without popping the element.
// Else link the created node to the right child of stack’s topmost element. Remove the stack’s topmost element from the set and the stack.
// Push the node to a stack.

// 1

// 2. Keep popping the nodes from the stack until either the stack is empty, or the topmost element of stack compares to the current element of InOrder traversal. Once the loop is over, push the last node back into the stack and into the set.

// 2

// 3. Goto Step 1.
// set<TreeNode*> s; 
// stack<TreeNode*> st; 
  
// // Function to build tree using given traversal 
// TreeNode* buildTree(int preorder[], int inorder[],int n) 
// { 
  
//     TreeNode* root = NULL; 
//     for (int pre = 0, in = 0; pre < n;)  
//     { 
  
//         TreeNode* node = NULL; 
//         do
//         { 
//             node = new TreeNode(preorder[pre]); 
//             if (root == NULL) 
//             { 
//                 root = node; 
//             } 
//             if (st.size() > 0)  
//             { 
//                 if (s.find(st.top()) != s.end()) 
//                 { 
//                     s.erase(st.top()); 
//                     st.top()->right = node; 
//                     st.pop(); 
//                 } 
//                 else
//                 { 
//                     st.top()->left = node; 
//                 } 
//             } 
//             st.push(node); 
//         } while (preorder[pre++] != inorder[in] && pre < n); 
  
//         node = NULL; 
//         while (st.size() > 0 && in < n &&  
//                 st.top()->val == inorder[in])  
//         { 
//             node = st.top(); 
//             st.pop(); 
//             in++; 
//         } 
  
//         if (node != NULL)  
//         { 
//             s.insert(node); 
//             st.push(node); 
//         } 
//     } 
  
//     return root; 
// } 

// for Symmetric purpose
bool isSymmetricUtil(Node* root1,Node* root2){
    if(root1==NULL && root2 ==NULL) return true;
    if(root1 && root2)
    	return ((root1->data == root2->data)&&isSymmetricUtil(root1->left,root2->right)&&isSymmetricUtil(root1->right,root2->left));
	return false;
}


// return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node* root){
    if(!root) return true;
    return isSymmetricUtil(root,root);
}

// flatten the binary tree
void preorderprint(struct Node* root){
	if(!root) return;
	cout<<root->data<<" ";
	preorderprint(root->left);
	preorderprint(root->right);
}

void flattenUtil(Node *root,Node **flat) {
	if(!root) return;
	Node* fleft = root->left; 
    Node* fright = root->right; 
	if(root != *flat){
		(*flat)->right = root;
		(*flat)->left = NULL;
		(*flat)=root;
	}
	flattenUtil(fleft,flat);
	flattenUtil(fright,flat);
	if(fleft == NULL && fright == NULL) (*flat)=root;
}

void flatten(Node *root){
	if(!root) return;
	Node *flat = root;
	flattenUtil(root,&flat);
	preorderprint(root);
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
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

		// cout<<"max path sum: "<<maxpathsumleaves(root)<<endl;
		// cout<<"max path sum: "<<maxpathsum(root)<<endl;
		//inorder or preorder to tree
		// inorder or postorder to tree just change the index and positon of right left
		// check for symmetric(mirror) of tree
		cout<<"flatten binary tree: "; flatten(root); cout<<endl;
	}
	return 0;
}