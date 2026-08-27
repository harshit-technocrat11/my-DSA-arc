class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int total=0;
        for ( int i=0;i < n; i++){
            total+=nums[i];
        }
        vector<int> ans(n);

        for (int i=0; i < n ; i++){
            int lsum=curr;

            curr+=nums[i];
            
            int rsum = total-curr;
            ans[i]= abs(lsum - rsum);

        }


        return ans;

    }
};