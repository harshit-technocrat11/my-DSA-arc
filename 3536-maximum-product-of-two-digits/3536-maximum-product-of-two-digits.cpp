class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> pq;

        while(n!=0){
            int digit = n%10;
            pq.push(digit);

            n=n/10;
        }

        int a =  pq.top(); pq.pop();
        int b= pq.top(); pq.pop();

        return a*b;
    }
};