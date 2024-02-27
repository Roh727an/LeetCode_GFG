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
    TreeNode* find(TreeNode* root){
        if(root->right==NULL)
        return root;
        return find(root->right);
    }
    TreeNode* rec(TreeNode* root){
        // Base Case
        if(root->left==NULL && root->right==NULL)
        return NULL;
        if(root->left==NULL)
        return root->right;
        else if(root->right==NULL)
        return root->left;

        TreeNode* curr=root->left;
        TreeNode* rightChild=root->right;
        TreeNode* leftLastChild=find(root->left);
        leftLastChild->right=rightChild;
        
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        return NULL;
        if(root->val==key)
        return rec(root);

        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->val > key) 
            {
                if(curr->left!=NULL && curr->left->val==key){
                    curr->left=rec(curr->left);
                    break;
                }
                else
                curr=curr->left;
            }
            else // Right
            { 
                if(curr->right!=NULL && curr->right->val==key){
                    curr->right=rec(curr->right);
                    break;
                }
                else
                curr=curr->right;
            }
        }
        return root;
    }
};