#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << 'z'-'a'<<endl; 
    cout << 'a'-'a'<<endl;
    cout << 'b'-'a'<<endl;
    cout << 'c'-'a'<<endl;
    cout << 'd'-'a'<<endl;

    cout << "start ---------"<<endl;

    
    int n;
    cout << "enter value of n:";
    cin >> n;

    char arr[n]; //aabcdefa
    cout << "enter elements of array :"<<endl;
    for ( int i =0; i< n; i++){
        cin >> arr[i];
    }

    // precompute
    // int hash[13] = {0};

    // for ( int i =0; i < n; i++){
        
    //     int index = arr[i]-'a'; //formula

    //     hash[index]+=1;
    // }

    // cout << "no. of keys to be searched : ";
    // // keys to be searched
    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     char c;
    //     cin >> c;

    //     // fetch
    //     cout << "freq of " << c << " is : " << hash[c-'a'] << endl;
    // }

    int hash[256] = {0};

    for (int i = 0; i < n; i++)
    {

        // if a=97 
        // then hash ++
        hash[arr[i]] ++;
    }

    cout << "no. of keys to be searched : ";
    // keys to be searched
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;

        // fetch
        cout << "freq of " << c << " is : " << hash[c] << endl;
    }

    return 0;
}