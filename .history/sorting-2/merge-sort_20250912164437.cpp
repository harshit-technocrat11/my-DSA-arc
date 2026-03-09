#include <bits/stdc++.h>
using namespace std;


void mergeSort(vector<int> &arr, int low , int high){

    int mid = (low + high)/2;

    mergeSort(arr, low, mid);

    mergeSort(arr, mid+1, high);

    merge(arr, low , mid, high);

    
}

void merge(vector <int> arr, int low, int mid, int high){

    //temporary - sorted merged halves
    int left = low;

    int right =  mid +1;

    while (condition)
    {
        /* code */
    }
    
    




}

int main() {
    

    return 0;
}