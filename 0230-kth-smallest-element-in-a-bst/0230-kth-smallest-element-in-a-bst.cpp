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

    void inorderTraverse(TreeNode* root,  int k, int &cnt, int &ans){
        // base case 
        if ( root==NULL) return ;

            // left, root, right
            inorderTraverse(root->left, k , cnt, ans);

            // push the root / check
            cnt++;
            if ( cnt==k){
                ans = root->val;
                return ;
            }
            

            // right
            inorderTraverse(root->right, k , cnt , ans);
        

    }

    int kthSmallest(TreeNode* root, int k) {
        
        int answer=0;
        int cnt=0;
        
        inorderTraverse(root, k , cnt, answer);

        return answer;

    }
};