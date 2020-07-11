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

// Method 1:using stack
bool isPalindrome(Node *head){
	stack<int> stk;
	struct Node* root = head,*node=head;
	while(root!=NULL){
		stk.push(root->data);
		root=root->next;
	}
	while(node!=NULL){
		int d = stk.top();
		stk.pop();
		if(d != node->data) return false;
		node = node->next; 
	}
	return true;
}

// METHOD 2 (By reversing the list)
// This method takes O(n) time and O(1) extra space.
// 1) Get the middle of the linked list.
// 2) Reverse the second half of the linked list.
// 3) Check if the first half and second half are identical.
// 4) Construct the original linked list by reversing the second half again and attaching it back to the first half

// To divide the list in two halves, method 2 of this post is used.
// When number of nodes are even, the first and second half contain exactly half nodes. 
// The challenging thing in this method is to handle the case when number of nodes are odd. 
// We don’t want the middle node as part of any of the lists as we are going to compare them for equality. 
// For odd case, we use a separate variable ‘midnode’.
  
/* Function to check if given linked list is 
  palindrome or not */
bool isPalindrome(struct Node* head) 
{ 
    struct Node *slow_ptr = head, *fast_ptr = head; 
    struct Node *second_half, *prev_of_slow_ptr = head; 
    struct Node* midnode = NULL; // To handle odd size list 
    bool res = true; // initialize result 
  
    if (head != NULL && head->next != NULL) { 
        /* Get the middle of the list. Move slow_ptr by 1 
          and fast_ptrr by 2, slow_ptr will have the middle 
          node */
        while (fast_ptr != NULL && fast_ptr->next != NULL) { 
            fast_ptr = fast_ptr->next->next; 
  
            /*We need previous of the slow_ptr for 
             linked lists  with odd elements */
            prev_of_slow_ptr = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
  
        /* fast_ptr would become NULL when there are even elements in list.  
           And not NULL for odd elements. We need to skip the middle node  
           for odd case and store it somewhere so that we can restore the 
           original list*/
        if (fast_ptr != NULL) { 
            midnode = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
  
        // Now reverse the second half and compare it with first half 
        second_half = slow_ptr; 
        prev_of_slow_ptr->next = NULL; // NULL terminate first half 
        reverse(&second_half); // Reverse the second half 
        res = compareLists(head, second_half); // compare 
  
        /* Construct the original list back */
        reverse(&second_half); // Reverse the second half again 
  
        // If there was a mid node (odd size case) which 
        // was not part of either first half or second half. 
        if (midnode != NULL) { 
            prev_of_slow_ptr->next = midnode; 
            midnode->next = second_half; 
        } 
        else
            prev_of_slow_ptr->next = second_half; 
    } 
    return res; 
} 
  
/* Function to reverse the linked list  Note that this 
    function may change the head */
void reverse(struct Node** head_ref) 
{ 
    struct Node* prev = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
  
/* Function to check if two input lists have same data*/
bool compareLists(struct Node* head1, struct Node* head2) 
{ 
    struct Node* temp1 = head1; 
    struct Node* temp2 = head2; 
  
    while (temp1 && temp2) { 
        if (temp1->data == temp2->data) { 
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        } 
        else
            return 0; 
    } 
  
    /* Both are empty reurn 1*/
    if (temp1 == NULL && temp2 == NULL) 
        return 1; 
  
    /* Will reach here when one is NULL 
      and other is not */
    return 0; 
} 

// METHOD 3 (Using Recursion)
// Use two pointers left and right. Move right and left using recursion and check for following in each recursive call.
// 1) Sub-list is palindrome.
// 2) Value at current left and right are matching.

// If both above conditions are true then return true.

// The idea is to use function call stack as container. Recursively traverse till the end of list. When we return from last NULL,
// we will be at last node. The last node to be compared with first node of list.

// In order to access first node of list, we need list head to be available in the last call of recursion.
// Hence we pass head also to the recursive function. If they both match we need to compare (2, n-2) nodes.
// Again when recursion falls back to (n-2)nd node, we need reference to 2nd node from head. We advance the head pointer in previous call, 
// to refer to next node in the list.

// However, the trick in identifying double pointer. 
// Passing single pointer is as good as pass-by-value, 
// and we will pass the same pointer again and again. 
// We need to pass the address of head pointer for reflecting the changes in parent recursive calls.

bool isPalindromeUtil(struct node** left, struct node* right) 
{ 
    /* stop recursion when right becomes NULL */
    if (right == NULL) 
        return true; 
  
    /* If sub-list is not palindrome then no need to 
    check for current left and right, return false */
    bool isp = isPalindromeUtil(left, right->next); 
    if (isp == false) 
        return false; 
  
    /* Check values at current left and right */
    bool isp1 = (right->data == (*left)->data); 
  
    /* Move left to next node */
    *left = (*left)->next; 
  
    return isp1; 
} 
  
// A wrapper over isPalindromeUtil() 
bool isPalindrome(struct node* head) 
{ 
    isPalindromeUtil(&head, head); 
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
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			root=insert(root,a);
		}
		cout<<isPalindrome(root)<<endl;
		
        
	}
	return 0;
}