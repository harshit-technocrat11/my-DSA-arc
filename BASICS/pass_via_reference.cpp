#include <iostream>
using namespace std;

// THIS IS CALL BY REFERENCE AS WE PROVIDE THE ADDRESS  &<_variable_>
string dosomething ( string &s){
    s[0]='x';
    cout << s << endl;
    s[s.size()-1]='y';
    cout << s << endl;
    return s;

}

int main() {
    string s= "harshit";
    cout<< "original string = "<< s<< endl;

    cout << "final string = " << dosomething(s) << endl;

    return 0;
}