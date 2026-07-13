class Solution {
public:
    void backtrack(vector<string> &ans , string temp, int open ,int close, int n){
        if ( open==n && close==n){
            ans.push_back(temp);
            return;
        }

        if ( open<n){
            temp+="(";
            backtrack(ans, temp , open+1, close, n);
            temp.pop_back(); 
        }
        if ( close < open){
            temp+= ")";
            backtrack(ans, temp , open , close+1,n);
            // cleanup
            temp.pop_back();
        }
    }


    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        backtrack(answer, "",0,0,n );

        return answer;

    }
};