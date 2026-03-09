#include <bits/stdc++.h>
using namespace std;

void checkprime(int n){

    int c =0;

   
    for ( int i =1; i*i<=n; i++){
        if( n%i==0){
            c++;
            
            if ( (n/i)!=i){
                c++;
            }
        }

        
    }
    if(c==2){
        cout << "yes its prime";
    }
    else{cout << "its not prime";
    }
}


int main() {
    
    int n = 11;
    checkprime(n);
    

    return 0;
}