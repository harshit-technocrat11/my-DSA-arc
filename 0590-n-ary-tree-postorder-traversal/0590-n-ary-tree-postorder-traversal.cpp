/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
void pre(Node* root, vector<int> &ans){
        if ( root==NULL) return;

        // explore children
        for ( Node* ch : root->children){
            pre(ch, ans);
        }
        ans.push_back(root->val);

    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        pre(root, ans);

        return ans;
    }
};