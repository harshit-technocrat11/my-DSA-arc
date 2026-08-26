class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int count=0;
        int start=0;
        int end=0;
        string ans="";

        int n=s.size();

        while(end<=n-1){

            if ( s[end]=='1'){
                count++;
            }
            

            while (count>k){
                if(s[start]=='1'){
                    count--;
                }
                start++;
            }

            // for count<=k

            // if we have exaclty k ones , 
            if (count==k){
                int len =  end-start+1;

                // 2 cases , for updating the curr string
                // 1. len < minLen, then update minLen
                // 2. when len==minlen, but lexicographically greater is considered 
                
                // remove unwanted zeroes
                while ( start < end && s[start]=='0'){
                    start++;
                }

                string cur = s.substr(start, end-start+1);

                // if we found a smaller string
                // if the size if same, but lexicographically greater, is considerd 
                if ( ans=="" || cur.size() < ans.size() || ( cur.size() ==  ans.size() && cur<ans) ){
                    ans = cur;
                }
            }

            end++;
        }

        return ans;
    }
};