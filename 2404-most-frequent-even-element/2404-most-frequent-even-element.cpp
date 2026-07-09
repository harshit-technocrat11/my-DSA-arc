class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        // think if layers ( -> even -> max Freq -> minValue )
        unordered_map<int, int> mp;
        int maxFreq = 0;
        
        for ( int i = 0 ; i < nums.size();  i++){

            // if even 
            if ( nums[i]%2==0){
                mp[nums[i]]++;
                maxFreq = max(maxFreq, mp[nums[i]]);
            }
        }

        // if Map is empty ( no even found )
        if ( mp.empty()) return -1;

        // find the answer
        int minVal =  INT_MAX;
        for ( auto it: mp){
            if ( it.second == maxFreq){
                minVal = min(minVal, it.first);
            }
        }

        return minVal;
    }
};