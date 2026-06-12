class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // taking double search space
        
        // monotonic stack 
        stack <int> st;
        int n = nums.size();
        vector<int>  ans(n, -1);

        for ( int i = 2*n-1; i>=0; i--){
            // circular index extract
            int ind = i%n;

            //pop until u find , a NGE, than current element
            while ( !st.empty() && st.top()<= nums[ind]){
                st.pop();
            }
            if ( st.empty()) ans[ind] =  -1;
            
            else  ans[ind] = st.top();

            st.push(nums[ind]);
        }

        return ans;
    }
};