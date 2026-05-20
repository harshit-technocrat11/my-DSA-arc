class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minCap= *max_element(weights.begin(), weights.end());
        int maxCap=0;
        for ( int w: weights){
            maxCap+=w;
        }

        while ( minCap<maxCap){
            int mid=minCap+ (maxCap-minCap)/2;
            int capacity=mid;

            int d=1;//days
            int sum =0; //weight counter
            
            // loop for number of days -----------
            for (int w: weights){
                if ( sum+ w > capacity ){
                    d++; //move to next day
                    sum=0; //reset the sum
                }
                //keep addings weights until the condition hits
                sum+=w;
            }

            if( d>days){
                //increase capacity
                minCap=mid+1;
            }
            else {
                //decrease capacity
                maxCap=mid;
            }

        }

        return minCap;
    }
};