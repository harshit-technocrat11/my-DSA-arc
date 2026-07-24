class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Brute force, 
        // sort, pop last 2 elements, and push back 
        
        // loop until ,we have atleast 2 elements left
        while(stones.size() >1){

            sort(stones.begin(), stones.end());

            int x= stones.back() ; stones.pop_back();

            int y= stones.back() ;stones.pop_back();

            stones.push_back(abs(x-y));
        }

        return stones[0]; //last remaining element to be returned
    }
};