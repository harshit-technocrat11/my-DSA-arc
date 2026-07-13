class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int l=0, r=0;

        // while loop-1 
        while ( l<m && r<n ){
            if ( nums1[l]<=nums2[r]){
                ans.push_back(nums1[l]);
                l++;
            }
            else{
                ans.push_back(nums2[r]);
                r++;
            }
        }

        // 2nd pass remaining elements
        while ( r<n){
            ans.push_back(nums2[r]);
            r++;
        }
        while ( l<m){
            ans.push_back(nums1[l]);
            l++;
        }

        // ---------------replace elements
        for ( int i = 0; i < m+n;  i++){
            nums1[i]=ans[i];
        }

    }
};