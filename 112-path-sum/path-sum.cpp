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
    bool rec(TreeNode* root,int target,int sum){
        sum+=root->val;
        if(root->left==NULL && root->right==NULL)
        {
            
            return sum==target;
        }
        bool left=false,right=false;
        if(root->left)
        left=rec(root->left,target,sum);

        if(root->right)
        right=rec(root->right,target,sum);

        sum-=root->val;

        return right || left;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        return false;
        return rec(root,targetSum,0);
    }
};