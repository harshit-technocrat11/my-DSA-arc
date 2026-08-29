class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if ( grid[0][0]!=0) return -1;

        int m=grid.size(); //nxn

        vector<vector<int>> dir =  {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

        // lambda
        auto isSafe = [&](int x, int y){
            return (x>=0 && x<m && y>=0 && y<m);
        };

        // using BFS
        queue<pair<int, int>> q;

        q.push({0,0});
        grid[0][0]=1;

        int count =0 ;

        while (!q.empty()){
            // length of the queue , or current level 
            int n = q.size();

            // traverse all elements in queue
            while ( n-- ){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                // base case, if target end reached
                if (x==m-1 && y==m-1) return count+1;

                for ( auto d: dir){
                    int nr =  x + d[0];
                    int nc =  y + d[1];

                    if (isSafe(nr, nc) && grid[nr][nc]==0){
                        q.push({nr, nc});

                        grid[nr][nc]=1; //mark visited
                    }
                }
            }

            count++;
        }

        return -1;
    }
};