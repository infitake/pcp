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

int ceil(Node* root,int k){
	if(!root) return -1;
	if(root->data  == k){
		return root->data;
	}
	if(root->data < k){
		return ceil(root->right,k);
	}
	
	int val = ceil(root->left,k);
	return (val>=k)?val:root->data;
}
int floor(Node* root,int k){
	if(!root) return INT_MAX;
	if(root->data  == k){
		return root->data;
	}
	if(root->data > k){
		return floor(root->left,k);
	}
	
	int val = floor(root->right,k);
	return (val<=k)?val:root->data;
}
int kthsmallestDistance(Node* root,int &k){
	if(!root) return -1;
    int l = kthsmallestDistance(root->left,k);
    if(l!=-1) return l;
    if(k == 1) return root->data;
    k--;
    return kthsmallestDistance(root->right,k);
}
int kthlargestDistance(Node* root,int &k){
	if(!root) return INT_MAX;
    int r = kthlargestDistance(root->right,k);
    if(r!=INT_MAX) return r;
    if(k == 1) return root->data;
    k--;
    return kthlargestDistance(root->left,k);
}

// This method take O(n) extra space
// this also not return all pair
// we have to find more space efficient
bool pairsumUtil(Node* root,int sum,set<int> &s){
	if(!root) return false;
	if(pairsumUtil(root->left,sum,s)) return true;

	if(s.find((sum-root->data))!=s.end()){
		cout<<root->data<<" "<<(sum-root->data)<<endl;
		return true;
	}else{
		s.insert(root->data);
	}
	return pairsumUtil(root->right,sum,s);

}

// bool pairsum(Node* root,int sum){
// 	set<int> s;
// 	return pairsumUtil(root,sum,s);
// }

// there is a itertive solution for the above recursive approach

bool pairsum(Node* root,int sum){
	stack<Node*> stk1,stk2;

	Node* temp = root;
	while(temp!=NULL){
		stk1.push(temp);temp = temp->left;
	}
	temp = root;
	while(temp!=NULL){
		stk2.push(temp);temp = temp->right;
	}
	while(stk1.top() != stk2.top()){
		int n1 = (stk1.top())->data,n2 = (stk2.top())->data;
		if(n1 + n2 == sum){
			cout<<n1<<" "<<n2<<endl;
			return true;
		}
		if(n1+n2<sum){
			temp = stk1.top();
			stk1.pop();
			temp = temp->right;
			while(temp!=NULL){
				stk1.push(temp);temp = temp->left;
			}
		}else{
			temp = stk2.top();
			stk2.pop();
			temp = temp->left;
			while(temp!=NULL){
				stk2.push(temp);temp = temp->right;
			}
		}
	}
	return false;
}
// This is for the iterator purpose(forward iterator)(in sorted order)
class bstit {
private:
	stack<Node*> stk;
public:
	bstit(Node* root){
		Node* temp = root;
		while(temp!=NULL){
			stk.push(temp);temp = temp->left;
		}
	}
	Node* curr(){
		return stk.top();
	}
	void next(){
		Node* temp = stk.top();
		stk.pop();
		temp = temp->right;
		while(temp != NULL){
			stk.push(temp);temp = temp->left;
		}
	}

	bool isEnd(){
		return !(stk.size());
	}
};

void iterators(bstit it){
	while(!it.isEnd()){
		cout<<(it.curr())->data<<" ";
		it.next();
	}
}
// for forward iterator question

// This is for the iterator purpose(backward iterator)(in sorted order)
class bstitb {
private:
	stack<Node*> stk;
public:
	bstitb(Node* root){
		Node* temp = root;
		while(temp!=NULL){
			stk.push(temp);temp = temp->right;
		}
	}
	Node* curr(){
		return stk.top();
	}
	void next(){
		Node* temp = stk.top();
		stk.pop();
		temp = temp->left;
		while(temp != NULL){
			stk.push(temp);temp = temp->right;
		}
	}

