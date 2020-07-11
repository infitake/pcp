#include <bits/stdc++.h>
using namespace std;

// Method 1:

int minplatform(vector<float> arr,vector<float> dep){
	int n=arr.size();
	int m=dep.size();
	int i=0,j=0;
	int count=0,maxval=INT_MIN;
	while(i<n&&j<m){
		if(arr[i]<dep[j]){
			count++;
			i++;
		}else{
			count--;
			j++;
		}
		maxval = max(maxval,count);
	}
	while(i<n){
		count++;
		i++;
		maxval = max(maxval,count);
	}
	while(j<m){
		count--;
		j++;
		maxval = max(maxval,count);
	}
	return maxval;
}

// Method 2:
// Approach: The idea is to take every interval one by one and find the number of intervals that overlap with it. 
// Keep track of the maximum number of intervals that overlap with an interval. Finally, return the maximum value.
// Algorithm:
// Run two nested loops the outer loop from start to end and inner loop from i+1 to end.
// For every iteration of outer loop find the count of intervals that intersect with the current interval.
// Update the answer with maximum count of overlap in each iteration of outer loop.

int findPlatform(int arr[], int dep[], int n) 
{ 
  
    // plat_needed indicates number of platforms 
    // needed at a time 
    int plat_needed = 1, result = 1; 
    int i = 1, j = 0; 
  
    // run a nested  loop to find overlap 
    for (int i = 0; i < n; i++) { 
        // minimum platform 
        plat_needed = 1; 
  
        for (int j = i + 1; j < n; j++) { 
            // check for overlap 
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i])) 
                plat_needed++; 
        } 
  
        // update result 
        result = max(result, plat_needed); 
    } 
  
    return result; 
} 


// Complexity Analysis:
// Time Complexity: O(n^2).
// Two nested loops traverse the array, so the time complexity is O(n^2).
// Space Complexity: O(1).
// As no extra space is required.



// Method 3:
// Efficient Solution:

// Approach: The idea is to consider all events in sorted order. 
// Once the events are in sorted order, trace the number of trains at any time keeping track of trains that have arrived, 
// but not departed.
// For example consider the above example.

// arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
// dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

// All events are sorted by time.
// Total platforms at any time can be obtained by
// subtracting total departures from total arrivals
// by that time.

//  Time      Event Type     Total Platforms Needed 
//                                at this Time                               
//  9:00       Arrival                  1
//  9:10       Departure                0
//  9:40       Arrival                  1
//  9:50       Arrival                  2
//  11:00      Arrival                  3 
//  11:20      Departure                2
//  11:30      Departure                1
//  12:00      Departure                0
//  15:00      Arrival                  1
//  18:00      Arrival                  2 
//  19:00      Departure                1
//  20:00      Departure                0

// Minimum Platforms needed on railway station 
// = Maximum platforms needed at any time 
// = 3  
// Note: This approach assumes that trains are arriving and departing on the same date.

// Algorithm:
// Sort the arrival and departure time of trains.
// Create two pointers i=0, and j=0 and a variable to store ans and current count plat
// Run a loop while i<n and j<n and compare the ith element of arrival array and jth element of departure array.
// if the arrival time is less than or equal to departure then one more platform is needed so increase the count, i.e. plat++ and increment i
// Else if the arrival time greater than departure then one less platform is needed so decrease the count, i.e. plat++ and increment j
// Update the ans, i.e ans = max(ans, plat).
// Implementation: This doesn’t create a single sorted list of all events, 
// rather it individually sorts arr[] and dep[] arrays, and then uses merge process of merge sort to process them together as a single sorted array.
int findPlatform(int arr[], int dep[], int n) 
{ 
    // Sort arrival and departure arrays 
    sort(arr, arr + n); 
    sort(dep, dep + n); 
  
    // plat_needed indicates number of platforms 
    // needed at a time 
    int plat_needed = 1, result = 1; 
    int i = 1, j = 0; 
  
    // Similar to merge in merge sort to process 
    // all events in sorted order 
    while (i < n && j < n) { 
  
        // If next event in sorted order is arrival, 
        // increment count of platforms needed 
        if (arr[i] <= dep[j]) { 
            plat_needed++; 
            i++; 
        } 
  
        // Else decrement count of platforms needed 
        else if (arr[i] > dep[j]) { 
            plat_needed--; 
            j++; 
        } 
  
        // Update result if needed 
        if (plat_needed > result) 
            result = plat_needed; 
    } 
  
    return result; 
} 
// Complexity Analysis:
// Time Complexity: O(n Log n).
// One traversal of both the array is needed, so the time Complexity is O(n).
// Space Complexity: O(1).
// As no extra space is required.

// Method 4:
// we are inserting all the arrival and departure times in a multimap. 
// The first value of element in multimap tells the arrival/departure time and second value tells whether it’s arrival or departure represented by ‘a’ or ‘d’ respectively.
// If its arrival then do increment by 1 otherwise decrease value by 1. 
// If we are taking the input from STDIN then we can directly insert the times in the multimap and no need to store the times in the array.

int findPlatform(int arr[], int dep[], int n) 
{ 
    // Insert all the times (arr. and dep.) 
    // in the multimap. 
    multimap<int, char> order; 
    for (int i = 0; i < n; i++) { 
  
        // If its arrival then second value 
        // of pair is 'a' else 'd' 
        order.insert(make_pair(arr[i], 'a')); 
        order.insert(make_pair(dep[i], 'd')); 
    } 
  
    int result = 0; 
    int plat_needed = 0; 
  
    multimap<int, char>::iterator it = order.begin(); 
  
    // Start iterating the multimap. 
    for (; it != order.end(); it++) { 
  
        // If its 'a' then add 1 to plat_needed 
        // else minus 1 from plat_needed. 
        if ((*it).second == 'a') 
            plat_needed++; 
        else
            plat_needed--; 
  
        if (plat_needed > result) 
            result = plat_needed; 
    } 
    return result; 
} 

// Method 5:
// If all the arrival and departure occur on the same day then we can use and auxiliary array to compute the required number of the platform in O(n).

// Whenever an arrival occurs we increase the count of the required platform when a departure occurs we decrease the required platform at that point of time, 
// after that, we take the cumulative sum, which would provide the required number of platform for all point of time, out of these values maximum value is our answer.
int minPlatform(int arrival[], int departure[], int n) 
{ 
  
    // as time range from 0 to 2359 in 24 hour clock, 
    // we declare an array for values from 0 to 2360 
    int platform[2361] = {}; 
    int requiredPlatform = 1; 
    for (int i = 0; i < n; i++) { 
  
        // increment the platforms for arrival 
        ++platform[arrival[i]];  
  
         // once train departs we decrease the platform count 
        --platform[departure[i] + 1]; 
    } 
  
    // We are running loop till 2361 because maximum time value 
    // in a day can be 23:60 
    for (int i = 1; i < 2361; i++) { 
  
        // taking cumulative sum of platform give us required 
        // number of platform fro every minute 
        platform[i] = platform[i] + platform[i - 1];  
        requiredPlatform = max(requiredPlatform, platform[i]); 
    } 
    return requiredPlatform; 
} 

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,m; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<float> arr;
		vector<float> dep;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		for(int i=0;i<m;i++){
			cin>>a;
			dep.push_back(a);
		}  
		cout<<minplatform(arr,dep)<<endl;
	}
	return 0;
}