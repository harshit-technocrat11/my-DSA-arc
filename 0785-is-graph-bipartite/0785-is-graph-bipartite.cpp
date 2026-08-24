class Solution {
public:
    bool dfs (int node,vector<vector<int>> &graph, vector<int> &vis, int color  ){
        // mark visited
        vis[node] = color;

        for ( int &v: graph[node]){
            if ( vis[v]==-1 ){
                if ( !dfs(v, graph, vis, 1-color)) return false;
            }

            // checking the already visisted neighbor
            else if( vis[v]==color){
                return false; //cannot be bipartite , same color detected , in adjacent node
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        // -1 = not vis
        // 0 - Blue
        // 1 = red
        int color=0;
        for ( int i = 0; i< graph.size(); i++){
            if ( vis[i]==-1 ){
                if (dfs(i, graph, vis, color )==false){
                    return false;
                }
            }
        }

        return true;
    }
};