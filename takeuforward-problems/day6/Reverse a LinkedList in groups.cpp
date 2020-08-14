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

struct Node* revs(struct Node *root){
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

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}
// Good Question 
// Method 1:
// 1
// 8 3
// 1 2 3 4 5 6 7 8
// you have 3 set of result 123 456 and 78 
// so first reverse first set and change the root pointer for another set
// Reverse the first sub-list of size k. While reversing keep track of the next node and previous node. Let the pointer to the next node be next and pointer to the previous node be prev. See this post for reversing a linked list.
// head->next = reverse(next, k) ( Recursively call for rest of the list and link the two sub-lists )
// Return prev ( prev becomes the new head of the list (see the diagrams of iterative method of this post) )

struct Node *grpreverse(struct Node *root,int k){
    struct Node *temp = root,*prev=NULL,*curr=root,*h=NULL,*last;
    int i=0;
    while(curr!=NULL && i<k){
        h=curr->next;
        curr->next=prev;
        prev=curr;
        curr=h;
        i++;
    }

    if(h!=NULL){
        root->next = grpreverse(h,k);
    }
    return prev;
}

// Method 2:
//  we have used a stack which will store the nodes of the given linked list.
//  Firstly, push the k elements of the linked list in the stack.
//  Now pop elements one by one and keep track of the previously popped node.
//  Point the next pointer of prev node to top element of stack. 
//  ////////////Repeat this process, until NULL is reached.

// This algorithm uses O(k) extra space.
struct Node* Reverse(struct Node* head, int k) 
{ 
    // Create a stack of Node* 
    stack<Node*> mystack; 
    struct Node* current = head; 
    struct Node* prev = NULL; 
  
    while (current != NULL) { 
  
        // Terminate the loop whichever comes first 
        // either current == NULL or count >= k 
        int count = 0; 
        while (current != NULL && count < k) { 
            mystack.push(current); 
            current = current->next; 
            count++; 
        } 
  
        // Now pop the elements of stack one by one 
        while (mystack.size() > 0) { 
  
            // If final list has not been started yet. 
            if (prev == NULL) { 
                prev = mystack.top(); 
                head = prev; 
                mystack.pop(); 
            } else { 
                prev->next = mystack.top(); 
                prev = prev->next; 
                mystack.pop(); 
            } 
        } 
    } 
  
    // Next of last element will point to NULL. 
    prev->next = NULL; 
  
    return head; 
}

// Method 3:
// Approach: Two different approaches to solve this problem have been discussed in Set 1 and Set 2 of this article. In this article, an approach based on deque will be discussed.
// Create a deque.
// Store the address of the first k nodes in the deque.
// Pop first and the last value from the deque and swap the data values at those addresses.
// Repeat step 3 till the deque is not empty.
// Repeat step 2 for the next k nodes and till the end of the linked list is not reached.
/* Function to reverse the linked list in groups of  
size k and return the pointer to the new head node. */
struct node* reverse(struct node* head, int k) 
{ 
  
    if (head == NULL) 
        return head; 
  
    // Create deque to store the address 
    // of the nodes of the linked list 
    deque<node*> q; 
  
    // Store head pointer in current to 
    // traverse the linked list 
    node* current = head; 
    int i; 
  
    // Iterate through the entire linked 
    // list by moving the current 
    while (current != NULL) { 
        i = 1; 
  
        // Store addresses of the k 
        // nodes in the deque 
        while (i <= k) { 
            if (current == NULL) 
                break; 
            q.push_back(current); 
            current = current->next; 
            i++; 
        } 
  
        /* pop first and the last value from  
        the deque and swap the data values at  
        those addresses 
        Do this till there exist an address in  
        the deque or deque is not empty*/
        while (!q.empty()) { 
            node* front = q.front(); 
            node* last = q.back(); 
            swap(front->data, last->data); 
  
            // pop from the front if 
            // the deque is not empty 
            if (!q.empty()) 
                q.pop_front(); 
  
            // pop from the back if 
            // the deque is not empty 
            if (!q.empty()) 
                q.pop_back(); 
        } 
    } 
    return head; 
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
		root=grpreverse(root,k);
        print(root);		
	}
	return 0;
}