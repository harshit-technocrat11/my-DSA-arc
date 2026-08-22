class Solution {
public:
    bool DFS (vector<vector<int>> &adj, int u , vector<bool> &vis, vector<bool> & inRecursion, stack<int> &s){

        // mark vis
        vis[u] = true;
        inRecursion[u]=true;

        // put the children of u, i.e v1, v2, v3 , ... v inside the in the stack
        for ( int v: adj[u]){

            if ( inRecursion[v]==true){
                // cycle detected , return false; , i.e course couldnot be completed in Order
                return false;
            }

            if  ( !vis[v] && !inRecursion[v] ){
               if ( !DFS(adj, v, vis,inRecursion, s) ) {
                    return false;
               }
            }
        }

        inRecursion[u]=false;
        s.push(u);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // construct the adj list

        vector<bool> vis(numCourses, false);

        vector<bool> inRecursion(numCourses, false);

        stack<int> s;

        vector<vector<int>> adj(numCourses);

        for ( auto n: prerequisites){
            adj[n[1]].push_back(n[0]);
        }

        // handle the cycle 
        for ( int i=0; i < numCourses; i++){
            if (!vis[i]){
                if ( !DFS( adj, i,  vis,inRecursion, s)){
                    return {};
                }
            }
        }

        vector<int> ans;

        while ( !s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};