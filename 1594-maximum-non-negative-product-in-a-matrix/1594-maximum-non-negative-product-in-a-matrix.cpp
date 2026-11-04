class Solution {
public:
    pair<long long, long long>  dp[16][16];
  

    const int MOD = 1e9 + 7;
    pair<long long , long long>  solve (int i, int j, vector<vector<int>> &grid  ){
        int m = grid.size();
        int n = grid[0].size();

        // base cases
        
        if (i==m-1 && j==n-1 ) return {grid[i][j], grid[i][j]};
        pair<int , int> cmp =  {-1, -1};
        if (dp[i][j]!=cmp) return dp[i][j];
        long long  maxi =  LLONG_MIN;
        long long mini  = LLONG_MAX;
        
        // computing for right side , if next cell exists
        if (j + 1 < n) {
            auto p = solve(i, j + 1, grid);

            long long a = grid[i][j] * p.first;
            long long b = grid[i][j] * p.second;

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }
        // for down side, also checking if next cell exists
        if ( i+1<m) {
            auto p = solve(i+1, j, grid);

            long long a = grid[i][j] * p.first;
            long long b = grid[i][j] * p.second;

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        return  dp[i][j] = {maxi, mini};

    }

    int maxProductPath(vector<vector<int>>& grid) {
        memset(dp, -1,sizeof(dp));
        
        auto p = solve(0 , 0, grid);
        long long  ans =  max(p.first, p.second);
        
        if ( ans<0) return -1;

        return ans % MOD;
    }
};