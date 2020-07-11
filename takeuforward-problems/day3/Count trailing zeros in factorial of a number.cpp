#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Method 1: (count no of 5 because they are responsible for 0)
ll trailzero(ll n){
	ll count=0;
	for(ll i=5;n/i>=1;i = i*5){
		count += n/i;
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
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	while(t--){
		cin>>n;
		cout<<trailzero(n)<<endl;
		
	}
	return 0;
}