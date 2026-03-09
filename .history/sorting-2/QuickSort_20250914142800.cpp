#include <bits/stdc++.h>
using namespace std;

int partition( int arr[],int start , int end ){
    //take pivot as the starting or the last elem
    int pivot = arr[start];

    int count = 0;

    //count - no of elems < pivot 
    for ( int i=start+1 ; i <= end; i++ ){
        if ( arr[i] <=pivot){
            count ++;
        }
    }
    
    // find correct pos of pivot
    int pivotIndex = start + count;

    // place pivot as correct position
    swap(pivot, arr[pivotIndex]);

    // handle the left and right part
    int i = start , j = end;

    while ( i < pivotIndex  && j > pivotIndex){

        while ( arr[i] < pivot){
            i++;

        }
        while ( arr[j ]> pivot)


    }



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
    quickSort(arr, pivot + 1, end);

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