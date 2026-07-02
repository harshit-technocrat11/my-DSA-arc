class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        
        vector<int> pse;
        stack < int> st;
        
        for ( int i = 0 ; i < arr.size() ; i++){
            
            while ( !st.empty() && arr[i]<=st.top() ){
                st.pop();
            }
            
            if (st.empty()) pse.push_back(-1);
            
            else pse.push_back(st.top());
            
            st.push(arr[i]);
        }
        
        return pse;
    }
};