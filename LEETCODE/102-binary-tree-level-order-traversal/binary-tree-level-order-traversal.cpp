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
    vector<vector<int>> levelOrder(TreeNode* root) {
         if ( root==nullptr) return {};
        
        // initialize an empty queue
         queue<TreeNode*> Q;
        // initalize a 2D vector - to store answers - or LEVELS 
        vector<vector<int>> Answer;

        Q.push(root);

        while ( !Q.empty()){
            // size of the current level ---- 
            int size = Q.size();
            // to store the processed nodes
            vector<int> level;

            for ( int i =0; i<size; i++){
                TreeNode* node= Q.front(); //store frontnode
                Q.pop();  //pop to process

                level.push_back(node->val);

                // start processing the left and right child -and store in the queue
                if(node->left!=nullptr){
                    Q.push(node->left);
                }
                if ( node->right!=nullptr){
                    Q.push(node->right);
                }
            }
            // level- stores the processed nodes of the current level 
            Answer.push_back(level);

        }

        return Answer;
         
    }
};