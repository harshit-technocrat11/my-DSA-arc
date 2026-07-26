class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int max1 = nums.back();
        nums.pop_back();

        int max2 = nums.back();
        nums.pop_back();
        
        int max3 = nums.back();
        nums.pop_back();

        return max1*max2*max3;
    }
};