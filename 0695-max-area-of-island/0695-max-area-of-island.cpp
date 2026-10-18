class Solution {
public:
    void dfs ( int r, int c, vector<vector<int>> &grid, int &area, vector<int> &drow, vector<int> & dcol) {
        // mark visited
        int m = grid.size();
        int n =  grid[0].size();
        grid[r][c] = 0;
        area++;


        for ( int i=0; i < 4; i++){
            int nr =  drow[i]+r;
            int nc = dcol[i] + c;

            if (nr>=0 && nr<m && nc>=0 && nc < n && grid[nr][nc]==1){
                dfs(nr, nc, grid,  area, drow, dcol );
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int m = grid.size();
        int n =  grid[0].size();
        vector<int> drow = {-1,0, 1,0};
        vector<int>dcol = {0,1, 0,-1};

        for ( int i = 0 ; i < m ; i++){
            for ( int j=0; j<n ; j++){

                int area = 0;

                if (grid[i][j]==1){
                    dfs( i, j , grid, area, drow, dcol);
                }
                maxArea =  max( area, maxArea);
            }

        }

        return maxArea;
    }
};