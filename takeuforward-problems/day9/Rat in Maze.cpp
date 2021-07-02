#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &sol,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool issafe(vector<vector<int>> &arr,int n,int x,int y){
	return (x>=0 && x<n && y>=0 && y<n && arr[x][y]==1);
}

bool ratinmaze(vector<vector<int>> &arr,vector<vector<int>> &sol,int n,int x,int y){
	if(x==n-1&&y==n-1 && arr[x][y]==1){
		sol[x][y]=1; // sol array works as visited
		print(sol,n);
		return true;
	}

	if(issafe(arr,n,x,y)){
		sol[x][y]=1;
		if(ratinmaze(arr,sol,n,x+1,y)) return true;
		if(ratinmaze(arr,sol,n,x,y+1)) return true;
		sol[x][y]=0;
		return false;
	}
	return false;
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
		vector<vector<int>> arr;
		for(int i=0;i<n;i++){
			vector<int> v;
			for(int j=0;j<n;j++){
				cin>>a;
				v.push_back(a);
			}
			arr.push_back(v);
		}
		vector<vector<int>> sol(n,vector<int>(n,0));
		if(!ratinmaze(arr,sol,n,0,0)) cout<<"no solution"<<endl;
	}
	return 0;
}