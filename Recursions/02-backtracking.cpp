#include <bits/stdc++.h>
using namespace std;

// using backtracking concept ------

void printNto1(int i, int n)
{

    // base case
    if (i < 1)
        return;

    printNto1(i - 1, n);

    cout << i << endl;
}

// only using single parameter -- backtracking

void printN(int n)
{
    if (n < 1)
        return;

    printN(n - 1);
    cout << n << endl;
}

// sum of first n numebers]

int NnumbersSum(int N)
{
    //base case- when N=0 , sum = 0
    if ( N<1) return 0;

    return N + NnumbersSum(N - 1);

}

int main()
{

    int n = 6;
    printNto1(n, n);

    cout << endl;
    printN(n);

    cout << endl;

    cout << "sum is "<< NnumbersSum(n);
    return 0;
}