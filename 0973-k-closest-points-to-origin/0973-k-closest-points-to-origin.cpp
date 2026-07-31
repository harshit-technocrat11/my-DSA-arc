class Solution {
public:
    // struct Compare{
    //     bool operator()( pair<vector<int>,int>& a, pair<vector<int>,int>& b ){
    //         return a.second<b.second;
    //     }
    // };

    int dist(int x, int y){
        return x*x + y*y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // {dist, point}
        
        priority_queue<pair<int, vector<int>>> pq; //max heap

        vector<vector<int>> ans;

        for ( auto pt: points){
            int d =  dist(pt[0],pt[1]);
            pq.push( {d, pt});
            // maintain the size , upto k 
            if ( pq.size() > k) {
                pq.pop();
            }
        }


        while (!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};