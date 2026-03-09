#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cout << "enter length of array: ";
    cin >> n;   //length of input array
    
    cout << "enter the elements of array : ";
    int arr[n];
    for ( int i =0; i<n; i++){
        cin >> arr[i];
    }



    // precompute
    int hash[10000] = {0};  //all initialized to 0

    //storing frequency
    for ( int i=0; i<n; i++){
        hash[arr[i]]+=1;
    }

    cout << "no. of keys to be searched : ";
    // keys to be searched
    int q;
    cin >> q;
    while (q-- ){
        int num; 
        cin >> num;
        
        //fetch 
        cout <<"freq of "<<num << " is : "<< hash[num] << endl;
    }

    return 0;
}