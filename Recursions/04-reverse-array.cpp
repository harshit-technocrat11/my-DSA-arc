#include <bits/stdc++.h>
using namespace std;


void printArray(int arr[], int n){
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void reverseArray(int arr[], int n)
{

    // int mid =n/2 -1;
    
    // or better use 
    

    for (int i = 0; i < n/2; i++)
    {
        std::swap(arr[i],arr[n-1-i]);
    }
    printArray(arr, n);

}

// void recursivefunc(int arr [], int left, int right){

//     if ( left>=right) return;

//     swap(arr[left], arr[right]);

//     recursivefunc(arr,left+1, right-1);


// }

void recursion2(int arr[],int  i,int  n){
    if ( i >= n/2) return;

    swap(arr[i],arr[n-i-1]);

    recursion2(arr, i+1, n-1);
}

int main()
{

    int arr[] = {1, 2, 3, 4,5,6};
    // reverseArray(arr, 6);

    //using recursion
    // recursivefunc(arr, 0, 5);

    recursion2(arr, 0, 6);
    printArray(arr, 6);

    return 0;
}