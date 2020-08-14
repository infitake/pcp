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

void nextpointer(Node* root,int key){
	// cout<<"hello1";
	if(!root) return;
	queue<Node*> q;
	q.push(root);
	queue<Node*> temp;
	while(!q.empty()){
		int k = q.size();
		bool flag = false;
		temp = q;
		while(!temp.empty()){
			Node* tp = temp.front();
			if(tp->data == key){
				temp.pop();
				if(!temp.empty()){
					tp = temp.front();
					cout<<tp->data<<endl;
					flag = true;
					break;
				}else{
					cout<<"-1"<<endl;
					flag = true;
					break;
				}
			}
			if(flag) break;
			// cout<<"kp"<<tp->data<<endl;
			temp.pop();
		}
		// cout<<"hello2";
		if(flag) break;
		while(k--){
			Node* tp = q.front();
			// cout<<tp->data<<endl;
			q.pop();
			if(tp->left) q.push(tp->left);
			if(tp->right) q.push(tp->right);
		}
	}
}

// 
void populateNextPointer(TreeLinkNode* root) {
    queue<TreeLinkNode*> q;
    q.push(root);
    int level=0;
    while(!q.empty()){
        int k = q.size();
        while(k--){
            TreeLinkNode* temp = q.front();q.pop();
            if(k==0) temp->next = NULL;
            else{
                TreeLinkNode* random = q.front();
                temp->next = random;
            }
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
    }
}

bool search(Node* root,int key) {
	if(!root) return false;
	if(root->data == key) return true;
	if(key<root->data) return search(root->left,key);
	else return search(root->right,key);
	return false;
}

// constract a bst from preorder array
Node* constractPreorderTreeUtil(vector<int> &preorder,int &preIndex,int key,int min,int max,int n){
	if(preIndex>n) return NULL;
	Node* root=NULL;
	if(key>min && key<max){
		root = new Node(key);
		preIndex++;
		if(preIndex<n){
			root->left = constractPreorderTreeUtil(preorder,preIndex,preorder[preIndex],min,key,n);
			root->right = constractPreorderTreeUtil(preorder,preIndex,preorder[preIndex],key,max,n);
		}
	}
	return root;
}

Node* constractPreorderTree(vector<int> &preorder){
	int n = preorder.size();
	int preIndex=0;
	return constractPreorderTreeUtil(preorder,preIndex,preorder[0],INT_MIN,INT_MAX,n);
}
// preorder tree in O(n) time
// Node* constructTree ( int pre[], int size )  
// {  
//     // Create a stack of capacity equal to size  
//     Stack* stack = createStack( size );  
  
//     // The first element of pre[] is always root  
//     Node* root = newNode( pre[0] );  
  
//     // Push root  
//     push( stack, root );  
  
//     int i;  
//     Node* temp;  
  
//     // Iterate through rest of the size-1 items of given preorder array  
//     for ( i = 1; i < size; ++i )  
//     {  
//         temp = NULL;  
  
//         /* Keep on popping while the next value is greater than  
//         stack's top value. */
//         while ( !isEmpty( stack ) && pre[i] > peek( stack )->data )  
//             temp = pop( stack );  
  
//         // Make this greater value as the right child 
//                 // and push it to the stack 
//         if ( temp != NULL)  
//         {  
//             temp->right = newNode( pre[i] );  
//             push( stack, temp->right );  
//         }  
  
//         // If the next value is less than the stack's top 
//                 // value, make this value as the left child of the 
//                 // stack's top node. Push the new node to stack 
//         else
//         {  
//             peek( stack )->left = newNode( pre[i] );  
//             push( stack, peek( stack )->left );  
//         }  
//     }  
  
//     return root;  
// }  

// constract a bst from postorder array
Node* constractPostorderTreeUtil(vector<int> &postorder,int &postIndex,int key,int min,int max,int n){
	if(postIndex<0) return NULL;
	Node* root=NULL;
	if(key>min && key<max){
		root = new Node(key);
		postIndex--;
		if(postIndex>=0){
			root->right = constractPostorderTreeUtil(postorder,postIndex,postorder[postIndex],key,max,n);
			root->left = constractPostorderTreeUtil(postorder,postIndex,postorder[postIndex],min,key,n);
		}
	}
	return root;
}

Node* constractPostorderTree(vector<int> &postorder){
	int n = postorder.size();
	int postIndex=n-1;
	return constractPostorderTreeUtil(postorder,postIndex,postorder[n-1],INT_MIN,INT_MAX,n);
}

// constract a tree from level order
Node* constractLevelorderTreeUtil(Node* root,int key){
	if(root == NULL) return new Node(key);
	if(key<root->data) 
		root->left = constractLevelorderTreeUtil(root->left,key);
	else
		root->right = constractLevelorderTreeUtil(root->right,key);
	return root;
}

Node* constractLevelorderTree(vector<int> &levelorder){
	int n = levelorder.size();

	Node* root = NULL;

	for(int i=0;i<n;i++){
		root = constractLevelorderTreeUtil(root,levelorder[i]);
	}
	return root;
}
// constract level order in O(n) time
// Node* getNode(int data) 
// { 
//     Node* temp = new Node(0); 
//     temp->data = data; 
//     temp->left = NULL; 
//     temp->right = NULL; 
//     return temp; 
// } 
  
// // Function to construct the BST 
// Node* constructBst(int arr[], int n) 
// { 
//     if (n == 0) 
//         return NULL; 
  
//     Node* root; 
  
//     queue<NodeDetails> q; 
  
//     // index variable to 
//     // access array elements 
//     int i = 0; 
  
//     // Node details for the 
//     // root of the BST 
//     NodeDetails newNode; 
//     newNode.ptr = getNode(arr[i++]); 
//     newNode.min = INT_MIN; 
//     newNode.max = INT_MAX; 
//     q.push(newNode); 
  
//     // Getting the root of the BST 
//     root = newNode.ptr; 
  
//     // Until there are no more 
//     // elements in arr[] 
//     while (i != n) { 
  
//         // Extracting NodeDetails of a 
//         // node from the queue 
//         NodeDetails temp = q.front(); 
//         q.pop(); 
  
//         // Check whether there are more elements 
//         // in the arr[] and arr[i] can be  
//         // left child of 'temp.ptr' or not 
//         if (i < n && (arr[i] < temp.ptr->data  
//                         && arr[i] > temp.min)) { 
  
//             // Create NodeDetails for newNode 
//             // and add it to the queue 
//             newNode.ptr = getNode(arr[i++]); 
//             newNode.min = temp.min; 
//             newNode.max = temp.ptr->data; 
//             q.push(newNode); 
  
//             // Make this 'newNode' as left child 
//             // of 'temp.ptr' 
//             temp.ptr->left = newNode.ptr; 
//         } 
  
//         // Check whether there are more elements 
//         // in the arr[] and arr[i] can be  
//         // right child of 'temp.ptr' or not 
//         if (i < n && (arr[i] > temp.ptr->data 
//                           && arr[i] < temp.max)) { 
  
//             // Create NodeDetails for newNode 
//             // and add it to the queue 
//             newNode.ptr = getNode(arr[i++]); 
//             newNode.min = temp.ptr->data; 
//             newNode.max = temp.max; 
//             q.push(newNode); 
  
//             // Make this 'newNode' as right  
//             // child of 'temp.ptr' 
//             temp.ptr->right = newNode.ptr; 
//         } 
//     } 
  
//     // Root of the required BST 
//     return root; 
// }

// finding tree is bst or not
bool isBSTUtil(Node* root,int min,int max){
	if(!root) return true;  
    if (root->data < min || root->data > max)  return false; 

    return
        isBSTUtil(node->left, min, root->data-1) && 
        isBSTUtil(node->right, root->data+1, max);
}
bool isBST(Node* root){
	if(!root) true;
	// [-2147483648] fails on this output on leetcode
	return isBSTUtil(root,INT_MIN,INT_MAX);
}
Node* LCA(Node* root,int n1,int n2){
	if(!root) return NULL;
	if(root->data>n1 && root->data >n2) return LCA(root->left,n1,n2);
	if(root->data <n1 && root->data <n2) return LCA(root->right,n1,n2);
	return root;
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
		// cout<<"nextpointer: ";nextpointer(root,4);cout<<endl;
		// cout<<"search: "<<search(root,7)<<endl;
		// root = constractPreorderTree(vec);
		// root = constractPostorderTree(vec);
		// root = constractLevelorderTree(vec);
		// inorderprint(root);
		cout<<"isbst: "<<isBST(root)<<endl;
	}
	return 0;
}