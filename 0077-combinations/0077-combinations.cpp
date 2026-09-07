class Solution {
public:

    void solve ( vector<vector<int>> &ans, vector<int>&path,int &n, int k , int ind){

        if ( path.size()==k){
            ans.push_back(path);
            return;
        }

        for ( int i = ind; i <=n ; i++){
            path.push_back(i);

            solve (ans, path, n , k ,i+1);

            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans; 
         vector<int> path;

         solve(ans, path, n, k , 1);

        return ans;
    }
};