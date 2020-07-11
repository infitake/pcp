#include <bits/stdc++.h>
using namespace std;
// Method 1:
vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> vec;
        int n = nums.size();
        for(int i=0;i<n;i++) mp[nums[i]]=i+1;
        for(int i=0;i<n;i++){
            int j = mp[(target-nums[i])];
            if(j>0 && i!=j-1){
                vec.push_back(i);
                vec.push_back(j-1);
                break;
            }
        }
        return vec;
 }

// Method 2:
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int val = target-nums[i];
            if(mp.find(val)!=mp.end()){
                ans.push_back(mp[val]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    } 

// Method 3:
vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>res;
        int n = numbers.size();
        if(n == 0)  return res;
        int i = 0, j = n - 1;
        while(i < j){
            int x = numbers[i] + numbers[j];
            if(x == target){
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            else if(x > target)
                j--;
            else 
                i++;
        }
        return res;
    }

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n,a,target; cin>>t;
	while(t--){
		cin>>n>>target;
		vector<int> arr;
		vector<int> ans;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		ans = twoSum(arr,target);
		for(auto x:ans) cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}