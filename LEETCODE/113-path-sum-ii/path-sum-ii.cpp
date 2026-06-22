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
    void AllPaths(TreeNode* root, int targetSum, vector<int> &path ,vector<vector<int>> &ans  ){
        if (root==NULL) return;
        
        targetSum-=root->val; 

        // if ( targetSum<0) return ;
        path.push_back(root->val);

        if ( root->left==NULL && root->right==NULL ){
            if ( targetSum==0){ //if leaf node encountered, + targetsum achieved
                ans.push_back(path);
                path.pop_back(); //now backtrack 
                return;
            }
        }

        AllPaths(root->left, targetSum , path, ans);

        AllPaths(root->right, targetSum, path, ans);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> Ans;

        vector<int> path;  //temp path

        AllPaths(root,targetSum,path, Ans );

        return Ans;
    }
};