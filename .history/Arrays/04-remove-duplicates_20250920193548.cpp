#include <bits/stdc++.h>
using namespace std;


// brute force approach
// - use SET  to store the unqiue elements

int removeDuplicates(vector <int>  &nums)
{
    set <int> st;
    int n= nums.size();
    // iterating via the array
    for ( int i = 0; i<n; i++){
        st.insert(nums[i]);
    }

    // iterating thru the array - and adding elements to it

    int index = 0;
    for ( auto it: st){
        nums[index] = 
    }


}
int main() {
    

    return 0;
}