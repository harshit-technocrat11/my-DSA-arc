class Solution {
public:
    long long dp[501][501][2];
    const int MOD = 1e9+7;
    int solve (int i , int j ,vector<vector<int>>& grid, int dir ){
        int m = grid.size();
        int n = grid[0].size();

        if ( i==m-1 && j==n-1) {
            return 1;
        }

        if (i<0 || i>=m || j<0 || j>=n ){
            return 0;
        }
        if (dp[i][j][dir] !=-1) {
            return dp[i][j][dir];
        }

        long long ans = 0;

        if (grid[i][j]==1){
            if (dir ==0){
                // right
               ans = solve(i+1, j,grid, 1);
            }
            else if (dir==1){
                // down
                ans = solve ( i, j+1,grid, 0);
            }
        }
        else{
            ans = (solve (i, j+1,grid , 0) + solve (i+1, j,grid , 1) )%MOD;
        }
        // normalcell
        
        return dp[i][j][dir] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));

        int m = grid.size();
        int n = grid[0].size();

        return  solve(0,0, grid, 0);
    }
};