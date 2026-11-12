class Solution {
public:
    int solve (int i, int t,vector<int>& coins, vector<vector<int>> &dp){
        if(t==0) return 1;

        if ( i==0 ) {
            if (t%coins[i] == 0){
               return 1;
            }
            else{
                return 0;
            }
        }

        if (dp[i][t] != -1){
            return dp[i][t];
        }
        // skip
        int nottake = solve(i-1, t, coins, dp);

        // take
        int take = 0;

        if(t>=coins[i]) {
            take = solve(i, t-coins[i], coins, dp);
        }

        return dp[i][t] = take + nottake;
    }

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        return solve(n-1, amount, coins, dp); 
    }
};