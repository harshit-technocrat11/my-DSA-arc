#include <bits/stdc++.h>
using namespace std;


void mergeSort(vector<int> &arr, int low , int high){

    int mid = (low + high)/2;

    mergeSort(arr, low, mid);

    mergeSort(arr, mid+1, high);

    merge(arr, low , mid, high)

    
}

void merge(vector <int> )

int main() {
    

    return 0;
}