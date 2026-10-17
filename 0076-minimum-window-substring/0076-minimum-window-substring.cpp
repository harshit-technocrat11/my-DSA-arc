class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n = t.size();
        if ( n>m) return "";

        // map for t
        vector<int> need(128,0);
        
        for ( int i=0; i<n ; i++){
            need[t[i]]++;
        }

        string ans="";
        int minlen = INT_MAX;
        int matched=0; //global
        int startIdx=-1;
        int l=0; //left ptr

        // new map for window
        vector<int> win(128,0);

        for ( int r=0; r<m; r++){
            
            char c =  s[r];
            win[c]++;

            if (need[c]>0 && win[c]<=need[c]){
                matched++;
            }
            // shrink condtn
            while (matched==n){
                // shrink the win
                int currlen=r-l+1;
                if ( currlen < minlen){
                    minlen = currlen;
                    startIdx = l;
                }

                // remove left mst char
                char leftC =  s[l];
                win[leftC]--;

                if (need[leftC]>0 && win[leftC] < need[leftC]){
                    matched--; //if we removed a useful needed char
                }
                l++;
            }
            
        }
        return startIdx==-1? "" : s.substr(startIdx, minlen);

    }
};