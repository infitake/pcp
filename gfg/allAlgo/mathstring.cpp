#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll knapsack(ll val[],ll wt[],ll n, ll w){
    if(w == 0) return 1;
    if(w<0 || n<0) return 0;
    if(n<0 && w>1) return 0;
    
    if(wt[n-1]>w)
        return knapsack(val,wt,n-1,w);
        
    return max(val[n-1] + knapsack(val,wt,n,w-wt[n-1]), knapsack(val,wt,n-1,w));
}

int main()
{
    ll t,n,w; cin>>t;
    while(t--) {
        cin>>n>>w;
        ll val[n],wt[n];
        for(ll i=0;i<n;i++){
            cin>>val[i];
        }
        for(ll i=0;i<n;i++){
            cin>>wt[i];
        }
        cout<<knapsack(val,wt,n,w)<<endl;
    }
}