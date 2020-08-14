#include <bits/stdc++.h>
using namespace std;

void buildSegmentTree(int arr[],int n,int index,int tree[],int l,int r){
	if(l>r) return;
	if(l == r){
		tree[index]=arr[l];
		return;
	}
	int mid = l + (r-l)/2;
	buildSegmentTree(arr,n,2*index+1,tree,l,mid);
	buildSegmentTree(arr,n,2*index+2,tree,mid+1,r);

	int left = tree[2*index+1];
	int right = tree[2*index+2];

	tree[index]=min(left,right);

}

int query(int tree[],int index,int l,int r,int qs,int qe) {
	// outside the range
	if(qe < l || qs > r) return INT_MAX;

	// completly overlap
	if(qs<=l && qe>=r) return tree[index];

	// partially overlap
	int mid = l + (r-l)/2;
	int left = query(tree,2*index+1,l,mid,qs,qe);
	int right = query(tree,2*index+2,mid+1,r,qs,qe);
	return min(left,right);
}

void updateElement(int tree[],int index,int l,int r,int k,int indexupdate) {
	if(l>r) return;

	if(l == r){
		if(indexupdate == l) tree[index] = k;
		return;
	}

	int mid = l + (r-l)/2;

	updateElement(tree,2*index+1,l,mid,k,indexupdate);
	updateElement(tree,2*index+2,mid+1,r,k,indexupdate);

	tree[index] = min(tree[2*index+1],tree[2*index+2]);

}

void updateElementInRange(int tree[],int index,int l,int r,int k,int rs,int re) {
	if(re < l || rs > r) return;

	if(l == r){
		tree[index] += k;
		return;
	}

	int mid = l + (r-l)/2;

	updateElementInRange(tree,2*index+1,l,mid,k,rs,re);
	updateElementInRange(tree,2*index+2,mid+1,r,k,rs,re);

	tree[index] = min(tree[2*index+1],tree[2*index+2]);

}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,b; cin>>t;
	while(t--){
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int tree[4*n];
		buildSegmentTree(arr,n,0,tree,0,n-1);

		int k,g,f;cin>>k>>g>>f; g--,f--;
		// updateElement(tree,0,0,n-1,k,g);
		updateElementInRange(tree,0,0,n-1,k,g,f);
		// enter the queries
		int m;
		cin>>m;

		for(int i=0;i<m;i++) {
			cin>>a>>b;
			a--;
			b--;
			cout<<query(tree,0,0,n-1,a,b)<<endl;
		}
	}
	return 0;
}