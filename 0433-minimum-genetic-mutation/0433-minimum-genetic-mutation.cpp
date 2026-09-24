class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st;
        for ( string s: bank ){
            st.insert(s);
        }
        // if end not in dict
        if (st.find(endGene)==st.end()) return -1;

        vector<char> choices = {'A','C', 'G', 'T'};

        queue<pair<string,int>> q;  // {word , step}

        q.push({startGene , 0});
        st.erase(startGene);

        while (!q.empty()){

            string gene = q.front().first;
            int len = q.front().second; //no of mutations
            q.pop();

            if ( gene == endGene){
                return len;
            }

            // iterate thru the word
            for ( int i = 0; i < gene.size(); i++){
                string temp = gene;

                for ( int j=0; j< choices.size(); j++){
                    temp[i] = choices[j];
                    // if inside set
                    if (st.find(temp)!=st.end()){
                        // push
                        q.push({temp, len+1});
                        st.erase(temp);
                    }

                }

            }
        }

        return -1;
    }
};