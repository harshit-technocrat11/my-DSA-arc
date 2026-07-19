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
    void parentMap(TreeNode* node, unordered_map<TreeNode* , TreeNode* > &parentOf ){
        queue<TreeNode*> q;
        q.push(node);

        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();

            if ( currNode->left){
                parentOf[currNode->left]=currNode;
                q.push(currNode->left);
            }
            if ( currNode->right){
                parentOf[currNode->right]=currNode;
                q.push(currNode->right);
            }

        }
    }
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Build a parent map
        unordered_map<TreeNode* , TreeNode*> parentOf;

        parentMap(root, parentOf);

        // now main Algo : traverse the Tree like an Undirected graph 
        queue<TreeNode*> queue;
        unordered_map<TreeNode*,bool> visited;
        queue.push(target); //start from the target
        visited[target]=true;
        int currLevel = 0;

        while ( !queue.empty()){
        
            int size = queue.size();

            if( currLevel==k) break;
            currLevel++;

            for ( int i = 0; i < size; i++){
                TreeNode* currNode = queue.front();
                queue.pop();

                // left and right check

                // if left node exists and , it is unvisited
                if (currNode->left && visited.find(currNode->left)==visited.end() ){
                    visited[currNode->left]=true;
                    queue.push(currNode->left);
                }
                // if right node exists and , it is unvisited
                if (currNode->right && visited.find(currNode->right)==visited.end() ){
                    visited[currNode->right]=true;
                    queue.push(currNode->right);
                }

                // check only if parent NOT visited, and parent exists
                if ( parentOf[currNode] && visited.find(parentOf[currNode])==visited.end()){
                    visited[parentOf[currNode]] = true;
                    queue.push(parentOf[currNode]);
                }

            }

        }

        // remaining elements of the queue now contain the Answer Nodes
        vector<int> ans;
        
        while(!queue.empty()){
            ans.push_back(queue.front()->val);
            queue.pop();
        }

        return ans;

    }
};