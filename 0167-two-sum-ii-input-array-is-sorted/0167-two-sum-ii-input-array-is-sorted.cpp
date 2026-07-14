class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int l=0;
        int h=numbers.size()-1;
        

        while ( l<h){
            int sum = numbers[l]+numbers[h];

            if (target==sum ){
                return {l+1,h+1};
            }
            else if (sum > target){
                h--;
            }
            else{
                l++;
            }

        }

        return {l+1, h+1};
    }
};