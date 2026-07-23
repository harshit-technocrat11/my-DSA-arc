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
    // inorder traversal
    void inorderTraverse(TreeNode* node, vector<int>& ans){
        // base case 
        if (node==nullptr) return ;

        // leaf 
        if (node->left==NULL && node->right==NULL) {
            ans.push_back(node->val);
            return;
        }

        // left, root, right
        if ( node->left) inorderTraverse(node->left, ans);

        // push the root
        ans.push_back(node->val);

        // right
        if (node->right) inorderTraverse(node->right, ans);

        return;

    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorderTraverse(root, ans);

        // 1 indexed array

        return ans[k-1];
    }
};