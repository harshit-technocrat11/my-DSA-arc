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
    vector <int> temp = []
    int left = low;

    int right =  mid +1;

    while (left<=right && right <=high)
    {
        if (arr[left]<=arr[right]){
            temp.add()
        }
    }
    
    




}

int main() {
    

    return 0;
}