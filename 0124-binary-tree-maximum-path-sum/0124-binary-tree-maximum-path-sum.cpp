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
    // DP on trees
    int solve(TreeNode* root, int&ans){
        if (root==NULL) return 0;

        // we gotta avoid , -ve returing trees
        int l = max(0, solve(root->left, ans)); 
        int r = max(0, solve(root->right, ans));

        //1. path passing via current node
        ans = max(ans, l + r + root->val);

        // 2. path extending upwards to parent , then take max of what tree can return 

        return  root->val + max(l,r);

    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;

        solve(root, ans);

        return ans == INT_MIN? -1 : ans;
    }
};