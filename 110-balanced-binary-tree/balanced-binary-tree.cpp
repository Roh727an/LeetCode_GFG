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
    // If any of the Subtree Gives us -1 thats mean that subtree is Not heght
    // Balanced so we return -1 further without checking anuthing
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        // cout<<root->val<<endl;
        int left = height(root->left);
        // Left Subtree is Not Height Balanced
        if (left == -1)
            return -1;

        int right = height(root->right);
        // Right Subtree is Not Height Balanced
        if (right == -1)
            return -1;
        // cout<<"Left "<<left<<" Right "<<right<<endl;
        // Not Height-Balanced
        if (abs(left - right) > 1)
            return -1;
        // Return height
        // cout<<"Height is "<<1 + max(left, right)<<endl;
        // cout<<endl;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) { 
        return height(root) != -1; 
        }
};