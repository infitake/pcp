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
int len(struct Node *root){
	int a=0;
	while(root!=NULL) {
		root=root->next;
		a++;
	}
	return a;
}

Node *swapkthnode(Node* head, int k) {
    int n = len(head);

    // if k is greater than size of linked list
    if(k>n) return head;

    // if k is same from both front and back

    if((2*k)-1 == n) return head;


    Node *first = head,*first_pre=NULL;
    for(int i=1;i<k;i++){
        first_pre = first;
        first = first->next;
    }

    Node *second = head,*second_pre=NULL;
    for(int i=1;i<(n-k+1);i++){
        second_pre=second;
        second = second->next;
    }

    if(first_pre)
        first_pre->next=second;
    if(second_pre)
        second_pre->next=first;

    Node* temp=first->next;
    first->next = second->next;
    second->next = temp;

    if(k==1) return second;
    if(k == n) return first;

    return head;
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
		root=swapkthnode(root,k);
        print(root);		
	}
	return 0;
}