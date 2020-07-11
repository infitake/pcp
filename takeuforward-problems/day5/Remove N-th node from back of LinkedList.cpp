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
// Deleting Bth node from last is basically same as deleting (length-B+1) from start. 
// In our approach first we evaluate the length of linked-list, then check

// If length < B, then we can’t remove the node
// If length = B, then return head->next
// If length > B, then it means we have to delete the intermediate node, 
// we will delete this node and make its prev node point to next node of deleted node.
Node* removeNthFromEnd(Node* head, int B) 
{ 
    // To store length of the linked list 
    int len = 0; 
    Node* tmp = head; 
    while (tmp != NULL) { 
        len++; 
        tmp = tmp->next;  
    } 
      
    // B > length, then we can't remove node 
    if (B > len)  
    { 
        cout << "Length of the linked list is " << len; 
        cout  << " we can't remove "<< B << "th node from the"; 
        cout << " linked list\n"; 
        return head;  
    } 
      
    // We need to remove head node 
    else if (B == len) { 
          
        // Return head->next 
        return head->next;  
          
    } 
    else 
    { 
        // Remove len - B th node from starting 
        int diff = len - B;           
        Node* prev= NULL;        
        Node* curr = head;          
        for(int i = 0;i < diff;i++){ 
            prev = curr;             
            curr = curr->next;       
        } 
        prev->next = curr->next; 
        return head; 
    } 
      
} 

// Method 2:
// Take two pointers, first will point to the head of the linked list and second will point to the Nth node from the beginning.
// Now keep increment both the pointers by one at the same time until second is pointing to the last node of the linked list.
// After the operations from the previous step, first pointer should be pointing to the Nth node from the end by now.
// So, delete the node first pointer is pointing to.
Node* deleteNode(int key) 
    { 
  
        // First pointer will point to 
        // the head of the linked list 
        Node *first = head; 
  
        // Second pointer will poin to the 
        // Nth node from the beginning 
        Node *second = head; 
        for (int i = 0; i < key; i++) 
        { 
  
            // If count of nodes in the given 
            // linked list is <= N 
            if (second->next == NULL)  
            { 
  
                // If count = N i.e. 
                // delete the head node 
                if (i == key - 1) 
                    head = head->next; 
                return head; 
            } 
            second = second->next; 
        } 
  
        // Increment both the pointers by one until 
        // second pointer reaches the end 
        while (second->next != NULL) 
        { 
            first = first->next; 
            second = second->next; 
        } 
  
        // First must be pointing to the 
        // Nth node from the end by now 
        // So, delete the node first is pointing to 
        first->next = first->next->next; 
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
	int t,n,a,m; cin>>t;
	while(t--){
		struct Node *root=NULL;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
		lastn(root,m);
		// print(root);
	}
	return 0;
}