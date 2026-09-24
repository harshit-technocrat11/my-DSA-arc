class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int minIdx = INT_MAX;

        for ( int i = 0; i < nums.size(); i++){
            int sum=0;
            int n=nums[i];
            while (n){
                sum+=n%10;
                n=n/10;
            }
            if (sum==i) minIdx = min(minIdx, i);
        }

        if (minIdx==INT_MAX) return -1;

        return minIdx;
    }
};