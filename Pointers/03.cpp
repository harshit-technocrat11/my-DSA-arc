#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // pointers using array

    int arr[] = {1,2,3,4,5,6,7,8,9};
    cout << arr<< endl; 

    // array is pointer in cpp storing the value of 0th elem
// constant pointer

    int *p = arr; //stores 1
    cout << *p << endl;
    cout << *(p+1) << endl;
    cout << *(p+2) << endl;
    // cout << *(p+3) << endl;
    cout << p << endl;
    cout << (p+1) << endl;
    cout << (p+2) << endl;
    
    cout << (p+3) << endl;
    cout << (p+4) << endl;
    cout << *(p+5) << endl;


    // for ( int *ptr=arr; )

    int a =0, b=10;
    int *ptr = &a; //initialize
    
    cout << ptr<< endl;
    ptr = &b;
    cout << ptr<< endl;

    cout << "address of "<< 0 << ": "<< arr+0 << endl;
    cout << "address of whole array  = " << &arr<< endl;
    cout << "address of "<< 1 << ": "<< arr+1 << endl;
    
    cout << arr << endl;
    cout << &arr << endl;
    cout << *arr << endl;

    //alias of arrays
    
    int list[] = {1,2,3,4,5};

    int (&ref)[5] = list;
    for ( int x : ref){
        cout << x <<  " ";

    }
    

    return 0;
}