#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "apple";

    for (auto it : str)
    {
        cout << it << endl;
    }
    str = "programming";
    cout << str<<endl;

    // for (int i = 0; i < str.size(); i++)
    // {
    //     if (str[i] == 'g')
    //     {
    //         cout << "g  found at index : " << i << endl;
    //     }
    // }

    int start = 0; 
    int end = str.size()-1;
    char temp;
    while ( start<end){
        swap(str[start], str[end]);
        start ++;
        end--;

    }
    cout << str ;

    unordered_map<char, int> map;
    for ( int i =0; i < str.size(); i++){
        map[str[i]]++;
    }
   
    int hash[26]={0};
    for ( int i =0; i < str.size() ; i++){
        hash[ str[i]-'a']++;

    }

    int maxi =  INT_MIN;

    for ( auto it: hash){
        if ( maxi<=it){
            maxi = it;
            
        }
    }
    cout << "max freq is : "<< maxi;
    

    return 0;
}