class Solution {
public:

    // using Swaping approach - winner and contender logic

    void ans(int i, vector<int> &nums,  vector<vector<int>> &answer){       
        // base cases
        if(i==nums.size()){
            answer.push_back(nums);
            return;
        }
        for ( int j=i ; j < nums.size() ; j++){
            swap(nums[i] , nums[j]);
            ans ( i+1, nums, answer );
            swap(nums[i] , nums[j]); //restore
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;

        ans(0, nums , answer);
        return answer; 
    }
};