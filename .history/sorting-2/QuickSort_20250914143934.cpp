#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end)
{
    // take pivot as the starting or the last elem
    int pivot = arr[start];

    int count = 0;

    // count - no of elems < pivot
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    // find correct pos of pivot
    int pivotIndex = start + count;

    // place pivot as correct position
    swap(pivot, arr[pivotIndex]);

    // handle the left and right part
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {

            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }

    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // algos

    int pivotIndex = partition(arr, start, end);

    // left part sort
    quickSort(arr, start, pivotIndex - 1);

    // right part sort
    quickSort(arr, pivotIndex + 1, end);
}

void printArray(int arr[],int size )
{
    for (int i=0; i < size;i ++ )
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {23,45,2,1,9,0,-1,12};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    int end = size - 1;
    
    cout << "before sorting : ";
    printArray(arr, size);
    
    quickSort(arr, 0, end);
    
    cout << "after sorting :";

    printArray(arr, size);

    return 0;
}