class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0;
        unordered_map<int,int> mp;
        // take 2 pointers r, l
        int r=0;
        int l=0;
        int n=nums.size();

        while ( r<n ){
            mp[nums[r]]++;

            while ( mp[0]>k){
                // shrink until window --- mein the count of Zeroes reduces to <=2
                mp[nums[l]]--;
                l++;
            }

            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;

    }
};