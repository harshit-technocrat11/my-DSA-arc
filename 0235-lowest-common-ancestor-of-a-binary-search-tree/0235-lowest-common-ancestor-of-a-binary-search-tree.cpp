/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void searchNode(TreeNode* node, int val, vector<TreeNode*>&path){
        if(node==nullptr) return;

        path.push_back(node);

        if ( node->val==val ){
            return ;
        }
        else if ( node->val > val){
            if(node->left){
                searchNode(node->left, val, path );
            }
        }
        else {
            if ( node->right ){
                searchNode(node->right, val , path);
            }
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        searchNode(root, p->val, path1);

        vector<TreeNode*> path2;
        searchNode(root, q->val, path2);

        int n=path1.size();
        int m=path2.size();
        TreeNode* lca=0;
        for ( int i =0; i< min(m, n); i++){
            if ( path1[i]->val==path2[i]->val){
                lca=path1[i];
            }
        }

        return lca;
    }
};