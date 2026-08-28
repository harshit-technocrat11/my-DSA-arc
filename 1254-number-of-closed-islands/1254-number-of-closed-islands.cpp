class Solution {
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dir ){
        int m=grid.size();
        int n=grid[0].size();
        grid[r][c] = 1;

        for ( auto &d: dir){
            int nr =  r + d[0];
            int nc = c + d[1];

            if ( nr>=0 && nr<m && nc >=0 && nc<n && grid[nr][nc]==0){
                dfs ( nr, nc, grid, dir);
            }
        }

        return ;
        
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};


        // 1st and last row
        for (int j=0; j < n; j++){
            if (grid[0][j]==0){
                dfs(0, j, grid, dir);
            }

            if ( grid[m-1][j]==0){
                dfs(m-1, j , grid, dir);
            }
        }

        // 1st col and last col
        for (int i=0; i < m; i++){
            if (grid[i][0]==0){
                dfs(i,0 , grid, dir);
            }

            if ( grid[i][n-1]==0){
                dfs(i, n-1, grid, dir);
            }
        }


        // traverse the last time, perform dfs , increment counter for each 
        int count = 0;
        
        for ( int i = 0; i < m; i++){
            for ( int j = 0; j < n; j++){
                if (grid[i][j] == 0) {
                    dfs( i, j,grid ,dir);
                    count++;
                }
            }
        }

        return count;
        
    }
};