class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf=0;
        int minPrice = 10e5; //store infinity

        for ( int  i =0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxProf = max(prices[i]-minPrice, maxProf);
        }

        return maxProf;
    }
};