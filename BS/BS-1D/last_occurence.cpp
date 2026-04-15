#include <bits/stdc++.h>
using namespace std;

// brute
// int find_last_occ( vector<int> arr, int target){
//     int n=arr.size();
//     // brute-
//     int res= -1;
//     for ( int i =n-1; i>=0; i--){
//         if ( arr[i]==target){
//             res=i;
//             break;
//         }
//     }
//     return res;
// }

int find_last_occ(vector<int> arr, int target)
{
    int n = arr.size();
    int l = 0;
    int h = n - 1;
    int res = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if ( arr[mid]==target){

            res = mid;
    
            l = mid + 1; // store and move right !!
        }
        else if ( arr[mid]>target){
            //move left 
            h= mid-1;

        }
        else {
            // right 
            l=mid+1;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {2, 3, 5, 6, 7, 10, 12, 12,15};
    int ans = find_last_occ(arr, 12);
    cout << "last occuring index:  " << find_last_occ(arr, 12);
    return 0;
}