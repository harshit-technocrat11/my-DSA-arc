class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // 1 = +1 , 0 = -1
        int n=nums.size();

        unordered_map<int,int> mp; // sum , idx
        mp[0]=-1;
        
        int sum = 0;
        int maxLen =  0;

        for ( int i = 0; i < n; i++){
            sum+=  nums[i]? 1 : -1;

            // if the prefixSum , was found earlier
            if ( mp.find(sum) != mp.end()){
                int size = i -  mp[sum];
                maxLen = max(maxLen, size);
            }
            else{
                mp[sum] = i;
            }
        }
        return maxLen;


    }
};