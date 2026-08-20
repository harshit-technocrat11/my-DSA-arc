class Solution {

    void dfs (int row, int col ,vector<vector<char>>& grid ){
        int m=grid.size();
        int n= grid[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == '0') {
            return;
        }
        // mark as visited 
        grid[row][col]='0';

        dfs ( row+1, col , grid);
        dfs ( row-1, col , grid);
        dfs ( row, col+1 , grid);
        dfs ( row, col-1 , grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // we maintain a global counter- and count each dfs traversal
        int m=grid.size();
        int n= grid[0].size();
        int count =0; 

        for ( int i=0; i < m; i++){
            for ( int j=0; j < n; j++){
                if ( grid[i][j]=='1'){
                    dfs ( i, j, grid  );
                    count++;
                }
            }
        }   

        return count;
    }
};