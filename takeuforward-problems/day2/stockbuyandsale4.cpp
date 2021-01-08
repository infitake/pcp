#include <bits/stdc++.h>
using namespace std;

// use this to understand the question
// https://www.youtube.com/watch?v=6928FkPhGUA

// Method 1:
int stockBuySell(int arr[],int n,int k){
    // case 1: n<=1 and k==0
    if(k ==0 && n<=1) return 0;

    // case 2: 2*k > n
    if(2*k > n ){
        int sum=0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                sum += arr[i]-arr[i-1];
            }
        }
        return sum;
    }
    // case 3: 0< k <n
    int dp[2*k+1];
    dp[0]=-arr[0];
    for(int i=1;i<=2*k;i++){
        if(i%2==0) dp[i] = INT_MIN;
        else dp[i]=0;
    }

    for(int i=0;i<n;i++){
        for(int j = 0;j<=2*k;j++){
            if(j==0){
                dp[j] = max(dp[j],-arr[i]);
            }else if(j%2==0) {   // we must buy or skip
                dp[j] = max(dp[j],dp[j-1]-arr[i]);
            }else{
                dp[j] = max(dp[j],dp[j-1]+arr[i]);
            }
        }
    }

    return dp[2*k-1];
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
    int t,n,k; cin>>t;
    while(t--){
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<stockBuySell(arr,n,k)<<endl;
        
    }
    return 0;
}