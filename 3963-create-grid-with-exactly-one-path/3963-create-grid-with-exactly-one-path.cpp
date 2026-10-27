class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;
        string top(n, '.');

        grid.push_back(top);
        string bottom(n, '#');

        bottom[n-1] = '.';

        for ( int j=1; j<m ; j++){
            grid.push_back(bottom);
        }

        return grid;

    }
};