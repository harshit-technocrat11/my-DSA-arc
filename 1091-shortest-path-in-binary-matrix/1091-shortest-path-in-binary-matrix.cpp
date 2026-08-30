class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        typedef  pair<int, pair<int, int>> P;
        
        if ( grid[0][0]!=0) return -1;

        int m=grid.size(); //nxn

        vector<vector<int>> directions =  {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        vector< vector<int>> result(m, vector<int>(m, INT_MAX));

        // lambda
        auto isSafe = [&](int x, int y){
            return (x>=0 && x<m && y>=0 && y<m);
        };

        priority_queue<P, vector<P>, greater<P> > pq;

        pq.push({0, {0,0}});
        grid[0][0]=1;
        result[0][0]=0;

        // use grid - to mark visited 
        while (!pq.empty()){
            int d = pq.top().first;
            pair<int, int> node = pq.top().second;

            int x = node.first;
            int y = node.second;

            pq.pop();

            for ( auto dir : directions){
                int nr =  x+dir[0];
                int nc = y +  dir[1];

                if ( isSafe(nr,nc) && grid[nr][nc]==0 && d + 1 < result[nr][nc]){
                    pq.push({d+1, {nr, nc}});
                    result[nr][nc]= d+1;
                }
            }

        }

        if (result[m-1][m-1]==INT_MAX){
            return -1;
        }
        
        return result[m-1][m-1]+1;
    }
};