class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        // keeping a set
        int n = matrix.size();

        for ( int i = 0; i < n; i++){
            set<int> st;

            for ( int j = 0; j<n ; j++){

                st.insert(matrix[i][j]);

            }
            if ( st.size()!=n) return false;
        }

        //col check
        for (int j=0; j<n ; j++){
            set<int> st;
            for (int i=0;i < n; i++){
                st.insert(matrix[i][j]);
            }

            if (st.size()!=n) return false;
        }

        return true;
    }
};