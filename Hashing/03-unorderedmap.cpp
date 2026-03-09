#include <bits/stdc++.h>
using namespace std;

int main()
{
    // UNORDERED MAP - just like dictionary

    // unordered_map<int, string> UnMap = {
    //     {1, "harshit"},
    //     {2, "harshita"},
    //     {3, "ritika"},
    //     {3, "ritika"},
    //     {4, "adi"},
    // };

    // for (auto i : UnMap)
    // {
    //     cout << "key: " << i.first << " : " << i.second
    //          << endl;
    // }

    int n;
    cout << "enter length of array: ";
    cin >> n; // length of input array

    cout << "enter the elements of array : ";
    // int arr[n];
    char arr[n];  //char set
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // pre storing 

    // unordered_map <int, int> Mpp;
    map <char, int> Mpp;


    for ( int i =0; i< n; i++){
        Mpp[arr[i]]++;
    }

    // iterating thru the map 
    for ( auto i: Mpp){
        cout << i.first<<" : "<< i.second << endl;
    }

    // input
    cout << "no. of keys to be searched : ";
    // keys to be searched
    int q;
    cin >> q;

   while ( q-- ){
    // int key;
    char key;
    cout << "enter key : ";
    cin >> key;

    cout << "freq of "<<key<< " is :"<< Mpp[key] << endl;


   }

    return 0;
}