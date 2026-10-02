class DSU {
    vector<int> parent;
    vector<int> rank;

    public:
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if ( connections.size()<n-1) return -1; //not enough cables

        int count=n; //no. of components

        DSU dsu(n);

        for ( auto &edge : connections){
            int u = edge[0];
            int v = edge[1];

            if (dsu.find(u)!=dsu.find(v)){
                //count 
                dsu.Union(u,v);
                count--;
            } 

        }

        return count-1;


    }
};