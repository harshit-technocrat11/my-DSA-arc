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

    bool isSymmetric(TreeNode* root) {  
        //  if the tree is empty
        if ( root==NULL) return true;

        return isSymmetricHelper(root->left, root->right);

    }

    bool isSymmetricHelper(TreeNode*  root1,TreeNode* root2){
        if ( root1==NULL || root2 == NULL) {
            return root1==root2;
        }

        //check if the data in the current node is equal that is recursively check for symmetry in both subtrees
        return (root1->val == root2->val) &&
                isSymmetricHelper(root1->left, root2->right)
                && isSymmetricHelper(root1->right, root2->left);
    }
};