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
    void preOrderTraversal(TreeNode* node,vector<TreeNode*> &preOrder){
         if (node==nullptr) {
            return;
         }

        preOrder.push_back(node);

        // DFS
        preOrderTraversal(node->left, preOrder);
        preOrderTraversal(node->right, preOrder);

    }

   

    void flatten(TreeNode* root) {
        
        vector<TreeNode*> preOrder ;

        preOrderTraversal(root, preOrder);

        // construct the linkedlist - tree - by transfering the root value
        if (!preOrder.size()) return;

        for ( int i=0;i<preOrder.size()-1; i++){
            preOrder[i]->left=NULL;
            preOrder[i]->right=preOrder[i+1];
        }

        // for last node 
        if ( !preOrder.empty()){
            preOrder.back()->left=NULL;
            preOrder.back()->right=NULL;
        }


    }
};