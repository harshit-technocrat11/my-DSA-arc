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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result ;
        if ( root==NULL) return result;

        queue <TreeNode*> q;
        q.push(root); //initialize by pushing the root


        bool leftToRight = true;

        while (!q.empty()){
            int size = q.size();

            vector<int> level(size);

            for ( int i =0; i<size; i++){
                TreeNode* node = q.front(); //store it in temp node
             
                q.pop(); //pop the front node

                // if flag ( leftToRight ==false, then reverse index ) 
                int index = leftToRight ? i : (size-1-i) ;

                level[index] = node->val; //push it into the vector

                if ( node->left) {
                    q.push(node->left);
                }

                if ( node->right){
                    q.push(node->right);
                }
            }
            // now reverse the flag
            leftToRight = !leftToRight;
            result.push_back(level);  
        }

        return result;
    }
};