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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);

        TreeNode* curr = root;
        while (curr != NULL) {
            // Move Right
            if (curr->val <= val) {
                // If there exist Right then Move Left
                if (curr->right)
                    curr = curr->right;
                else {
                    curr->right = new TreeNode(val);
                    break;
                }

            }
            // Move Left
            else {
                // If there exist Left then Move Left
                if (curr->left)
                    curr = curr->left;
                else {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};