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
void preorderprint(struct Node* root){
	if(!root) return;
	cout<<root->data<<" ";
	preorderprint(root->left);
	preorderprint(root->right);
}
void postorderprint(struct Node* root){
	if(!root) return;
	postorderprint(root->left);
	postorderprint(root->right);
	cout<<root->data<<" ";
}

void leftviewTree(struct Node* root){
	if(!root) return;
	queue<Node*> q;
	q.push(root);
	Node* temp;
	vector<int> v;
	while(!q.empty()){
		int k = q.size();
		temp = q.front();
		v.push_back(temp->data);
		while(k--){
			temp = q.front();
			q.pop();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
	for(auto x:v) cout<<x<<" ";
}
void rightviewTree(struct Node* root){
	if(!root) return;
	queue<Node*> q;
	q.push(root);
	Node* temp;
	vector<int> v;
	while(!q.empty()){
		int k = q.size();
		temp = q.back();
		v.push_back(temp->data);
		while(k--){
			temp = q.front();
			q.pop();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
	for(auto x:v) cout<<x<<" ";
}

// for bottom view or top view we use the horizontal distance for finding view
// for left we just decrease horizontal distance by 1
// for right we just increase horizontal distance by 1
void topviewTreeUtil(struct Node *root,map<int,int> &mp,int h){
	if(!root) return;
	if(mp[h]==0) mp[h]=root->data;
	topviewTreeUtil(root->left,mp,h-1);
	topviewTreeUtil(root->right,mp,h+1);
}

void topviewTree(struct Node* root){
	if(!root) return;
	map<int,int> mp;
	topviewTreeUtil(root,mp,0);
	// cout<<"dkd"<<endl;
	for(auto x:mp) cout<<x.second<<" ";
}
void bottomviewTreeUtil(struct Node *root,map<int,int> &mp,int h){
	if(!root) return;
	mp[h]=root->data;
	bottomviewTreeUtil(root->left,mp,h-1);
	bottomviewTreeUtil(root->right,mp,h+1);
}

void bottomviewTree(struct Node* root){
	if(!root) return;
	map<int,int> mp;
	bottomviewTreeUtil(root,mp,0);
	// cout<<"dkd"<<endl;
	for(auto x:mp) cout<<x.second<<" ";
}

void levelorder(Node *root){
	if(!root) return;
	queue<Node*> q;
	q.push(root);
	Node* temp;
	vector<int> v;
	while(!q.empty()){
		temp = q.front();
		v.push_back(temp->data);
		q.pop();
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
	for(auto x:v) cout<<x<<" ";
}

int height(Node *root){
	if(!root) return 0;
	int l=height(root->left);
	int r=height(root->right);
	return max(l,r)+1;
}
int diameterutil(Node* root,int &h){
	int lh=0,rh=0,ld=0,rd=0;
	if(!root){
		h=0;
		return 0;
	}
	ld = diameterutil(root->left,lh);
	rd = diameterutil(root->right,rh);
	h = max(lh,rh)+1;
	return max(lh+rh+1,max(ld,rd));
}

int diameter(Node* root){
	int h = 0;
	int k = diameterutil(root,h);
	return h;
}

// Method 1:
bool balancedornot(Node* root){
	if(!root)
        return true;
    if(root->left == NULL&&root->right==NULL)
        return true;
    int l = height(root->left);
    int r = height(root->right);
    // cout<<l<<" "<<r<<endl;
    if(abs(l-r)<=1 &&balancedornot(root->left)&&balancedornot(root->right))
        return true;
    else
        return false;	
}
// Method 2(finding height in same recursion)
bool balancedornotUtil(Node *root,int &h){
	int lh=0,rh=0;
	if(!root){
		h=0;
		return true;
	}

	bool l = balancedornotUtil(root->left,lh);
	bool r = balancedornotUtil(root->right,rh);

	h = max(l,r)+1;

	if(abs(lh-rh)>=2) return false;

	return l&&h;
}

// bool balancedornot(Node* root){
// 	int h=0;
// 	return balancedornotUtil(root,h);
// }

// Method 1: for finding lca in binarya tree (By Storing root to n1 and root to n2 paths):
// Following is simple O(n) algorithm to find LCA of n1 and n2.
// 1) Find path from root to n1 and store it in a vector or array.
// 2) Find path from root to n2 and store it in another vector or array.
// 3) Traverse both paths till the values in arrays are same. 
// Return the common element just before the mismatch
// lca for binary tree
// bool findpathrootton(Node* root,int n,vector<int> &vec) {
// 	if(!root) return false;
// 	vec.push_back(root->data);
// 	if(root->data == n) return true;

// 	if((root->left && findpathrootton(root->left,n,vec))||(root->right,findpathrootton(root->right,n,vec)))
// 		return true;
// 	vec.pop_back();
// 	return false;
// }

// int lcaBinaryTree(Node* root,int n1,int n2){
// 	vector<int> vec1,vec2;

// 	// path is not found from root
// 	if(!findpathrootton(root,n1,vec1) || !findpathrootton(root,n2,vec2)) return -1;

// 	int i;
// 	for(i=0;i<vec1.size()&&i<vec2.size();i++){
// 		if(vec1[i]!=vec2[i]) break;
// 	}
// 	// cout<<"hello"<<endl;
// 	return vec1[i-1];

// }

// Method 2 (Using Single Traversal)
// The method 1 finds LCA in O(n) time, but requires three tree traversals plus extra spaces for path arrays. 
// If we assume that the keys n1 and n2 are present in Binary Tree, 
// we can find LCA using single traversal of Binary Tree and without extra storage for path arrays.
Node* lcaBinaryTreeUtil(Node *root,int n1,int n2,bool &v1,bool &v2) {
	if(!root) return NULL;

	if(root->data == n1){
		v1=true;
		return root;
	}
	if(root->data == n2){
		v2 = true;
		return root;
	}

	Node *lroot = lcaBinaryTreeUtil(root->left,n1,n2,v1,v2);
	Node *rroot = lcaBinaryTreeUtil(root->right,n1,n2,v1,v2);

	if(lroot && rroot) return root;

	return (lroot!=NULL)?lroot:rroot;
}

bool find(Node *root,int n){
	if(!root) return false;

	if((root->data == n) || find(root->left,n) || find(root->right,n)){
		return true;
	}
	return false;
}

int lcaBinaryTree(Node* root,int n1,int n2){
	bool v1=false,v2=false;

	Node* lca = lcaBinaryTreeUtil(root,n1,n2,v1,v2);
	if((v1&&v2) || (v1 && find(lca,n2)) || (v2 && find(lca,n1))) return lca->data;

	return -1;
}

// 2 TREES ARE IDENTICAL OR NOT
 bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q== NULL) return true;
        if(p!=NULL && q!=NULL)
            if((p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right)) return true;
        return false;
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
		// cout<<"inorder: "; inorderprint(root); cout<<endl;
		// cout<<"preorder: "; preorderprint(root); cout<<endl;
		// cout<<"postorder: "; postorderprint(root); cout<<endl;
		// cout<<"left view: "; leftviewTree(root); cout<<endl;
		// cout<<"right view: "; rightviewTree(root); cout<<endl;
		// cout<<"top view: "; topviewTree(root); cout<<endl;
		// cout<<"bottom view: "; bottomviewTree(root); cout<<endl;
		// cout<<"level order: "; levelorder(root); cout<<endl;
		// cout<<"height: "<<height(root)<<endl;
		// cout<<"diameter: "<<diameter(root)<<endl;
		// cout<<"balancedornot: "<<balancedornot(root)<<endl;
		cout<<"lca binary tree: "<<lcaBinaryTree(root,5,4)<<endl;
	}
	return 0;
}