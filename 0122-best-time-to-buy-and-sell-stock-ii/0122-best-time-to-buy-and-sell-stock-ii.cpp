class Solution {
public:
    int dp[30001][2];
    int solve (int i , int canBuy , vector<int> &prices ){
        
        int n = prices.size();
        
        if ( i==n) return 0;
        
        if (dp[i][canBuy]!=-1){
            return dp[i][canBuy];
        }

        if (canBuy){

            long long buy = -prices[i] + solve(i+1, 0, prices);
            long long skip = solve(i+1, 1, prices);

            return dp[i][canBuy] = max(skip, buy);
        }

        else {
            // sell state canBuy = 0
            long long sell =  prices[i] + solve(i+1 , 1 , prices);
            long long skip =  solve(i+1, 0, prices);
            
            return dp[i][canBuy] = max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));

        return solve(0, 1, prices);
    }
};