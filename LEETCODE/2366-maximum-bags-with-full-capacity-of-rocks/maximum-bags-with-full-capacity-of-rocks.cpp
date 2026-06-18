class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> need;

        int n = capacity.size();

        for ( int i =0; i<n;i++){
            need.push_back(capacity[i]-rocks[i]);
        }
        // sort
        sort(need.begin() , need.end());

        int count=0;
        for ( int n : need ){
            if ( additionalRocks >=n ){
                additionalRocks-=n;
                count++;
            }
            else {
                break;
            }
        }

        return count;
    }
};