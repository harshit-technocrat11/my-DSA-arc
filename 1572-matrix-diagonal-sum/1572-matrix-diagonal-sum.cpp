class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int size=mat.size();
        // in pd: j=i
        // in sd j=size-i-1


        for ( int i =0; i <size;i++ ){
            sum+=mat[i][i];
            if(i!=size-i-1){
                sum+=mat[i][size-i-1];
            }
           
        }

        return sum;
    }
};