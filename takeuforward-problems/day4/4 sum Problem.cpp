#include <bits/stdc++.h>
using namespace std;

// Method 1:(2 pointer)
vector<vector<int>> fourSum( vector<int>& nums,int target ) {
    vector<vector<int>> result;
    int size = nums.size();
    if( size <= 3 ) return result;

    sort( nums.begin(), nums.end() );
    int sum;
    for(int j=0;j<size-3;j++){
        if( j>0 && nums[j-1] == nums[j] ) continue;
    for( int i=j+1; i < size - 2; i++ ) {
        // if( nums[i] > 0 ) break;
        if( i > j+1 && nums[i-1] == nums[i] ) continue;

        int start = i + 1, end = nums.size() - 1;
        while( start < end ) {
            sum = target-(nums[i] + nums[j]);
            if( sum == nums[start]+nums[end] ) {
                result.push_back( {nums[j], nums[i], nums[start], nums[end] } );
                start++;
                end--;
                while( start < end && nums[start] == nums[start - 1] ) start++;
                while( start < end && nums[end] == nums[end + 1] ) end--;
            }
            else if( nums[start]+nums[end] > sum)
                end--;
            else
                start++;
        }
    }
}
    return result;
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
		vector<vector<int>> ans;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		ans = fourSum(arr,target);
        
        int k=ans.size();
        int l = ans[0].size();
        for(int i=0;i<k;i++){
            for(int j=0;j<l;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
		cout<<endl;
	}
	return 0;
}