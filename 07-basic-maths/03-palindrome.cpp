#include <bits/stdc++.h>
using namespace std;

bool palindrome(int n)
{
    int c = 0;
    int num = n; // copy of no
    int lastdig; 
    int revno = 0;

    while (n > 0)
    {

        lastdig = n % 10;
        revno = lastdig + revno * 10;
        n = n / 10;
    }

   return (revno==num) ?  true :  false;


}

int main()
{

    int n = 123321;

    cout <<n << " is a palindrome? " << palindrome(n);

    return 0;
}