class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // pair - node, wt

        // each point , (x, y) = i idx
        typedef pair<int,int> p;
        int n = points.size(); //total nodes
        
        int min_cost = 0;
        vector<int> vis(n,0);

        priority_queue< p, vector<p> , greater<p> > pq; //cost , vertex

        pq.push({0,0});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int u = it.second;
            
            if (vis[u]==1) continue;
            vis[u]=1;
            min_cost+=dist;

            // each point, is connected to every other point 
            for ( int i=0; i<n; i++){
                // cost cal
                if (!vis[i]){
                    
                    int cost  = abs(points[i][0] - points[u][0]) + abs(points[i][1] - points[u][1]); 
                    
                    pq.push({cost, i});
                }
            }
        }

        return min_cost;

    }
};