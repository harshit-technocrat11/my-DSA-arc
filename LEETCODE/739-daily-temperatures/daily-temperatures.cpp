class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size();
        vector<int> answer(n, 0);

        stack<int> stack;  //store indices in the stack - 

        for ( int i =0; i < n; i++){
            // if current temperature is > temp stored at top in stack - then find answer[i]
            //then pop the index i 

            while ( !stack.empty()  && temperatures[i] > temperatures[stack.top()]){
                // update results
                answer[stack.top()] =  i - stack.top();
                stack.pop();
            }

            stack.push(i);
        }

        return answer;
    }
};