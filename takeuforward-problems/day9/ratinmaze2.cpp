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

bool issafe(vector<vector<int>> &arr,int x,int y,int n,vector<vector<bool>> &visited){
	if(x==-1 || x==n || y==-1 || y==n || arr[x][y]==0 || visited[x][y]) return false;
	return true;
}

// 1 0 0 0 0
// 1 1 1 1 1
// 1 1 1 0 1 
// 0 0 0 0 1
// 0 0 0 0 1
void ratinmaze2(vector<vector<int>> &arr,int n,int x,int y,string &path,vector<string> &finalpath,vector<vector<bool>> &visited){
	if(x==-1 || x==n || y==-1 || y==n || arr[x][y]==0 || visited[x][y]) return;
	if(x==n-1&&y==n-1){
		// cout<<path<<" ";
		finalpath.push_back(path);
		return;
	} 
	visited[x][y]=true;
	if(issafe(arr,x+1,y,n,visited)){
		path.push_back('D');
		ratinmaze2(arr,n,x+1,y,path,finalpath,visited);
		path.pop_back();
	}
	if(issafe(arr,x,y-1,n,visited)){
		path.push_back('L');
		ratinmaze2(arr,n,x,y-1,path,finalpath,visited);
		path.pop_back();
	}
	if(issafe(arr,x,y+1,n,visited)){
		path.push_back('R');
		ratinmaze2(arr,n,x,y+1,path,finalpath,visited);
		path.pop_back();
	}
	if(issafe(arr,x-1,y,n,visited)){
		path.push_back('U');
		ratinmaze2(arr,n,x-1,y,path,finalpath,visited);
		path.pop_back();
	}
	visited[x][y]=false;
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
		vector<vector<bool>> visited(n,vector<bool>(n,false));
		string path;
		vector<string> finalpath;
		ratinmaze2(arr,n,0,0,path,finalpath,visited);
		for(auto x:finalpath) cout<<x<<endl;
	}
	return 0;
}