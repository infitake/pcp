#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool dichave(string word,string text[],ll n){
    for(ll i=0;i<n;i++){
        if(text[i].compare(word) == 0) return true;
    }
    return false;
}

bool wordbreak(string text[],ll n,string word){
    ll sz = word.size();
    if(sz==0) return true;
    bool dp[sz+1];
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<=sz;i++){
        if(dp[i]==false && dichave(word.substr(0,i),text,n))
            dp[i]=true;
        if(dp[i]==true){
            if(i==sz) return true;
            for(ll j=i+1;j<=sz;j++){
                if(dp[i]==false && dichave(word.substr(i,j-i),text,n))
                    dp[j]=true;
                if(j==sz && dp[j]==true)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t,n; cin>>t;
    while(t--) {
        cin>>n;
        string text[n];
        for(ll i=0;i<n;i++){
            cin>>text[i];
        }
        string word;
        cin>>word;
        cout<<wordbreak(text,n,word)<<endl;
    }
}