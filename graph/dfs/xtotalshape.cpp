#include <bits/stdc++.h>
#define pb push_back
#define endll "\n";
using namespace std;
vector<int> t1={1,-1,0,0};
vector<int> t2={0,0,-1,1};
int issafe(int i,int j,int n,int m,vector<vector<int>> vis,vector<vector<char>> v){
    if(i>=0&&j>=0&&i<n&&j<m&&vis[i][j]==0&&v[i][j]=='X'){
        return 1;
    }
    return 0;
}
void dfs(vector<vector<char>> v,int i,int j,int n,int m,vector<vector<int>> &vis){
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        if(issafe(i+t1[k],j+t2[k],n,m,vis,v)){
            dfs(v,i+t1[k],j+t2[k],n,m,vis);
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        vector<vector<int>> vis(n,vector<int> (m,0));
        vector<vector<char>> v;
        for(int i=0;i<n;i++){
            cin>>s;
            vector<char> v1;
            for(int j=0;j<s.length();j++){
                v1.pb(s[j]);
            }
            v.pb(v1);
        }
        int ans=0;
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]=='X'&&vis[i][j]==0){
                    ans++;
                    dfs(v,i,j,n,m,vis);
                }
            }
        }
        cout<<ans<<endll;
    }
    return 0;
}

