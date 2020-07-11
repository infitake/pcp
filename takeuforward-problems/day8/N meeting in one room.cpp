#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct job {
    int index;
  int first;
  int second;
};


bool comp(struct job j1,struct job j2){
    return j1.second<j2.second;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n; cin>>t;
    while(t--) {
        cin>>n;
        ll str[n],fin[n];
        for(ll i=0;i<n;i++){
            cin>>str[i];
        }
        for(ll i=0;i<n;i++){
            cin>>fin[i];
        }
        struct job jobs[n];
        for(ll i=0;i<n;i++){
            jobs[i].index = i+1;
            jobs[i].first = str[i];
            jobs[i].second = fin[i];
        }
        sort(jobs,jobs+n,comp); 
        cout<<jobs[0].index<<" ";
        ll lasjob = jobs[0].second;
        for(ll i=1;i<n;i++){
            if(jobs[i].first>lasjob){
                cout<<jobs[i].index<<" ";
                lasjob = jobs[i].second;
            }
        }
        cout<<endl;
    }
}