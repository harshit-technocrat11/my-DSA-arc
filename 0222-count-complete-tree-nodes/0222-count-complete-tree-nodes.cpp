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
    void NodeCounter( TreeNode* node , int &count){
        if ( node == NULL) return ;
        count++;
        // leaf node condition
        if ( node->left == NULL && node->right == NULL){
            return ;
        }

        NodeCounter( node->left, count);
        NodeCounter( node->right, count);

    }

    int countNodes(TreeNode* root) {
        int count = 0;
        
        NodeCounter(root, count);

        return count;
    }
};