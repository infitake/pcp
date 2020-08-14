#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> &arr,int l,int r){
    if(l>r) return -1;
    int ans = 0;
    for(int i=l;i<=r;i++) ans += arr[i];
    return ans;
}

void plusOneUtil(vector<int> &arr,int l,int r,int &count,int n,map<pair<int,int>,bool> &visited) {
    if(l>r) return;
    // if(visited[l]==true && visited[r]==true) return;
    if(visited[{l,r}]==true) return; 
    int first = sum(arr,0,l);
    int last = sum(arr,r,n-1);
    int mid = sum(arr,l+1,r-1);

    if((first == last)&&(mid == last)){
        // cout<<"helo"<<first<<" "<<last<<" "<<mid<<" "<<l<<" "<<r<<endl;
        count += 1;
        visited[{l,r}]=true;
        plusOneUtil(arr,l+1,r,count,n,visited);
        plusOneUtil(arr,l,r-1,count,n,visited);
    }else if(first<last){
        plusOneUtil(arr,l+1,r,count,n,visited);
    }else{
        plusOneUtil(arr,l,r-1,count,n,visited);
    }
}

int plusOne(vector<int> &arr) {
    int count=0;
    int n = arr.size();
    int l = 0,r=n-1;
    // vector<pair<> visited(n,false);
    map<pair<int,int>,bool> visited;
    plusOneUtil(arr,l,r,count,n,visited);
    return count;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a; cin>>t;
	while(t--){
		cin>>n;
		vector<int> arr1,arr2;
		for(int i=0;i<n;i++){
			cin>>a;
			arr1.push_back(a);
		}
		cout<<plusOne(arr1)<<endl;
	}
	return 0;
}