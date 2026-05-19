class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxPile = *max_element(piles.begin() , piles.end());

        int low=1, high=maxPile;
        int ans= maxPile ;

        while ( low<=high){
            int mid = (high-low)/2+low;

            long long totalhrs = 0;
            for ( int bananas: piles){
                totalhrs += (bananas+mid-1)/mid;
            }

            if ( totalhrs<=h){
                ans=mid;
                high=mid-1;

            }

            else {
                low=mid+1;
            }

        }

        return ans ; 

    }
};