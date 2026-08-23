class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        // consider outdegree 
        vector<int> outdegree(n,0);

        vector<vector<int>> parents(n);

        queue<int> q;

        for ( int u=0; u<n; u++){
            // push all terminal nodes first ( with outdeg=0)
            outdegree[u] = graph[u].size();
            if ( outdegree[u]==0){
                q.push(u);
            }

            // find the parents ( process neighbors of u)
            for ( int i : graph[u]){
                parents[i].push_back(u);
            }

        }

        // process the queue
        while (!q.empty()){
            int u = q.front();
            q.pop();

            for ( int parent: parents[u]){
                outdegree[parent]--;
                
                if ( outdegree[parent]==0){
                    q.push(parent);
                }
            }
        }


        vector<int> res;

        // find , the nodes whose outdegree is <= 0
        for (int i=0; i < n; i++){
            if ( outdegree[i]<=0){
                res.push_back(i);
            }
        }

        return res;
    }
};