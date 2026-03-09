#include <bits/stdc++.h>
using namespace std;

int countDigit(int n)
{
    int c = 0;
    int lastdig;
    int display = n;

    while (n > 0)
    {

        lastdig = n % 10;

        n = n / 10;
        c++;
    }
    cout << "total no. of digits in " << display << "= " << c;
}

int main() {

    int n = 96578;

    
    countDigit(n);

    //using maths

    int cnt = (int) ( log10(n) + 1);
    cout << endl<< "using maths = " << cnt;
    return 0;
}