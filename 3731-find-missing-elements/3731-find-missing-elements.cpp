class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        vector<int> ans;
        int n= nums.size();
        unordered_map < int, bool> mp;
        for ( int n: nums){
            mp[n]=true;
        } 
        //  * -- for dereference 
        int max = *max_element(nums.begin() , nums.end());
        int min = *min_element(nums.begin() , nums.end());

        // iterate in the range
        for ( int i = min; i <= max ;i++){
            if ( mp[i]==false){
                // push
                ans.push_back(i);
            }

            else continue;
        }



        return ans;
    }
};