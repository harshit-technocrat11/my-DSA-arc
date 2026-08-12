class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // store in format - {{r, c} , t}
        // queue - , and visited array
        queue< pair< pair<int, int> , int>> q;
        vector<vector<int>> vis(n, vector<int> (m,0)); 

        // find all the rotten oranges - coordinates , at time=0
        for ( int i=0; i < n; i++){
            for ( int j=0; j < m; j++){
                // if rotten
                if ( grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                // if not rotten, then not visited..
                else {
                    vis[i][j]=0;
                }
            }
        }

        int tm=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0, 1,0,-1};

        while (!q.empty()){
            int r = q.front().first.first;
            int c =  q.front().first.second;
            int t =  q.front().second;

            q.pop();

            tm = max(tm, t);

            // check all 4 neighbors ..

            for ( int i=0; i <4; i++){

                int nrow = r+ drow[i];
                int ncol= c+ dcol[i];

                // check if the neighbor is inside the grid , and also if the orange is not already rotten
                if ( nrow>=0 && nrow<n &&  ncol >= 0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2 ){
                    
                    // rot the orange
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2; 
                }

            }

        }
        // check if , we rot all the fresh oranges or not 
        for ( int i =0; i < n; i++){
            for ( int j=0; j<m; j++){
                if (vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return tm;
        
    }
};