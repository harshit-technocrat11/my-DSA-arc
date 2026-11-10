class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // tabulation approach
        vector<int> dp(n+1);
        dp[0] = 0;


        for ( int i=n-1; i >=0 ;i--){
            int cost = INT_MAX;

            for ( int j=i+1; j<= min(n, i+3); j++){
                cost  = min(cost, costs[j-1] + (j-i)*(j-i) + dp[j]);
            }

            dp[i] = cost;
        }

        return dp[0];
    }
};