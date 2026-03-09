#include <bits/stdc++.h>
using namespace std;

// class or  struct 

class Node {
    public: 
    int data;
    Node* next;

    public: 
    Node( int d, Node* ptr){
        data =  d;
        next = ptr;
    }
};

int main() {
    
    vector <int> arr  {2,5,8,7};
    Node * y = new Node(arr[0],nullptr);

    cout << y->next;

    
    return 0;
}