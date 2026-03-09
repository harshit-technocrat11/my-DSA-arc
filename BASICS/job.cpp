#include <iostream>
using namespace std;

// if age < 18 not eligible for job
// if age >18 and age <54 the eligible for job
// if age > 55 and age < 57 then eligble for job but retirement soon
// if age > 57 the retirement time
int main() {
    int age; 
    cout << " enter age:";
    cin>> age;
    
    if (age < 18){
        cout << "not eligible for job";
    }
   
    
    else if ( age <=57) {
        cout << "eligible for job";
        if (age>=55){
            cout << " but retirement soon";
        }
    }   
    else{
        cout<< " retirement time";

    }
    return 0;
}