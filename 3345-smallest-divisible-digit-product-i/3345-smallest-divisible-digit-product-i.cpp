class Solution {
public:
    int digProduct(int n){
        int prod=1;
        while ( n){
            prod*=n%10;
            
            n=n/10;
        }

        return prod;
    }

    int smallestNumber(int n, int t) {

        while (true){
            if (digProduct(n)%t==0){
                return n;
            }
            n++;
        }    

        return n;
    }
};