#include <iostream>
using namespace std;

//take the day no. and print the corresponding day for 1 print Monday
//for 2 print Tuesday and so on for 7 print sunday
int main() {
    int day;
    cout << "enter day no.";
    cin >> day;

    switch (day)
    {
    case 1:
        cout << "monday";
        break;
    case 2:
        cout << "tuesday";
        break;
    case 3:
        cout << "wednesday";
        break;
    case 4:
        cout << "thursday";
        break;
    case 5:
        cout << "friday";
        break;
    case 6:
        cout << "saturday";
        break;
    
    
    default:
    cout << "invalid";

        break;
    }



    return 0;
}