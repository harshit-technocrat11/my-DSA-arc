class Solution {
public:
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    long long dfs(int r, int c , vector<vector<int>>& grid ){

        int m = grid.size();
        int n = grid[0].size();
        long long sum=grid[r][c];

        // mark vis
        grid[r][c]=-1; 

        for ( int i =0 ; i < 4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!=-1 && grid[nr][nc]!=0){
                sum+=dfs(nr, nc, grid);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> vis(m, vector<int> (n,0));
        int count=0;
        for ( int i =0; i < m ; i++){
            for ( int j=0; j<n ; j++){
                if (grid[i][j]!=-1 && grid[i][j]!=0){
                    long long sum = dfs(i, j , grid);
                    if(sum%k==0) count++;
                }
            }
        }

        return count;
    }
};