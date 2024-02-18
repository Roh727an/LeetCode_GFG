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
void ParentChildConnection(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp,TreeNode* &targetNode,int target)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        // Target Node Found
        if(curr->val==target)
        targetNode=curr;
        
        if(curr->left!=NULL){
            // Child-Parent Connection
            mp[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            // Child-Parent Connection
            mp[curr->right]=curr;
            q.push(curr->right);
        }
    }
}
    int amountOfTime(TreeNode* root, int start) {
                // Your code goes here
         // return the sorted vector of all nodes at k dist
                // Step 1: Create Parental Node Map with BFS
        unordered_map<TreeNode*,TreeNode*>mp;
        TreeNode* targetNode;
        ParentChildConnection(root,mp,targetNode,start);
        // Step 2: Locate the Target Node -> ALready Located
        // Step 3:  Perform a DFS traversal from the target node to find nodes at distance ‘K’
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        
        q.push(targetNode);
        visited[targetNode]=true;
        int dis=0;
        while(!q.empty()){
            int size=q.size();
            dis++;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left!=NULL && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right!=NULL && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(mp[curr] && !visited[mp[curr]]){
                    q.push(mp[curr]);
                    visited[mp[curr]]=true;
                }
            }
        }
        
        return dis-1;
    }
};