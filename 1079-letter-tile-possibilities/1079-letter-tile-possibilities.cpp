class Solution {
public:
    void solve(string &tiles, unordered_set<string> &res, string &curr , vector<bool> &used ){
        // always insert the current string
        res.insert(curr);

        for ( int i = 0; i < tiles.size() ; i++){
            if (used[i]) continue;

            used[i] = true;

            curr.push_back(tiles[i]);
            solve(tiles, res , curr, used);
            used[i] = false;
            curr.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
        unordered_set<string> result;

        vector<bool> used(tiles.size(), false);
        string curr;
        solve(tiles, result,curr , used);

        return result.size()-1; //exclude the empty string
    }
};