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
struct Node* rotate(struct Node *root,int k){
    if(k == 0) return root;
    struct Node *curr = root,*temp=root;
    while(curr!=NULL && k>1){
        curr = curr->next;
        k--;
    }
    if(curr == NULL || curr->next == NULL) return temp;
    struct Node *h = curr->next;
    curr->next=NULL;
    struct Node *fl = h;
    while(fl->next != NULL) fl = fl->next;
    fl->next = temp;
    return h;
}
 
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
	int t,n,a,m,k; cin>>t;
	while(t--){
		struct Node *root=NULL;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
        root = rotate(root,k);
        print(root);	
	}
	return 0;
}