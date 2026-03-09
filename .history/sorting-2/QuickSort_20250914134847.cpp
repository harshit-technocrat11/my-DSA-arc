#include <bits/stdc++.h>
using namespace std;

int partition( int arr,int start , int end ){


    return 
}



void quickSort(int arr[], int start , int end ){

    //base case 
    if ( start>=end) return;

    // algos

    int pivot = partition(arr, start, end);

    // left part sort
    quickSort(arr, start , pivot-1);

    // right part sort
    quickSort(arr, pivot + 1, end)
}

void printArray(vector<int> &arr)
{
    for (int  x: arr){
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    
    return 0;
}