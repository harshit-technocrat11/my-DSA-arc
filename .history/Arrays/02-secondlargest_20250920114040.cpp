#include <bits/stdc++.h>
using namespace std;


    void bubbleSort(vector<int> &nums)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            bool swapped = true;
            for (int j = 0; i < nums.size() - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                    swapped = false;
                }
            }

            if (!swapped) break;
        }
        // return - the largest elem
       
    }

    int secondLargestElement(vector<int> &nums)
    {
        for ( int i=0; i< nums.size(); i++){
            cout<< nums[i] << endl;
        }
        // your code goes here
        bubble
        // reverse loop
        for (int i = nums.size() - 2; i >= 1; i--)
        {
            if (nums[i] == nums[i - 1])
            {
                high--;
            }
        }

        if (low == high)
            return -1; // if not found

        // second largest
        return nums[high];

    }

    int main(){
        vector<int> nums = {8, 8, 7, 6, 5 };

        cout << "second largest elem: "<< secondLargestElement(nums);
        return 0;


    }
