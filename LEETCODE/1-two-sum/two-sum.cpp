class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // using 2 pointers + sorting
        // storing the vals in array ( val, ind)
        vector<pair<int,int>> arr;
        for ( int i =0; i<nums.size() ;i++){
            arr.push_back({nums[i],i});
        }
        sort( arr.begin(), arr.end());
        
        int l=0;
        int r=arr.size()-1;
        while ( l<r){
            int sum = arr[l].first+arr[r].first;
            if (sum == target ) return {arr[l].second, arr[r].second};
            
            if ( sum < target)  l++     ;//increase sum
            if ( sum> target) r--;  //decrease sum

        }
    return {};

    }
};