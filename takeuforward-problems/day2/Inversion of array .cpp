#include <bits/stdc++.h>
using namespace std;

// METHOD 1 (Simple)

// Approach :Traverse through the array and for every index find the number of smaller elements on its right side of the array. 
// This can be done using a nested loop. Sum up the counts for all index in the array and print the sum.
// Algorithm :
// Traverse through the array from start to end
// For every element find the count of elements smaller than the current number upto that index using another loop.
// Sum up the count of inversion for every index.
// Print the count of inversions.
int getInvCount(int arr[], int n) 
{ 
    int inv_count = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] > arr[j]) 
                inv_count++; 
  
    return inv_count; 
} 

// Complexity Analysis:
// Time Complexity: O(n^2), Two nested loops are needed to traverse the array from start to end so the Time complexity is O(n^2)
// Space Compelxity:O(1), No extra space is required.


// METHOD 2(Enhance Merge Sort)

// Approach:
// Suppose the number of inversions in the left half and right half of the array (let be inv1 and inv2), what kinds of inversions are not accounted for in Inv1 + Inv2?
//  The answer is – the inversions that need to be counted during the merge step.
//  Therefore, to get a number of inversions, that needs to be added a number of inversions in the left subarray, right subarray and merge().
// inv_count1
// How to get number of inversions in merge()?
// In merge process, let i is used for indexing left sub-array and j for right sub-array. At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions. 
// because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]

// Algorithm:
// The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step until the base case is reached.
// Create a function merge that counts the number of inversions when two halves of the array are merged, create two indices i and j, i is the index for first half and j is an index of the second half. 
// if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
// Create a recursive function to divide the array into halves and find the answer by summing the number of inversions is the first half, number of inversion in the second half and the number of inversions by merging the two.
// The base case of recursion is when there is only one element in the given half.
// Print the answer

int merge(int arr[],int l,int mid,int r){
	int i=l,j=mid;
	int temp[r],k=l,inv=0;
	while(i<=mid-1 && j<=r){
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else{
			temp[k++]=arr[j++];
			inv += (mid-i);
		}
	}
	while(i<=(mid-1)){
		temp[k++]=arr[i++];
	}
	while(j<=r){
		temp[k++]=arr[j++];
	}
	for (i = l; i <= r; i++) 
        arr[i] = temp[i]; 
	return inv;

}

int mergesort(int arr[],int l,int r){
	int inv=0;
	if(l<r){
		int mid = l+(r-l)/2;
		inv +=mergesort(arr,l,mid);
		inv +=mergesort(arr,mid+1,r);
		inv +=merge(arr,l,mid+1,r);
	}
	return inv;
}

// Method 3:(using set in stl)
// Create an empty Set in C++ STL (Note that a Set in C++ STL is 
//    implemented using Self-Balancing Binary Search Tree). And insert
//    first element of array into the set.

// 2) Initialize inversion count as 0.

// 3) Iterate from 1 to n-1 and do following for every element in arr[i]
//      a) Insert arr[i] into the set.
//      b) Find the first element greater than arr[i] in set
//         using upper_bound() defined Set STL.
//      c) Find distance of above found element from last element in set
//         and add this distance to inversion count.

// 4) Return inversion count.
int getInvCount(int arr[],int n) 
{ 
    // Create an empty set and insert first element in it 
    multiset<int> set1; 
    set1.insert(arr[0]); 
  
    int invcount = 0; // Initialize result 
  
    multiset<int>::iterator itset1; // Iterator for the set 
  
    // Traverse all elements starting from second 
    for (int i=1; i<n; i++) 
    { 
        // Insert arr[i] in set (Note that set maintains 
        // sorted order) 
        set1.insert(arr[i]); 
  
        // Set the iterator to first greater element than arr[i] 
        // in set (Note that set stores arr[0],.., arr[i-1] 
        itset1 = set1.upper_bound(arr[i]); 
  
        // Get distance of first greater element from end 
        // and this distance is count of greater elements 
        // on left side of arr[i] 
        invcount += distance(itset1, set1.end()); 
    } 
  
    return invcount; 
} 

