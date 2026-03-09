#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str) {
   //using iterations
   int size=str.size();

   bool flag = false;
   for ( int i=0; i< size/2; i++){
    if ( str[i] == str[size-i-1]){
        flag = true;
    }
    else{
        flag =false;
    }
   }

   return flag;

}

//using recursion 
bool recursionPlaindrome(string& str,int i){
    if (i>= str.size()/2 ) return true;

    if ( str[i] == str[str.size()-i-1]){
         return recursionPlaindrome(str,i+1 );
    }
    else {
        return false;
    }
}

int main() {
    
    string str;
    cout << "enter a string: ";
    cin >> str ;
    // cout << str.size();
    cout << "is str a palindrome? "<< recursionPlaindrome(str, 0);

    return 0;
}