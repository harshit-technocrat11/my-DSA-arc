class Solution {
public:
    int isPossibleToPlace(vector<int>& position,int Force ,int m){
        int prev = position[0];
        int countBall=1; // counter for no. of balls

        for ( int i =1; i<position.size(); i++){
            int curr = position[i]; //current position to consider

            if ( curr-prev >= Force){
                countBall++;
                prev = curr; // update the prev pointer position  to current
            }
            //this For loop either breaks by Below condition or when it gets exhausted
            // break condition
            if (countBall==m){
                break;
            }
        }
        return countBall==m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int n=position.size();
        int minF= 1;
        int maxF = position[n-1] - position[0]; //brute

 
        int result =0;

        while (minF <= maxF){
            int mid = minF + (maxF-minF)/2;

            // func calculateMinForce ( mid ) --> isPossibleToPlace()

            if ( isPossibleToPlace(position, mid , m) ){
                result = mid;
                // then try to increase minF  - and try out if its Possible to achieve
                minF =  mid+1;
            }
            else {
                maxF = mid-1;
            }

        }

        return result ;
    }
};