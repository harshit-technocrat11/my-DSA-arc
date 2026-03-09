// basics of array

// array is used to store the similar data types

#include <bits/stdc++.h>
using namespace std;

void dosomething(int arr[], int n)
{
    arr[0] += 100;
    cout << "value inside the fn is : = " << arr[0] << endl;
}

int main()
{
    // int arr[5];
    // cout << "enter numbers:";
    // cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

    // arr[3] += 5;
    //     cout << arr[3];
    // return 0;

    int n = 5;
    int arr[n];
    for (int i = 0; i < n; i = i + 1)
    {
        cin >> arr[i];


    }

    dosomething(arr, n);
    cout << "value inside int main " << arr[0] << endl;
    
    return 0;

    //arrays - pass by ref
}

// arrays - always goes via reference ,even if & is not given then also


