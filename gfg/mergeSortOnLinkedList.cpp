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

struct node {
	ll data;
	node *next;
};
struct node *head=NULL;

void push(ll val){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = val;
	temp->next = NULL;
	if(head==NULL)
		head = temp;
	else{
		struct node *temp2;
		temp2 = head;
		while(temp2->next!=NULL){
			temp2 = temp2->next;
		}
		temp2->next = temp;
		temp2 = head;
	}
}

void display(){
	cout<<"insidedisplay"<<" "<<(head == NULL)<<endl;
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void splitList(struct node *headnode,struct node *a,struct node *b){
	struct node *fast,*slow,*temp;
	slow = headnode;
	fast = headnode->next;
	while(fast != NULL){
		fast = fast->next;
		if(fast!=NULL){
			fast = fast->next;
			slow = slow->next;
		}
	}
	a = headnode;
	b = slow->next;
	slow->next = NULL;
}

struct node* merge(struct node *a,struct node *b){
	struct node *result=NULL,*final = NULL;

	if(a == NULL) return b;
	if(b == NULL) return a;

	if (a->data <= b->data) { 
        result = a; 
        result->next = merge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = merge(a, b->next); 
    } 
    return (result); 
	
}

void mergeSort(){
	struct node *headnode ,*a=NULL,*b=NULL,*val=NULL;
	headnode=head;

	if(headnode == NULL || headnode->next == NULL) return

	splitList(headnode,a,b);
	mergeSort();
	mergeSort();

	val = merge(a,b);
	head = val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>n;
	for(ll i=0;i<n;i++){
		cin>>t;
		push(t);
	}
	
	mergeSort();
	display();
	
	return 0;
}