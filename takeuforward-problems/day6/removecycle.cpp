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
// similar like finding middle
// use 2 pointer one is fast and other is slow
// if fast pointer equals slow then loop
//  Floyd’s Cycle-Finding Algorithm
// Approach: This is the fastest method and has been described below:

// Traverse linked list using two pointers.
// Move one pointer(slow_p) by one and another pointer(fast_p) by two. 
// If these pointers meet at the same node then there is a loop. 
// If pointers do not meet then linked list doesn’t have a loop.
void rmcycle(struct Node *loop,struct Node *root){
	struct Node *ptr1,*ptr2;
	ptr1=root;
	while(1){
		ptr2 = loop;
		while(ptr2->next!=loop && ptr2->next != ptr1){
			ptr2=ptr2->next;
		}
		if(ptr2->next == ptr1) break;
		ptr1 = ptr1->next;
	}
	ptr2->next = NULL;
}

// Method 2 (Better Solution)

// This method is also dependent on Floyd’s Cycle detection algorithm.
// Detect Loop using Floyd’s Cycle detection algorithm and get the pointer to a loop node.
// Count the number of nodes in loop. Let the count be k.
// Fix one pointer to the head and another to a kth node from the head.
// Move both pointers at the same pace, they will meet at loop starting node.
// Get a pointer to the last node of the loop and make next of it as NULL.

void rmLoop(struct Node* loop_node, struct Node* head) 
{ 
    struct Node* ptr1 = loop_node; 
    struct Node* ptr2 = loop_node; 
  
    // Count the number of nodes in loop 
    unsigned int k = 1, i; 
    while (ptr1->next != ptr2) { 
        ptr1 = ptr1->next; 
        k++; 
    } 
  
    // Fix one pointer to head 
    ptr1 = head; 
  
    // And the other pointer to k nodes after head 
    ptr2 = head; 
    for (i = 0; i < k; i++) 
        ptr2 = ptr2->next; 
  
    /*  Move both pointers at the same pace, 
      they will meet at loop starting node */
    while (ptr2 != ptr1) { 
        ptr1 = ptr1->next; 
        ptr2 = ptr2->next; 
    } 
  
    // Get pointer to the last node 
    while (ptr2->next != ptr1) 
        ptr2 = ptr2->next; 
  
    /* Set the next node of the loop ending node 
      to fix the loop */
    ptr2->next = NULL; 
} 

bool detectloop(struct Node *root) {
    struct Node *fast = root,*slow = root;
    while (slow && fast && fast->next) { 
        slow = slow->next; 
        fast = fast->next->next; 
        if (slow == fast) { 
        	rmcycle(slow,root);
            return true; 
        } 
    } 
    return false; 
}

// Method 3 (Optimized Method 2: Without Counting Nodes in Loop)
// We do not need to count number of nodes in Loop. After detecting the loop, if we start slow pointer from head and move both slow and fast pointers at same speed until fast don’t meet, they would meet at the beginning of the loop.

// How does this work?
// Let slow and fast meet at some point after Floyd’s Cycle finding algorithm. Below diagram shows the situation when cycle is found.




// LinkedListCycle

// We can conclude below from above diagram


// Distance traveled by fast pointer = 2 * (Distance traveled 
//                                          by slow pointer)

// (m + n*x + k) = 2*(m + n*y + k)

// Note that before meeting the point shown above, fast
// was moving at twice speed.

// x -->  Number of complete cyclic rounds made by 
//        fast pointer before they meet first time

// y -->  Number of complete cyclic rounds made by 
//        slow pointer before they meet first time

// From above equation, we can conclude below

//     m + k = (x-2y)*n

// Which means m+k is a multiple of n. 
// So if we start moving both pointers again at same speed such that one pointer (say slow) begins from head node of linked list and other pointer (say fast) begins from meeting point. When slow pointer reaches beginning of loop (has made m steps), fast pointer would have made also moved m steps as they are now moving same pace. Since m+k is a multiple of n and fast starts from k, they would meet at the beginning. Can they meet before also? No because slow pointer enters the cycle first time after m steps.


void detectAndRemoveLoop(Node* head) 
{ 
    // If list is empty or has only one node 
    // without loop 
    if (head == NULL || head->next == NULL) 
        return; 
  
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
  
    /* If loop exists */
    if (slow == fast) { 
        slow = head; 
        while (slow->next != fast->next) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
  
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    } 
} 

// Method 4 Hashing: Hash the address of the linked list nodes
// We can hash the addresses of the linked list nodes in an unordered map and just check if the element already exists in the map. 
// If it exists, we have reached a node which already exists by a cycle,
// hence we need to make the last node’s next pointer NULL.
void hashAndRemove(Node* head) 
{ 
    // hash map to hash addresses of the linked list nodes 
    unordered_map<Node*, int> node_map; 
    // pointer to last node 
    Node* last = NULL; 
    while (head != NULL) { 
        // if node not present in the map, insert it in the map 
        if (node_map.find(head) == node_map.end()) { 
            node_map[head]++; 
            last = head; 
            head = head->next; 
        } 
        // if present, it is a cycle, make the last node's next pointer NULL 
        else { 
            last->next = NULL; 
            break; 
        } 
    } 
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
        root->next->next->next->next = root; 
		if(detectloop(root)) cout<<"loop"<<endl;
        else cout<<"no loop"<<endl;		
        if(detectloop(root)) cout<<"loop"<<endl;
        else cout<<"no loop"<<endl;		
	}
	return 0;
}