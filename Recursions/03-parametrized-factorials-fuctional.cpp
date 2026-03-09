#include <bits/stdc++.h>
using namespace std;

//factorial --- 

void FactorialIterative(){

}


int FactorialRecursive(int n){

    if (n<1) return 1;

    return n * FactorialRecursive(n - 1);
}

int main() {
    cout << FactorialRecursive(4);

    return 0;
}