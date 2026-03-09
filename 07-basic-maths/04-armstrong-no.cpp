#include <bits/stdc++.h>
using namespace std;

// - 
// int countDig(int n)
// {

//     int count = 0;
//     int lastdig;

//     while (n > 0)
//     {

//         // lst dig
//         lastdig = n % 10;

//         count++;
//         n = n / 10;
//     }
//     return count;
// }

bool angstrom(int n)
{
    int sum = 0;
    int num = n;
    // int power = countDig(n);

    int power = to_string(n).length();
    cout <<"power "<< power << endl;

    while (n > 0)
    {

        int lastdig = n % 10;
        
        cout << "lastdig = "<< lastdig << endl;      
        sum = sum + round(pow(lastdig, power)); 
        cout << "sum = "<< sum<< endl;      

        n = n / 10;
    }
    cout << sum << endl;

    return num == sum;
}

int main()
{

    int n = 9474; // 9474

    cout << n << " is an angstrom number ? " << angstrom(n);
    return 0;
}