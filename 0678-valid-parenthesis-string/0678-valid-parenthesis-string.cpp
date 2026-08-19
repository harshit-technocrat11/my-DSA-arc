class Solution {
public:
    bool checkValidString(string s) {
        
        int leftMin=0;
        int leftMax =0;

        for ( char c : s){
            if ( c == '('){
                leftMin++;
                leftMax++;
            }

            else if ( c==')'){
                leftMin--;
                leftMax--;
            }

            else {
                //  for *
                leftMin--;
                leftMax++;
            }

            if (leftMax<0){
                return false;
            }

            if (leftMin<0){
                leftMin=0; //reset to 0
            }
        }

        return leftMin==0; //true if , leftmin is 0
    }
};