class DSU {

    public:

    vector<int> parent;
    vector<int> rank;

        DSU (int n){
            parent.resize(n+1);
            rank.resize(n+1);
            for ( int i = 0; i < n; i++){
                parent[i] = i;
                rank[i]=0;
            }
        }

        int find(int x){
            if (x==parent[x]) return x;

            return parent[x] = find(parent[x]);
        }

        void Union(int x , int y){
            int x_parent = find(x);
            int y_parent = find(y);

            if (x_parent==y_parent) return;

            if (rank[x_parent]>rank[y_parent]) parent[y_parent ] = x_parent;
            else if (rank[y_parent]>rank[x_parent]) parent[x_parent ] = y_parent;

            else {
                // if both rank same
                parent[x_parent] = y_parent;
                // incr rank
                rank[x_parent]++;
            }
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // intuitive approach
        int n = stones.size();

        DSU dsu(n);

        for ( int i=0; i < n; i++){
            for (int j=i+1; j<n; j++){
                if (stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    dsu.Union(i,j);
                }
            }
        }

        int groups = 0; //no. of unique parents / components
        for ( int i  = 0; i < n ; i++ ){
            if ( dsu.parent[i]==i){

                groups++;
            }
        }

        return n - groups;
    }
};