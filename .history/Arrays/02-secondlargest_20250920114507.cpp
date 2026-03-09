#include <bits/stdc++.h>
using namespace std;


    // void bubbleSort(vector<int> &nums)
    // {

    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         bool swapped = true;
    //         for (int j = 0; i < nums.size() - 1; j++)
    //         {
    //             if (nums[j] > nums[j + 1])
    //             {
    //                 swap(nums[j], nums[j + 1]);
    //                 swapped = false;
    //             }
    //         }

    //         if (!swapped) break;
    //     }
    //     // return - the largest elem
       
    // }

    int secondLargestElement(vector<int> &nums)
    {
        for ( int i=0; i< nums.size(); i++){
            cout<< nums[i] << " ";
        }
        int n = nums.size();

        // sort 
        sort(nums.begin(), nums.begin()+ n);
   
        int largest = nums[n-1];
        
        // reverse loop
       for ( int i=n-2; i>=0; i++){
        if (nums[i]!=largest)
         //secnd largest
        return nums[i];
       }

       return -1;
    }

    int main(){
        vector<int> nums = {8, 8, 7, 6, 5 };

        cout << "second largest elem: "<< secondLargestElement(nums);
        return 0;


    }
