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
    int solve(TreeNode* root  , int prev ){
        if (root==NULL) return 0;
        if (root->left==NULL && root->right==NULL && prev==0 ){
            return root->val;
        }

        // left explore and right
        int l =  solve(root->left, 0 );
        int r = solve(root->right, 1);

        return l+r;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (root->left==NULL && root->right==NULL) return 0;
        
        int ans = solve(root, -1);
        
        return ans;
    }
};