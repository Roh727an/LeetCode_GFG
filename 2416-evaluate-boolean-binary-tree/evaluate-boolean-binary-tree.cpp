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
    bool evaluateTree(TreeNode* root) {

        if(root->left==NULL && root->right==NULL){
            if(root->val==0)
            return false;
            else 
            return true;
        }

        bool leftRec=evaluateTree(root->left);
        bool rightRec=evaluateTree(root->right);

        if(root->val==2)
        return leftRec || rightRec;
        else
        return leftRec && rightRec;
    }
};