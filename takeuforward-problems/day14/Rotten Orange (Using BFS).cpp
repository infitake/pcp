#include <bits/stdc++.h>
using namespace std;
#define N 101
struct raxis{
	int x;
	int y;
};
int x_axis[]={-1,0,1,0};
int y_axis[]={0,1,0,-1};
int rottenorange(int arr[][N],int n,int m){
	raxis temp;
	queue<raxis> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j] == 2){
				temp.x=i;
				temp.y=j;
				q.push(temp);
			}
		}
	}
	// here we have a queue with axis containg all 2's
	int frame=-1;
	while(!q.empty()){
		int s = q.size();
		frame++;
		while(s--){
			raxis temp = q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int a = x_axis[i]+temp.x;
				int b = y_axis[i]+temp.y;
				if(a>=0&&a<n && b>=0 &&b<m && arr[a][b]==1){
					arr[a][b]=2;
					raxis temp1;
					temp1.x=a;
					temp1.y=b;
					q.push(temp1);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j] == 1) return -1;
		}
	}
	return frame;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,m; cin>>t;
	while(t--){
		cin>>n>>m;
		int arr[N][N];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		cout<<rottenorange(arr,n,m)<<endl;
		
	}
	return 0;
}