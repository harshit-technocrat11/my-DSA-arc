class Solution {
public:
    // int check(int row , int col, int n){
    //     return (row>=0 && row<n && col>=0 && col<n);
    // }
    // int solve (int r, int c, vector<vector<int>>& matrix, vector<vector<int>> & dp,int & n){

    //     if ( r==n-1) return  matrix[r][c];
    //     if ( dp[r][c]!=-1) return dp[r][c];

    //     int mini = INT_MAX;

    //     if (check(r+1, c-1, n)){
    //         int left = matrix[r][c] + solve(r+1, c-1 , matrix, dp, n);
    //         mini = min(mini, left);
    //     }
    //     if (check(r+1, c, n)){
    //         int below = matrix[r][c] + solve(r+1, c , matrix, dp, n);
    //         mini = min(mini, below);
    //     }
    //     if (check(r+1, c+1, n)){
    //         int right = matrix[r][c] + solve(r+1, c+1 , matrix, dp, n);
    //         mini = min(mini, right);
    //     }

    //     return dp[r][c] = mini;

    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
    // Tabulation - optimized space
        int n = matrix.size();

        // vector<vector<int>> dp = matrix;
        // int ans=INT_MAX;

        for ( int r=n-2 ; r>=0 ; r--){
            for ( int c = 0 ; c<n; c++){
                int mini = 100000;

                if (c-1>=0){
                    mini = min(mini, matrix[r+1][c-1]);
                }

                mini = min(mini, matrix[r+1][c]);
                
                if ( c+1<n){
                    mini = min(mini,  matrix[r+1][c+1]);
                }

                matrix[r][c] = matrix[r][c] + mini;
            }

        }

        return *min_element(matrix[0].begin(), matrix[0].end());

    }
};