class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum  = INT_MAX;
        bool f = false;
        
        vector<int> prefix(n+1, 0);
        for ( int i=1; i<n+1; i++ ){
            prefix[i]= prefix[i-1] + nums[i-1];
        }

        for ( int k=l; k<=r; k++){ // all possible sizes 
            for ( int i = 0; i+k <= n ; i++){

                int sum = prefix[k+i] - prefix[i];

                if ( sum> 0){
                    minSum= min(minSum, sum);
                    f= true;
                }
            }
        }

        return f? minSum : -1;
    }
};