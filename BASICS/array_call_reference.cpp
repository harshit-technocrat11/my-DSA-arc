#include <iostream>
using namespace std;


void dosomething(int arr[] , int n){
    arr[0]+=100;
    cout << "value inside function "<< arr[0] << endl;

}
int main() {
    int n=5;
    int arr[n];
    for(int i =0 ; i<n ; i=i+1){
        cin >> arr[i];
    }
    cout << "intitial arr[0] = "<< arr[0]<<endl ;
    dosomething( arr, n);
    cout << "\n value inside int main is :"<< arr[0] << endl;
    return 0;
}