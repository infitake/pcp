#include <bits/stdc++.h>
using namespace std;


int x_axis[] = {2,1,-1,-2,-2,-1,1,2};
int y_axis[] = {1,2,2,1,-1,-2,-2,-1};

// Method 1:(This is the backtracking Method)

void printarr(vector<vector<int>> &arr,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool issafe(vector<vector<int>> &arr,int n,int x,int y){
	if(x>=0 && x<n && y>=0&&y<n && arr[x][y]==-1) return true;
	return false;
}

bool solvekt(vector<vector<int>> &arr,int n,int x,int y,int num){
	// cout<<num<<endl;
	if(num == (n*n)){
		printarr(arr,n);
		return true;
	}
	for(int i=0;i<8;i++){
		int a=x + x_axis[i];
		int b=y + y_axis[i];
		if(issafe(arr,n,a,b)){
			arr[a][b]=num;
			if(solvekt(arr,n,a,b,num+1)==true) return true;
			arr[a][b]=-1;
		}
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
	int t,n; cin>>t;
	while(t--){
		n=8;
		vector<vector<int>> arr(n,vector<int>(n,-1));
		arr[0][0]=0;
		if(!solvekt(arr,n,0,0,1)) cout<<"solution not exit"<<endl;
	}
	return 0;
}