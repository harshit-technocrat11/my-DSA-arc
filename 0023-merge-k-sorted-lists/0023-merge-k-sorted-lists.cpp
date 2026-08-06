/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compare {
        bool operator() (ListNode*a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        

        priority_queue<ListNode* , vector<ListNode*>, compare > minHeap;

        // push the first node of every non empty list

        for ( ListNode* node: lists){
            if ( node!=nullptr){
                minHeap.push(node);
            }
        }
        // if empty heap
        if ( minHeap.empty()) return nullptr;

        ListNode* head = new ListNode(0);
        ListNode* temp = head; //iterator

        // now main Loop 
        while (!minHeap.empty()){

            ListNode* smallestNode = minHeap.top();
            minHeap.pop();

            temp->next = smallestNode; 
            temp = temp->next; 

            // push smallest's node , next value into the heap

            if ( smallestNode->next!=nullptr){
                minHeap.push(smallestNode->next);
            }
            
        }
        return head->next ;
    }
};