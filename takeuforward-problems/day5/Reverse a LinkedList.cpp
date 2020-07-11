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

// Method 1:(simple iterative)
struct Node* reverse(struct Node *root) {
	struct Node *pre=NULL,*curr=root;
	struct Node *h=NULL;
	while(curr != NULL){
		h = curr->next;
		curr->next = pre;
		pre = curr;
		curr = h;
	}
	root = pre;
	return root;
}
// Method 2: (recursive method)
 // 1) Divide the list in two parts - first node and 
 //      rest of the linked list.
 //   2) Call reverse for the rest of the linked list.
 //   3) Link rest to first.
 //   4) Fix head pointer
Node* reverse(Node* head) 
    { 
        if (head == NULL || head->next == NULL) 
            return head; 
  
        /* reverse the rest list and put  
          the first element at the end */
        Node* rest = reverse(head->next); 
        head->next->next = head; 
  
        /* tricky step -- see the diagram */
        head->next = NULL; 
  
        /* fix the head pointer */
        return rest; 
 }

 // Method 3:
  
// A simple and tail recursive function to reverse 
// a linked list.  prev is passed as NULL initially. 
void reverseUtil(Node* curr, Node* prev, Node** head) 
{ 
    /* If last node mark it head*/
    if (!curr->next) { 
        *head = curr; 
  
        /* Update next to prev node */
        curr->next = prev; 
        return; 
    } 
  
    /* Save curr->next node for recursive call */
    Node* next = curr->next; 
  
    /* and update next ..*/
    curr->next = prev; 
  
    reverseUtil(next, curr, head); 
}  

 void reverse(Node** head) 
{ 
    if (!head) 
        return; 
    reverseUtil(*head, NULL, head); 
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
	int t,n,a; cin>>t;
	while(t--){
		struct Node *root=NULL;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
		root=reverse(root);
		print(root);
	}
	return 0;
}