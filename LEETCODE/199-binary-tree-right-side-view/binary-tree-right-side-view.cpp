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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans; //2D vector
        if ( root==nullptr) return {};

        // queue
        queue <TreeNode*> q;

        q.push(root);

        while ( !q.empty()){
            int size = q.size();
            vector<int> level;
            for ( int i = 0 ; i < size; i++ ){
                TreeNode* node = q.front();
                q.pop();

                //push into the level 
                level.push_back(node->val);

                //now inspect the current node
                if ( node->left) q.push(node->left);
                if ( node->right) q.push(node->right);

            }
            //push the level
            ans.push_back(level);
        }

        vector<int> final_answer;
        // extract the last values of each level
        for ( auto level : ans){
            final_answer.push_back(level.back());
        }


        return final_answer;
    }
};