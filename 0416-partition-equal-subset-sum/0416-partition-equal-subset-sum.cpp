class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        // similar to subset sum = k problem

        if ( n==1) return false;
        
        int target = 0;
        for( int i = 0; i < n; i++) target+=nums[i];
        // for odd sum
        if ( target%2!=0) return false;

        target = target/2;

        vector<bool> prev(target+1, false), curr(target+1, false);
        prev[0] =true;
        curr[0]=true;

        if (target >= nums[0]) prev[nums[0]] = true; 

        for ( int i=1; i<n;i++) {
            for ( int t=target; t>=0 ; t--){
                bool notTake = prev[t];  //since index = i-1

                bool take = false;

                if (t>=nums[i]) take =  prev[t-nums[i]];

                curr[t] = take || notTake;
                // update
                prev = curr;
            }
        }

        return curr[target];
    }
};