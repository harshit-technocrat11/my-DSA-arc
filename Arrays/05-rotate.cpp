// rotate by k places

#include <bits/stdc++.h>
using namespace std;

// void rotateArray(vector<int> &nums, int k)
// {

//     int size = nums.size();

//     // loop for k- rotations
//     for (int i = 1; i <= k; i++)
//     {
//         // loop for assigning
//         for (int j = 0; j <= size - 2; j++)
//         {
//             // nums[j] = nums[j + 1];
//             swap(nums[j], nums[j+1]);
//         }

//     }
// }

// approach 2
// void rotateArray(vector<int> &nums, int k){
//     int n = nums.size();
    
//     k = k%n;

//     int temp[k];

//     // copy the 1st k elements 
//     for ( int i=0; i<k ; i++){
//         temp[i] = nums[i];
//     }

//     // shift n-k elems from last by k positions 
//     for (int i=0; i< n-k ; i++ ){
//         nums[i] = nums[i+k];
//     }

//     // now placing temp at last 
//     for ( int i= n-k; i< n ; i++){

//         nums[i] = temp[i-n+k];
//     }

// }

// =========================================
// OPTIMAL

void rotateArray(vector<int> &nums, int k){
    
}

void printArr(vector<int> nums)
{
    for ( int i =0;i < nums.size(); i++){
        cout <<  nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    printArr(nums);

    rotateArray(nums, 4);

    printArr(nums);

    return 0;
}