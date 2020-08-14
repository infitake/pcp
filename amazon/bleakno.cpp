#include<bits/stdc++.h>
using namespace std;

int leftbit(int n){
    return log2(n);
}

int countbit(int n) {
    int count=0;
    while(n>0) {
        count++;
        n &= (n-1);
    }
    return count;
}

int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t,n; cin>>t;
    while(t--) {
        cin>>n;
        int k = leftbit(n);
        int newval = n-k;
        // cout<<"newval "<<newval<<endl;
        bool flag = true;
        for(int i=newval;i<n;i++){
            if(i + countbit(i) == n) {cout<<"0"<<endl; flag = false; break;}
        }
        if(flag) cout<<"1"<<endl;
    }
}