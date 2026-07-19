class KthLargest {
    priority_queue<int, vector<int> , greater<int>> minHeap;
    int kSize;
public:
    KthLargest(int k, vector<int>& nums) {
        // push all elements into min heap
        kSize=k;
        
        for ( int n: nums){
            add(n);
        }
    }
    
    int add(int val) {
        
        minHeap.push(val);

        while(minHeap.size()>kSize){
            minHeap.pop();
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */