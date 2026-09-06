class Solution {
    
    bool check (vector<int> &nums, int k , long long threshold){
        long long sum = 0;
        int cnt = 1 ; //assigned to first child 

        for ( int i = 0 ; i < nums.size() ; i++){

            if ( sum +  nums[i] > threshold ) {
                // move to next child
                cnt++;
                sum = 0; //reset
            }

            sum+= nums[i];
        }

        return cnt<=k; 
    }
    
public:
    int splitArray(vector<int>& nums, int k) {
        
        long long  l = *max_element(nums.begin(), nums.end());
        long long h = 0;
        for ( auto n : nums) h+= n;

        long long ans = -1;  

        while ( l<=h){
            long long mid =  (h-l)/2 + l;

            // for a threshold value - , check if , the array can be split into , exactly k or not
            if (check(nums, k , mid)){
                ans =  (int) mid;
                h = mid - 1;
            }
            else {
                l = mid+1;
            }
        } 

        return ans;
    }
};