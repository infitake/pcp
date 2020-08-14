#include <bits/stdc++.h>
using namespace std;

int x_axis[] = {-1,-1,-1,0,0,1,1,1};
int y_axis[] = {0,1,-1,-1,1,-1,0,1};

void dfsutil(vector<int> arr[],int n,int m,int x,int y,vector<vector<bool>> &visited){
    visited[x][y]=true;
    for(int i=0;i<8;i++){
        int a = x+x_axis[i];
        int b = y+y_axis[i];
        if(a>=0 &&a<n && b>=0 && b<m){
            if(arr[a][b]!=0 && !visited[a][b])
                dfsutil(arr,n,m,a,b,visited);
        }
    }
    
}

int findIslands(vector<int> arr[], int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    int count=0;
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            if(arr[i][j]!=0 && !visited[i][j]){
                dfsutil(arr,n,m,i,j,visited);
                count++;
            }
        }
    }
    return count;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_ base& str);
	int t,n,m,a; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<int> arr[n];
		for(int i=0;i<n;i++){
			vector<int> temp(m);
			arr[i]=temp;
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		cout<<findIslands(arr,n,m)<<endl;
	}
	return 0;
}