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
vector<int>t1,t2;
    void inorder(TreeNode* root,vector<int>&t){
        if(root==NULL){
        t.push_back(-1);
        return ;
        }
        t.push_back(root->val);
        inorder(root->left,t);
        inorder(root->right,t);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        inorder(p,t1);
        inorder(q,t2);
        return t1==t2;
    }
};