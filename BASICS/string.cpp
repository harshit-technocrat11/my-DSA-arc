#include <iostream>
using namespace std;

int main() {
    string s = "harshit";
    int len = s.size();
    s[len-1] = 'z';
    cout << s[len-1]<< endl;
    cout << s ;

    //last value is modified
    // 🟢 Yes, std::string in C++ is mutable.That means once you've crechange its contents — individual characters, ated a string, you can append new characters, delete, etc.

    
    return 0;
}