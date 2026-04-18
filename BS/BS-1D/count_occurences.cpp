//  2 approaches- 
// 1. using count = UB - LB

// 2. using count = [ last occurence - first occurence ]


#include <bits/stdc++.h>
using namespace std;

int count_occ(vector<int> arr, int target)
{
    // count occurences 
    auto lb= lower_bound(arr.begin() , arr.end() , target);
    auto ub= upper_bound(arr.begin() , arr.end() , target);

    // returns count = 0, if target not present
    
    int count = ub-lb;
    return count;
}

int main()
{
    vector<int> arr = {2, 3, 5, 6, 7, 10, 12, 12,12,12, 15};
    int ans = count_occ(arr, 12);
    cout << "counting the occurences of x: " << count_occ(arr, 12);
    return 0;
}