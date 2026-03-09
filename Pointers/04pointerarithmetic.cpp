#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 10;
    int *ptr = &a;

    // each inc or dec is ---4 bytes

    cout << ptr<< endl;

    ptr++;
    cout <<  ptr << endl;
    ptr++;
    cout << ptr << endl;
    
    ptr --; 
    
    cout << ptr << endl;

    int arr[]={1,2,3,4,5};
    cout <<arr << endl;
    cout <<arr +1<< endl;

    // addtion and substraction


    int *ptr1 ; 
    int *ptr2 = ptr1 + 2; 

    cout << ptr2-ptr1 << endl;

    ptr1 = &arr[0]; //value changed
    ptr2 = &arr[4 ] ;// last

    cout << "size of the array "<< ptr2 -ptr1 << endl;
    cout <<( ptr1 <= ptr2 )<< endl;



    return 0;
}