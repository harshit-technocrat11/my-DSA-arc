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
            left++;
        }
        
        // if arr[right] <=  arr[left]
        else{
            temp.push_back(arr[right]);
            right++;

        }
    }

    //once left half is exhausted

    while ( right <=high ){
        temp.push_back(arr[right]);
        right++;

    }
}

void printArray(vector<int> &arr){
    int size = arr.size();
    for ( int i=0; i<size; i++){
        cout << arr[i] << " ";
        
    }
    cout << endl;
}


int main() {
    
    vector <int> array = {3,4,1,19,17,14,78,10};
    cout << "before sorting : ";
    printArray(array);

    


    return 0;
}