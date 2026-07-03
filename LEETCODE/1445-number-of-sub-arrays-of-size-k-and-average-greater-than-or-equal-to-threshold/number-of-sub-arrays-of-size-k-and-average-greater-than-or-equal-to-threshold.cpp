class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count =0;
        int l = 0, r = k-1;

        float sum  = 0;
        // initial
        for ( int i =0; i < k; i++){
            sum+=arr[i];
        }
        if  ( sum >= threshold*k) count++;

        while ( r < arr.size()-1){
            sum = sum - arr[l++];
         
            sum = sum + arr[++r];

            if  ( sum >= threshold*k) count++;
        }

        return count;
    }
};