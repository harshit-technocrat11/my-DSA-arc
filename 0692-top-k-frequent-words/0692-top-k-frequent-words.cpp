class Solution {
public:

// use a custom comparator 
    struct Compare {
        bool operator()(const pair<int, string> &a, const pair<int, string> &b ){
            if ( a.first!=b.first){
                return a.first<b.first;
            }
            // if freq match , return lexico smaller word
            return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        // count the freq
        for (auto s: words){
            mp[s]++;
        } 

        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> maxHeap;


        for (const auto& it : mp) {
            maxHeap.push({it.second, it.first}); 
        }

        // pop out the elements from heap
        vector<string> ans;
        // store top k elements
        for ( int i =0; i < k ; i++){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};