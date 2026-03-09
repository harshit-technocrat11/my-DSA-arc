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

    while (right <= mid)
    {
        temp.push_back(arr[left]);
        right++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    arr = temp;
}

void MergeSort(vector<int> &arr, int low, int high)
{

    {


            int mid = (low + high) / 2
            MergeSort(arr, low, mid);

            MergeSort(arr, mid + 1, high);

            Merge(arr, low, mid, high);
        }

        void printArray(vector<int> & arr)
        {
            int size = arr.size();
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{

    vector<int> array = {3, 4, 1, 19, 17, 14, 78, 10};
    cout << "before sorting : ";
    printArray(array);

    MergeSort(array, 0, array.size());

    cout << "after sorting :";

    printArray(array);

    return 0;
}