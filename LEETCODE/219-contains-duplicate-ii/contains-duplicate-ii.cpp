class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map <int,int> mp; 

        for (int i=0; i < n; i++){

            // first check whether the number was seen before or not  , then check window       condition
            if( mp.count(nums[i])){
                if (abs(i-mp[nums[i]]<=k)){
                    return true;
                }
            }

            // if the element is not seen before , update it with index 
            mp[nums[i]]=i;
        }

        return false;
    }
};