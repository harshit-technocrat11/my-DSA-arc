class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // constructing adj list
        vector<vector< pair<int, int> >> adj(n+1);

        for ( auto &it: times){
            // node, dist
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n+1, 1e9); // 1 based indexing

        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int,int>> > pq;
        // dist , node


        // src to src dist = 0
        dist[k]=0; 
        pq.push({0, k});


        while ( !pq.empty()){

            int d = pq.top().first;
            int node = pq.top().second ;
            pq.pop();

         

            for ( auto &it: adj[node]){

                int v = it.first;
                int edge = it.second;

                if (  d + edge < dist[v]){
                    dist[v] = d+edge; 
                    // edge relaxation
                    pq.push({dist[v], v});
                }
            }

        }

        int ans =0;

        for( int i =1 ; i <= n; i++){
            if (dist[i]==1e9){
                return -1;
            }

            ans = max(dist[i], ans);
        }

        return ans;
    }
};