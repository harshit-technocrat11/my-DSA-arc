class Solution {
public:

    void dfs ( int row, int col,vector<vector<int>>& image ,vector<vector<int>>& ans ,vector<vector<int>> &dir ,  int newColor , int& oldColor ){
        
        ans[row][col] = newColor; //mark visited
        int n= image.size();
        int m= image[0].size();

        // expand in 4 directions

        for ( int i = 0; i < 4;i++){
            
            // new row and col
            int nrow = row + dir[i][0];
            int ncol = col + dir[i][1];
            
            if ( nrow>=0  && nrow<n && ncol >=0 && ncol<m && image[nrow][ncol]==oldColor && ans[nrow][ncol]!=newColor ){
                
                // dfs call
                dfs(nrow, ncol , image, ans, dir, newColor, oldColor);
            }
        }
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // using DFS

        // check 
        if ( image[sr][sc]==color) return image;

        vector<vector<int>> ans=image;
        int oldColor = image[sr][sc];
        // direction , change, delta
        vector<vector<int>> dir = {{-1,0},{0,1}, {1,0}, {0,-1}};

        dfs(sr, sc, image, ans ,dir , color, oldColor );
        return ans;
    }
};