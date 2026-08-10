class Solution {
private:
    
    void dfs(int node,vector<vector<int>>& isConnected,  unordered_set<int>& visited) {
       
        visited.insert(node); //mark current node as visited

        // vist all neighbors
        for ( int i=0; i < isConnected[node].size(); i++){
    

            if (isConnected[node][i] && visited.find(i)==visited.end()){
                dfs(i, isConnected, visited);
            }
        }
    }
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        // convert the adjacency matrix into - adjacency list
        unordered_set<int> visited;
        int provinces = 0;

        for ( int i=0; i < isConnected.size();i++){
            if ( visited.find(i)==visited.end()){
                dfs(i, isConnected, visited);
                provinces++;
            }
        }

        return provinces;
    }
};