//  Method 4:(using AVL Trees)
// An AVL tree node 
// Approach: The idea is to use Self-Balancing Binary Search Tree like Red-Black Tree, AVL Tree, etc and augment it so that every node also keeps track of number of nodes in right subtree. 
// So every node will contain the count of nodes in its right subtree i.e. the number of nodes greater than that number. So it can be seen that the count increases when there is a pair (a,b), where a appears before b in the array and a > b, So as the array is traversed from start to the end, 
// add the elements to the AVL tree and the count of the nodes in its right subtree of the newly inserted node will be the count increased or the number of pairs (a,b) where b is the present element.

// Algorithm:

// Create an AVL tree, with a property that every node will contain the size of its subtree.
// Traverse the array from start to the end.
// For every element insert the element in the AVL tree
// The count of the nodes which are greater than the current element can be found out by checking the size of the subtree of its right children, So it can be guaranteed that elements in the right subtree of current node have index less than the current element and their values are greater than the current element.
// So those element satisfy the criteria.
// So increase the count by size of subtree of right child of the current inserted node.
// Display the count.
struct Node 
{ 
    int key, height; 
    struct Node *left, *right; 
  
// size of the tree rooted with this Node 
    int size;  
}; 
  
// A utility function to get the height of 
// the tree rooted with N 
int height(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 
  
// A utility function to size of the 
// tree of rooted with N 
int size(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->size; 
} 
  
/* Helper function that allocates a new Node with 
the given key and NULL left and right pointers. */
struct Node* newNode(int key) 
{ 
    struct Node* node = new Node; 
    node->key   = key; 
    node->left   = node->right  = NULL; 
    node->height = node->size = 1; 
    return(node); 
} 
  
// A utility function to right rotate  
// subtree rooted with y 
struct Node *rightRotate(struct Node *y) 
{ 
    struct Node *x = y->left; 
    struct Node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), 
 height(y->right))+1; 
    x->height = max(height(x->left), 
 height(x->right))+1; 
  
    // Update sizes 
    y->size = size(y->left) + size(y->right) + 1; 
    x->size = size(x->left) + size(x->right) + 1; 
  
    // Return new root 
    return x; 
} 
  
// A utility function to left rotate  
// subtree rooted with x 
struct Node *leftRotate(struct Node *x) 
{ 
    struct Node *y = x->right; 
    struct Node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Update sizes 
    x->size = size(x->left) + size(x->right) + 1; 
    y->size = size(y->left) + size(y->right) + 1; 
  
    // Return new root 
    return y; 
} 
  
// Get Balance factor of Node N 
int getBalance(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 
  
// Inserts a new key to the tree rotted with Node. Also, updates 
// *result (inversion count) 
struct Node* insert(struct Node* node, int key, int *result) 
{ 
    /* 1.  Perform the normal BST rotation */
    if (node == NULL) 
        return(newNode(key)); 
  
    if (key < node->key) 
    { 
        node->left  = insert(node->left, key, result); 
  
        // UPDATE COUNT OF GREATE ELEMENTS FOR KEY 
        *result = *result + size(node->right) + 1; 
    } 
    else
        node->right = insert(node->right, key, result); 
  
    /* 2. Update height and size of this ancestor node */
    node->height = max(height(node->left), 
                       height(node->right)) + 1; 
    node->size = size(node->left) + size(node->right) + 1; 
  
    /* 3. Get the balance factor of this ancestor node to 
          check whether this node became unbalanced */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then there are 
    // 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
// The following function returns inversion count in arr[] 
int getInvCount(int arr[], int n) 
{ 
  struct Node *root = NULL;  // Create empty AVL Tree 
  
  int result = 0;   // Initialize result 
  
  // Starting from first element, insert all elements one by 
  // one in an AVL tree. 
  for (int i=0; i<n; i++) 
  
     // Note that address of result is passed as insert 
     // operation updates result by adding count of elements 
     // greater than arr[i] on left of arr[i] 
     root = insert(root, arr[i], &result); 
  
  return result; 
} 
  


int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n; cin>>t;
	while(t--){
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		cout<<mergesort(arr,0,n-1)<<endl;
	}
	return 0;
}