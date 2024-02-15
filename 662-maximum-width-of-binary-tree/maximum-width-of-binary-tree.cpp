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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        return 0;
        long long ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            long long size=q.size();
            long long minIdx=q.front().second;
            long long first,last;
            // Traverse the level
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front().first;
                long long currIdx=q.front().second-minIdx;
                q.pop();

                // If leftMost Node
                if(i==0)
                first=currIdx;
                // If the RightMost Node
                if(i==size-1)
                last=currIdx;

                // Push Left & Right CHildren
                if(curr->left)
                q.push({curr->left,currIdx*2+1});
                if(curr->right)
                q.push({curr->right,currIdx*2+2});
            }
            // Calculate Max Width
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};