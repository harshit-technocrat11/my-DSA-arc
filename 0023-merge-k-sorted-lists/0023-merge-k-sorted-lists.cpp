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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0) return nullptr;

        priority_queue<int , vector<int>, greater<int> > minHeap;

        for ( int i = 0 ; i < lists.size() ; i++){
            ListNode* node = lists[i];

            while (node!=nullptr){
                minHeap.push(node->val);
                node= node->next;
            }

        }

        if ( minHeap.empty()) return nullptr;

        // now merge 
        ListNode* head= new ListNode(minHeap.top());
        minHeap.pop();
        ListNode* temp = head; 

        while (!minHeap.empty()){
            temp->next =new ListNode(minHeap.top());
            minHeap.pop();

            temp = temp->next;
        }

        return head;
    }
};