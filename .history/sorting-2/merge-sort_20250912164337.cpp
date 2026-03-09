#include <bits/stdc++.h>
using namespace std;


void mergeSort(vector<int> &arr, int low , int high){

    int mid = (low + high)/2;

    mergeSort(arr, low, mid);

    mergeSort(arr, mid+1, high);

    merge(arr, low , mid, high);

    
}

void merge(vector <int> arr, int left, int mid, int right){

    //temporary - sorted merged halves
    



}

int main() {
    

    return 0;
}