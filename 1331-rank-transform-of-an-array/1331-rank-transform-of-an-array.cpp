class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // sort 
        vector<int> temp = arr;
        sort(temp.begin() , temp.end());

        unordered_map<int,int> mp;
        int rank=1;
        for ( int n: temp){
            if ( mp.find(n)==mp.end()){
                mp[n] = rank;
                rank++;
            }
        }
        // -----------
        for ( int i =0; i <arr.size(); i++){
            // reconstruct
            temp[i] =  mp[arr[i]];
        }

        return temp;

    }
};