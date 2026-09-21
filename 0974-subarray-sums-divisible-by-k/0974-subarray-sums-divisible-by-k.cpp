class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> mp;
        mp[0]=1;

        int sum = 0;

        int count = 0;

        for ( int i = 0 ; i < n; i++){
            sum+=nums[i];

            int rem = sum%k; //find remainder

            if (rem<0){
                rem+=k;
            }

            if ( mp.find(rem)!=mp.end()) {
                // if remainder found earlier
                count+= mp[rem];
            }

            mp[rem]++; //record remainder
        }

        return count;
    }
};