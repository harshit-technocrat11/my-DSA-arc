class Solution {
public:
    bool dfsTopo ( int u,vector<vector<int>>& adj , vector<int> &vis , vector<int> &inRec, string&colors, vector<vector<int>> &dp ){
        vis[u] = 1;
        inRec[u] = 1;

        for ( auto &v: adj[u]){
            if (inRec[v]==1){
                return true;
            }
            else if (!vis[v]){
                if (dfsTopo(v , adj , vis, inRec, colors, dp)){
                    return true;
                }  
            }
            // for current state, best val
            for ( int c=0; c<26; c++){

                dp[u][c] =  max(dp[u][c] , dp[v][c]);
            }
        }

        dp[u][colors[u] - 'a']++; 
        // pop
        inRec[u] = 0;
        return false;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // topo sort
        int n = colors.size();
        vector<vector<int>> adj(n);

        for ( vector<int> edge: edges ){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        // dp 
        vector<vector<int>> dp(n, vector<int>(26 , 0));
        int maxi = 0;

        vector<int> inRec (n, 0);

        vector<int> vis(n,0);

        for ( int i = 0; i < n; i++){
            if(!vis[i]){
                if (dfsTopo(i, adj, vis, inRec ,colors , dp )) {
                    return -1; //cycle detected 
                }
                int m = *max_element(dp[i].begin(), dp[i].end());
                maxi  = max ( maxi ,m );
            }
        }

        return maxi;
        
    }
};