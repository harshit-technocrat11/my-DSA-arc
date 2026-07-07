class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum  = 0, rsum =0;

        // initialize the sum 
        for (int i = 0; i<k;i++)   lsum+=cardPoints[i];   

        int maxSum = lsum ;

        int r = cardPoints.size()-1; //rightIndex

        for ( int i = k-1 ; i>=0; i--){
            // shrink left window
            lsum = lsum -  cardPoints[i];
            // increment right side
            rsum = rsum + cardPoints[r];

            r = r-1;

            // max sum 
            maxSum = max(maxSum , lsum + rsum );
        }

        return maxSum;

    }
};