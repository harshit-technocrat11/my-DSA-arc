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
    void helper( TreeNode* node, vector<int> & inorder ){
        // 
        if (node==NULL) return;

        helper(node->left, inorder);
        inorder.push_back(node->val);
        helper(node->right, inorder);

    }

    bool findTarget(TreeNode* root, int k) {
        // obtain the inorder traversal 
        vector<int> inorder;
        helper(root, inorder);

        // use 2 sum on sorted input 
        int l=0;
        int r = inorder.size()-1;

        while(l<r){
            int sum=inorder[l]+inorder[r];

            if (sum==k) return true;

            else if (sum>k) r--;
            else l++;
        }

        return false;

    }
};