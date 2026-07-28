class Solution {
public:
    string smallestPalindrome(string s) {

        int n= s.length();
        int mid=n/2;

        // sort the first half
        sort(s.begin(), s.begin()+mid); 

        // now create the mirror image on right half

        for  ( int i=mid; i<n;i++){
            s[i]=s[n-i-1];
        }   

        return s;
    }
};