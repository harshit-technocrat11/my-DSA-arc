class Solution {
public:
    bool isSafe(int row, int col , vector<string> &board, int n){
        int r =row;
        int c = col;

        // upper diag check
        while (r>=0 && c>=0){
            if (board[r][c]=='Q') return false;

            r--;
            c--;
        }

        r=row ; c=col;
        // left check
        while (c>=0){
            if (board[r][c]=='Q') return false;
            c--;
        }

        r=row ; c=col;
        // lower diag
        while (r<n && c>=0){
            if (board[r][c]=='Q') return false;
            r++;
            c--;

        }

        return true;
    }

    void solve(int col, int &n, vector<string> &board, int &count){
        if ( col==n){
            count++;
            return;
        }

        for (int row = 0; row<n; row++){
            if (isSafe(row, col , board ,n)){

                board[row][col]='Q';

                solve(col+1, n , board, count);

                board[row][col]='.';
            }
        }
    }

    int totalNQueens(int n) {
        // board define
        vector<string> board(n);
        string s(n,'.');
        for ( int i=0; i<n ; i++){
            board[i]=s;
        }    
        int count=0;
        solve (0, n, board, count );

        return count;
    }
};