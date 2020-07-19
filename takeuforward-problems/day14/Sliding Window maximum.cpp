#include <bits/stdc++.h>
using namespace std;


// Method 1:(simple Method)
// void windowmax(vector<int> arr,int n,int k){
// 	for(int i=0;i<n-k+1;i++){
// 		int maxval=0;
// 		for(int j=i;j<k+i;j++){
// 			if(maxval<arr[j]) maxval = arr[j];
// 		}
// 		cout<<maxval<<" ";
// 	}
// 	cout<<endl;
// }

// Method 2:(using dequeue)
// Algorithm :
// Create a deque to store k elements.
// Run a loop and insert first k elements in the deque. While inserting the element if the element at the back of the queue is smaller than the current element remove all those elements and then insert the element.
// Now, run a loop from k to end of the array.
// Print the front element of the array
// Remove the element from the front of the queue if they are out of the current window.
// Insert the next element in the deque. While inserting the element if the element at the back of the queue is smaller than the current element remove all those elements and then insert the element.
// Print the maximum element of the last window.
void windowmax(vector<int> arr,int n,int k){
	deque<int> dq;
	for(int i=0;i<k;i++){
		while(!dq.empty() && arr[i]>=arr[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	for(int j=k;j<n;j++){
		cout<<arr[dq.front()]<< " ";
		while(!dq.empty() && dq.back() <= j-k) dq.pop_front();
		while(!dq.empty() && arr[j]>=arr[dq.back()]) dq.pop_back();
		dq.push_back(j);
	}
	cout<<arr[dq.front()]<<endl;
}

// Method 3:(using stack)
void print_max(int a[], int n, int k) 
{ 
    // max_upto array stores the index 
    // upto which the maximum element is a[i] 
    // i.e. max(a[i], a[i + 1], ... a[max_upto[i]]) = a[i] 
  
    int max_upto[n]; 
  
    // Update max_upto array similar to 
    // finding next greater element 
    stack<int> s; 
    s.push(0); 
    for (int i = 1; i < n; i++) { 
        while (!s.empty() && a[s.top()] < a[i]) { 
            max_upto[s.top()] = i - 1; 
            s.pop(); 
        } 
        s.push(i); 
    } 
    while (!s.empty()) { 
        max_upto[s.top()] = n - 1; 
        s.pop(); 
    } 
    int j = 0; 
    for (int i = 0; i <= n - k; i++) { 
  
        // j < i is to check whether the 
        // jth element is outside the window 
        while (j < i || max_upto[j] < i + k - 1) 
            j++; 
        cout << a[j] << " "; 
    } 
    cout << endl; 
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
		for(int i=0;i<n;i++) {cin>>a;arr.push_back(a);}
		cin>>k;
		windowmax(arr,n,k);
		
	}
	return 0;
}