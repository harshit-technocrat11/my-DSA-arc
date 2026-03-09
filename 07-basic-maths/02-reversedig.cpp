#include <bits/stdc++.h>
using namespace std;
int reverse(int n)
{
    int c = 0;
    int lastdig;
    int revno = 0;

    while (n > 0)
    {

        lastdig = n % 10;
        revno=lastdig + revno*10;
        n = n / 10;
    }
   
return revno;
}

int main() {
    
    int n = 9876;

    cout <<"rev no = "<<reverse(n);

    return 0;
}