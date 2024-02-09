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
    void preOrder(TreeNode* root,vector<int>&order)
    {
        if(root==NULL) return;
        order.push_back(root->val);
        preOrder(root->left,order);
        preOrder(root->right,order);
    }
    bool checkTree(TreeNode* root) {
        vector<int>order;
        preOrder(root,order);

        return order[0]==order[1]+order[2];
    }
};