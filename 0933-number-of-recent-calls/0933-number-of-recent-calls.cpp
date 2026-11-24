class RecentCounter {
    vector<int> requests;
    int i;
    int j;
public:

    RecentCounter() {
        i=0;
        j=-1;
    }
    
    int ping(int t) {
        requests.push_back(t);
        j++;

        // check thru the window
        while (i<j && requests[j]-3000 > requests[i]){
            i++;
        }

        return j-i+1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */