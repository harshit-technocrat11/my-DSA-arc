class Solution {
public:

    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        //    count no. of servers in each row and each col
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        // if count>1, then include the answer, as min 2 servers needed to communicate
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]==1 && ( row[i]>1 || col[j]>1 )){
                    count++;
                }
            }
        }

        return count;
    }
    
};