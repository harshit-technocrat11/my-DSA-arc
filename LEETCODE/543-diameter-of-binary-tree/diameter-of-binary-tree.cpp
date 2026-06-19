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


    int Height(TreeNode* node, int &diameter){
        if ( node==NULL) return 0;

        int lh = Height(node->left, diameter);
        int rh = Height(node->right, diameter);
        diameter = max( lh+rh , diameter); //find the current diameter of the node, and update the answer with max value 

        return max(lh, rh) +1; 
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter =0;

        Height(root, diameter);

        return diameter;

    }
};