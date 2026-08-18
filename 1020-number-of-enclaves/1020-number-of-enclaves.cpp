class Solution {
public:
    void dfs ( int row, int col , vector<vector<int>>& grid ,vector<vector<int>> &vis, vector<vector<int>> dir, int &count){
        int m = grid.size(), n = grid[0].size();
        count--;
        vis[row][col]=1;
        // mark visited and , dec counter
        for ( int k=0; k<4; k++){
            int nrow = row + dir[k][0], ncol = col + dir[k][1];

            if ( nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1 ){
                dfs(nrow, ncol , grid, vis , dir, count);
            }
        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0; //total count of ones
        int m=grid.size(); 
        int n= grid[0].size();
        vector<vector<int>> dir= {{-1,0},{0,1}, {1,0}, {0,-1}};
        vector<vector<int>> vis(m, vector<int> (n, 0));

        // count total no. of 1s
        for ( int i = 0 ; i < m; i++){
            for ( int j =0; j< n ; j++){
                if ( grid[i][j]==1){
                    count++;
                }
            }
        }

        // first row , last row 
        for ( int j=0; j<n; j++){
            if ( grid[0][j]==1 && !vis[0][j]){
                dfs( 0, j, grid , vis , dir,count);
            }

            if ( grid[m-1][j] && !vis[m-1][j]){
                dfs(m-1, j, grid, vis , dir,count);
            }
        }

        // first and last column
        // left + right
        for (int i = 0; i < m; i++) {

            if (!vis[i][0] && grid[i][0] ==1)
                dfs(i, 0,  grid, vis, dir,count);

            if (!vis[i][n-1] && grid[i][n-1] == 1)
                dfs(i, n-1, grid, vis, dir,count);
        }

        return count;

    }
};