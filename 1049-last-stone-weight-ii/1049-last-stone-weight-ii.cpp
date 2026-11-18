class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // quite of a puzzling ques, using 0/1 knapsack , 
        // we need to find max subset sum , s2, such that , its closest to TotalSum/2

        int n = stones.size();

        int totalSum =  0;
        for (int x: stones) totalSum+=x;

        // dp[i][j] =  the max subset sum that can be formed from 0 to ith index, closest to target j
        vector<vector<int>> dp(n+1, vector<int>(totalSum+1, 0));

        int target =  totalSum/2;
        // base case initalizing, for i==0
        for (int wt = stones[0]; wt<=target; wt++){
            dp[0][wt] = stones[0];
        }

        // take / not take

        for ( int i=1; i< n; i++){
            for ( int s=0; s<=target; s++){
                
                int notTake = dp[i-1][s];

                int take = 0;

                if ( stones[i]<=s){
                    take = stones[i] +  dp[i-1][s - stones[i]];
                }

                dp[i][s] = max(take, notTake);
            }
        }

        // we have extracted s2

        return  totalSum - 2*dp[n-1][target];
        
    }
};