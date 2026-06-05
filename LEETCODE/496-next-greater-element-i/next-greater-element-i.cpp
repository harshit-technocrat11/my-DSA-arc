class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int > st;
        int n = nums2.size();
        unordered_map < int , int> answerMap; 

        for ( int i = n-1; i>=0; i--){
            
            // if stack not empty ---> pop elements until u find a NGE 
            while (!st.empty() && st.top()<=nums2[i] ){
                st.pop();
            }

            //if stack becomes empty--> then no NGE was found for current element
            if ( st.empty()){
                answerMap[nums2[i]]=-1;
            }
            else{ //if NGE found
                 answerMap[nums2[i]]=st.top();
            }

            //push
            st.push(nums2[i]);

        }

        //now 
        vector<int> finalAns;
        for ( int i=0; i < nums1.size();i++){
            finalAns.push_back( answerMap[nums1[i]]);
        }

        return finalAns;
    }
};