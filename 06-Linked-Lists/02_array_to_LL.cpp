#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int d, Node *ptr)
    {
        data = d;
        next = ptr;
    }

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

Node *convertArrayToLL(vector<int> &arr)
{

    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);

    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        // mover = temp;
        mover = mover->next;
    }
    return head;
}

int length_LL(vector<int> &arr)
{
    int c = 0;
    Node *head = convertArrayToLL(arr);
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        c++;
    }
    return c;
}

int Search(Node *head, int val)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

Node *removeHead(Node *head)
{
    if (head == NULL)
        return head; // empty array

    Node *temp = head;
    head = head->next;

    // delete temp;
    free(temp);

    return head;
    // return the new head
}

Node * removeTail( Node* head) {
    if ( head== NULL || head-> next == nullptr) return nullptr;

    Node * temp = head;
    
    // until Second last element

    while ( temp->next-> next != nullptr){
        temp = temp -> next;
    }

    delete temp-> next;

    temp-> next =  nullptr;

    return head;
}

Node * insertHead (Node* head, int val ){
    return new Node(val, head);

}
Node* insertTail(Node* head, int val){
    // edge case 
    if ( !head) return new Node(val, nullptr);
    Node * temp =head;
    while ( temp->next!=nullptr){
        temp = temp->next;
    }
    Node* last = new Node(val , nullptr);
    temp->next= last;
    return head;
}

// at kth position
Node* insertK( Node*head, int val, int k){
    // edge case
    if ( head==NULL){
        if ( k==1){
            return new Node(val,nullptr);
        }
        else return NULL;  // error case
    }
    if ( k==1){
        Node*temp = new Node(val, head);
        return temp;
    }

    // for other values
    int count = 0;
    Node * temp = head;
    while(temp){
        count++;

        if ( count==k-1){
            Node* insert = new Node(val, nullptr);
            insert->next = temp->next;
            temp->next = insert;

            return head;
        }
        temp = temp->next;
    }
    return head;

}

void print(Node*head){
    Node* temp =head;
    while(temp){
        cout << temp->data << ":[" << temp->next << "] ";
        temp = temp->next;
    }
    cout<<endl;
} 


int main()
{
    vector<int> A = {2, 3, 4, 5, 6};

    Node *head = convertArrayToLL(A);
    cout << "head: " << head << endl;

    // Traversing
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << ":[" << temp->next << "] ";
        temp = temp->next;
    }
    cout << endl;

    // length
    cout << "lenght of LL : " << length_LL(A) << endl;

    // Search()
    cout << bool(Search(head, 2)) <<endl;

    head = removeHead(head); //new head
    cout <<" removeHead: "<< head << endl
         << endl;

    temp = head;
    while (temp)
    {
        cout << temp->data << ":[" << temp->next << "] ";
        temp = temp->next;
    }
    cout << endl;

    head = removeTail(head);
    
    temp = head;
    while (temp)
    {
        cout << temp->data << ":[" << temp->next << "] ";
        temp = temp->next;
    }
    cout << "remove tail (returns head):"<<  head<<endl;
    
    // inserting a new head;
    
    head = insertHead(head , 34);
    print(head);
    head = insertTail(head, 78);
    print(head);

    head = insertK(head, 546, 2);
    print(head);
    return 0;
}