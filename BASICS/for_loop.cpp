#include <iostream>
using namespace std;

int main() {
    
    cout << "harshit" << endl;
    int i;
    for ( i=5 ; i>0; i--){
        cout << "hey there" << i << endl;
        //body is executed first then - i is updated

    }
    cout << i <<endl; // last value is 0
    

    int a=1;
    while ( a<=10){
        cout << "while loop iteration= "<< a<<endl;

        a+=1;
    }

    int b=1;
    do {
        cout << i << "\n";
        i++;
    }
    while (i < 5);

    return 0;
}