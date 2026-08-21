class Solution {
public:

    bool dfs(int node, vector<vector<int>> &adj,vector<int> &vis,vector<int> &inRecursion){
        // mark it as visited , and include in current recursion
        vis[node]=1;
        inRecursion[node] = 1;

        // cases for cycle detection
        for (int &n : adj[node] ){

            // if not visited , and if cycle detected
            if (!vis[n] && dfs(n, adj, vis, inRecursion)){
                return true;
            }

            // if in current recursion, and is already visited
            else if (inRecursion[n]){
                return true;
            }
        }
        inRecursion[node] = 0;
        return false; //backtrack

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vertex = numCourses 

        // construct adj list
        vector<vector<int>> adj(numCourses);

        for ( auto &it: prerequisites){
            adj[it[1]].push_back(it[0]); 
        }   

        vector<int> vis(numCourses, 0);

        vector<int> inRecursion(numCourses, 0);

        for ( int i=0; i < numCourses; i++){
            if (!vis[i] && dfs(i , adj, vis, inRecursion)==true){
                return false; //cannot complete course , if cycle detected 
            }
        }

        return true;
    }
};