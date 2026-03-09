#include <bits/stdc++.h>

using namespace std;

void print7(int n)
{
    for (int i = 0; i < n; i++) // rows
    {

        // space -1
        for (int j = n - i - 1; j > 0; j--)
        {

            cout << "-";
        }

        for (int j = 0; j < 2 * i + 1; j++)
        {

            cout << "*";
        }
        // space -2

        for (int j = n - i - 1; j > 0; j--)
        {

            cout << "-";
        }

        cout << "\n";
    }
}

void print8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            cout << " ";
        }
        for (int j = 0; j < 2 * (n - i - 1) + 1; j++)
        {

            cout << "*";
        }
        for (int j = 0; j < i; j++)
        {

            cout << " ";
        }
        cout << endl;
    }
}

void print9(int n)
{

    for (int i = 0; i < n; i++) // rows
    {

        // space -1
        for (int j = n - i - 1; j > 0; j--)
        {

            cout << "-";
        }

        for (int j = 0; j < 2 * i + 1; j++)
        {

            cout << "*";
        }
        // space -2

        for (int j = n - i - 1; j > 0; j--)
        {

            cout << "-";
        }

        cout << "\n";
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            cout << " ";
        }
        for (int j = 0; j < 2 * (n - i - 1) + 1; j++)
        {

            cout << "*";
        }
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

        if (i > n)
            stars = 2 * n - i;

        // stars = no. of stars in a row

        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void print11(int n)
{

    for (int i = 0; i < n; i++)
    {
        int start;

        // start = 1 intitially
        (i % 2 == 0) ? start = 1 : start = 0;

        for (int j = 0; j <= i; j++)
        {

            // //even

            // if ( start %2 == 0){
            //     cout << "0";
            // }
            // // odd
            // else{
            //     cout << "1";
            // }

            // start++;

            // or fliping concept

            cout << start;
            // flip
            start = 1 - start;
        }
        cout << endl;
    }
}

void print12(int n)
{

    for (int i = 1; i <= n; i++)
    {

        // num
        for (int j = 1; j <= i; j++)
        {

            cout << j;

            // space
        }
        for (int j = 1; j <= 2 * (n - i + 1) - 2; j++)
        {
            cout << " ";
        }

        // num
        for (int j = i; j > 0; j--)

        {
            cout << j;
        }
        cout << endl;
    }
}

void print13(int n)
{

    int c = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {

            c++;

            cout << c << " ";
        }
        cout << endl;
    }
}

void print14(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            cout << char(j + 65);
        }
        cout << endl;
    }
}

void print15(int n)
{

    for (int i = n; i > 0; i--)
    {
        // for (int j = 0; j < i; j++)
        // {

        //     cout << char(j + 65);
        // }

        for (char j = 'a'; j < 'a' + i; j++)
        {

            cout << j << " ";
        }

        cout << endl;
    }
}

void print16(int n)
{
    for (int i = 0; i < n; i++)
    {

        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void print17(int n)
{

    for (int i = 0; i <n; i++)
    {
       
        //space
        for ( int j=0; j<n-i; j++){
            cout <<  " ";

        }

        char ch='A';
        int breakpoint = (2*i+1)/2;
        
        for ( int j = 1; j<=2*i+1; j++ ){

            if ( j<=breakpoint){
                cout << ch;
                ch++;
            }
            else{
                cout << ch;
                ch--;
            }
        }
        
        //space
        for ( int j=0; j<n-i; j++){
            cout <<  " ";

        }
        cout << endl;
    }
}


void print18(int n){


    for ( int i =0; i<n; i++){
        for ( char ch = 'E'-i; ch<= 'E'; ch++ ){
            cout << ch;
        }
        cout << endl;
    }
}


void print19(int n){
    
}

int main()
{

    int n;
    cout << "enter  value of n: ";
    cin >> n;

    print18(n);

    return 0;
}
