class Solution {
    void dfs (  int node , vector<int> &path , vector<vector<int>> &graph, vector<vector<int>>& ans, int &n ){
            if (node == n-1){ 
                ans.push_back(path);
                return;
            }

            for (auto v: graph[node]){
                path.push_back(v);
                dfs ( v, path, graph ,ans  , n);
                path.pop_back();
            }
        };
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> ans;
        int n =  graph.size();
        path.push_back(0); //start 
        dfs ( 0, path, graph, ans , n);

        return ans;

    }
};