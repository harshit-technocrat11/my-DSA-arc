class Solution {
public:
   bool getNeighbors(string s,
    unordered_set<string>& end,
    unordered_set<string>& st,
    unordered_set<string>& nextLevel ){

        vector<int> ans;

        for ( int i = 0 ; i < 4; i++){
            string temp = s;
            char ch = temp[i];

            char dec = ch=='0' ? '9' : ch-1;
            char inc = ch=='9' ? '0' : ch+1;

            temp[i]=dec;
            
            if (end.find(temp)!=end.end()) return true;

            if (st.find(temp)==st.end()){
                st.insert(temp);
                nextLevel.insert(temp);
            }

            temp[i]=inc;
            
            if (end.find(temp)!=end.end()) return true;

            if (st.find(temp)==st.end()){
                st.insert(temp);
                nextLevel.insert(temp);
            }
        }
        return false;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end()); //set for visited
        if (dead.count("0000")){
            return -1;
        }
        if ( target=="0000") return 0;

        dead.insert("0000");
        dead.insert(target);

        int stepsBegin = 0;
        int stepsEnd = 0;

        unordered_set<string> begin = {"0000"};
        unordered_set<string> end = {target};

        while (!begin.empty() && !end.empty()){

            if ( begin.size() > end.size()){
                swap(begin, end);
                swap(stepsBegin, stepsEnd);

            }

            unordered_set<string> nextLevel;

            for ( string curr: begin){

                if (getNeighbors(curr, end, dead, nextLevel)) {
                    // if match found b/w End search and begin search 
                    return stepsBegin+stepsEnd+1;
                }
            }
            begin= nextLevel;
            stepsBegin++;
        }
        
        return -1;
    }

};