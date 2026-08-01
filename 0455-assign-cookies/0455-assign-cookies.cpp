class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort both 
        sort(g.begin(), g.end());
        sort(s.begin() , s.end());

        int count=0;
        int j=0; int i=0;
        
        while (j < s.size() && i < g.size() ){

            if ( s[j]>=g[i]){
                count++;
                i++;
            }
            // move to next cookie - in both cases
            j++;
        }

        return count;
    }
};