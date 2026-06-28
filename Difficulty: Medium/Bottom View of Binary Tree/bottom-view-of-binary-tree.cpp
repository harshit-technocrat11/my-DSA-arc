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
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> answer;
        
        if ( root == NULL) return answer;
        
        // queue
        queue<pair<Node* , int >> q;  // ( node, line )
        
        //map 
        map< int, int > map; // to store the <line, node>
        
        //push initial node into queue
        q.push({root, 0});
        
        while ( !q.empty()) {
            
            //find size
            
            
            //store
            auto temp = q.front();
            
            int line = temp.second;
            
            Node* node = temp.first;
            
            q.pop();
            
            //update mapping each time  
            map[line] = node->data;
            
            //traverse further into left and right nodes
            
            if (node->left){
                //push into queue
                q.push({node->left, line-1});
            }
            
            //right 
            if ( node->right) {
                q.push ( {node->right, line+1});
            }
            
            
        }
        
        //extract all the elements
        for ( auto it : map ){
            answer.push_back(it.second);
        }
        
        return answer;
    }
};