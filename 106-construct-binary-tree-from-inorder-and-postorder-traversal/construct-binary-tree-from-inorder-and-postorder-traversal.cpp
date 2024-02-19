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
TreeNode* rec(vector<int>& inorder,int inS,int inE,vector<int>& postorder,int postS,int postE,map<int,int>&inMap){
        // Base Case
        if(inS>inE || postS > postE)
        return NULL;

        // Create the Current Node from PreOrder
        TreeNode* curr=new TreeNode(postorder[postE]);
        // Find the curr in Inorder
        int idx=inMap[curr->val];
        // Number of Elements present in Left of Curr in Inorder will be Left SUbtree
        int numsLeft=idx-inS;
        // Left Subtree Build Recursive Call
        curr->left=rec(inorder,inS,idx-1,postorder,postS,postS+numsLeft-1,inMap);

        curr->right=rec(inorder,idx+1,inE,postorder,postS+numsLeft,postE-1,inMap);

        return curr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
        return NULL;
        map<int,int>inMap;
        // Hash Map of Inorder to Optimize Searching
        for(int i=0;i<inorder.size();i++)
        inMap[inorder[i]]=i;

        TreeNode* root=rec(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inMap);
        return root;
    }
};