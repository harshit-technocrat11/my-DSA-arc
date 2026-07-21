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
    TreeNode* findParents_and_return_startNode(TreeNode* node, unordered_map<TreeNode*, TreeNode*> &parentMap, int start){
        // BFS traversal 

        queue<TreeNode*> q;
        q.push(node);

        TreeNode* startNode;

        while ( !q.empty()){
            TreeNode* currNode = q.front();

            if ( q.front()->val==start){
                startNode=q.front();
            }
            q.pop();

            if (currNode->left){
                parentMap[currNode->left] = currNode ;
                q.push(currNode->left);
            }
            if (currNode->right){
                parentMap[currNode->right] = currNode ;
                q.push(currNode->right);
            }

        }

        return startNode;

    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentOf;
        TreeNode* startNode= findParents_and_return_startNode(root, parentOf, start);

        // visited record - Infected nodes
        unordered_map<TreeNode*, bool> isInfected;
        queue<TreeNode* > q;
        q.push(startNode);
        // infect the start
        isInfected[startNode]=true;

        int t=0;

        while( !q.empty()){
            // traverse- similar to undirected graph 
            int size = q.size();
            t++;
        
            // 3D
            for ( int i=0; i < size; i++){
                TreeNode* currNode = q.front();
                q.pop();

                if (currNode->left && isInfected.find(currNode->left)==isInfected.end()){
                    q.push(currNode->left);
                    isInfected[currNode->left] = true;
                }
                
                if (currNode->right && isInfected.find(currNode->right)==isInfected.end()){
                    q.push(currNode->right);
                    isInfected[currNode->right] = true;
                }
                if (parentOf[currNode] && isInfected.find(parentOf[currNode])==isInfected.end()){
                    q.push(parentOf[currNode]);
                    isInfected[parentOf[currNode]] = true;
                }
                
            }
            
        }

        return t-1;

    }
};