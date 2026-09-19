class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum  = INT_MAX;
        bool f = false;

        for ( int s = 0 ; s< n; s++){
            int sum  = 0;
            for ( int e = s; e<n; e++){
                sum+= nums[e];
                int len = e-s+1;

                // check Valid
                if ( len>= l && len <= r && sum > 0){
                    minSum = min(sum , minSum);
                    f= true;
                }
            }
        }

        return f? minSum: -1; 
    }
};