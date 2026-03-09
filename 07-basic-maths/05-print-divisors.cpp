#include <bits/stdc++.h>
using namespace std;



void printDivsiors(int n){



    // for ( int i=1; i <=n; i++){
    //     if (n%i ==0){
    //         cout << i << " ";
    //     }
    // }
    // time complexity = O(n)

    // or 

    vector <int> list;

    // int limit =sqrt(n);
    //as we should not use sqrt(n) in upper limit - as it will be called again and again - increasing the time complexity

    //so we need to write it as i*i<=n or use variable

    //O(sqrt(n))- for loop

    for ( int i =1 ; i*i<=n; i++){
        if (n%i ==0){
            // cout << i << " ";
            list.push_back(i);
            if ( (n/i)!=i){

                // cout << n/i << " ";
                list.push_back(n/i);
                
            } 
        }
    }

    

    //sorting the list
    // O(num*log10(num)) -  num -of factors
    sort(list.begin(), list.end());

    for ( auto i:list){
        cout << i << " ";
    }

    // total= O(num*log10(num)) + O(sqrt(n))
}



int main() {
    
    int n = 36;
    cout << "divisors of "<< n << " = ";
    printDivsiors(n);

    return 0;
}