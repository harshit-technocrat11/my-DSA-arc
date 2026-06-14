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
    void postorder (TreeNode* node, vector<int> &output){
        
        if ( node==nullptr){
            return ;
        }
        // left 
        postorder(node-> left, output);
      
        // right
        postorder(node-> right, output);
        // value
        output.push_back(node->val);

    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output; 

        postorder(root, output);

        return output;

    }
};