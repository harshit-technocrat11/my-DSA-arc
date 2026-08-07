class Solution {
public:
    struct compare{
        bool operator() (vector<int> &a, vector<int> &b){
            return a[0]<b[0];
        }
    };
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i =0;
        int n= intervals.size();
       
        //1.   intervals completely before newInterval 
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // 2: merge overlapping intervals
        while (i<n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);

            i++;
        }

        // push the new interval
        ans.push_back(newInterval);

        // 4. remaining elements

        while (i<n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};