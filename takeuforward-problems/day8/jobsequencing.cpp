#include <bits/stdc++.h>
using namespace std;

struct job {
	char id;
	int deadline;
	int profit;
};

// Method 1:
// put the job according to their profit
// and put all job in their last slot of deadline first
// if this slot is fill than go to next slot

bool comp(struct job a,struct job b){
	return a.profit>b.profit;
}

void jobsequencing(struct job j1[],int n){
	sort(j1,j1+n,comp);
	int slot[n];
	int result[n];
	memset(slot,false,sizeof(slot));
	for(int i=0;i<n;i++){
		for(int j=min(n,j1[i].deadline)-1;j>=0;j--){
			if(slot[j]==false){
				result[j]=i;
				slot[j]=true;
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(slot[i]) cout<<j1[i].id<<" ";
	}
	cout<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,b,c; cin>>t;
	char a;
	while(t--){
		cin>>n;
		struct job j1[n];
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			j1[i].id=a;
			j1[i].deadline=b;
			j1[i].profit=c;
		}
		jobsequencing(j1,n);
		
	}
	return 0;
}

// Method 2:(using the disjoint set)
// C++ Program to find the maximum profit job sequence 
// from a given array of jobs with deadlines and profits 
#include<bits/stdc++.h> 
using namespace std; 

// A structure to represent various attributes of a Job 
struct Job 
{ 
	// Each job has id, deadline and profit 
	char id; 
	int deadLine, profit; 
}; 

// A Simple Disjoint Set Data Structure 
struct DisjointSet 
{ 
	int *parent; 

	// Constructor 
	DisjointSet(int n) 
	{ 
		parent = new int[n+1]; 

		// Every node is a parent of itself 
		for (int i = 0; i <= n; i++) 
			parent[i] = i; 
	} 

	// Path Compression 
	int find(int s) 
	{ 
		/* Make the parent of the nodes in the path 
		from u--> parent[u] point to parent[u] */
		if (s == parent[s]) 
			return s; 
		return parent[s] = find(parent[s]); 
	} 

	// Makes u as parent of v. 
	void merge(int u, int v) 
	{ 
		//update the greatest available 
		//free slot to u 
		parent[v] = u; 
	} 
}; 

// Used to sort in descending order on the basis 
// of profit for each job 
bool cmp(Job a, Job b) 
{ 
	return (a.profit > b.profit); 
} 

// Functions returns the maximum deadline from the set 
// of jobs 
int findMaxDeadline(struct Job arr[], int n) 
{ 
	int ans = INT_MIN; 
	for (int i = 0; i < n; i++) 
		ans = max(ans, arr[i].deadLine); 
	return ans; 
} 

int printJobScheduling(Job arr[], int n) 
{ 
	// Sort Jobs in descending order on the basis 
	// of their profit 
	sort(arr, arr + n, cmp); 

	// Find the maximum deadline among all jobs and 
	// create a disjoint set data structure with 
	// maxDeadline disjoint sets initially. 
	int maxDeadline = findMaxDeadline(arr, n); 
	DisjointSet ds(maxDeadline); 

	// Traverse through all the jobs 
	for (int i = 0; i < n; i++) 
	{ 
		// Find the maximum available free slot for 
		// this job (corresponding to its deadline) 
		int availableSlot = ds.find(arr[i].deadLine); 

		// If maximum available free slot is greater 
		// than 0, then free slot available 
		if (availableSlot > 0) 
		{ 
			// This slot is taken by this job 'i' 
			// so we need to update the greatest 
			// free slot. Note that, in merge, we 
			// make first parameter as parent of 
			// second parameter. So future queries 
			// for availableSlot will return maximum 
			// available slot in set of 
			// "availableSlot - 1" 
			ds.merge(ds.find(availableSlot - 1), 
							availableSlot); 

			cout << arr[i].id << " "; 
		} 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	Job arr[] = { { 'a', 2, 100 }, { 'b', 1, 19 }, 
				{ 'c', 2, 27 }, { 'd', 1, 25 }, 
				{ 'e', 3, 15 } }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Following jobs need to be "
		<< "executed for maximum profit\n"; 
	printJobScheduling(arr, n); 
	return 0; 
} 
