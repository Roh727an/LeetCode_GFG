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
    vector<int>order;
    void inOrderRec(TreeNode* root)
    {
        // Base Case
        if(root==NULL)
        return ;
        // Left
        inOrderRec(root->left);
        // Store
        order.push_back(root->val);
        // Right
        inOrderRec(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inOrderRec(root);
        return order;
    }
};