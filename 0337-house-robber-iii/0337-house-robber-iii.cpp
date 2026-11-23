/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // memoization
    unordered_map<TreeNode*, vector<int>> dp;

    int solve (TreeNode* root, int canRob ){
        if (root==NULL) return 0;
        if (dp.find(root)==dp.end()){
            // need to intialize memo
            dp[root] = vector<int> (2,-1);
        }
        if (dp.find(root)!=dp.end() && dp[root][canRob]!=-1) {
            return dp[root][canRob];
        }

        int take = 0, skip=0;

        // if we skip current state. ( if canRob=0/1)
        // skipping leads to canRob= True always
        skip = solve(root->left, 1) + solve(root->right, 1);

        // if we Rob current state ( if canRob=1)
        if (canRob == true){
            take = root->val + solve(root->left, 0) + solve(root->right, 0);
        }

        return dp[root][canRob] =  max(take, skip);
    }

    int rob(TreeNode* root) {
        if ( root->left==nullptr && root->right==nullptr) return root->val;
        // rob or skip
        // each node returns 2 states

        return solve(root, 1);
    }
};