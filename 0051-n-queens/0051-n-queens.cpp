class Solution {
public:
    bool isSafe(int row , int col, vector<string> board , int n){
        int r =  row;
        int c = col;

        // upper diag check 
        while (col>=0 && row >=0){
            if (board[row][col]=='Q') return false;
            row--;
            col--;  
        }

        row = r;
        col = c;
        // left check
        while(col>=0){
            if (board[row][col]=='Q') return false;

            col--;
        }

        // lower diag check
        row = r;
        col = c;
        while(col>=0 && row < n){
            if (board [row][col]=='Q') return false;

            row++;
            col--;
        }
        
        return true;
    }

    void solve (int col , vector<string>& board, vector<vector<string>> &ans , int &n ){
        if ( col==n){
            // base case
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n ; row++){
            if ( isSafe(row, col, board,n)){

                board[row][col] = 'Q';

                solve (col+1, board, ans, n);

                // reset 
                board[row][col] = '.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans ; //multiple ans

        vector<string> board(n); 
        string s (n, '.');

        for (int i =0;i < n; i++){
            board[i] = s;
        }

        // iterate col by col
        solve(0, board, ans,n );

        return ans;


    }
};