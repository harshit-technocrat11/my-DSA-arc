class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int l=0;
        int r=1;
        int n = nums.size();
        int maxL = INT_MIN;
        // increasing seq
        while(r<=n-1){

            while(r<=n-1 && nums[r]>nums[r-1]){
                r++;
            }
            
            maxL = max(r-l, maxL);
            l=r;  
            r++; //incre
        }

        maxL = maxL == INT_MIN ? 1: maxL;

        int maxD = INT_MIN;
        l=0;
        r=1;
        while(r<=n-1){
            while(r<=n-1 && nums[r]<nums[r-1] ){
                r++;
            }

            maxD = max(r-l, maxD);

            l=r;
            r++; //incre
        } 

        maxD = maxD == INT_MIN ? 1: maxD;


        return max(maxL, maxD);

    }
};