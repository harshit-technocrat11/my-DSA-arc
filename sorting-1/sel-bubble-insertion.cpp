#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}

vector<int> selectionSort(vector<int> &nums)
{

    int n = nums.size();

    int temp;
    for (int i = 0; i <= n - 2; i++)
    {
        int min_indx = i;

        for (int j = i; j <= n - 1; j++)
        {

            if (nums[j] < nums[min_indx])
            {
                min_indx = j; // extracted min index
            }

            // swap values with i and min_index
            temp = nums[i]; // store it
            nums[i] = nums[min_indx];

            nums[min_indx] = temp;
        }
    }
    return nums;
}

vector<int> BubbleSort(vector<int> &nums)
{

    int n = nums.size();

    // for ( int i=0; i<=n-1; i++){

    //     for ( int j = 0; j<= n-2-i; j++){
    //         if ( nums[j] > nums[j+1]){
    //             // swap here logic
    //             int  temp = nums[j];
    //             nums[j] = nums[j+1];
    //             nums[j + 1] = temp;
    //         }

    //     }
    // }

    // optimised solution -- to lower the time complexity- for already sorted list /array

    for (int i = n - 1; i > 0; i--)
    {
        int swapped = 0; // false

        for (int j = 0; j <= i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                // swap here logic
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;

                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            // not swapped - even after 1st iteration- means the list is already sorted

            break;
        }
        // cout << "runs" << i<< endl;
    }

    return nums;
}

vector<int> insertionSort(vector<int> &nums)
{

    int n = nums.size();
    for (int i = 0; i <= n - 1; i++)
    {

        int j=i; //current element 

    
        while ( j> 0 && nums[j-1] > nums[j]){
            //swap

            swap(nums[j-1], nums[j]);

            j--; // to move to left element

        }

        // using for loop- 

        // bool swap = false;

        // for ( j=i; j>0; j--){
        //     if (nums[j-1] > nums[j]){
        //         swap(nums[j - 1], nums[j]);

        //         swap = true;
        //     }

        //     if ( swap = false){
        //         break;
        //     }
        // }
    }

    return nums;
}

int main()
{

    vector<int> nums = {1, 78, 6, 3, 5, 7, 2, 89, 13, 100, 112, 34, 77, 23,0};
    // vector<int> nums = {1, 2,5,4,6,7};

    cout << " before swapping : " << endl;
    for (auto i : nums)
    {
        cout << i << " ";
    }

    cout << endl;

    cout << " after swapping : ";

    for (auto i : insertionSort(nums))
    {
        cout << i << " ";
    }

    return 0;
}