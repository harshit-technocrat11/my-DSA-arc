class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int count=0;

        for ( int i = 0; i<nums.size(); i++){
            
            unordered_set<int> st;
            for ( int j=i; j<nums.size() ;j++){

                st.insert(nums[j]);
                int t=st.size();
                count+=t*t;
            }
        }

        return count;
    }
};