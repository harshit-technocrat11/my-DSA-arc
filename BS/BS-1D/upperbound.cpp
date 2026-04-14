#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1; // go left
        }
        else
        {
            // go right
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 5, 6, 7, 10, 12, 15};

    int ans = upperBound(arr, 4);
    cout << "upperBound value : " << arr[ans] << endl;
    cout << "upperBound index is : " << ans;

    return 0;
}