class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // medium - hardishh

        // modify tasks , include indx
        int n= tasks.size();

        for ( int i = 0; i < n; i++) { tasks[i].push_back(i);}

        priority_queue<pair<int,int>,  vector<pair<int, int>> , greater<pair<int, int>>> minHeap;

        // sort
        sort(tasks.begin(), tasks.end());
        // {processing time, indx}

        vector<int> ans; // order 

        long long t = (long long) tasks[0][0];

        int idx=0;
        while (ans.size()!=tasks.size()){
            while (idx<n && tasks[idx][0] <= t){
                minHeap.push({tasks[idx][1], tasks[idx][2]});
                idx++;
            }

            if (!minHeap.empty()){
                auto [duration, taskId ] = minHeap.top();

                minHeap.pop();
                ans.push_back(taskId);

                t+= (long long )duration;

            }
            else {
                // no tasks available at current t, then skip idle period
                t = (long long )tasks[idx][0];
            }
        }

        return ans;

    }
};