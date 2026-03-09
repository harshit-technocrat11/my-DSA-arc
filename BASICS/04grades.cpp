#include <iostream>
using namespace std;

int main() {
    int marks;
    cout << "enter marks:";
    cin>>marks;
    
    if(marks <25){
        cout<<"grade = F";

    }
    else if( marks <45){
        cout<<"grade = E";

    }
    else if( marks <50){
        cout<<"grade = D";

    }
    else if(marks <60){
        cout<<"grade = c";

    }
    else if(marks <80){
        cout<<"grade = B";

    }
    
    else if( marks <100){
        cout<<"grade = A";

    }
   

    
    return 0;
}