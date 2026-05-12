class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // define mapA, mapB
        unordered_map<int,int> mapp;
        int r=0, l=0;
        int maxlen = 0;

        while ( r < fruits.size()){
            // check condition
            mapp[fruits[r]]++;
            if ( mapp.size()>2){
                while ( mapp.size()>2){
                    mapp[fruits[l]]--;
                     //element freq becomes -->0
                    if ( mapp[fruits[l]]==0){

                         mapp.erase(fruits[l]);
                    }
                    l++;
                }
            }
            maxlen = max(maxlen, r-l+1);

            r++;
        }
        return maxlen;
        
    }
};