#include <bits/stdc++.h>
using namespace std;



// Method 2:
int maxPrice(int arr[],int n){
    int n=p.size();
        if(n<2){
            return 0;
        }
        vector<int> left(n,0);
        vector<int> right(n,0);
        //The concept is to find the max profit for (0 to i) + (i to n-1);
        //So we find the max value for each i;
        int l=p[0];
        for(int i=1;i<n;i++){
            l=min(l,p[i]);
            left[i]=max(left[i-1],p[i]-l);
        }
        int r=p[n-1];
        for(int i=n-2;i>=0;i--){
            r=max(r,p[i]);
            right[i]=max(right[i+1],r-p[i]);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,left[i]+right[i+1]);
        }
        ans=max(ans,max(left[n-1],right[0]));
        return ans;
}
// time complexity:O(n)
// space :O(1)

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
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<stockBuySell(arr,n)<<endl;
        
    }
    return 0;
}