#include<bits/stdc++.h>
using namespace std;
#define ll long long


// Method 1:(using job seducheling concept)
ll comp(pair<ll,ll> a,pair<ll,ll> b){
    return a.first<b.first; 
}

void overlap(vector<pair<ll,ll>> arr,ll n){
	vector<ll> vec;
	sort(arr.begin(),arr.end(),comp);
    ll fst=arr[0].first,sec=arr[0].second;
    for(ll i=1;i<n;i++){
        if(sec>=arr[i].first && sec<=arr[i].second) sec=arr[i].second;
        else if(sec < arr[i].first){
            vec.push_back(fst);
            vec.push_back(sec);
            fst = arr[i].first;
            sec = arr[i].second;
            if(i+1 == n){
              	vec.push_back(fst);
          		vec.push_back(sec);
            }
        }
    }
   	if(find(vec.begin(),vec.end(),fst)==vec.end()) vec.push_back(fst); 
   	if(find(vec.begin(),vec.end(),sec)==vec.end()) vec.push_back(sec);
   	if(fst == sec) vec.push_back(fst);

    for(auto x:vec) cout<<x<<" ";
}

// Method 2: extended version of 1 method using stack
void overlap(vector<pair<ll,ll>> arr, int n) 
{ 
    // Test if the given set has at least one interval 
    if (n <= 0) 
        return; 
  
    // Create an empty stack of intervals 
    stack<pair<ll,ll>> s; 
  
    // sort the intervals in increasing order of start time 
    sort(arr.begin(),arr.end(),comp); 
  
    // push the first interval to stack 
    s.push(arr[0]); 
  
    // Start from the next interval and merge if necessary 
    for (int i = 1 ; i < n; i++) 
    { 
        // get interval from stack top 
        pair<ll,ll> top = s.top(); 
  
        // if current interval is not overlapping with stack top, 
        // push it to the stack 
        if (top.second < arr[i].first) 
            s.push(arr[i]); 
  
        // Otherwise update the ending time of top if ending of current 
        // interval is more 
        else if (top.second < arr[i].second) 
        { 
            top.second = arr[i].second; 
            s.pop(); 
            s.push(top); 
        } 
    } 
    while (!s.empty()) 
    { 
        pair<ll,ll> t = s.top(); 
        cout <<t.first <<" "<< t.second<<" "; 
        s.pop(); 
    } 
} 

// Method 3:
// A O(n Log n) and O(1) Extra Space Solution
// The above solution requires O(n) extra space for stack. We can avoid use of extra space by doing merge operations in-place. Below are detailed steps.

// 1) Sort all intervals in decreasing order of start time.
// 2) Traverse sorted intervals starting from first interval, 
//    do following for every interval.
//       a) If current interval is not first interval and it 
//          overlaps with previous interval, then merge it with
//          previous interval. Keep doing it while the interval
//          overlaps with the previous one.         
//       b) Else add current interval to output list of intervals.
// Note that if intervals are sorted by decreasing order of start times,
// we can quickly check if intervals overlap or not by comparing start time of previous interval with end time of current interval.
void overlap(vector<pair<ll,ll>> arr, ll n) 
{  
    // Sort Intervals in increasing order of 
    // start time 
    sort(arr.begin(),arr.end(),comp); 
  
    ll index = 0; // Stores index of last element  
    // in output array (modified arr[])  
  
    // Traverse all input Intervals  
    for (ll i=1; i<n; i++)  
    {  
        // If this is not first Interval and overlaps  
        // with the previous one  
        if (arr[index].second >=  arr[i].first)  
        {  
               // Merge previous and current Intervals  
            arr[index].second = max(arr[index].second, arr[i].second);  
            arr[index].first = min(arr[index].first, arr[i].first);  
        }  
        else { 
            arr[index] = arr[i];  
            index++; 
        }     
    }  
  
    // Now arr[0..index-1] stores the merged Intervals   
    for (ll i = 0; i <= index; i++)  
        cout  << arr[i].first << " " << arr[i].second <<" ";  
}  

int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t,n,a,b; cin>>t;
    while(t--) {
        cin>>n;
        vector<pair<ll,ll>> arr;
        for(ll i=0;i<n;i++){
            cin>>a>>b;
            arr.push_back({a,b});
        }
        overlap(arr,n);
        cout<<endl;
    }
}