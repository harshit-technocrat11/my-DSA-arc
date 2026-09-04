class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> arr(n,0);

        if (k==0) return arr;

        for ( int i = 0 ; i < n; i++){
        
            int sum=0;

            if (k>0){
                for (int j=i+1; j<i+k+1 ;j++){
                    sum+= code[j%n];
                }
            }
            else {
                // k<0
                for (int j = i - abs(k); j < i; j++) {
                    sum += code[(j + n) % n];
                }
            }

            arr[i] = sum;
            
        }

        return arr;
    }
};