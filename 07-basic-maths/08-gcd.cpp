#include <bits/stdc++.h>
using namespace std;

int gcd(int n1, int n2){

    int hcf=1; //

    // the gcd- will never be greater than the smallest of 2 numbers
    // like 20 and 40 - >> 20 is the gcd
    int min_n = min(n1,n2);

    //Reverse approach 
    for (int i = min_n; i >=1 ; i--)
    {

        if ( n1%i ==0 && n2%i==0){
            hcf = i;
            cout << i << endl;
            break;
        }
    }

    //forward approach- ( less eficient than above)
    
    // for (int i = 1; i <=min_n; i++)
    // {

    //     if (n1 % i == 0 && n2 % i == 0)
    //     {
    //         hcf = i;
    //         cout << i << endl;
            
    //     }
    // }

    return hcf;
}

int main() {
    
    cout << "the hcf is " << gcd(12,16);
    return 0;
}