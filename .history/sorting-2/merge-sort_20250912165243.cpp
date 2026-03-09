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
    vector <int> temp = {};
    int left = low;

    int right =  mid +1;

    while (left<=right && right <=high)
    {
        if (arr[left]<=arr[right]){
            temp.push_back(arr[left]);
        }
        
        // if arr[right] <=  arr[left]
        else{
            temp.push_back(arr[right]);

        }

    }

    //once left half is exhausted

    while ( right <=high ){
        temp.push_back(arr[right])
        rg
    }
    
    




}

int main() {
    

    return 0;
}