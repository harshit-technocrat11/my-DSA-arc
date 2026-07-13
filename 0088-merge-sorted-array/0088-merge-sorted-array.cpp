class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // using 3 pointers and no extra space.!
        // use the extra space of nums1
        // traverse from the back

        int i=m-1, j=n-1, k=m+n-1;

        while ( i>=0 && j>=0){
            if ( nums2[j]>nums1[i]){
                nums1[k]=nums2[j];
                k--;
                j--;
            }
            else{
                nums1[k]=nums1[i];
                k--;
                i--;
            }
        }
        // remaining elements of nums2
        while ( j>=0){
            nums1[k]=nums2[j];
            k--;
            j--;
        }

    }
};