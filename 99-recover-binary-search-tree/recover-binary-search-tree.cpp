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
vector<int>v;
    void inOrder(TreeNode* root){
        if(root==NULL)
        return ;
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }
    void rec(int &idx,TreeNode*& root){
        if(idx>=v.size() || root==NULL)
        return;
        rec(idx,root->left);
        
        
        root->val=v[idx];
        idx++;

        rec(idx,root->right);
    }
    void recoverTree(TreeNode* root) {
        // Store Inorder
        inOrder(root);
        // Sort Inorder to make correct Inorder
        sort(v.begin(),v.end());
        int idx=0;
        rec(idx,root);
        
    }
};