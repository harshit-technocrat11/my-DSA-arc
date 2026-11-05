class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{-1,0}, {0,1} , {1, 0 }, {0, -1}};
    bool isSafe(int i , int j){
        return i>=0 &&i < m && j>=0 && j<n;
    }

    void dfs(int i, int j, vector<vector<int>> &grid, set<pair<int, int>> &visCell){
        if (!isSafe(i, j) || grid[i][j] == 0 || visCell.find({i, j}) != visCell.end()){
            return ;
        }

        visCell.insert({i, j});

        for (auto &d: dir){
            int ni = i+d[0];
            int nj = j+d[1];

            dfs(ni, nj, grid , visCell);
        }
    }

    int bfs(vector<vector<int>> &grid, set<pair<int, int>> &visCell){
        queue<pair<int, int>> q;

        // constrcut queue
        for (auto &it: visCell){
            q.push(it);
        }

        int level = 0;

        while (!q.empty()){
            int l = q.size();

            while(l--){
                pair<int, int> p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second;

                for(auto &d: dir ){
                    int nx = x + d[0];
                    int ny = y + d[1];
                    // within bound nd not visited yet
                    if(isSafe(nx, ny) && visCell.find({nx, ny}) == visCell.end() ){
                        if (grid[nx][ny]==1) {
                            return level;
                        }

                        visCell.insert({nx, ny});
                        q.push({nx, ny});
                    }
                }
            }
            level++;
        }

        return level;

    }

    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        set<pair<int, int>> visitedCell;

        for ( int i=0; i < m ; i++){
            for ( int j = 0; j< n ;j++){
                if (grid[i][j]==1){ //found 1st island
                    dfs(i, j, grid, visitedCell);  //mark all 1cells of island-1 and store them in visitedcell

                    return bfs(grid, visitedCell);
                }
            }
        }

        return -1;
    }
};