	bool isEnd(){
		return !(stk.size());
	}
};

void iteratorb(bstitb it){
	while(!it.isEnd()){
		cout<<(it.curr())->data<<" ";
		it.next();
	}
}
// for forward iterator question

// for finding largest bst size in a binary tree
bool isBSTUtil(Node* root,int min,int max){
	if(root==NULL) return true;
	if(root->data < min || root->data > max) return false;
	return isBSTUtil(root->left,min,root->data-1) &&
		   isBSTUtil(root->right,root->data+1,max);
}
bool isBST(Node* root){
	return isBSTUtil(root,INT_MIN,INT_MAX);
}

int size(Node* root){
	if(root==NULL) return 0;
	return 1+size(root->left)+size(root->right);
}

// int largestBSTBT(Node* root){
// 	if(isBST(root)){
// 		return size(root);
// 	}
// 	return max(largestBSTBT(root->left),largestBSTBT(root->right));
// }
// Method 2 for largestbstin bt (more effiecient)\
// Method 2 (Tricky and Efficient)
// In method 1, we traverse the tree in top down manner and do BST test for every node. If we traverse the tree in bottom up manner, then we can pass information about subtrees to the parent. 
// The passed information can be used by the parent to do BST test (for parent node) only in constant time (or O(1) time). 
// A left subtree need to tell the parent whether it is BST or not and also need to pass maximum value in it. So that we can compare the maximum value with the parent’s data to check the BST property. 
// Similarly, the right subtree need to pass the minimum value up the tree. The subtrees need to pass the following information up the tree for the finding the largest BST.
// 1) Whether the subtree itself is BST or not (In the following code, is_bst_ref is used for this purpose)
// 2) If the subtree is left subtree of its parent, then maximum value in it. And if it is right subtree then minimum value in it.
// 3) Size of this subtree if this subtree is BST (In the following code, return value of largestBSTtil() is used for this purpose)
int largestBSTSTUtil(Node* root,int &minval,int &maxval,int &finalmax,bool &isbst){
	if(root == NULL){
		isbst = true;
		return 0;
	}
	int min = INT_MAX;

	bool left_flag = false;
	bool right_flag = false;

	maxval = INT_MIN;

	int ls,rs;

	ls = largestBSTSTUtil(root->left,minval,maxval,finalmax,isbst);
	if(isbst && root->data > maxval) left_flag=true;

	min = minval;
	minval = INT_MAX;

	rs = largestBSTSTUtil(root->right,minval,maxval,finalmax,isbst);
	if(isbst && root->data < minval) right_flag=true;

	if(min < minval) minval = min;
	if(root->data < minval) minval = root->data; // for leaves
	if(root->data > maxval) maxval = root->data;

	if(left_flag && right_flag) {
		if(finalmax<(ls+rs+1)) finalmax = ls+rs+1;
		return ls+rs+1;
	}else{
		isbst = false;
		return 0;
	}

}

int largestBSTBT(Node* root){
	int min = INT_MAX;
	int max = INT_MIN;
	int maxsize = 0;
	bool isbst = false;
	return largestBSTSTUtil(root,min,max,maxsize,isbst);
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
		// for(int i=0;i<16;i++){
		// 	// cout<<"ceil of "<<i<<" :"<<ceil(root,i)<<endl;
		// 	cout<<"floor of "<<i<<" :"<<floor(root,i)<<endl;
		// }
		// int k = 2;
		// cout<<"kth smallest: "<<kthsmallestDistance(root,k)<<endl;
		// cout<<"kth largest: "<<kthlargestDistance(root,k)<<endl;
		// cout<<"pair sum: "<<pairsum(root,24)<<endl;
		// bstit it(root);
		// iterators(it);
		// bstitb it(root);
		// iteratorb(it);
		cout<<"largest bst in bt: "<<largestBSTBT(root)<<endl;

	}
	return 0;
}