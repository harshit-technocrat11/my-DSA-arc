class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m =  grid.size(); //rows
        int n =  grid[0].size(); // col
        int total=n*m;

        vector<vector<int>> temp (m, vector<int>(n)) ;

         for (int i = 0; i < m; ++i) { 
            for ( int j=0;j<n;j++){
                int indx = (i*n+j+k)%total; //1 D index

                int x = indx/n;
                int y = indx%n;

                temp[x][y] = grid[i][j];
            }
         }

         return temp;
    }
};