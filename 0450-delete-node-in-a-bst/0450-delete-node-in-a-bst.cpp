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

    TreeNode* findMinRightNode(TreeNode* node){
        // iterate until we reach the left most , leaf node
        while(node->left!=NULL){
            node=node->left;
        }
        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if ( root==NULL) return NULL;

        // step-1 : search for key
        else if (key < root->val){
            // iterate left
            root->left = deleteNode(root->left, key);
        }
        else if(key>root->val){
            //iterate right
            root->right = deleteNode(root->right, key);
        }
        // found the key !!!!, delete it
        else {
            // case 1: no child
            if ( root->left==NULL && root->right==NULL ){
                delete root;
                return NULL;
            }

            // case 2 : one child, left or right
            else if (root->left==NULL){
                // if right exists 
                TreeNode* temp = root;
                root=root->right;
                delete temp;
                return root;
            }
            else if ( root->right==NULL){
                // if left exists
                TreeNode* temp = root;
                root=root->left;
                delete temp;
                return root;
            }
            
            // 2 children
            else {
                // find min val from right subtree  (  inorder successor)
                TreeNode* temp = findMinRightNode(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);  //delete the immediate right duplicate right child 
            }
        }

        return root;
    }
};