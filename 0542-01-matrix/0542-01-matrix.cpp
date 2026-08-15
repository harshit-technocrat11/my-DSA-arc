class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // using a better approach-> BFS from 0 -- and keep updating the distances
        vector<vector<int>> direction = {{-1,0},{0,1},{1, 0},{0, -1} };
        int m= mat.size();
        int n= mat[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> result (m , vector<int>(n,-1)); //initialize the result/vis array with -1

        // store all the 0's coords
        for (int i =  0; i < m; i++){
            for ( int j=0; j<n; j++){
                if ( mat[i][j]==0){
                    result[i][j]=0; //distance from 0 to itself = 0
                    q.push({i,j});
                }
            }
        }

        // 4 directions traversal

        while (!q.empty()){

            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for ( int i=0; i<4;i++){

                int nrow =  r + direction[i][0];
                int ncol = c + direction[i][1];

                // if point inside the boundary condition and result == -1

                if ( nrow>=0 && nrow <m && ncol>=0 && ncol<n && result[nrow][ncol]==-1){
                    // store the updated distance ( previous distance + 1)
                    result[nrow][ncol] = result[r][c]+1; 

                    q.push({nrow, ncol});
                }
            }
        }

        return result;


    }
};