class Solution {
    void dfs(int curr,  vector<vector<int>> &adj,vector<int> &vis){
        // mark vis
        vis[curr]=1;
    
        for ( auto &v: adj[curr]){
            if ( !vis[v] ){
                dfs(v,adj, vis);
            }
        }

    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);

        // create
        for ( auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
            
        dfs(source, adj, vis);
        if ( vis[destination]) return true;

        return false;
    }
};