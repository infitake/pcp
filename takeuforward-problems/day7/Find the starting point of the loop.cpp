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
int startpoint(struct Node *loop,struct Node *root){
    struct Node *ptr1,*ptr2;
    ptr1=loop;ptr2=loop;
    int k=1;
    while(ptr1->next != ptr2){
        ptr1 = ptr1->next;
        k++;
    }
    ptr1 = root;
    ptr2 = root;
    while(k--){
        ptr1=ptr1->next;
    }
    while(ptr1 != ptr2){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return ptr1->data;
}

int detectloop(struct Node* root){
    struct Node *fast=root,*slow=root;
    while(slow!=NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return startpoint(slow,root);
        }
    }
    return -1;
}

// Method 2:
// Function to detect and remove loop 
// in a linked list that may contain loop 
Node* detectAndRemoveLoop(Node* head) 
{ 
    // If list is empty or has only one node 
    // without loop 
    if (head == NULL || head->next == NULL) 
        return NULL; 
  
    Node *slow = head, *fast = head; 
  
    // Move slow and fast 1 and 2 steps 
    // ahead respectively. 
    slow = slow->next; 
    fast = fast->next->next; 
  
    // Search for loop using slow and 
    // fast pointers 
    while (fast && fast->next) { 
        if (slow == fast) 
            break; 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
  
    // If loop does not exist 
    if (slow != fast) 
        return NULL; 
  
    // If loop exists. Start slow from 
    // head and fast from meeting point. 
    slow = head; 
    while (slow != fast) { 
        slow = slow->next; 
        fast = fast->next; 
    } 
  
}

// Method 3:
ListNode* detectCycle(ListNode* A) 
{ 
  
    // declaring map to store node address 
    unordered_set<ListNode*> uset; 
  
    ListNode *ptr = A; 
  
    // Default consider that no cycle is present 
    while (ptr != NULL) { 
  
        // checking if address is already present in map  
        if (uset.find(ptr) != uset.end())  
          return ptr; 
  
        // if address not present then insert into the set 
        else 
            uset.insert(ptr);  
          
        ptr = ptr->next; 
    } 
    return NULL; 
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
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
        root->next->next->next->next->next = root->next->next; 
		cout<<detectloop(root)<<endl;
    }
	return 0;
}