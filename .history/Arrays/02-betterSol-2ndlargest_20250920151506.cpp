#include <bits/stdc++.h>
using namespace std;

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

    for ( int i=0; i<n; i++){

        if ( nums[i]<largest && nums[i])
        if ( nums[i]>largest ){
            // secondLargest = largest;
            largest = nums[i];
        }
    }

    return secondLargest;

}

    int main()
{
    vector<int> nums = {8, 8, 7, 6, 5, 10, 9};

    cout << "second largest elem: " << secondLargestElement(nums);
    return 0;
}