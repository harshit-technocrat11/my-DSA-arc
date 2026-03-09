#include <bits/stdc++.h>
using namespace std;


// brute force approach
// - use SET  to store the unqiue elements

// int removeDuplicates(vector <int>  &nums)
// {
//     set <int> st;
//     int n= nums.size();
//     // iterating via the array
//     for ( int i = 0; i<n; i++){
//         st.insert(nums[i]);
//     }

//     // iterating thru the array - and adding elements to it

//     int index = 0;
//     for ( auto it: st){
//         nums[index] = it;
//         index++;
//     }

//     return index;
// }

// OPTIMAL SOL
// 2 pointer approach 
int removeDuplicates(vector <int>  &nums){
    int n = nums.size();
    int i=0;

    for ( int j=0; j< n; j++){
        if (nums[i]!=nums[j]){
            // i=j;
            nums[i+2]
        }
    }

    // since last index - of unqiue elem = i
    // total unique values  = i+1;

    return i+1;

}
int main() {
    vector<int> nums = {8, 8, 8, 6, 5};

    cout << "no of unique elements are: " << removeDuplicates(nums);


    return 0;
}