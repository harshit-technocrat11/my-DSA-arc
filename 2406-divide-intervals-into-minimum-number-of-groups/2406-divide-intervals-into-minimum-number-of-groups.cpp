class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // sort
        sort(intervals.begin(), intervals.end());

        // minheap
        priority_queue<int, vector<int> , greater<int>> pq;

        for ( auto &interval : intervals){
            int start = interval[0];
            int end = interval[1];

            if (!pq.empty() && start > pq.top() ){
                // insert into the smallest grp
                pq.pop();
                
            }

            pq.push(end); // create new grp;
        }

        return pq.size();
    }
};