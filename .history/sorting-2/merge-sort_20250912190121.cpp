#include <bits/stdc++.h>
using namespace std;


void Merge(vector<int> &arr, int low, int mid, int high)
{
    // temporary - sorted merged halves
    vector<int> temp = {};
    int left = low;

    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }

        // if arr[right] <=  arr[left]
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // once left half is exhausted

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //remaining elems in right

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for ( int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

void MergeSort(vector<int> &arr, int low, int high)
{
    //base case
    if ( low>=high) return;

    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);

    MergeSort(arr, mid + 1, high);

    Merge(arr, low, mid, high);
}


void printArray(vector<int> &arr)
{
    for ( int x: arr){
        cout << x <<  " ";
    }
    cout << endl;
}

int main()
{

    vector<int> array = {3, 4, 1, 19, 17, 14, 78, 10,7,0,-1};
    cout << "before sorting : ";
    printArray(array);

    int high = array.size() -1;

    MergeSort(array, 0,high );
    
    cout << "after sorting :";

    printArray(array);

    return 0;
}