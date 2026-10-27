class Solution {
public:
    int dp[301][301];

    int solve (int i , int j, vector<vector<char>> &matrix, int &maxi){
        int m= matrix.size();
        int n = matrix[0].size();

        if (i<0 || i>=m || j<0 || j>=n ){
            return 0;
        }
        
        if (dp[i][j]!=-1) return dp[i][j];

        if ( matrix[i][j]=='0') {
            return dp[i][j]=0;
        }

        int mini = +1e8;

        mini  = min(mini, solve(i, j-1, matrix, maxi ));
       
        mini  = min(mini, solve( i-1,j-1, matrix, maxi));
       

        mini  = min(mini, solve( i-1,j, matrix, maxi));

        maxi = max(mini+1, maxi);

        return dp[i][j] =  mini + 1 ;

    }

    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int maxi = 0;
        int m= matrix.size();
        int n = matrix[0].size();
        for (int i=0; i < m; i++){
            for ( int j=0; j<n; j++){

                solve(i,j, matrix, maxi );
            }
        }

        return maxi*maxi;
    }


};