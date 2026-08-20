class Solution {
  public:
    bool dfs(int u, int parent, vector<int> adj[],
             vector<bool>& vis) {

        vis[u] = true;

        for (int &v : adj[u]) {
            
            if (v == parent)
                continue;

            if (vis[v])
                return true;

            
            if (dfs(v, u , adj, vis ))
                return true;
        }

        return false;
    }

  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        // construct the adjList
         vector<int> adj[V];
       
        for (auto edge : edges) {
              int u = edge[0];
              int v = edge[1];

              adj[u].push_back(v);
              adj[v].push_back(u);
        }
         
        vector<bool> visited(V, false);
        
        //  in case graph if disconnected
        for (int i = 0; i < V; i++) {

            if (!visited[i]) {

                if (dfs(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
         
    }
};