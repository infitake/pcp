#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,k; cin>>t;
    while(t--) {
        cin>>n>>k;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll val = arr[0],count=0;
        for(ll i=1;i<n;i++){
            if(abs(val-arr[i])>k){
                while(abs(val-arr[i])>k){
                    if(val>arr[i]) --val;
                    else --arr[i];
                    count++;
                }
            }
            val=arr[i];
        }
        cout<<count<<endl;
    }
}
// method 2:

int minimumCoins(int a[], int n, int k) 
{ 
    // To store the coins needed to be removed 
    int cnt = 0; 
  
    // Minimum value from the array 
    int minVal = *min_element(a, a + n); 
  
    // Itereate over the array and remove extra coins 
    for (int i = 0; i < n; i++) { 
        int diff = a[i] - minVal; 
  
        // If the difference between the current pile and 
        // the minimum coin pile is greater than k 
        if (diff > k) { 
  
            // Count the extra coins to be removed 
            cnt += (diff - k); 
        } 
    } 
  
    // Return the required count 
    return cnt; 
}