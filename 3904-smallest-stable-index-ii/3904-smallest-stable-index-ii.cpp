class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int n = nums.size();

        vector<int> prefMax(n, 0) ;
        vector<int> sufMin(n,0);
        int mx = nums[0], mi = nums[n-1];

        for  ( int i = 0; i < n; i++){
            // storing left max
            mx = max(nums[i], mx);
            prefMax[i] = mx;

            // storing right min
            mi = min(nums[n-i-1], mi);
            sufMin[n-i-1] = mi;
        }

        for ( int i = 0; i < n; i++ ){

            if (prefMax[i]-sufMin[i] <= k){
                ans = min(ans, i);
            } 
        }

        if (ans==INT_MAX){
            return -1;
        }

        return ans;

    }
};