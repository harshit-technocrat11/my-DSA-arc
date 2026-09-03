class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int,int>>> adj(n);

        for (auto it: edges){
            int u= it[0];
            int v= it[1];
            int wt= it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});

        }


        // best city and best count
        int best_city =-1;
        int best_count = INT_MAX;

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for ( int i=0; i < n ; i++){
            // source
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
    
            pq.push({0, i});
            
            int count=0;

            while (!pq.empty()){
                int u = pq.top().second;
                int wt = pq.top().first;
                pq.pop();

                // stale check
                if (wt > dist[u]){
                    continue;
                }

                for (auto &it: adj[u]){
                    int v = it.first;
                    int edgeWt = it.second;

                    if ( dist[v]> wt + edgeWt){
                        dist[v] = wt + edgeWt;
                        pq.push({dist[v],v});
                    }
                    }
            }
            

            for ( int j=0; j< n; j++){
                if ( i!=j && dist[j] <=distanceThreshold){
                    count++;
                }
            }

            if ( count< best_count || (best_count==count && best_city < i) ){
                best_count=count;
                best_city = i;
            }
        
        }

        return best_city;

    }
};