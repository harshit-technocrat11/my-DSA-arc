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
    pair<int,int> dfs( TreeNode*  node, int &ans ){
        if (node==nullptr) return {0,0};

        // sum, count - pair
        auto [leftSum, leftCount] = dfs(node->left, ans);
        auto [rightSum, rightCount] =  dfs (node->right, ans);

        int sum =  leftSum + rightSum + node->val;

        int cnt =  leftCount + rightCount + 1; //include the curr node 

        if (sum/cnt ==  node->val){
            ans++; 
        }

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        dfs ( root, ans);

        return ans;
    }
};