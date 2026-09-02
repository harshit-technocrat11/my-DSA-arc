class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // store (probability, node)
        typedef pair<double,int> t;

        // store {node, prob}
        vector<vector<pair<int,double>>> adj(n);
        
        // adj list
        for (int i = 0; i <edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            double p = succProb[i];
            adj[a].push_back({b,p });
            adj[b].push_back({a,p });
        }

        // prob
        vector<double> P(n,1e-5);
        P[start_node]=1.0;

        priority_queue<t > pq; //max heap

        pq.push({1.0, start_node});

        while (!pq.empty()){
            int node = pq.top().second;
            double prob =  pq.top().first;

            pq.pop();
            

            for ( auto &it : adj[node]){
                int v = it.first;
                double edgeProb =  it.second; //probability

                // if we found a greater probability, then
                double newProb =  edgeProb*prob;

                if ( newProb > P[v] ){
                    P[v] = newProb;

                    pq.push({newProb, v});
                }
            }
        }

        if ( P[end_node]==1e-5){
            return 0;
        }

        return P[end_node];

    }
};