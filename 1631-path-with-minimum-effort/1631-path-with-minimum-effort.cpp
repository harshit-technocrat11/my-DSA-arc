class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n= heights[0].size();
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        vector< vector<int>> result(m, vector<int>(n, INT_MAX));

        typedef  pair<int, pair<int, int>> P;
        
        // lambda
        auto isSafe = [&](int x, int y){
            return (x>=0 && x<m && y>=0 && y<n);
        };

        priority_queue<P, vector<P>, greater<P> > pq;

        pq.push({0,{0,0}});
        result[0][0]=0; //min effor is 0 currently

        while (!pq.empty()){
            int effSoFar = pq.top().first;
            pair<int, int> node = pq.top().second;

            int x = node.first;
            int y = node.second;
            pq.pop();


            // stale check , then skip 
            if (effSoFar > result[x][y]) continue;
            


            for ( auto d : dir){
                int nr =  x+d[0];
                int nc = y +  d[1];   
            

                if ( isSafe(nr,nc)){
                    int diff = abs(heights[x][y] - heights[nr][nc]);
                    int newEff = max(effSoFar, diff );

                    if (newEff < result[nr][nc]){
                        result[nr][nc] = newEff;
                        pq.push({result[nr][nc], {nr, nc}});
                    }
                }
            }

        }

        return result[m-1][n-1];
        
    }
};