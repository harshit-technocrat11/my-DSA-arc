class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // optimal solution - modified Voting algo
        // take 2 candidates
        int cand1 = INT_MIN, cand2 =INT_MIN;
        // counter
        int cnt1=0, cnt2=0;
        
        for ( int i =0; i < nums.size(); i++){

            if ( cnt1==0 && cand2!=nums[i] ){
                cnt1=1 ;
                cand1 = nums[i];
            }
            else if (cnt2==0 && cand1!=nums[i]){

                cnt2=1;
                cand2 = nums[i];
            }
            else if ( cand1==nums[i]) cnt1++;
            else if ( cand2 == nums[i]) cnt2++;

            else {
                cnt1--, cnt2--;
            }
        }

        // last check 
        cnt1=0;
        cnt2=0;
        for ( int i = 0; i < nums.size(); i++){
            if ( nums[i]==cand1) cnt1++;
            if ( nums[i]==cand2) cnt2++;
        }
        vector<int> ans;
        if ( cnt1> int(nums.size()/3) ){
            ans.push_back(cand1);
        }

        if (  cnt2 > int(nums.size()/3)){
            ans.push_back(cand2);
        }

        return ans;
    }
};