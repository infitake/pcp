#include <bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<int>> &arr,int n,int m,int x,int y,int c,int newcolor){
	if(x<0 || x>=n || y<0 || y>=m) return;
	if(arr[x][y] != c) return;
	arr[x][y] = newcolor;
	floodfill(arr,n,m,x-1,y,c,newcolor);
	floodfill(arr,n,m,x,y+1,c,newcolor);
	floodfill(arr,n,m,x+1,y,c,newcolor);
	floodfill(arr,n,m,x,y-1,c,newcolor);
}

void print(vector<vector<int>> &arr,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,m,a,x,y,newcolor; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<vector<int>> arr;
		for(int i=0;i<n;i++){
			vector<int> v;
			for(int j=0;j<m;j++){
				cin>>a;
				v.push_back(a);
			}
			arr.push_back(v);
		}
		cin>>x>>y>>newcolor;
		int c = arr[x][y];
		floodfill(arr,n,m,x,y,c,newcolor);
		print(arr,n,m);
	}
	return 0;
}