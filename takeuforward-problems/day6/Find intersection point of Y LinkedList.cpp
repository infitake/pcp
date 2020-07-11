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

void print(struct Node *root){
	struct Node *h = root;
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}
// Method 1:
int intersection(struct Node *root1,struct Node *root2,int d){
	struct Node *node1=root1,*node2=root2;
	while(d--){
		node1=node1->next;
	}
	while(node1!=NULL && node2!=NULL){
		// cout<<node1->data <<" "<<node2->data<<endl;
		if(node1->data == node2->data) return node1->data;
		node1 =node1->next;
		node2=node2->next;
	}
	return -1;
}
// complexity:O(m+n)
// space:O(1)

// Method 2:
// 1) Let X be the length of the first linked list until intersection point.
//    Let Y be the length of the second linked list until the intersection point.
//    Let Z be the length of the linked list from the intersection point to End of
//    the linked list including the intersection node.
//    We Have
//            X + Z = C1;
//            Y + Z = C2;
// 2) Reverse first linked list.
// 3) Traverse Second linked list. Let C3 be the length of second list - 1. 
//      Now we have
//         X + Y = C3
//      We have 3 linear equations. By solving them, we get
//        X = (C1 + C3 – C2)/2;
//        Y = (C2 + C3 – C1)/2;
//        Z = (C1 + C2 – C3)/2;
//       WE GOT THE INTERSECTION POINT.
// 4)  Reverse first linked list.
// Advantage: No Comparison of pointers.
// Disadvantage : Modifying linked list(Reversing list).

// Time complexity: O(m+n)
// Auxiliary Space: O(1)


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
		struct Node *root1=NULL,*root2=NULL;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a;
			root1=insert(root1,a);
		}
		for(int i=0;i<m;i++){
			cin>>a;
			root2=insert(root2,a);
		}
		int point;
		int len1=len(root1);
		int len2=len(root2);
		int d= abs(len1-len2);
		if(len1>len2){
			point = intersection(root1,root2,d);
			// print(root1);
		}
		else {
			point = intersection(root2,root1,d);
			// print(root2);
		}
		cout<<point<<endl;
        
	}
	return 0;
}