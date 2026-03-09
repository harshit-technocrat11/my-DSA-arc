#include <iostream>
using namespace std;


// basic grid pattern
void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*  ";
        }
        cout << endl;
    }
}
void print2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void print3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void print5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void print7(int n)
{
    for (int i = 0; i < n; i++)

    {

        // SPACE
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // STAR
        for (int j = 0; j < 2 * (i) + 1; j++)
        {
            cout << "*";
        }
        // SPACE
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print8(int n)
{
    for (int i = 0; i < n; i++)

    {

        // SPACE
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // STAR
        for (int j = 0; j < 2 * (n - i) - 1; j++)
        {
            cout << "*";
        }
        // SPACE
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print9(int n)
{
    for (int i = 0; i < n; i++)

    {

        // SPACE
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // STAR
        for (int j = 0; j < 2 * (i) + 1; j++)
        {
            cout << "*";
        }
        // SPACE
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)

    {

        // SPACE
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // STAR
        for (int j = 0; j < 2 * (n - i) - 1; j++)
        {
            cout << "*";
        }
        // SPACE
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;

        if (stars > n) // this is the case for lower triangle part
        {
            for (int j = 1; j <= 2 * n - i; j++)
            {
                cout << "*";
            }
        }
        else // this is normal case for upper triangle
        {
            for (int j = 1; j <= stars; j++)
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}
void print11(int n)
{
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         if ( (i+j)%2==0){
    //             cout << "1";
    //         }
    //         else{
    //             cout <<"0";
    //         }

    //     }
    //     cout << endl;
    // }

    // using the flip logic
    for (int i = 0; i < n; i++)
    {
        int start = 1;
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start; // flip logic
        }
        cout << endl;
    }
}
void print12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}
void print13(int n)
{
    int c = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {

            cout << c << " ";
            c++;
        }
        cout << endl;
    }
}
void print14(int n)
{
    // int c=65;
    for (int i = 0; i < n; i++)
    {
        for (char j = 'A'; j <= 'A' + i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void print15(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char j = 'A'; j <= 'A' + (n - i - 1); j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void print16(int n)
{
    for (int i = 0; i < n; i++)
    {
        char c = 'A' + i;
        for (char j = 0; j <= i; j++)
        {
            cout << c;
        }
        c++;
        cout << endl;
    }
}
void print17(int n)
{
    for (int i = 0; i < n; i++)

    {

        // SPACE
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // LETTERS
        char c = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * (i) + 1; j++)
        {

            cout << c;
            if (j <= breakpoint)
                c++;
            else
                c--;
        }
        // SPACE
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print18(int n)
{
    for (int i = 0; i < n; i++)
    {
        char c = 'A' + n - 1;
        for (char j = c - i; j <= c; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void print19(int n)
{
    for (int i = 0; i < 2*n; i++)
    {
        if (i<n)
        {
            // STARS
            for (int j = 0; j <n - i; j++)
            {
                cout << "*";
            }
            // SPACE
            for (int j = 0; j < 2*i; j++)
            {
                cout << " ";
            }
            // STARS
            for (int j = 0; j < n - i; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
        else{
            //STARS
            for ( int j=0; j<=n-i+1; j++){
                cout<< "*";
            }
            //SPACE
            for ( int j=0; j<=2*n - i -1; j++){
                cout<< " ";

            }
            // STARS
            for (int j = 0; j <= n-i+1; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
}
int main() 
{
    int t; // t is the test case
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        print19(n);
    }

    return 0;
    }