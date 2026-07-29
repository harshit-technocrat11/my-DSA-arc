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
    
    TreeNode* build ( vector<int> & preorder,int& preIndex, int upperbound){

        // if we reach the end of the array ,or Invalid range
        if( preIndex==preorder.size() || preorder[preIndex]>upperbound) return NULL;

        // create new node 
        TreeNode* currNode= new TreeNode(preorder[preIndex]);
        preIndex++;

        // construct left tree 
        currNode->left = build (preorder, preIndex, currNode->val);

        // construct right tree
        currNode->right = build (preorder, preIndex, upperbound );

        return currNode;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int preIdx=0;
        // passing the upper bound as infinity+
        return build(preorder, preIdx, INT_MAX);

    }
};