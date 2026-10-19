class Solution {
public:
    
    // int sum(int r, int i, vector<vector<int>> &triangle ,vector<vector<int>> &dp){
        
    //     if ( r==triangle.size()-1) return triangle[r][i]; //at last row
    //     if ( dp[r][i]!=-1) return dp[r][i];

    //     int sumi = triangle[r][i] + sum(r+1, i, triangle, dp);
    //     int sumi_plus = triangle[r][i] + sum(r+1, i+1, triangle, dp);

    //     return dp[r][i]=min(sumi, sumi_plus);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp = triangle;

        for ( int r = n-2; r>=0; r--){
            for ( int c=0; c<=r; c++){
                dp[r][c] = dp[r][c] + min(dp[r+1][c], dp[r+1][c+1]);
            }
        }

        return dp[0][0];
    }
};