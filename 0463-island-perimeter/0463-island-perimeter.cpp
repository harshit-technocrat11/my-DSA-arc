class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // simple approach
        int n=grid.size();
        int m=grid[0].size();
        int perimeter=0;

        vector< vector<int>>  del = {{-1,0},{0,1},{1,0},{0,-1}};

        for ( int i=0; i < n; i++){
            for ( int j=0; j<m; j++){

                if ( grid[i][j]!=1){
                    continue;
                }
                // if its a land

                int row = i;
                int col=j;

                // checking in 4 directions
                for ( int x=0; x<4 ;x++){
                    int nrow= row + del[x][0];
                    int ncol= col + del[x][1];

                    // index out of range
                    if (( nrow<0 || nrow >=n || ncol<0 || ncol>=m) ) {
                        perimeter++;
                        continue;
                    }
                    // if the col is water
                    if (  grid[nrow][ncol]==0 ){
                        perimeter++;
                    }
                    
                }
            }
        }

        return perimeter;
    }
};