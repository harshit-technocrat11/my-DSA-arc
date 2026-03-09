#include <bits/stdc++.h>
using namespace std;

// pass by reference using - pointers 
void increaseNUM (int* num){
    *num=99;
    *num +=1;
}

// pass by reference using  - ALIAS -- &
// void increaseNUM(int &num){
//     num = 99;
//     num += 1;
// }

void passByValue ( int num){
    num = 99;
}

int main() {

    // pass by reference 
    int n = 9;
    increaseNUM(&n);
    cout << n;

    // using alias
    // increaseNUM(n)

    // alias
    int b =0;
    int &ref = b;

    ref = 99;
    cout << "b = "<< b << endl;
    cout << "ref = "<< ref<< endl;

    return 0;
}