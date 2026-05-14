class Solution {
public:
    int atMost( vector<int>&nums , int goal){
        // here-- ----- Count no. of subarrays <= goal 
        int l=0, r=0;
        int count=0, sum =0; 
        if (goal<0) return 0;

         while( r < nums.size()){
            sum+=nums[r];
            while ( sum > goal){
                // shrink loop
                sum-=nums[l];
                l++; 
            }
            // expand
            count+=(r-l+1);
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // optimal approach ! using - sliding window ( but there's a catch- )
        
        return atMost(nums, goal )- atMost(nums, goal-1);
    }
};