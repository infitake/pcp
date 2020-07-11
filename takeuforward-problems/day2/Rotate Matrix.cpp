#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000001
void transpose(ll arr[][N],ll n){
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			swap(arr[i][j],arr[j][i]);
		}
	}
}
void printmat(ll arr[][N],ll n){
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
void rotatematrix(ll arr[][N],ll n){
	transpose(arr,n);
	// reverse(arr,n);
	printmat(arr,n);
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		ll arr[N][N];
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				cin>>arr[i][j];
			}
		} 
		rotatematrix(arr,n);
	}
	return 0;
}