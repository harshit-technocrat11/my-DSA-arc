/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    
    void AllPaths(Node* node, vector<int> &path, vector<vector<int>> &ans){
        
        // base cases
        if ( node == NULL) return ;
        
        path.push_back(node->data);
        
        // leaf node
        if ( node->left==NULL && node->right==NULL) {
            ans.push_back(path);
            // pop node
            path.pop_back();
            return ;
        }
        
        // DFS recursion 
        AllPaths(node->left, path, ans);
        AllPaths(node->right, path, ans);
        
        path.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> answer;
        vector<int> temp;
        
        AllPaths(root, temp, answer);
        
        return answer;
        
    }
};