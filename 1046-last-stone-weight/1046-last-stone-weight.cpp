class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // using priority queue
        priority_queue<int> maxHeap;
        for ( int n : stones){
            maxHeap.push(n);
        }

        while(maxHeap.size() >1){

            int x= maxHeap.top() ; maxHeap.pop();

            int y= maxHeap.top() ;maxHeap.pop();

            maxHeap.push(abs(x-y));
        }

        return maxHeap.top(); //last remaining element to be returned
    }
};