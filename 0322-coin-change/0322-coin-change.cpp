class Solution {
public:
    int solve (int i, vector<int> &coins, int target, vector<vector<int>> &dp){
        // quite interesting, cause, u can take 1 deno, infinite number of times, 
        // unsual recursion tree
        // at base case , if target is div by coins[i] ,then return t/coins[i]
        // memoization, dp[ind][target]; // ind = which coin

        if ( i==0) {
            if (target%coins[i]==0) return target / coins[i];

            else {
                return 1e9;
            }
        } 
        if ( dp[i][target]!=-1) return dp[i][target];

        // at each step , take or not take
        int nottake = 0 + solve(i-1, coins, target , dp);

        int take = 1e9;
        if (coins[i] <=target ) take = 1 + solve(i,coins, target-coins[i] , dp); //take current, and stay till condtin invalid

        return dp[i][target] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // from the end
        int ans = solve(n-1, coins, amount, dp);

        return ans>=1e9? -1: ans;
    }
};