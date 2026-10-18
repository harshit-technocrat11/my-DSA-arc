class Solution {
    bool insideCircle(long long x, long long y, long long r , long long h , long long k ){
        long long rhs = r*r; 
        long long lhs =  (x-h)*(x-h) + (y-k)*(y-k); 
        
        return lhs <= rhs? true: false;
    }

    void dfs(int u, vector<vector<int>> &bombs, vector<int> &vis , int &count ){
        int x = bombs[u][0]; 
        int y = bombs[u][1]; 
        int r = bombs[u][2];
        // vis
        vis[u]=1;
        count++; //detonated

        for ( int i=0; i < bombs.size() ; i++){
            if (i==u) continue;
            int nx = bombs[i][0]; 
            int ny = bombs[i][1]; 
            int nr = bombs[i][2];

            if ( insideCircle(x, y, r, nx, ny) && vis[i]!=1){
                dfs(i, bombs, vis, count);
            } 
        } 

    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        int mxCnt = 0;
        for ( int i = 0; i < n; i++ ) {
            vector<int> vis(n,0);
            int count = 0;

            dfs(i , bombs, vis, count);

            mxCnt =  max(mxCnt, count);

        }

        return mxCnt;
    }
};