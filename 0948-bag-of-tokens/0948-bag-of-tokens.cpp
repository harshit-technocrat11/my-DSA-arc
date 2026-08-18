class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // sort 
        sort ( tokens.begin() , tokens.end());

        int sc=0;
        int start = 0, end=tokens.size()-1;
        int maxScore=0;

        while (start<=end){
            
            // play face up 
            if ( power>= tokens[start]){
                sc++; 
                power =  power - tokens[start];
                start++;
                maxScore = max(maxScore, sc); //maintain a max score always;
            }

            // play a face down
            else if (sc>=1){
                sc--;
                power = power+ tokens[end];

                end--;
            }
            
            // if no moves can be made
            // power< tokens[i] && sc==0

            else {
                break;
            } 

        }

        return maxScore;
    }
};