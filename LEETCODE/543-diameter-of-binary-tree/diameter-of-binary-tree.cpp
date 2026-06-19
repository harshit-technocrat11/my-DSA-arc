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

    int Height(TreeNode* node){
        if ( node==NULL) return 0;

        int lh = Height(node->left);
        int rh = Height(node->right);
        return max(lh, rh) +1; 
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if ( root == NULL) return 0;

        int LD = diameterOfBinaryTree(root->left); //left diameter
        int RD = diameterOfBinaryTree(root->right); //right diameter 

        int currD = Height(root->left) + Height(root->right);  // diameter via current root

        //max of all 3 diameters

        return max(currD, max(LD, RD));

    }
};