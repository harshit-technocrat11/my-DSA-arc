class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> mp(edges.size()+2, 0);

        for (auto edge: edges){
            int x=edge[0];
            int y = edge[1];
            mp[x]++;
            mp[y]++;
        }

        // max size
        int mxi=0;
        for ( int i = 1; i < mp.size() ;i++){
            if (mp[i]  > mp[mxi]){
                mxi = i;
            }
        }

        return mxi;
    }
};