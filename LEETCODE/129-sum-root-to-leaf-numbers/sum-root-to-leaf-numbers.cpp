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
    // here totalSum -- is the global variable for storing the answer
    void sumOfPaths(TreeNode* node, int pathSum, int &totalSum){
        if ( node==NULL) return ;

        pathSum=pathSum*10 + node->val;

        // leaf node condition
        if (node->left==NULL && node->right==NULL ){
            // store path sum in totalsum
            totalSum+=pathSum;
            //exclude the current node

            return;
        }

        // traverse
        sumOfPaths(node->left, pathSum, totalSum);
        sumOfPaths(node->right, pathSum, totalSum);

        //exclude/pop node after processing
        pathSum= pathSum/10;
    }

    
    int sumNumbers(TreeNode* root) {
        int totalSum=0;

        sumOfPaths(root, 0, totalSum);

        return totalSum;
    }
};