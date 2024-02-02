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
    void preOrderRec(TreeNode * root)
    {
        // Base Case
        if(root==NULL)
        return ;

        // Push Current Node
        order.push_back(root->val);
        // Move Left
        preOrderRec(root->left);
        // Move Right
        preOrderRec(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preOrderRec(root);
        return order;
    }
};