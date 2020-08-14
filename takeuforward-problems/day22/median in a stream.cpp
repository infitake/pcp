#include <bits/stdc++.h>
using namespace std;


// The idea is to use max heap and min heap to store the elements of higher half and lower half. Max heap and min heap can be implemented using priority_queue in C++ STL. Below is the step by step algorithm to solve this problem.
// Algorithm:

// Create two heaps. One max heap to maintain elements of lower half and one min heap to maintain elements of higher half at any point of time..
// Take initial value of median as 0.
// For every newly read element, insert it into either max heap or min heap and calculate the median based on the following conditions:
// If the size of max heap is greater than size of min heap and the element is less than previous median then pop the top element from max heap and insert into min heap and insert the new element to max heap else insert the new element to min heap. Calculate the new median as average of top of elements of both max and min heap.
// If the size of max heap is less than size of min heap and the element is greater than previous median then pop the top element from min heap and insert into max heap and insert the new element to min heap else insert the new element to max heap. Calculate the new median as average of top of elements of both max and min heap.
// If the size of both heaps are same. Then check if current is less than previous median or not. If the current element is less than previous median then insert it to max heap and new median will be equal to top element of max heap. If the current element is greater than previous median then insert it to min heap and new median will be equal to top element of min heap.
void streamMedian(vector<int> pq){
	int n = pq.size();
	priority_queue<int> maxpq;
	priority_queue<int,vector<int>,greater<int>> minpq;
	int median = pq[0];
	maxpq.push(median);
	cout<<median<<" ";

	for(int i=1;i<n;i++){
		int x = pq[i];
		if(maxpq.size()>minpq.size()){
			if(x < median){
				minpq.push(maxpq.top());
				maxpq.pop();
				maxpq.push(x);
			}else{
				minpq.push(x);
			}
			median = (minpq.top()+maxpq.top())/2;
		}else if(maxpq.size() == minpq.size()){
			if(x<median){
				maxpq.push(x);
				median = maxpq.top();
			}else{
				minpq.push(x);
				median = minpq.top();
			}
		}else{
			if(x>median){
				maxpq.push(minpq.top());
				minpq.pop();
				minpq.push(x);
			}else{
				maxpq.push(x);
			}
			median = (minpq.top()+maxpq.top())/2;
		}
		cout<<median<<" ";
	}

}
// Time Complexity: O(n Log n)
// Auxiliary Space : O(n)
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a; cin>>t;
	while(t--){
		cin>>n;
		vector<int> pq;
		for(int i=0;i<n;i++){
			cin>>a;
			pq.push_back(a);
		}
		streamMedian(pq);
		cout<<endl;
	}
	return 0;
}