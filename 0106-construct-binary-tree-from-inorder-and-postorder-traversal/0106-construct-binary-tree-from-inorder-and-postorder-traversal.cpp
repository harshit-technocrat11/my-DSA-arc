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
    TreeNode* build(vector<int> &postorder,vector<int> &inorder ,int  inStart, int inEnd, map<int, int> &inorderMap , int & postIndex){
        if ( inStart>inEnd)  return NULL;

        TreeNode* root = new TreeNode(postorder[postIndex--]);

        // find the inorder index of the root node
        int inRoot= inorderMap[root->val]; 

        // build right subtree
        root->right = build(postorder, inorder, inRoot+1, inEnd, inorderMap, postIndex );

        // build left subtree
        root->left = build(postorder, inorder, inStart, inRoot-1 , inorderMap, postIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inorderMap; // so as to eliminate searching 

        for (int i =0; i < inorder.size(); i++ ){
            inorderMap[inorder[i]]=i;
        }

        // traverse the postorder from the reverse
        int postIndex=postorder.size()-1;

        return build ( postorder , inorder, 0, inorder.size()-1 ,inorderMap , postIndex);

    }
};