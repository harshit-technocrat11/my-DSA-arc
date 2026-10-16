class DSU{
    vector<int> parent;
    vector<int> size; 

    public:

    // constr
    DSU(int n){
        parent.resize(n,0);
        for (int i = 0 ; i < n; i++){
            parent[i]=i;
        }
        size.resize(n,0);
    }
    // union
    void UnionBySize(int x, int y){
        int x_parent = find(x);
        int y_parent =  find(y);

        if (size[x_parent]>size[y_parent]){
            parent[y_parent] = x_parent;
            size[x_parent]+=size[y_parent];
        }
        else if (size[x_parent]<size[y_parent]){
            parent[x_parent] = y_parent;
            size[y_parent]+=size[x_parent];
        }
        else{
            // if both size equal
            parent[x_parent] = y_parent;
            size[y_parent]+=size[x_parent];
        }
    }

    // find
    int find(int x){
        if (parent[x]==x) return x;

        return parent[x] =  find(parent[x]);
    }

};

class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n =  accounts.size();
        unordered_map<string, int> mp; // mail: node
        DSU dsu(n);
        for ( int i =0; i < accounts.size(); i++){
            for ( int j = 1; j<accounts[i].size() ; j++){
                string mail = accounts[i][j];

                if ( mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                    dsu.UnionBySize(i, mp[mail]);
                }
            }
        }

        vector<string> mergedMail[n];

        for ( auto it: mp){
            string mail =  it.first;
            int node =  dsu.find(it.second); //always find the parent most node

            mergedMail[node].push_back(mail);
        }

        // ans
        vector<vector<string>> ans;

        for ( int i = 0; i < n; i++){
            if ( mergedMail[i].size()==0) continue;
            
            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for ( auto it: mergedMail[i]){
                temp.push_back(it); 
            }
            ans.push_back(temp);
        }

        return ans;
    }
};