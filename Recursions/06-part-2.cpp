#include <bits/stdc++.h>
using namespace std;

// print all the subsequences

void printF(int ind, vector<int> &ds, int arr[], int n)
{
    if (ind == n)
    {
        for (auto it : ds)
        {
            cout << it << ",";
        }

        // null
        if (n == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    // take or not take the elements
    ds.push_back(arr[ind]);
    printF(ind + 1, ds, arr, n);
    ds.pop_back();

    // not take
    printF(ind + 1, ds, arr, n);
}

void subseqSUM_k1(int i, vector<int> &ds, int arr[], int sum, int s, int n)
{
    if (i == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << ",";
            }
            cout <<endl;     
        }
        return;
    }
    // take it
    ds.push_back(arr[i]);
    s += arr[i];
    subseqSUM_k1(i + 1, ds, arr, sum, s, n);

    // undo the take, take another elem
    ds.pop_back();

    s -= arr[i];
    subseqSUM_k1(i + 1, ds, arr, sum, s, n);
}

bool subseqSUM_k2(int i, vector<int> &ds, int arr[], int sum, int s, int n)
{
    if (i == n){
        if (s == sum){
            for (auto it : ds){
                cout << it << ",";
            }
            cout <<endl;     
            return true;
        }
        // else condition false
        else return false;
    }
    // take it
    ds.push_back(arr[i]);
    s += arr[i];
    if (subseqSUM_k2(i + 1, ds, arr, sum, s, n) ==true){
        return true;
    }

    // undo the take, take another elem
    ds.pop_back();

    s -= arr[i];
    if (subseqSUM_k2(i + 1, ds, arr, sum, s, n)) return true;

    return false;
}

int countSubseqs(int i, vector<int> &ds, int arr[], int sum, int s, int n)
{
    if (i == n){
        if (s == sum){
        
            return 1;
        }
        else return 0;
    }
    // take it
    ds.push_back(arr[i]);
    s += arr[i];
    int l = countSubseqs(i + 1, ds, arr, sum, s, n); //left branch valid cases

    // undo the take, take another elem
    ds.pop_back();

    s -= arr[i];
    int r = countSubseqs(i + 1, ds, arr, sum, s, n); //right branch valid cases
    return l+r;
}

int main()
{
    // take an array
    int arr[] = {3, 1, 2,4 };
    vector<int> ds;
    int n = 4;
    printF(0, ds, arr, n);

    // 1. print all the subsequences whose sum == k
    int sum = 3;

    cout << endl;
    cout << "subseq with sum: " << sum << endl;
    subseqSUM_k1(0, ds, arr, sum, 0, n);
    cout << endl;
    
    
    // 2. print any 1 subsequence with sum == k
    sum= -1;
    // int arr2[] = {1,2,1,-1,-3};
    int arr2[] = {2,-3,1,-1};
    n=4;
    cout << "subseq with sum: " << sum << endl;
    subseqSUM_k2(0, ds, arr2, sum, 0, n);
    
    // 3. COUNT all the subsequences with sum == k
    cout << endl;
    cout<< "count of all the subsequences with sum: "<< sum <<" is "<<endl;
    cout << countSubseqs(0, ds, arr2, sum, 0, n);
    return 0;
}