#include <bits/stdc++.h>
using namespace std;

// binary search

// 👉 Binary search only works on sorted arrays/lists.
// It keeps dividing the array into halves until the element is found (or not found).

int binSearch(int arr[], int size, int key)
{

    int start = 0;
    int end = size - 1;
    int mid = start + (end-start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        else if (arr[mid] > key)
        {
            // search - LHS
            end = mid - 1;
        }

        else
        { // search RHS
            start = mid + 1;
        }
         mid = start + (end - start) / 2;
        
    }
    return -1;
}

int main()
{
    // already sorted array or vector
    int even[6] = {2, 4, 6, 8, 12, 18};

    int odd[5] = {3, 8, 11, 14, 16};
    cout << "checking if " << 18 << " exists in even = " << binSearch(even, 6, 18) << endl;

    cout << "checking if " << 14 << " exists in odd = " << binSearch(odd, 5, 14) << endl;

    return 0;
}