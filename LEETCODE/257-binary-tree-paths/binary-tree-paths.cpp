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
    void DFSpath(TreeNode* node,string path ,vector<string>&ans){
        if ( node==NULL) return;

        // process the current node
        path+=to_string(node->val);

        if (node->left==NULL && node->right==NULL) //leaf node
        {
            ans.push_back(path);
            return ;
        }

        path+="->";

        DFSpath(node->left, path, ans);
        DFSpath(node->right, path, ans);

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;

        DFSpath(root, s , ans);

        return ans;
    }
};