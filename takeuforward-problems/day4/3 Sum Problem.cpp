#include <bits/stdc++.h>
using namespace std;
// Method 1:(2 pointer)
vector<vector<int>> threeSum( vector<int>& nums,int target ) {
    vector<vector<int>> result;
    int size = nums.size();
    if( size <= 2 ) return result;

    sort( nums.begin(), nums.end() );
    int sum;
    for( int i=0; i < size - 2; i++ ) {
        // if( nums[i] > 0 ) break;
        if( i > 0 && nums[i-1] == nums[i] ) continue;

        int start = i + 1, end = nums.size() - 1;
        while( start < end ) {
            sum = nums[i] + nums[start] + nums[end];
            if( sum == 0 ) {
                result.push_back( { nums[i], nums[start], nums[end] } );
                start++;
                end--;
                while( start < end && nums[start] == nums[start - 1] ) start++;
                while( start < end && nums[end] == nums[end + 1] ) end--;
            }
            else if( sum > 0 )
                end--;
            else
                start++;
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
		ans = threeSum(arr,target);
		// for(auto x:ans) cout<<x<<" ";
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