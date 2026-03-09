#include <bits/stdc++.h>
using namespace std;


// brute force approach !!!
void moveZeroes(vector<int> &nums)
{
    // find 0  ka position
    int n = nums.size();
    vector<int> temp;

    for ( int i=0; i < n; i++){

        if ( nums[i]==0){
            for ( int j=i; j<n-1; j++){
                swap(nums[j], nums[j+1]);
            }
        }
    }
}


void printArr(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}


int main() {
    vector<int> nums = { 0, 1, 4, 0, 5, 2,3,0 };
    
    cout << "before :";
    printArr(nums);

    moveZeroes(nums);
    cout << "after : ";
    printArr(nums);

    return 0;
}