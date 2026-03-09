#include <bits/stdc++.h>
using namespace std;
//fibonacci sequence-- find the nth term

//  terms - 0, 1 , 1, 2, 3, 5, 8 ... . .

//note f(0)  = 0, f(1) = 1


int fib(int n){
    // your code goes here

    if (n >= 0)
    {

        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
    } // base case

    return fib(n - 1) + fib(n - 2);
}

int main() {
    
    cout << fib(2);

    return 0;
}