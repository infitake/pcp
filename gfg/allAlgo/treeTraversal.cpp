#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define pii pair<ll,ll>
#define vec1 vector<ll>
#define vec2 vector<ll,ll>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep1(i,b) for(ll i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((ll)(x).size())
#define S(x) scanf("%d",&(x))
#define S2(x,y) scanf("%d%d",&(x),&(y))
#define SL(x) scanf("%lld",&(x))
#define SL2(x) scanf("%lld%lld",&(x),&(y))
#define P(x) printf("%d\n",(x))
#define FT first
#define SN second

struct tree{
	ll data;
	struct tree *left;
	struct tree *right;
};

struct tree* createNode(ll a) {
	struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
	temp->data = a;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(struct tree *root,ll a){
	queue<struct tree*> q;
	q.push(root);
	// cout<<"before queue"<<endl;
	while(!q.empty()){
		struct tree *root = q.front();
		q.pop();
		// if(!root) root = createNode(a);
		// else{
		// cout<<"inside queue"<<endl;
			if(!root->left){
				root->left = createNode(a);
				break;
			} 
			else q.push(root->left);
			if(!root->right){
				root->right = createNode(a);
				break;
			} 
			else q.push(root->right);
		// }
			// cout<<"last of queu"<<endl;
	}
	// cout<<"outside of queue"<<endl;

}

void inorder(struct tree* root){
	if(!root) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(struct tree *root){
	if(!root) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct tree *root){
	if(!root) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void printLevelOrder(struct tree *root){
	if(root == NULL) return;
	queue<struct tree*>q;
	q.push(root);
	while(!q.empty()){
		struct tree *temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left != NULL) q.push(temp->left);
		if(temp->right != NULL) q.push(temp->right);
	}
}

ll diameterTree(struct tree *root,ll *h){
	ll lh=0,rh=0,ld=0,rd=0;
	if(root == NULL) {
		*h=0;
		return 0;
	}
	ld = diameterTree(root->left,&lh);
	rd = diameterTree(root->right, &rh);
	*h = max(lh,rh)+1;
	return max(lh+rh+1,max(ld,rd));
}

ll height(struct tree *root) {
	if(root == NULL) return 0;
	// ll l = height(root->left);
	// ll r = height(root->right);
	// if(l>r) return l+1;
	// else return r+1;
	return 1+max(height(root->left),height(root->right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll n,a; cin>>n;
	struct tree *root=NULL;
	root = createNode(5);
	// root->left = createNode(2); 
 //    root->right= createNode(3); 
 //    root->left->left= createNode(4); 
 //    root->left->right = createNode(5);  
	for(ll i=0;i<n;i++) {
		cin>>a; insert(root,a);
	}
	ll h = 0;
	// all three traversal
	// inorder(root);
	// preorder(root);
	// postorder(root);
	// printLevelOrder(root);
	// ll val = diameterTree(root,&h);
	// cout<<" height "<<h;
	cout<<height(root);
	cout<<endl;

	return 0;
}