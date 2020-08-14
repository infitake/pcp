#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t,n,k; cin>>t;
    while(t--) {
        cin>>k>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        
        for(ll i=0;i<n;i++){
            if(pq.size() < (k)) {
                pq.push(arr[i]);
                if(pq.size()==k) cout<<pq.top()<<" ";
                else cout<<"-1"<<" ";
            }
            else{
                if(arr[i]>pq.top()){
                    pq.pop();
                    pq.push(arr[i]);
                }
                cout<<pq.top()<<" ";
            }
        }
        cout<<endl;
    }
}