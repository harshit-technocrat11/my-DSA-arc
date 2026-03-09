#include <bits/stdc++.h>
using namespace std;

vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
{

    set<int> temp;

    for (int i = 0; i < nums1.size(); i++)
    {
        temp.insert(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        temp.insert(nums2[i]);
    }

    // return vector unionArray
    vector<int> unionArr;

    for (auto i : temp)
    {
        unionArr.push_back(i);
    }
    return unionArr;
}

void printArr(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> a1 = {3, 4, 6, 7, 9, 9}, a2 = {1, 5, 7, 8, 8};

    printArr(unionArray(a1, a2));

    return 0;
}