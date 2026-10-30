class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l=0;
        int r =  l+minutes-1;
        int n=customers.size();

        long long sum=0;
        for ( int i =0; i <n ; i++){
            if (grumpy[i]==0) sum+=customers[i];
        }

        long long maxSum = 0;

        while ( r<n ){
            long long s=sum;
            for (int i=l ; i<=r; i++){
                if (grumpy[i]==1){
                    s+=customers[i];
                }
            }
            maxSum =  max(s, maxSum);
            r++;
            l++;
        }

        return maxSum;
    }
};