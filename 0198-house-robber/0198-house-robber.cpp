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
        // 2 ptrs
        int prev2=0;
        int prev1 = 0;

        for ( int num : nums){
            int curr =  max(num+prev2, prev1);

            prev2 = prev1;
            prev1=curr;
        }

        return prev1;

    }
};