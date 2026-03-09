#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &nums)
{
    // your code goes here
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (!nums[i] >= nums[i - 1])
        {
            return false;
        }
    }

    return true;
}

int main() {    
        vector <int> = {1,2,3,4,5,7,8};

    return 0;
}