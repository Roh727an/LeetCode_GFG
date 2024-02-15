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
// 
void ParentChildConnection(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step 1: Create Parental Node Map with BFS
        unordered_map<TreeNode*,TreeNode*>mp;
        ParentChildConnection(root,mp);
        // Step 2: Locate the Target Node -> ALready Located
        // Step 3:  Perform a DFS traversal from the target node to find nodes at distance ‘K’
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int dis=0;
        while(!q.empty()){
            int size=q.size();
            if(dis++==k)
            break;
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
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};