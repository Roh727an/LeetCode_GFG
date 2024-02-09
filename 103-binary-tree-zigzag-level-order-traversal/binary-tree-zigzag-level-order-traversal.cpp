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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        // If odd -> Left TO Right ,If Even -> Right to Left
        bool isOddLevel=true;
        // Level Order Traversal
        queue<TreeNode*>q;
        // Push the Root Node inot Queue
        q.push(root);

        while(!q.empty())
        {
            int levelSize=q.size();
            // Create a Vector to Store the Current Level Order
            vector<int> levelOrder(levelSize);
            // Iterate for Current Order
            for(int i=0;i<levelSize;i++)
            {
                // Take out the Front 
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL)
                q.push(curr->left);
                if(curr->right!=NULL)
                q.push(curr->right);

                // Now if The Current level is Odd then I Store Left to Right
                // level[i......size-1]
                // Else if the Current Level is Even then I Store Right To Left
                // level[size-1...i]
                int fill=isOddLevel ? i : levelSize-i-1;
                levelOrder[fill]=curr->val;
            }
            isOddLevel=!isOddLevel;
            ans.push_back(levelOrder);
        }
        return ans;
    }
};