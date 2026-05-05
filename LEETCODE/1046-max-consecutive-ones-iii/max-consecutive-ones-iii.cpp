class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0;
        int zeroCount = 0;
        // take 2 pointers r, l
        int r=0;
        int l=0;
        int n=nums.size();

        while ( r<n ){
            if ( nums[r]==0){
                zeroCount++;
            }

            while ( zeroCount>k){
                // shrink until window --- mein the count of Zeroes reduces to <=2
                
                if( nums[l]==0) zeroCount--;
                l++;
            }

            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;

    }
};