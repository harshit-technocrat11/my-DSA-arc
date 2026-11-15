class Solution {
public:
    bool solve(int i , int k ,  vector<int>& stones, unordered_map<int,int> &mp, vector<vector<int>> &dp){
        int n = stones.size();
        if (i>=n) return false;
        if (i==n-1) return true;
        
        if (dp[i][k]!=-1) return dp[i][k];

        // logic
        // if(mp.find(a[i])==mp.end()) return false;

        bool res=false;

        for (int t = k-1; t<=k+1; t++){
            if(t<=0 ) continue;
            if(mp.find(stones[i]+t)==mp.end())
            {
                res = res ||false;
                continue;
            }
            int idx = mp[stones[i]+t];
            res = res || solve(idx , t, stones, mp, dp);
        }

        return dp[i][k] = res;
    }

    bool canCross(vector<int>& stones) {
       unordered_map<int,int> mp;

        // edge case - too large dist
        if (stones[1]- stones[0] > 1) return false;
       
       for ( int i=0; i < stones.size(); i++){
        mp[stones[i]] = i;
       }
        
       int n= stones.size();
       vector<vector<int>> dp(n, vector<int>(n+1, -1) );

        // first jump should be only 1 , 
        // k=0 , initially
        // so , we get (-1,0,1)  , and only 1 is valid jump
       return solve(0, 0, stones, mp, dp);

    }
};