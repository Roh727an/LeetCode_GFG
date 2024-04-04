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
    bool checkTree(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
        return true;

        // Calculate Left
        int left=0;
        if(root->left)
        left=root->left->val;

        // Calculate Right
        int right=0;
        if(root->right)
        right=root->right->val;

        if(left+right != root->val)
        return false;

        return checkTree(root->left) && checkTree(root->right);
    }
};