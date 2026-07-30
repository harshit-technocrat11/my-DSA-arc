class Solution {
public:
    // define modulo
    const int Mod = 1e9+7;
    // binary expo
    long long findpower(long long a, long long b){
        if ( b==0) {  
            return 1;
        }

        long long half= findpower(a, b/2);
        long long result =  (half*half)%Mod ;

        // in case of odd 
        if (b%2==1){
            result = ( result*a )%Mod ;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        // count of even indices = n+1/2
        //  of odd = n/2
        //  even --> multiply 5
        // odd multiply --> 4

        return  (long long)findpower(5, (n+1)/2)*findpower(4, n/2) %Mod;

    }
};