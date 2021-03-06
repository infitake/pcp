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
// void middle(struct Node *root){
// 	struct Node *fast = root,*slow=root;
// 	while(fast->next!=NULL){
// 		fast = fast->next;
// 		if(fast->next!=NULL){
// 			fast=fast->next;
// 			slow=slow->next;
// 		}
// 	}
// 	cout<<slow->data<<" "<<endl;
// }

// // Method 2:
// void middle(struct Node *head) 
// { 
//     int count = 0; 
//     struct Node *mid = head; 
  
//     while (head != NULL) 
//     { 
//         /* update mid, when 'count' is odd number */
//         if (count & 1) 
//             mid = mid->next; 
  
//         ++count; 
//         head = head->next; 
//     } 
  
//     /* if empty list is provided */
//     if (mid != NULL) 
//         printf("The middle element is [%d]\n\n", mid->data); 
// } 
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
struct Node* rotateRight(struct Node* head, int k) {
        int l = 0;
        struct Node* node = head,*curr=head,*pre=NULL;
        while(node!=NULL){
            l++;
            node = node->next;
        }
        node = head;
        if(k==l) return head;
        if(k==0) return reverse(head);
        k = k%l;
        int pos = l-k;
        while(curr!=NULL && pos--){
            pre = curr;
            curr = curr->next;
        }
        head = curr;
        pre->next = NULL;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=node;
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
	int t,n,a,k; cin>>t;
	while(t--){
		struct Node *root=NULL;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
		// middle(root);
		root = rotateRight(root,k);
		print(root);
	}
	return 0;
}