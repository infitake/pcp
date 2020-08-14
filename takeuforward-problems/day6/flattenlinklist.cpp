// C++ program for Flattening 
// a linked list using Heaps 
#include <bits/stdc++.h> 
using namespace std; 

// Structure of given Linked list 
struct Node { 
	int data; 
	struct Node* right; 
	struct Node* left; 

	Node(int x) 
	{ 
		data = x; 
		right = NULL; 
		left = NULL; 
	} 
}; 

// Function to print the 
// linked list 
void printList(Node* Node) 
{ 
	while (Node != NULL) { 
		printf("%d ", Node->data); 
		Node = Node->left; 
	} 
} 

// Function that compares the value 
// pointed by node and returns true 
// if first data is greater 
struct compare { 
	bool operator()(Node* a, Node* b) 
	{ 
		return a->data > b->data; 
	} 
}; 

// Function which returns the root 
// of the flattened linked list 
Node* flatten(Node* root) 
{ 
	Node* ptr = root; 
	Node* head = NULL; 

	// Min Heap which will return 
	// smallest element currently 
	// present in heap 
	priority_queue<Node*, 
				vector<Node*>, 
				compare> 
		pq; 

	// Push the head nodes of each 
	// leftward linked list 
	while (ptr != NULL) { 
		pq.push(ptr); 
		ptr = ptr->right; 
	} 

	// This loop will execute 
	// till the map becomes empty 
	while (!pq.empty()) { 

		// Pop out the node that 
		// contains element 
		// currently in heap 
		Node* temp = pq.top(); 
		pq.pop(); 

		// Push the next node pointed by 
		// the current node into heap 
		// if it is not null 
		if (temp->left != NULL) { 
			pq.push(temp->left); 
		} 

		// Create new linked list 
		// that is to be returned 
		if (head == NULL) { 
			head = temp; 
			ptr = temp; 
		} 
		else { 
			ptr->left = temp; 
			ptr = temp; 
		} 
	} 

	// Pointer to head node 
	// in the linked list 
	return head; 
} 

// Create and push new nodes 
void push(Node** head_ref, 
		int new_data) 
{ 
	Node* new_node = (Node*)malloc(sizeof(Node)); 
	new_node->right = NULL; 
	new_node->data = new_data; 
	new_node->left = (*head_ref); 

	(*head_ref) = new_node; 
} 

// Driver Code 
int main() 
{ 
	Node* root = NULL; 

	// Given Linked List 
	push(&root, 30); 
	push(&root, 8); 
	push(&root, 7); 
	push(&root, 5); 

	push(&(root->right), 20); 
	push(&(root->right), 10); 

	push(&(root->right->right), 50); 
	push(&(root->right->right), 22); 
	push(&(root->right->right), 19); 

	push(&(root->right->right->right), 45); 
	push(&(root->right->right->right), 40); 
	push(&(root->right->right->right), 35); 
	push(&(root->right->right->right), 20); 

	// Flatten the list 
	root = flatten(root); 

	// Print the flatened linked list 
	printList(root); 

	return 0; 
} 
