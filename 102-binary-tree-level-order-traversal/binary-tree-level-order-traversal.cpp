/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Create ans
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        // Create a Queue Ds to Store
        queue<TreeNode*>q;
        // Push the Root Node
        q.push(root);
        while(!q.empty()){
            // Get the Size / Nodes PResent in the Level
            int sizeOfLevel=q.size();
            // Create a Vector to Store the Nodes of A Level
            vector<int>level;
            for(int i=0;i<sizeOfLevel;i++)
            {
                // Get the Front Node from Queue
                TreeNode* curr=q.front();
                q.pop();
                // Push Left & Right Child of the Node
                if(curr->left) 
                q.push(curr->left);
                if(curr->right) 
                q.push(curr->right);
                level.push_back(curr->val);
            }
            // After Completing  A Level make sure to Push the List of That Level into ANS
            ans.push_back(level);
        }
        return ans;
    }
};