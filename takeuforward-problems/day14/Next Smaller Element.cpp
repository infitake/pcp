#include <bits/stdc++.h>
using namespace std;

//Method 1:(using stack)
void nextlowerelement(vector<int> arr, int n) { 
  stack < int > s; 
  
  /* push the first element to stack */
  s.push(arr[0]); 
  
  // iterate for rest of the elements 
  for (int i = 1; i < n; i++) { 
  
    if (s.empty()) { 
      s.push(arr[i]); 
      continue; 
    } 
  
    //  if stack is not empty, then 
    //    pop an element from stack. 
    //    If the popped element is smaller 
    //    than next, then 
    // a) print the pair 
    // b) keep popping while elements are 
    // smaller and stack is not empty 
    while (s.empty() == false && s.top() > arr[i]) 
    {          
        cout << s.top() << " --> " << arr[i] << endl; 
        s.pop(); 
    } 
  
    /* push next to stack so that we can find 
    next greater for it */
    s.push(arr[i]); 
  } 
  
  /* After iterating over the loop, the remaining 
  elements in stack do not have the next greater 
  element, so print -1 for them */
  while (s.empty() == false) { 
    cout << s.top() << " --> " << -1 << endl; 
    s.pop(); 
  } 
} 
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,k; cin>>t;
	while(t--){
		cin>>n;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		nextlowerelement(arr,n);
	}
	return 0;
}