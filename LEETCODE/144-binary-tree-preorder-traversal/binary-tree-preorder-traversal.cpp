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
    void preorder(TreeNode* node, vector<int> &output){
        if ( node==nullptr ){
            return ;
        }
        //store ans
        output.push_back(node->val);
        preorder(node->left, output); //;left subtree
        preorder(node->right, output); //right subtree
        
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;

        preorder( root, output);
        return output;
    }
};