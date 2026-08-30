class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int l=0; 
        int h=letters.size()-1;
        // UBound

        if (target>=letters[h]){
            return letters[0];
        }

        while (l<h){
            int mid = (h-l)/2 + l;

            if ( letters[mid]>target){
                h=mid;
            }
            else {
                l=mid+1;
            }
        }


        return letters[l];
    }
};