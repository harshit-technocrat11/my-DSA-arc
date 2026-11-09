class Solution {
public:

    void solve(int i, int j , vector<vector<int>> &grid, int &c){
        int m = grid.size();
        int n = grid[0].size();
        if (i>=m || j>=n){
            return;
        }
        grid[i][j]=0;  //mark vis
        c++;
        // left check
        for ( int r=0; r<j ; r++){
            if (grid[i][r]==1){
              
                solve(i, r, grid, c);
            }
        }

        // up check
        for ( int r = 0; r<i ; r++){
            if (grid[r][j]==1){
                
                solve(r, j, grid, c);
            }
        }

        // right chcek
        for ( int r = j+1; r<n; r++){
            if (grid[i][r]==1){
               
                solve(i, r, grid, c);
            }
        }
        //down check
        for (int r = i+1; r<m ; r++ ){
            if (grid[r][j]==1){
             
                solve(r, j, grid, c);
            }
        }

    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for ( int i  = 0; i < m; i++){
            for ( int j = 0; j<n ; j++){
                if (grid[i][j]==0) continue;

                int c=0;
                solve(i, j ,grid, c);
                
                if(c>1){
                    count+=c;
                }
            }
        }

        return count;
    }
};