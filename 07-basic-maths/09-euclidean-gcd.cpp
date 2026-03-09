#include <bits/stdc++.h>
using namespace std;
//using euclidean theorem

int gcd(int a , int b){

    while ( a>0 && b>0){

        if ( a>b) a = a%b;  //greater%smaller
        else b= b%a;
    }

    //uuntil 0

    if ( a==0){
        return b;
    }
    return a;
}


int main() {
    
    int a=12;
    int b = 42;

    cout << gcd(a,b);
    

    return 0;
}