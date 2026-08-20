class Solution {

    void dfs (int row, int col ,vector<vector<char>>& grid, vector<vector<int>> &vis, vector<vector<int>> &dir ){
        int m=grid.size();
        int n= grid[0].size();
        // mark as visited
        vis[row][col]=1;

        for ( int i=0; i < 4; i++){
            int nrow =  row + dir[i][0];
            int ncol =  col + dir[i][1];

            if ( nrow>=0 && nrow < m  && ncol >=0 && ncol< n && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                dfs ( nrow, ncol , grid, vis, dir);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // we maintain a global counter- and count each dfs traversal
        int m=grid.size();
        int n= grid[0].size();
        int count =0; 
        vector<vector<int>> vis(m, vector<int>(n,0));

        vector<vector<int>> dir =  {{-1,0}, {0,1}, {1,0}, {0,-1}};

        for ( int i=0; i < m; i++){
            for ( int j=0; j < n; j++){
                if ( vis[i][j]==0 && grid[i][j]=='1'){
                    dfs ( i, j, grid, vis , dir );
                    count++;
                }
            }
        }   

        return count;
    }
};