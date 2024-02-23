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
int rec(TreeNode* root, int &k){
        if(root==NULL)
        return -1;

        int left=rec(root->left,k);
        if(left!=-1)
        return left;

        k=k-1;
        if(k==0)
        return root->val;

        return rec(root->right,k);
}
    int kthSmallest(TreeNode* root, int k) {
        // return rec(root,k);
        // MORRIS TRAVERSAL
        int ans=-1;
        TreeNode* curr = root;
        while (curr != NULL) {
            // IF Left Doesnot Exist
            if (curr->left == NULL) {
                k--;
                if(k==0)
                ans= curr->val;

                curr = curr->right;
            }
            // Left Exists
            else {
                TreeNode* prev = curr->left;
                // Find RightMost Node
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                // IF Rightmost Node is NULL
                if (prev->right == NULL) {
                    // Create Thread & Move Curr's Left
                    prev->right = curr;
                    curr = curr->left;
                }
                // Thread is already There
                else {
                    k--;
                    if(k==0)
                    ans= curr->val;
                    // Remove Thread
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};