class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        // edge case -- 
        if (  (long long )m*k > bloomDay.size() ) return -1; //if insufficient flowers 

        int minD= *min_element(bloomDay.begin(), bloomDay.end());
        int maxD = *max_element(bloomDay.begin(), bloomDay.end());
 
        while ( minD<=maxD){

            int mid= minD+(maxD-minD)/2;

            // ----function calculateBouquets(mid)---
            int count=0;
            int bouquets =0;
            for ( int day: bloomDay){
                if (day<=mid){
                    count++; //if flower bloomed
                    if ( count==k){ 
                        bouquets++;
                        count=0; //reset 
                    }
                }
               else{
                    count=0; // if no consecutive flowers
               }
            }

            if ( bouquets>=m){
                // decrease days
                maxD=mid-1;
            }
            else {
                minD=mid+1;
            }
           
        }

        return minD;
    }
};