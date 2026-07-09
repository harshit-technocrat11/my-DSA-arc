class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // using the hashmap 
        int n = nums.size() ;
        unordered_map<int, int> mp;
        vector<int> ans;
        int minFreq = int(n/3) + 1;

        for ( int i = 0 ; i < nums.size(); i++ ){
            mp[nums[i]]++; //increment frequency

            // check for majority element ;
            if ( mp[nums[i]] == minFreq){
                ans.push_back(nums[i]);
            }

            if ( ans.size() > 2) break;
            
        }

        return ans;
    }
};