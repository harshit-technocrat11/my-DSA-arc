class Solution {
public:
    // int solve(int i, vector<int> &nums, vector<int> &dp){
    //     if (i>=nums.size()) return 0;

    //     if (dp[i]!=-1) return dp[i];

    //     int rob = nums[i] + solve(i+2, nums, dp); //take
    //     int skip = solve(i+1, nums, dp); //not take

    //     return dp[i]= max(rob, skip);
    // }

    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+2,0);

        // tabulation
        for ( int i=n-1; i>=0; i--){
            int rob = nums[i] + dp[i+2];
            int skip =  dp[i+1];

            dp[i]= max(rob, skip);
        }

        return dp[0];

    }
};