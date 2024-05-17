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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Base Case
        if(root==NULL)
        return NULL;

        // Recursion Call Left
        if(root->left){
        TreeNode *left=removeLeafNodes(root->left,target);
        root->left=left;
        }
        // Recursion Call Right
        if(root->right){
        TreeNode *right=removeLeafNodes(root->right,target);
        root->right=right;
        }
        
        // Backtracing Condition
        if(root->left==NULL && root->right==NULL && root->val==target)
        return NULL;
        return root;
    }
};