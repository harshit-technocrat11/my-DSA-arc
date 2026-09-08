class Solution {
public:
    int countCommas(int n) {
        int count=0;
        if ( n<1000) return 0;
        else {
            // in range of 1000 to 100000 , 1 comma
            for (int i=1000; i <=n; i++){
                count++;
            }
        }
        return count;
    }
};