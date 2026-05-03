class Solution {
public:
    string expand( string &s, int &low , int &high , int &i ){
        while ( low>=0 && high<s.length() && s[low]==s[high]){
                high ++;
                low--;
                if ( low==-1 || high == s.length()) break;
        }
        return s.substr(low+1, high-low-1);
    }

    string longestPalindrome(string s) {
        if ( s.length()==1) return s;
        string LPS="";
        for ( int i =1; i < s.length(); i++){
            // for odd length palindrome check
            int high=i;
            int low =i;
            // extracting the substring
            
            string palindrome= expand(s, low, high , i);

            if (palindrome.length()  > LPS.length()){
                LPS = palindrome;  //update LPS to longest palin
            }

            // for even len 
            low = i-1;
            high=i;
           
            palindrome = expand ( s, low, high , i);

            if (palindrome.length()  > LPS.length()){
                LPS = palindrome;  //update LPS to longest palin
            }

        }   
        return LPS;
    }
};