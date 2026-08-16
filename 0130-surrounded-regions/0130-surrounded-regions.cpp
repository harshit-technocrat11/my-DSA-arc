class Solution {
public:
    void dfs(int row, int col ,vector<vector<int>> &vis, vector<vector<char>>& board, vector<vector<int>> dir ){

        int m = board.size(), n = board[0].size();
        // mark visited
        vis[row][col] = 1;

        // traverse in 4 directions - find 'O'
         for (int k = 0; k < 4; k++) {
          
            int nrow = row + dir[k][0], ncol = col + dir[k][1];
            // check bounds and unvisited 'O'
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                
                dfs(nrow, ncol, vis, board, dir );
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> dir= {{-1,0},{0,1}, {1,0}, {0,-1}};
        

        vector<vector<int>> vis(m, vector<int> (n, 0));

        // traverse first row and last row 
        for (int i = 0; i < n; i++) {

            if (!vis[0][i] && board[0][i] == 'O')
                dfs(0, i, vis, board, dir);

            if (!vis[m-1][i] && board[m-1][i] == 'O')
                dfs(m-1, i, vis, board, dir);
        }

        // left + right
        for (int i = 0; i < m; i++) {

            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, vis, board, dir);

            if (!vis[i][n-1] && board[i][n-1] == 'O')
                dfs(i, n-1, vis, board, dir);
        }

        // last checking ( to conquer the surrounded regions )

        for ( int i = 0; i < m; i++){
            for ( int j = 0; j < n ; j++){
                if ( !vis[i][j] && board[i][j]=='O'){
                    // modify the board
                    board[i][j]= 'X';
                }
            }
        }
        
    }
};