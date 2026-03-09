#include <bits/stdc++.h>
using namespace std;


    int bubbleSort(vector<int> &nums)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; i < nums.size() - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        // return - the largest elem
        return nums.size() - 1;
    }

    int secondLargestElement(vector<int> &nums)
    {
        // your code goes here
        int largestInd = bubbleSort(nums);
        for ( int i=0; i< nums.size(); i++){
            cout<< nums[i] << endl;
        }

        int low = 0;
        int high = nums.size() - 1;
        // reverse loop
        for (int i = nums.size() - 1; i >= 1; i--)
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
