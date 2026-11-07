class Solution {
public:
    typedef  pair<int,int> p;
    typedef  tuple<long, int , int> b;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // interesting question, just lke a case study
        int m= tasks.size();
        int n = servers.size();

        priority_queue<p ,vector<p>, greater<p>> freeServers;

        // at time = 0 all servers, are free
        for ( int i = 0; i<n; i++){
            freeServers.push({servers[i], i});
        }
     
        priority_queue<b, vector<b> , greater<b> > busyServers; 

        vector<int> result(m); //order ans

        for (int i = 0; i<m; i++){
            // time = i
            // 1. move busy servers to the free servers, if they are free by time i
            while(!busyServers.empty() && get<0>(busyServers.top())<=i){
                 auto [fintime, wt, idx] = busyServers.top();
                 busyServers.pop();
                // push
                freeServers.push({wt,idx});
            }

            // 2. if all servers are busy
            if (freeServers.empty()){
                // we can wait for the earliest finishing server
                auto [ftime, wt, idx] = busyServers.top();

                busyServers.pop();

                // assign task
                result[i] = idx;
                //push with ftime + task[i]

                busyServers.push({ftime + tasks[i], wt, idx}); 
            }
            else{ //not empty
            // last case- if we ever get a free server,
                auto [wt, idx] = freeServers.top(); 
                freeServers.pop();
                result[i] = idx; //assign task

                busyServers.push({i+tasks[i],wt, idx });
            }
        }

        return result;

    }
};