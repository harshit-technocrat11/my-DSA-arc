class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);

        vector<int> dist(n, INT_MAX);

        for ( auto &flight : flights){
            int start= flight[0];
            int end= flight[1];
            int cost = flight[2];
            adj[start].push_back({end, cost});
        }

        queue<pair<int,int>> q;
        
        int steps = 0;

        // push the src
        q.push({src,0}); 
        dist[src]=0;
   

        while (!q.empty() && steps<=k){
            int size = q.size();

            while (size--){

                auto &it =  q.front();
                int u= it.first;
                int d =  it.second;

                q.pop();

                for ( auto &it: adj[u]){
                    int wt = it.second;
                    int v = it.first;

                    if ( d + wt < dist[v] ){
                        dist[v] = d+wt;
                        
                        q.push({v, dist[v]});
                    }
                }
            }
            steps++;
        
        }

        if (dist[dst]==INT_MAX){
            return -1;
        }

        return dist[dst];
    }
};