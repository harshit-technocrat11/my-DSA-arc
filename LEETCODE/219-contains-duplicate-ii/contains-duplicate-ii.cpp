class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i =0,j=0;
        int n=nums.size();
        unordered_set <int> window;

        while ( j<n ){

            //1. check if condition
            if ( abs(i-j)>k){
                window.erase(nums[i]);
                i++; //shrink
            }

            //2. if element , seen in the past ( already present in the set)
            if ( window.find(nums[j])!=window.end()){
                return true;
            }

            //3. else 
            window.insert(nums[j]);
            j++;
        }
        return false;
    }
};