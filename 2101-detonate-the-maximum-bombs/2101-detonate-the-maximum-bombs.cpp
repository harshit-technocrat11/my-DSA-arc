class Solution {
    bool insideCircle(long long x, long long y, long long r , long long h , long long k ){
        long long rhs = r*r; 
        long long lhs =  (x-h)*(x-h) + (y-k)*(y-k); 
        
        return lhs <= rhs? true: false;
    }

    void dfs(int u, vector<vector<int>> &bombs, vector<vector<int>> &adj, vector<int> &vis , int &count ){
        int x = bombs[u][0]; 
        int y = bombs[u][1]; 
        int r = bombs[u][2];
        // vis
        vis[u]=1;
        count++; //detonated

        for (int &v : adj[u]){
            int nx = bombs[v][0]; 
            int ny = bombs[v][1]; 
            int nr = bombs[v][2];

            if ( vis[v]!=1){
                dfs(v, bombs,adj,  vis, count);
            } 
        } 
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        
        vector<vector<int>> adj(n);
        // build adj list 
        for ( int i=0; i < n; i++){
            long long x = bombs[i][0];
            long long y = bombs[i][1];
            long long r = bombs[i][2];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int nx = bombs[j][0]; 
                int ny = bombs[j][1]; 

                if ( insideCircle(x, y, r, nx, ny)){
                    adj[i].push_back(j);
                }
            }
        }

        int mxCnt = 0; //ans
        for ( int i = 0; i < n; i++ ) {
            vector<int> vis(n,0);
            int count = 0;

            dfs(i , bombs, adj,  vis, count);

            mxCnt =  max(mxCnt, count);
        }

        return mxCnt;
    }
};