class Solution {
public:
    int solve (int i , vector<int> &costs, vector<int> &dp , int n ){

        if ( i>=n) return 0 ;

        if ( dp[i]!=-1) return dp[i];
        
        long long currCost = 1e9;
        
        for ( int j=i+1; j<=min(n, i+3); j++){
            long long  a =costs[j-1] + (j-i)*(j-i) + solve(j, costs, dp, n);
            currCost = a<=currCost ? a: currCost;
        }

        return dp[i] =  currCost;
    }


    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        dp[n] = 0;
        return solve(0, costs, dp, n);
    }
};