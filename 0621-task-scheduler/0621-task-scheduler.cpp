class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;
        for ( auto c: tasks) map[c]++;

        // max heap
        priority_queue<int> maxHeap;

        for ( auto& it: map){
            maxHeap.push(it.second);
        }

        int time = 0;

        while (!maxHeap.empty()){
            vector<int> temp;

            // we take the cycle of n+1;
            int cycle = n+1;

            for ( int i =0;i <=n; i++){
                if (!maxHeap.empty()){

                    int count  = maxHeap.top();
                    maxHeap.pop();

                    count--;

                    if (count>0){
                        temp.push_back(count);
                    }

                    time++;
                }

                else{
                    // no task is available 
                    // idle time
                    if (!temp.empty()){
                        time++;
                    }
                }
            }

            // put remaining tasks back into the 
            for ( int count: temp){
                maxHeap.push(count);
            }

        }

        return time;

    }
};