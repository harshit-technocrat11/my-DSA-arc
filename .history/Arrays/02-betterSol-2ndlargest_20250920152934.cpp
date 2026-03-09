#include <bits/stdc++.h>
using namespace std;
// Better solution

// int secondLargestElement(vector<int> &nums){

//     int n = nums.size();
//     int largest = nums[0];

//     for ( int i=0; i< n; i++){
//         if ( nums[i] > largest){
//             largest = nums[i];
//         }
//     }

//     int secondLargest = -1;

//     for ( int i =0; i<n; i++){
//         if (nums[i]>secondLargest && nums[i] < largest){
//             secondLargest = nums[i];
//         }
//     }

//     return secondLargest;

// }   

// OPTIMAL SOLUTION
int secondLargestElement(vector<int> &nums){
    int n = nums.size();
    int largest = nums[0];
    int secondLargest = -1;

    for ( int i=1; i<n; i++){

        // find the latest largest number
        if ( nums[i]>largest ){
            // secondLargest = largest;
            largest = nums[i];
        }

        // then compare
        if ( nums[i]<largest && nums[i]>secondLargest){
            secondLargest = nums[i];
        }
    }

    return secondLargest;

}

int secondSmallestElement(vector<int> &nums){
    int n = nums.size();
    int smallest = nums[0];
    int secondSmallest = INT_MAX;

    for ( int i=0; i < n; i++0){
        if ( nums [i] < smallest){
            smallest = nums[i];
        }

        if ( nums[i] > smallest && nums[i]  > secondSmallest ){
            secondSmallest = nums[i];
        }

    }

        
}

    int main()
{
    vector<int> nums = {1,2, 7, 6, 5, 13, 9,12};

    cout << "second largest elem: " << secondLargestElement(nums);
    return 0;
}