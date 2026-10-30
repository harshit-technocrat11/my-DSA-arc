class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l=0;
        int r =  l+minutes-1;
        int n=customers.size();
        long long currWin = 0;
        long long sum=0;
        for ( int i =0; i <n ; i++){
            if (grumpy[i]==0){
                sum+=customers[i];
            }
            //  if encountered 1, then add to curr win
            else if (i<minutes){
                currWin+=customers[i];
            }
        }

        long long maxSum = currWin; 

        for ( int i = minutes; i<n; i++){
            // slide
            // consider 1, and add them, skip 0's
            currWin += customers[i]*grumpy[i];
            currWin-= customers[i-minutes]*grumpy[i-minutes]; 
            maxSum =  max(maxSum, currWin);
        }   

        return maxSum + sum; //extra + initial
    }
};