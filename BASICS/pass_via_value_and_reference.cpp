#include <iostream>
using namespace std;
//call by value or pass by value
//the copy of the original value was used inside the function

void dosomething (int num){
    cout << num << endl;
    num += 5;
    cout << num << endl;
    num += 5;
    cout << num << endl;
}
int main() {
    int num =10;
    cout << "initial value = " << num << endl;
    dosomething(num);
    cout << "final value = "<< num << endl;
    cout << num << endl;
    

    return 0;
}