#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sheet(string str,ll n){
    ll p=26;
    ll p_pow=1;
    ll k = n;
    ll ans=0;
    while(k>0){
        ll rem = str[k-1]-'A'+1;
        ans += rem*p_pow;
        p_pow = p_pow*p;
        k--;
    }
    return ans;
}
// 27
// 26
// 51
// 52
// 80
// 676
// 702
// 705
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t,n; cin>>t;
    string str;
    while(t--) {
        cin>>str;
        n = str.size();
        cout<<sheet(str,n)<<endl;
    }
}