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
private:
    TreeNode* prev;
    TreeNode* x;
    TreeNode* y;
    TreeNode* z;
public:
    void rec(TreeNode* root){
        // Base Case
        if(root==NULL)
        return;

        // Left Recursive Call
        rec(root->left);
        // MAIN LOGIC
        // There is a Violation
        if(prev!=NULL && root->val < prev->val){
            // First Violation
            if(x==NULL){
                x=prev;
                y=root;
            }
            // Last Violation
            else
            z=root;
        }
        // Update Prev
        prev=root;
        // Right Recursive Call
        rec(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev=new TreeNode(INT_MIN);
        rec(root);
        int first=x->val;
        if(x!=NULL && z!=NULL)
        swap(x->val,z->val);
        else if(x!=NULL && y!=NULL)
        swap(x->val,y->val);

    }
};