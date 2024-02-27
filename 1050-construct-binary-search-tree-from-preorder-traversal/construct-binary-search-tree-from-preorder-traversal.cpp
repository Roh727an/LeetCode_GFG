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
    TreeNode* rec(int &idx,vector<int>&v,int bound){
        // Base Condition
        if(idx>=v.size() || bound < v[idx])
        return NULL;
        // Create the Current Node
        TreeNode* curr=new TreeNode(v[idx++]);
        // Join it's left with recursive call (idx+1,v,bound=curr->val)
        curr->left=rec(idx,v,curr->val);
        // Join it's right with recursive call (idx+1,v,bound)
        curr->right=rec(idx,v,bound);
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)
        return NULL;
        int idx=0,bound=INT_MAX;
        return rec(idx,preorder,bound);
    }
};