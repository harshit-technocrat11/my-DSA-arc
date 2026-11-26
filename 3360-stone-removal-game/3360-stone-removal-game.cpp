class Solution {
public:
    bool canAliceWin(int n) {
        if ( n<10 ) return false;
        int alice=false;
        for ( int r= 10 ; r>=0; r=r-2){
            if (n-r >=0){
                alice =true;
                n=n-r;
            }
            else return false;

            if (n-(r-1)>=0){
                n =  n-(r-1);
            }
            else{
                return true;
            }
        }

        return alice;
    }
};