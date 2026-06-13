class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // 2 pointers approach! 

        int total_water=0;
        vector<int> maxright(n,0) ; 
        vector<int> maxleft(n,0) ;
        // pointers
        int maxL=0, maxR=0, water=0;

        maxleft[0]=height[0];
        for ( int i = 1 ; i< n; i++){
            // maxleft - skip the first element
            maxleft[i] = max(height[i], maxleft[i-1]);
        }
        maxright[n-1]=height[n-1];
        for ( int i=n-2; i>=0; i--){
            // maxright - exclude last element
            maxright[i] = max(height[i], maxright[i+1]);
        }

        // calculating water
        for ( int i =0 ; i<n ; i++){
            if ( maxleft[i]>height[i] && maxright[i] > height[i]){
                total_water+= min ( maxleft[i], maxright[i]) -height[i];  
            }
        }
        return total_water;
    }
};