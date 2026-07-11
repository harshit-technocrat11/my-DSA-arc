class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer; 
        vector<int> firstRow;
        firstRow.push_back(1);

        answer.push_back(firstRow);

        // loop-1
        for ( int i = 1 ; i < numRows; i++){
            // extract previous row
            vector<int> prevRow =  answer[i-1];

            vector<int> currRow;
            currRow.push_back(1); //start 

            for ( int j =0 ; j<i-1; j++ ){
                currRow.push_back(prevRow[j]+prevRow[j+1]);
            }
            currRow.push_back(1); //end

            answer.push_back(currRow);
        }
        return answer;
    }
};