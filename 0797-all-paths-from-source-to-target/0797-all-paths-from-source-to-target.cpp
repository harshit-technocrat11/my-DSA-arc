class Solution {
    void dfs (  int node , vector<int> &path , vector<vector<int>> &graph, vector<vector<int>>& ans ){  
            path.push_back(node);

            if (node == graph.size()-1){ 
                ans.push_back(path);
            }

            for (auto v: graph[node]){
                dfs ( v, path, graph ,ans );
            }
            path.pop_back();
        };
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> ans;
        int n =  graph.size();
  

        dfs ( 0, path, graph, ans );

        return ans;

    }
};