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
    int widthOfBinaryTree(TreeNode* root) {
        if ( root == NULL) return 0;

        int maxWidth = 0;

        // queue with indexing
        // BFS approach , parent = i, left =  2*i+1, right = 2*i+2;
        queue<pair<TreeNode*, long long>>  q;
        q.push({root, 0});

        // level order start
        while (!q.empty()) {
            // size of current level 
            int size =  q.size();

            // min index ( left most of level)
            int minIndex =  q.front().second;

            // tracking, first and last index
            int first = 0, last=0;

            for ( int i =0; i< size; i++){

                // current node
                TreeNode* currNode =  q.front().first;
                // curr index 
                long currIndex =  q.front().second  -  minIndex;

                // pop and process
                q.pop();

                // conditions - 
                if ( i==0) {
                    first =  currIndex;
                }
                if ( i==size-1){
                    last = currIndex;
                }

                if ( currNode->left ) q.push({currNode->left, 2*currIndex+1});

                if ( currNode->right) q.push({currNode->right, 2*currIndex+2});

            }
            // find the width
            maxWidth = max(maxWidth, (last-first+1) );
        }

        return maxWidth;
    }
};