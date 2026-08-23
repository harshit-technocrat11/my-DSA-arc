class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        // find indegree
        vector<int> indegree(V,0);
        
        // adj list
        vector<vector<int>> adj(V);
        
        for ( auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        
        for ( int u=0; u<V; u++){
            for ( int &v: adj[u]){
                indegree[v]++;
            }
        }
        
        queue<int> q;
        
        int count=0;
        // fill the queue
        for ( int u = 0; u< V; u++){
            if ( indegree[u]==0){
                q.push(u);
                count++;
            }
        }
        
        // simple BFS
        
        // process each element in the queue, and visit its neighbors, dec-- indegress
        // vector<int> result;
    
        while (!q.empty()){
            int u= q.front();
            
            q.pop();
            // result.push_back(u);
            
            for ( int &v: adj[u]){
                indegree[v]--;
                
                if ( indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }
        
        
        return count!=V;
        
        
        
    }
};