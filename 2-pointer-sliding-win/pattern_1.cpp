#include <bits/stdc++.h>
using namespace std;

// sliding window- pattern - expand and shrinking approach
// return max len

int maximumLength(vector<int> arr, int k){
    int l=0;
    int n= arr.size();
    int r=0;
    int maxlen=0;
    int sum =0;

    while (r< n ){
        sum = sum +arr[l];

        while ( sum>k ){
            sum = sum -arr[r];
            l=l+1;

        }

        if ( sum <=k){
            maxlen= max(maxlen, r-l+1);
        }
        r++;
    }
    return maxlen;
}



int main() {
    vector<int >arr = {2,5,1,7,10};

    cout << maximumLength(arr, 10);
    return 0;
}