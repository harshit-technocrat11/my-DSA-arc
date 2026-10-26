class Solution {
public:
    int t[101][101];

    int solve(int i , int j , int & m, int& n, vector<vector<int>>& obstacleGrid){
        // boundary limit
        if (i>=m || j>=n || obstacleGrid[i][j]==1) return 0;

        if (i==m-1 && j==n-1) return 1; //found a  path

        if (t[i][j]!=-1){
            return t[i][j];
        }

        int right =  solve(i, j+1, m, n, obstacleGrid); //right
        int down = solve(i+1, j, m , n,  obstacleGrid); //downn

        return t[i][j] = right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(t, -1, sizeof(t));
        int m=obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return solve(0,0, m,n, obstacleGrid);
    }
};
