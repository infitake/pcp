#include <bits/stdc++.h>
using namespace std;
#define N 9

void search(int arr[N][N],int n,int m,int key){
	// in this matrix the upper left is the smallest no and down right is largest number
	int min = arr[0][0],max = arr[n-1][m-1];
	if(key<min || key> max) cout<<"not present"<<endl;

	int i=0,j=m-1;

	while(i<n && j>=0){
		if(arr[i][j] == key){
			cout<<"found at "<<i<<" "<<j<<endl;
			break;
		}else if(arr[i][j]>key){
			j--;
		}else{
			i++;
		}
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
	int t,n,m; cin>>t;
	while(t--){
		cin>>n>>m;
		int arr[N][N];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		int k;
		cin>>k;
		search(arr,n,m,k);
	}
	return 0;
}