class Solution {
public:
    // int dp[30001][2];
    // int solve (int i , int canBuy , vector<int> &prices ){
        
    //     int n = prices.size();
        
    //     if ( i==n) return 0;
        
    //     if (dp[i][canBuy]!=-1){
    //         return dp[i][canBuy];
    //     }

    //     if (canBuy){

    //         long long buy = -prices[i] + solve(i+1, 0, prices);
    //         long long skip = solve(i+1, 1, prices);

    //         return dp[i][canBuy] = max(skip, buy);
    //     }

    //     else {
    //         // sell state canBuy = 0
    //         long long sell =  prices[i] + solve(i+1 , 1 , prices);
    //         long long skip =  solve(i+1, 0, prices);
            
    //         return dp[i][canBuy] = max(sell, skip);
    //     }
    // }

    int maxProfit(vector<int>& prices) {
        // memset(dp, -1, sizeof(dp));
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        // on last day , 0 transactns
        // dp[n][0] = dp[n][1] = 0;

        // space optmize
        int dp0 = 0;
        int dp1 = 0;

        for (int i=n-1; i>=0 ; i--){
            for (int canBuy=0; canBuy<=1; canBuy++){
                long long profit = 0;
                if (canBuy){
                profit+= max( -prices[i] + dp0 , 0 + dp1 );
                dp1 = profit;
                }

                else {
                // sell state canBuy = 0
                profit+= max( prices[i] + dp1 , 0 + dp0);
                dp0 = profit;
                }         
            }
        }

        return dp1;
    }
};