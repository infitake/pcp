#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next = NULL;
	};
};
// struct Node *root=NULL;
struct Node* insert(struct Node *root,int key){
	struct Node *temp;
	temp=new Node(key);
	if(root == NULL) root = temp;
	else{
		struct Node *h=root;
		while(h->next!=NULL) h = h->next;
		h->next = temp;
	}
	return root;
}
// Method 1:
void deleteNode(struct Node **node){
    if((*node) == NULL) return;
    struct Node *temp = (*node)->next->next;
    swap((*node)->data,(*node)->next->data);
    (*node)->next = temp;
}
// This solution doesn’t work if the node to be deleted is the last node of the list. 
// To make this solution work we can mark the end node as a dummy node. 
// But the programs/functions that are using this function should also be modified.

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,m; cin>>t;
	while(t--){
		struct Node *root=NULL;
		cin>>n>>m;
        m--;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
		Node *node = root;
        while(m--){
            node=node->next;
        }
        // cout<<node->data<<endl;
        deleteNode(&node);
        print(root);
	}
	return 0;
}