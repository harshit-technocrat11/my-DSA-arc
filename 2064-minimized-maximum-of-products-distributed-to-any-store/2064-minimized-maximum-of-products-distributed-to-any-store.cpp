class Solution {
public:
    bool distribute(int x, vector<int> & quantities , int shops ){
        int countStores=0;

        for ( int m : quantities){
            // try to distribute m, as x
            //find out the ceil
            countStores +=  (m+x-1)/x;

        }

        return countStores<=shops && countStores>0;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int h= *max_element(quantities.begin(), quantities.end());
        int ans=0;

        while (l<=h){
            int mid =  (h-l)/2 + l;

            if (distribute(mid, quantities, n)){
                ans = mid;
                h=mid-1 ; //try out a smaller possibility
            }    

            else {
                //false 
                l=mid+1;
            }
        }

        return ans;
    }
};