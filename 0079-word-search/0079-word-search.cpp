class Solution {
public:
    typedef vector<vector<char>> t;

    bool dfs (int r, int c, int idx, t &board, string & word , t &dir){
        if ( idx==word.size()-1){
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        // mark visited
        char temp =  board[r][c];
        board[r][c]='0';

        for ( int i=0; i < 4; i++){
            int nr = r+  dir[i][0];
            int nc = c+ dir[i][1];

            // within bounds
            if (nr>=0 && nr<m && nc>=0 && nc<n ){
                if ( word[idx+1]== board[nr][nc] ){
                    if (dfs(nr, nc, idx+1, board, word, dir)) {
                        return true;
                    }
                }

            }
        }

        board[r][c] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        string temp;
        t dir = {{-1,0}, {0,1} ,{1,0}, {0,-1}};

        int m = board.size();
        int n = board[0].size();

        for ( int i = 0; i < m; i++){
            for ( int j=0; j<n; j++){
                if ( word[0]==board[i][j]){
                    if (dfs( i,j, 0, board, word, dir)){
                        return true;
                    }

                }
            }
        }

        return false;

    }
};