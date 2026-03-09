// functions 
//a piece of code that can be used as per our need
//they are used to increase the readability 
//we can reduce code redundancy by using functions
// code efficiency increases

//parameterized 
// non parameterized - no params


#include <iostream>
using namespace std;

void printname( string name){
    cout << "hey "<< name<<endl;
}

int sum( int n1, int n2){
    return n1 + n2;
}

int maxx( int n1, int n2) {
    if (n1 >=n2 ) return n1;
    else if (n1 ==n2)  return n2;
    else return n2;

}

//if we use &- address
void pass_via_val(string &n) {
    n[0] = 't';

    cout << n << endl;
    
}

int main() {
    string mera_naam;
    mera_naam = "kanha";
    printname(mera_naam);

    cout << sum (3,4) <<endl;

    int n1, n2,n3;
    cin >> n1 >> n2;
    n3 = n1+n2;

    cout << n3;
    
    int maxy = maxx(4,55);
    cout << maxy;


    string s = "harshit";
    pass_via_val(s);
    cout << s << endl;
    return 0;
    return 0;
}

