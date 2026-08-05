class Solution {
public:
    int jump(vector<int>& nums) {
        int maxInd=0;
        int count=0;
        int end=0;

        if ( nums.size()==1) return count;
        for ( int i =0; i < nums.size()-1 ; i++){
            maxInd= max(maxInd, i+nums[i]);

            if ( i==end){
                count++;
                end = maxInd;
            }

        }

        return count;
    }
};