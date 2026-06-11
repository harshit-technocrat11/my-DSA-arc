class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //brute force 
        int n= nums.size();
        // answer array
        vector<int> ans(n,-1);
        
        for ( int i =0; i < n; i++ ){
            for ( int j=i+1; j<(n)+i; j++){
                //index -- circular check
                int indx = j%n;

                if ( nums[indx]>nums[i]){
                    ans[i]= nums[indx];
                    break;
                }

            }
        }

        return ans;
    }
};