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

// int maxD(Node* root){
//     if ( root==NULL) return 0;
//     int depth=0;

//     for ( Node* ch: root->children ){
//         int h = maxD(ch);

//         depth = max(depth, h);
//     }

//     return 1  + depth;
// }
public:
    int maxDepth(Node* root) {
        queue<Node*> q;
        if ( root==NULL) return 0;

        q.push(root);
        int depth=0;

        while(!q.empty()){
            int s = q.size();

            while ( s--){

                Node* node =  q.front();
                q.pop();

                for ( Node* ch: node->children){
                    q.push(ch);
                }
            }
            depth++;
        }

        return depth;
    }
};