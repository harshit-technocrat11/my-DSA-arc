#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int a  = 10;
    // cout << &a << endl;

    // pointer

    int *ptr = &a;
    cout <<"value stored in ptr:"<< ptr << endl;
    cout <<"value of ptr: "<< *ptr<< endl;
    cout << "address of a: "<< &a<< endl;


    // pointer to pointer

    int ** ptr2 = &ptr;
    cout << "address of ptr " << &ptr << endl;
    cout << "value of ptr " << ptr << endl;

    cout << "address of ptr2 " << &ptr2 << endl;
    cout << "value of ptr2 " << ptr2 << endl;

    cout << **ptr2 << endl;
    cout << *ptr2<<endl;
    cout <<  ptr<< endl;
    cout << *ptr << endl;

    int **parPtr = &ptr;  // 2 level
    int ***grandPtr = &parPtr ; //3 level

    // derefernce op 

    int b=90; 
    int *p = &b;

    cout << *(&b)<< endl;
    cout << *p << endl;

    // NULL pointer

    //  doesnt point to any location

    // int *ptr = NULL;

    int *p;
    cout << p << endl;
    int *ptr = nullptr;

    cout << ptr << endl;
    return 0;
}
