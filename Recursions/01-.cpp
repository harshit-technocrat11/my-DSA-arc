#include <bits/stdc++.h>
using namespace std;

void printName(int times){

    if ( times == 0){
        return;
    }

    cout << "hey there \n";

    printName(times-1);
}

void BaseConditionPrint(int times, int &count){

    if ( count == times){
        return;
    }

    //body
    cout << "i am using base condition "<< endl;
    count++;

    BaseConditionPrint(times, count);
}

void printOneToN(int &i, int n){

    if ( i>n) return ;

    cout << i << endl;
    i++;

    printOneToN(i , n);

}

//from N to 1

void printNtoOne( int n){
    if (n==0) return;

    cout << n <<endl;
    n--;
    printNtoOne(n);
}


// sum of n numbers


int main() {
    printName(4);

    int count = 0;

    BaseConditionPrint(5, count);

    int i=1;

    int n = 6;
    printOneToN(i, n);

    cout << endl;
    printNtoOne(n);

    return 0;
}