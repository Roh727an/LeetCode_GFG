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
    // Recursive Approch
    void postOrderRec(TreeNode* root)
    {
        // Base Case
        if(root==NULL)
        return ;
        // Left
        postOrderRec(root->left);
        // Right
        postOrderRec(root->right);
        // Store
        order.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postOrderRec(root);
        return order;
    }
};