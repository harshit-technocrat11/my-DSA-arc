class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        // create  pairs
        vector<pair<int, int>>  meetings;
        
        for ( int i = 0; i < start.size(); i++){
            meetings.push_back({finish[i], start[i]});
            // store the  end, start pair
        }
        
        // sort 
        sort ( meetings.begin(), meetings.end());
        
        int LastEnd=-1;
        int count=0; //no of meetings
        
        for ( auto meeting: meetings){
            int st = meeting.second;
            int end = meeting.first;
            
            if ( st > LastEnd){
                count++;
                LastEnd = end;
            }
        }
        
        return count;
    }
};