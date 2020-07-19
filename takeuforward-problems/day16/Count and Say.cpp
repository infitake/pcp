#include<bits/stdc++.h>
using namespace std;
#define ll long long

string solve(ll n){
    if(n == 1) return "1";
    else if(n==2) return "11";
    string str="11";
    for (ll i = 3; i<=n; i++) { 
        str += '$'; 
        ll len = str.size(); 
  
        ll cnt = 1;
        string  tmp = ""; 
        for (ll j = 1; j < len; j++) 
        { 
            if (str[j] != str[j-1]) 
            { 
                tmp += cnt + '0'; 
                tmp += str[j-1]; 
                cnt = 1; 
            } 
 
            else cnt++; 
        } 
        str = tmp; 
    } 
  
    return str;
}

int main()
{
    ll t,n; cin>>t;
    while(t--) {
        cin>>n;
        cout<<solve(n)<<endl;
    }
}