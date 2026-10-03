class Solution {
public:
    
    int solve(int i , vector<int> &nums, vector<int> &dp , int &limit){
        
        if ( i>=limit) return 0;
        if ( dp[i]!=-1) return dp[i]; 

        int rob = nums[i]+  solve(i+2, nums, dp , limit);
        int skip = solve(i+1, nums, dp , limit);

        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        if ( nums.size()==1) return nums[0];
        int l=nums.size()-1;
        int h=nums.size();
        vector<int> dp(nums.size(),-1);
        
        int sum1 = solve(0, nums, dp , l);
        
        dp.assign(nums.size(),-1);
        int sum2 =  solve(1, nums, dp , h);

        return max(sum1, sum2);


    } 
};